/***************************************
 
 Name: Jake Seawell
 Date: 11/20/18
 Description:
 This is the class implementation
 file for a class called EmptySpace.
 The EmptySpace class inherits from Space,
 and represents spaces on a
 game board, and contains a pointer
 to its current occupant, as well as
 pointers to all its adjacent spaces.
 
 **************************************/

#include "EmptySpace.hpp"
#include "Space.hpp"
#include "intVal.hpp"
#include "choiceFunction.hpp"
#include "FinalGame.hpp"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

/***************************************
             EmptySpace::EmptySpace()
 **************************************/
EmptySpace::EmptySpace(int r, int c, int num, Space*** board) : Space(r, c, board)
{
    //empty space
    name = '_';
    
    //set space number
    spaceNum = num;
}

/***************************************
  EmptySpace::addPlayer()
 
 This funtion adds a player to player
 vector in space and changes space name
 to P for display
 
 **************************************/
void EmptySpace::addPlayer(Player &p1)
{
        playerVect.push_back(p1);
        name = 'P';
}


/***************************************
 EmptySpace::movePlayer()
 
 This function allows the user to move
 the player to any adjacent space, as long
 as the space is not NULL. If the space is
 occupied by an item (except trap), the
 user will be prompted to move and collect
 the object, or not to move
 
 **************************************/
