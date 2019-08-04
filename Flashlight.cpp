/***************************************
 
 Name: Jake Seawell
 Date: 11/20/18
 Description:
 This is the class implementation
 file for a class called Flashlight.
 The Flashlight class inherits from Space,
 and represents a flashlight on a
 game board in a game called Fugitive.
 
 For function comments: see function comments
 in "EmptySpace.cpp"
 
 **************************************/

#include "Flashlight.hpp"
#include "Space.hpp"
#include "intVal.hpp"
#include "choiceFunction.hpp"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

/***************************************
 Flashlight::Flashlight()
 **************************************/
Flashlight::Flashlight(int r, int c, int num, Space*** board) : Space(r, c, board)
{
    //empty space
    name = 'L';
    
    //set space number
    spaceNum = num;
}

/***************************************
  Flashlight::addPlayer()
 **************************************/
void Flashlight::addPlayer(Player &p1)
{
        playerVect.push_back(p1);
        name = 'P';
}


/***************************************
 Flashlight::movePlayer()
 **************************************/
Player Flashlight::movePlayer(Player &p1)
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
 Flashlight::getSpaceNum
 **************************************/
int Flashlight::getSpaceNum()
{
    return spaceNum;
}





