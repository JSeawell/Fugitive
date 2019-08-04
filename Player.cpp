/***************************************
 
 Name: Jake Seawell
 Date: 11/20/18
 Description:
 This is the class implementation
 file for a class called Player. The
 Player class represents a Player in
 a Fugitive game, and contains a string name,
 a damage integer, and a vector of
 strings called belt.
 
 **************************************/

#include "Player.hpp"

#include "intVal.hpp"

#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

/***************************************
 Constructor
 **************************************/
Player::Player()
{
    name = 'P';
	damageTaken = 0;
}

/***************************************
 Player::getName
 **************************************/
char Player::getName()
{
    return name;
}

/***************************************
 Player::getDamageTaken
 **************************************/
int Player::getDamageTaken()
{
	return damageTaken;
}

/***************************************
 Player::setDamageTaken
 **************************************/
void Player::setDamageTaken(int d)
{
    damageTaken += d;
}


/***************************************
 Player::setName
 **************************************/
void Player::setName(char c)
{
    name = c;
}


/***************************************
 Player::hasCuffs
 
 This function returns true if the player
 has the handcuffs on their belt
 
 **************************************/
bool Player::hasCuffs()
{
	if (!belt.empty())
	{
		if (belt.size() == 1)
		{
			if (belt[0] == "Handcuffs")
				return true;
		}
		else if (belt.size() == 2)
		{
			if (belt[0] == "Handcuffs" || belt[1] == "Handcuffs")
				return true;
		}
		else
			return false;
	}
	else
		return false;
}


/***************************************
 Player::hasLight
 
 This function returns true if the player
 has the flashlight on their belt
 
 **************************************/
bool Player::hasLight()
{
	if (!belt.empty())
	{
		if (belt.size() == 1)
		{
			if (belt[0] == "Flashlight")
			{	
				return true;
			}
	
		}
		else if (belt.size() == 2)
		{
			if (belt[0] == "Flashlight" || belt[1] == "Flashlight")
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}


/***************************************
 Player::hasArmor
 
 This function returns true if the player
 has the armor on their belt
 
 **************************************/
bool Player::hasArmor()
{
	if (!belt.empty())
	{
		if (belt.size() == 1)
		{
			if (belt[0] == "Armor")
			{	
				return true;
			}
	
		}
		else if (belt.size() == 2)
		{
			if (belt[0] == "Armor" || belt[1] == "Armor")
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}



/***************************************
 Player::addToBelt
 
 add item to players belt
 
 **************************************/
void Player::addToBelt(string s)
{
    //belt full
    if (belt.size() == 2)
    {
        cout << "Utility belt full." << endl;
        cout << endl << "Would you like to replace an item on your belt?" << endl;
        cout << endl << "WARNING: If you choose not to, this item will no longer be attainable." << endl << endl;
        cout << "If this item is the 'Handcuffs', you will have no way to capture the fugitive and win." << endl;
        cout << endl << "WARNING: Any item you choose to drop will also no longer be attainable." << endl << endl;
        cout << "1: Yes, replace an item" << endl << "2: No, keep both items on my belt" << endl;
        int yesOrNo;
        yesOrNo = minMaxValidation(integerValidation(),1,2);
        if (yesOrNo == 1)
        {
            takeFromBelt();
            belt.push_back(s);
        }
        else
        {
            cout << "No item added or removed." << endl;
            if (s == "Handcuffs")
            {
		cout << "You have no way to capture the fugitive. There is no way for you to win the game." << endl;
		damageTaken = 300;
	    }
    	}
    }
    //not full yet
    else
    	belt.push_back(s);
}

/***************************************
 Player::displayBelt
 **************************************/
void Player::displayBelt()
{
    cout << endl;
    if (belt.empty())
    {
	cout << "Player's belt is empty." << endl;
    }
    else
    {
    	cout << "Player's belt: {";
    	for (int i = 0; i < belt.size(); i++)
    	{
        	cout << belt[i];
		if (i < (belt.size() - 1))
			cout << ", ";
    	}
    	cout << "}" << endl << endl;
    }
}


/***************************************
 Player::getBelt
 **************************************/
vector <string> Player::getBelt()
{
	return belt;
}


/***************************************
 Player::takeFromBelt
 **************************************/
string Player::takeFromBelt()
{
    string temp;
    if (belt.empty())
    {
        cout << "Player's belt is empty" << endl;
        return "Empty";
    }
    else if (belt.size() == 1)
    {
        temp = belt[0];
        belt.erase(belt.begin());
        cout << "Player removed the only item: " << temp << endl;
        displayBelt();
        return temp;
    }
    else
    {
    	int userWants;
    	displayBelt();
    	cout << "What item would you like to remove?" << endl;
    	cout << "For the first item, enter 1." << endl << "For the second, enter 2." << endl;
        cout << endl << "WARNING: If you currently have, and choose to remove the handcuffs, you will lose them," << endl;
        cout << "and cannot possibly capture the fugitive to win the game." << endl << endl;
    	userWants = minMaxValidation(integerValidation(), 1,2);
    	temp = belt[userWants - 1];
    	belt.erase(belt.begin() + (userWants - 1));
    	cout << "Player removed: " << temp << endl;
        if (temp == "Handcuffs")
	{
            cout << "You can no longer capture the fugitive. There is no way to win the game." << endl;
	    damageTaken =  300;
        }
    	return temp;
    } 
}