Player EmptySpace::movePlayer(Player &p1)
{
    if (!playerVect.empty())
    {
        
        int direction;
        cout << "Which direction would you like to move?" << endl;
        cout << endl << "7|8|9" << endl;
        cout << "-----" << endl;
        cout << "4| |6" << endl;
        cout << "-----" << endl;
        cout << "1|2|3" << endl << endl;
        direction = minMaxValidation(integerValidation(),1,9);
        while (direction == 5)
        {
            cout << "5 is not a valid move. Try again." << endl;
            direction = minMaxValidation(integerValidation(),1,9);
        }
        
        if (direction == 4 && left != NULL)
        {
            if (left->getName() == 'F' && !p1.hasCuffs())
            {
                cout << "You found the fugitive" << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "Try to capture the fugitive", "Don't move");
                if (moveOrNo == 1)
                {
                    cout << "You don't have the cuffs yet!" << endl;
                    if (!p1.hasArmor())
                    {
                        cout << "The fugitive escaped, and harmed you in the process." << endl;
                        cout << "You took 25 damage." << endl;
                        p1.setDamageTaken(25);
                    }
                    else
                    {
                        cout << "The fugitive escaped, but luckily you are carrying armor." << endl;
                        cout << "You avoided taking any damage." << endl;
                    }
                }
            }
            else if (left->getName() == 'C')
            {
                cout << "You found the handcuffs!" << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "Grab the cuffs", "Don't move");
                if (moveOrNo == 1)
                {
                    p1.addToBelt("Handcuffs");
                    left->addPlayer(p1);
                    playerVect.erase(playerVect.begin());
                    name = '_';
                }
            }
            else if (left->getName() == 'T')
            {
                cout << "Uh oh. You sprang a boobie-trap set by the fugitive." << endl;
                if (!p1.hasArmor())
                {
                    cout << "You took 35 damage." << endl;
                    p1.setDamageTaken(35);
                }
                else
                {
                    cout << "Luckily, you are carrying armor. You avoid taking any damage." << endl;
                }
                
                left->addPlayer(p1);
                playerVect.erase(playerVect.begin());
                name = '_';
            }
            else if (left->getName() == 'L')
            {
                cout << "You found the flashlight!" << endl;
                cout << "This will allow you to see the spaces nearby." << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "grab the flashlight", "Don't move");
                if (moveOrNo == 1)
                {
                    p1.addToBelt("Flashlight");
                    left->addPlayer(p1);
                    playerVect.erase(playerVect.begin());
                    name = '_';
                }
            }
            else if (left->getName() == 'A')
            {
                cout << "You found some body armor! This will protect you from taking damage." << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "Grab the armor", "Don't move");
                if (moveOrNo == 1)
                {
                    cout << "You are now protected, and time has been frozen for 10 minutes." << endl;
		    p1.addToBelt("Armor");
                    left->addPlayer(p1);
                    playerVect.erase(playerVect.begin());
                    name = '_';
                }
            }
            else
            {
                left->addPlayer(p1);
                playerVect.erase(playerVect.begin());
                name = '_';
            }
        }
        else if (direction == 7 && upLeft != NULL)
        {
            if (upLeft->getName() == 'F' && !p1.hasCuffs())
            {
                cout << "You found the fugitive" << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "Try to capture the fugitive", "Don't move");
                if (moveOrNo == 1)
                {
                    cout << "You don't have the cuffs yet!" << endl;
                    if (!p1.hasArmor())
                    {
                        cout << "The fugitive escaped, and harmed you in the process." << endl;
                        cout << "You took 25 damage." << endl;
                        p1.setDamageTaken(25);
                    }
                    else
                    {
                        cout << "The fugitive escaped, but luckily you are carrying armor." << endl;
                        cout << "You avoided taking any damage." << endl;
                    }
                }
            }
            else if (upLeft->getName() == 'C')
            {
                cout << "You found the handcuffs!" << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "Grab the cuffs", "Don't move");
                if (moveOrNo == 1)
                {
                    p1.addToBelt("Handcuffs");
                    upLeft->addPlayer(p1);
                    playerVect.erase(playerVect.begin());
                    name = '_';
                }
            }
            else if (upLeft->getName() == 'T')
            {
                cout << "Uh oh. You sprang a boobie-trap set by the fugitive." << endl;
                if (!p1.hasArmor())
                {
                    cout << "You took 35 damage." << endl;
                    p1.setDamageTaken(35);
                }
                else
                {
                    cout << "Luckily, you are carrying armor. You avoid taking any damage." << endl;
                }
                
                upLeft->addPlayer(p1);
                playerVect.erase(playerVect.begin());
                name = '_';
            }
            else if (upLeft->getName() == 'L')
            {
                cout << "You found the flashlight!" << endl;
                cout << "This will allow you to see the spaces nearby." << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "grab the flashlight", "Don't move");
                if (moveOrNo == 1)
                {
                    p1.addToBelt("Flashlight");
                    upLeft->addPlayer(p1);
                    playerVect.erase(playerVect.begin());
                    name = '_';
                }
            }
            else if (upLeft->getName() == 'A')
            {
                cout << "You found some body armor! This will protect you from taking damage." << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "Grab the armor", "Don't move");
                if (moveOrNo == 1)
                {
                    cout << "You are now protected, and time has been frozen for 10 minutes." << endl;
                    p1.addToBelt("Armor");
                    upLeft->addPlayer(p1);
                    playerVect.erase(playerVect.begin());
                    name = '_';
                }
            }
            else
            {
                upLeft->addPlayer(p1);
                playerVect.erase(playerVect.begin());
                name = '_';
            }
        }
        else if (direction == 8 && up != NULL)
        {
            if (up->getName() == 'F' && !p1.hasCuffs())
            {
                cout << "You found the fugitive" << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "Try to capture the fugitive", "Don't move");
                if (moveOrNo == 1)
                {
                    cout << "You don't have the cuffs yet!" << endl;
                    if (!p1.hasArmor())
                    {
                        cout << "The fugitive escaped, and harmed you in the process." << endl;
                        cout << "You took 25 damage." << endl;
                        p1.setDamageTaken(25);
                    }
                    else
                    {
                        cout << "The fugitive escaped, but luckily you are carrying armor." << endl;
                        cout << "You avoided taking any damage." << endl;
                    }
                }
            }
            else if (up->getName() == 'C')
            {
                cout << "You found the handcuffs!" << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "Grab the cuffs", "Don't move");
                if (moveOrNo == 1)
                {
                    p1.addToBelt("Handcuffs");
                    up->addPlayer(p1);
                    playerVect.erase(playerVect.begin());
                    name = '_';
                }
            }
            else if (up->getName() == 'T')
            {
                cout << "Uh oh. You sprang a boobie-trap set by the fugitive." << endl;
                if (!p1.hasArmor())
                {
                    cout << "You took 35 damage." << endl;
                    p1.setDamageTaken(35);
                }
                else
                {
                    cout << "Luckily, you are carrying armor. You avoid taking any damage." << endl;
                }
                
                up->addPlayer(p1);
                playerVect.erase(playerVect.begin());
                name = '_';
            }
            else if (up->getName() == 'L')
            {
                cout << "You found the flashlight!" << endl;
                cout << "This will allow you to see the spaces nearby." << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "grab the flashlight", "Don't move");
                if (moveOrNo == 1)
                {
                    p1.addToBelt("Flashlight");
                    up->addPlayer(p1);
                    playerVect.erase(playerVect.begin());
                    name = '_';
                }
            }
            else if (up->getName() == 'A')
            {
                cout << "You found some body armor! This will protect you from taking damage." << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "Grab the armor", "Don't move");
                if (moveOrNo == 1)
                {
                    cout << "You are now protected, and time has been frozen for 10 minutes." << endl;
                    p1.addToBelt("Armor");
                    up->addPlayer(p1);
                    playerVect.erase(playerVect.begin());
                    name = '_';
                }
            }
            else
            {
                up->addPlayer(p1);
                playerVect.erase(playerVect.begin());
                name = '_';
            }
        }
        else if (direction == 9 && upRight != NULL)
        {
            if (upRight->getName() == 'F' && !p1.hasCuffs())
            {
                cout << "You found the fugitive" << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "Try to capture the fugitive", "Don't move");
                if (moveOrNo == 1)
                {
                    cout << "You don't have the cuffs yet!" << endl;
                    if (!p1.hasArmor())
                    {
                        cout << "The fugitive escaped, and harmed you in the process." << endl;
                        cout << "You took 25 damage." << endl;
                        p1.setDamageTaken(25);
                    }
                    else
                    {
                        cout << "The fugitive escaped, but luckily you are carrying armor." << endl;
                        cout << "You avoided taking any damage." << endl;
                    }
                }
            }
            else if (upRight->getName() == 'C')
            {
                cout << "You found the handcuffs!" << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "Grab the cuffs", "Don't move");
                if (moveOrNo == 1)
                {
                    p1.addToBelt("Handcuffs");
                    upRight->addPlayer(p1);
                    playerVect.erase(playerVect.begin());
                    name = '_';
                }
            }
            else if (upRight->getName() == 'T')
            {
                cout << "Uh oh. You sprang a boobie-trap set by the fugitive." << endl;
                if (!p1.hasArmor())
                {
                    cout << "You took 35 damage." << endl;
                    p1.setDamageTaken(35);
                }
                else
                {
                    cout << "Luckily, you are carrying armor. You avoid taking any damage." << endl;
                }
                
                upRight->addPlayer(p1);
                playerVect.erase(playerVect.begin());
                name = '_';
            }
            else if (upRight->getName() == 'L')
            {
                cout << "You found the flashlight!" << endl;
                cout << "This will allow you to see the spaces nearby." << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "grab the flashlight", "Don't move");
                if (moveOrNo == 1)
                {
                    p1.addToBelt("Flashlight");
                    upRight->addPlayer(p1);
                    playerVect.erase(playerVect.begin());
                    name = '_';
                }
            }
            else if (upRight->getName() == 'A')
            {
                cout << "You found some body armor! This will protect you from taking damage." << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "Grab the armor", "Don't move");
                if (moveOrNo == 1)
                {
                    cout << "You are now protected, and time has been frozen for 10 minutes." << endl;
                    p1.addToBelt("Armor");
                    upRight->addPlayer(p1);
                    playerVect.erase(playerVect.begin());
                    name = '_';
                }
            }
            else
            {
                upRight->addPlayer(p1);
                playerVect.erase(playerVect.begin());
                name = '_';
            }
        }
        else if (direction == 6 && right != NULL)
        {
            if (right->getName() == 'F' && !p1.hasCuffs())
            {
                cout << "You found the fugitive" << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "Try to capture the fugitive", "Don't move");
                if (moveOrNo == 1)
                {
                    cout << "You don't have the cuffs yet!" << endl;
                    if (!p1.hasArmor())
                    {
                        cout << "The fugitive escaped, and harmed you in the process." << endl;
                        cout << "You took 25 damage." << endl;
                        p1.setDamageTaken(25);
                    }
                    else
                    {
                        cout << "The fugitive escaped, but luckily you are carrying armor." << endl;
                        cout << "You avoided taking any damage." << endl;
                    }
                }
            }
            else if (right->getName() == 'C')
            {
                cout << "You found the handcuffs!" << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "Grab the cuffs", "Don't move");
                if (moveOrNo == 1)
                {
                    p1.addToBelt("Handcuffs");
                    right->addPlayer(p1);
                    playerVect.erase(playerVect.begin());
                    name = '_';
                }
            }
            else if (right->getName() == 'T')
            {
                cout << "Uh oh. You sprang a boobie-trap set by the fugitive." << endl;
                if (!p1.hasArmor())
                {
                    cout << "You took 35 damage." << endl;
                    p1.setDamageTaken(35);
                }
                else
                {
                    cout << "Luckily, you are carrying armor. You avoid taking any damage." << endl;
                }
                
                right->addPlayer(p1);
                playerVect.erase(playerVect.begin());
                name = '_';
            }
            else if (right->getName() == 'L')
            {
                cout << "You found the flashlight!" << endl;
                cout << "This will allow you to see the spaces nearby." << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "grab the flashlight", "Don't move");
                if (moveOrNo == 1)
                {
                    p1.addToBelt("Flashlight");
                    right->addPlayer(p1);
                    playerVect.erase(playerVect.begin());
                    name = '_';
                }
            }
            else if (right->getName() == 'A')
            {
                cout << "You found some body armor! This will protect you from taking damage." << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "Grab the armor", "Don't move");
                if (moveOrNo == 1)
                {
                    cout << "You are now protected, and time has been frozen for 10 minutes." << endl;
                    p1.addToBelt("Armor");
                    right->addPlayer(p1);
                    playerVect.erase(playerVect.begin());
                    name = '_';
                }
            }
            else
            {
                right->addPlayer(p1);
                playerVect.erase(playerVect.begin());
                name = '_';
            }
        }
        else if (direction == 3 && downRight != NULL)
        {
            if (downRight->getName() == 'F' && !p1.hasCuffs())
            {
                cout << "You found the fugitive" << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "Try to capture the fugitive", "Don't move");
                if (moveOrNo == 1)
                {
                    cout << "You don't have the cuffs yet!" << endl;
                    if (!p1.hasArmor())
                    {
                        cout << "The fugitive escaped, and harmed you in the process." << endl;
                        cout << "You took 25 damage." << endl;
                        p1.setDamageTaken(25);
                    }
                    else
                    {
                        cout << "The fugitive escaped, but luckily you are carrying armor." << endl;
                        cout << "You avoided taking any damage." << endl;
                    }
                }
            }
            else if (downRight->getName() == 'C')
            {
                cout << "You found the handcuffs!" << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "Grab the cuffs", "Don't move");
                if (moveOrNo == 1)
                {
                    p1.addToBelt("Handcuffs");
                    downRight->addPlayer(p1);
                    playerVect.erase(playerVect.begin());
                    name = '_';
                }
            }
            else if (downRight->getName() == 'T')
            {
                cout << "Uh oh. You sprang a boobie-trap set by the fugitive." << endl;
                if (!p1.hasArmor())
                {
                    cout << "You took 35 damage." << endl;
                    p1.setDamageTaken(35);
                }
                else
                {
                    cout << "Luckily, you are carrying armor. You avoid taking any damage." << endl;
                }
                
                downRight->addPlayer(p1);
                playerVect.erase(playerVect.begin());
                name = '_';
            }
            else if (downRight->getName() == 'L')
            {
                cout << "You found the flashlight!" << endl;
                cout << "This will allow you to see the spaces nearby." << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "grab the flashlight", "Don't move");
                if (moveOrNo == 1)
                {
                    p1.addToBelt("Flashlight");
                    downRight->addPlayer(p1);
                    playerVect.erase(playerVect.begin());
                    name = '_';
                }
            }
            else if (downRight->getName() == 'A')
            {
                cout << "You found some body armor! This will protect you from taking damage." << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "Grab the armor", "Don't move");
                if (moveOrNo == 1)
                {
                    cout << "You are now protected, and time has been frozen for 10 minutes." << endl;
                    p1.addToBelt("Armor");
                    downRight->addPlayer(p1);
                    playerVect.erase(playerVect.begin());
                    name = '_';
                }
            }
            else
            {
                downRight->addPlayer(p1);
                playerVect.erase(playerVect.begin());
                name = '_';
            }
        }
        else if (direction == 2 && down != NULL)
        {
            if (down->getName() == 'F' && !p1.hasCuffs())
            {
                cout << "You found the fugitive" << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "Try to capture the fugitive", "Don't move");
                if (moveOrNo == 1)
                {
                    cout << "You don't have the cuffs yet!" << endl;
                    if (!p1.hasArmor())
                    {
                        cout << "The fugitive escaped, and harmed you in the process." << endl;
                        cout << "You took 25 damage." << endl;
                        p1.setDamageTaken(25);
                    }
                    else
                    {
                        cout << "The fugitive escaped, but luckily you are carrying armor." << endl;
                        cout << "You avoided taking any damage." << endl;
                    }
                }
            }
            else if (down->getName() == 'C')
            {
                cout << "You found the handcuffs!" << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "Grab the cuffs", "Don't move");
                if (moveOrNo == 1)
                {
                    p1.addToBelt("Handcuffs");
                    down->addPlayer(p1);
                    playerVect.erase(playerVect.begin());
                    name = '_';
                }
            }
            else if (down->getName() == 'T')
            {
                cout << "Uh oh. You sprang a boobie-trap set by the fugitive." << endl;
                if (!p1.hasArmor())
                {
                    cout << "You took 35 damage." << endl;
                    p1.setDamageTaken(35);
                }
                else
                {
                    cout << "Luckily, you are carrying armor. You avoid taking any damage." << endl;
                }
                
                down->addPlayer(p1);
                playerVect.erase(playerVect.begin());
                name = '_';
            }
            else if (down->getName() == 'L')
            {
                cout << "You found the flashlight!" << endl;
                cout << "This will allow you to see the spaces nearby." << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "grab the flashlight", "Don't move");
                if (moveOrNo == 1)
                {
                    p1.addToBelt("Flashlight");
                    down->addPlayer(p1);
                    playerVect.erase(playerVect.begin());
                    name = '_';
                }
            }
            else if (down->getName() == 'A')
            {
                cout << "You found some body armor! This will protect you from taking damage." << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "Grab the armor", "Don't move");
                if (moveOrNo == 1)
                {
                    cout << "You are now protected, and time has been frozen for 10 minutes." << endl;
                    p1.addToBelt("Armor");
                    down->addPlayer(p1);
                    playerVect.erase(playerVect.begin());
                    name = '_';
                }
            }
            else
            {
                down->addPlayer(p1);
                playerVect.erase(playerVect.begin());
                name = '_';
            }
        }
        else if (direction == 1 && downLeft != NULL)
        {
            if (downLeft->getName() == 'F' && !p1.hasCuffs())
            {
                cout << "You found the fugitive" << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "Try to capture the fugitive", "Don't move");
                if (moveOrNo == 1)
                {
                    cout << "You don't have the cuffs yet!" << endl;
                    if (!p1.hasArmor())
                    {
                        cout << "The fugitive escaped, and harmed you in the process." << endl;
                        cout << "You took 25 damage." << endl;
                        p1.setDamageTaken(25);
                    }
                    else
                    {
                        cout << "The fugitive escaped, but luckily you are carrying armor." << endl;
                        cout << "You avoided taking any damage." << endl;
                    }
                }
            }
            else if (downLeft->getName() == 'C')
            {
                cout << "You found the handcuffs!" << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "Grab the cuffs", "Don't move");
                if (moveOrNo == 1)
                {
                    p1.addToBelt("Handcuffs");
                    downLeft->addPlayer(p1);
                    playerVect.erase(playerVect.begin());
                    name = '_';
                }
            }
            else if (downLeft->getName() == 'T')
            {
                cout << "Uh oh. You sprang a boobie-trap set by the fugitive." << endl;
                if (!p1.hasArmor())
                {
                    cout << "You took 35 damage." << endl;
                    p1.setDamageTaken(35);
                }
                else
                {
                    cout << "Luckily, you are carrying armor. You avoid taking any damage." << endl;
                }
                
                downLeft->addPlayer(p1);
                playerVect.erase(playerVect.begin());
                name = '_';
            }
            else if (downLeft->getName() == 'L')
            {
                cout << "You found the flashlight!" << endl;
                cout << "This will allow you to see the spaces nearby." << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "grab the flashlight", "Don't move");
                if (moveOrNo == 1)
                {
                    p1.addToBelt("Flashlight");
                    downLeft->addPlayer(p1);
                    playerVect.erase(playerVect.begin());
                    name = '_';
                }
            }
            else if (downLeft->getName() == 'A')
            {
                cout << "You found some body armor! This will protect you from taking damage." << endl;
                int moveOrNo;
                moveOrNo = choiceFunction("What would you like to do?", "Grab the armor", "Don't move");
                if (moveOrNo == 1)
                {
                    cout << "You are now protected, and time has been frozen for 10 minutes." << endl;
                    p1.addToBelt("Armor");
                    downLeft->addPlayer(p1);
                    playerVect.erase(playerVect.begin());
                    name = '_';
                }
            }
            else
            {
                downLeft->addPlayer(p1);
                playerVect.erase(playerVect.begin());
                name = '_';
            }
        }
        else
        {
            cout << "Uh oh, you ran into a wall. Be careful, Officer!" << endl;
        }
        return p1;
    }
}


