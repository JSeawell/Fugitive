/***************************************
 
 Name: Jake Seawell
 Date: 11/20/18
 Description:
 This is the header/class specification
 file for a class called Player. The
 Player class represents a player in a
 Fugitive game, and contains a string name,
 a damage integer, and a vector of
 strings called belt.
 
 **************************************/
#ifndef Player_hpp
#define Player_hpp

#include <vector>
#include <string>
using std::vector;
using std::string;

class Player
{

protected:
    
    //member variables
    char name;
	int damageTaken;
    vector <string> belt;

public:
    
    //constructor
    Player();
    
    //member functions:
    
    //getters/setters
    char getName();
    int getDamageTaken();
    void setName(char c);
    void setDamageTaken(int d);
   
    //check belt functions
    bool hasLight();
    bool hasCuffs();
    bool hasArmor();
 
    //other functions
    void addToBelt(string s);
    void displayBelt();
    vector <string> getBelt();
    string takeFromBelt();
};

#endif