/***************************************
 EmptySpace::moveFugitive()
 **************************************/
void EmptySpace::moveFugitive()
{
    //choose random direction
    int direction;
    direction = minMaxRand(1,8);
    
    //if space is not NULL or occupied by Player or object
    if (direction == 1 && left != NULL && left->getName() != 'P' && left->getName() != 'C' && left->getName() != 'L' && left->getName() != 'A' && left->getName() != 'T')
    {
        //rename current space to blank
        name = '_';
        //move fugitive
        left->setName('F');
    }
    else if (direction == 2 && upLeft != NULL && upLeft->getName() != 'P' && upLeft->getName() != 'C' && upLeft->getName() != 'L' && upLeft->getName() != 'A' && upLeft->getName() != 'T')
    {
        name = '_';
        upLeft->setName('F');
    }
    else if (direction == 3 && up != NULL && up->getName() != 'P' && up->getName() != 'C' && up->getName() != 'L' && up->getName() != 'A' && up->getName() != 'T')
    {
        name = '_';
        up->setName('F');
    }
    else if (direction == 4 && upRight != NULL && upRight->getName() != 'P' && upRight->getName() != 'C' && upRight->getName() != 'L' && upRight->getName() != 'A' && upRight->getName() != 'T')
    {
        name = '_';
        upRight->setName('F');
    }
    else if (direction == 5 && right != NULL && right->getName() != 'P' && right->getName() != 'C' && right->getName() != 'L' && right->getName() != 'A' && right->getName() != 'T')
    {
        name = '_';
        right->setName('F');
    }
    else if (direction == 6 && downRight != NULL && downRight->getName() != 'P' && downRight->getName() != 'C' && downRight->getName() != 'L' && downRight->getName() != 'A' && downRight->getName() != 'T')
    {
        name = '_';
        downRight->setName('F');
    }
    else if (direction == 7 && down != NULL && down->getName() != 'P' && down->getName() != 'C' && down->getName() != 'L' && down->getName() != 'A' && down->getName() != 'T')
    {
        name = '_';
        down->setName('F');
    }
    else if (direction == 8 && downLeft != NULL && downLeft->getName() != 'P' && downLeft->getName() != 'C' && downLeft->getName() != 'L' && downLeft->getName() != 'A' && downLeft->getName() != 'T')
    {
        name = '_';
        downLeft->setName('F');
    }
}

/***************************************
 EmptySpace::getSpaceNum
 **************************************/
int EmptySpace::getSpaceNum()
{
    return spaceNum;
}


EmptySpace::~EmptySpace()
{
	playerVect.clear();
}


