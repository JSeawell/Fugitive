/***************************************
 
 Name: Jake Seawell
 Date: 11/20/18
 Description:
 This is the class implementation
 file for a class called Handcuffs.
 The Handcuffs class inherits from Space,
 and represents handcuffs on a
 game board in a game called Fugitive.
 
 **************************************/

#ifndef Handcuffs_hpp
#define Handcuffs_hpp

#include "Space.hpp"


class Handcuffs : public Space
{

protected:
   
    //holds player
    vector <Player> playerVect;
    
    //set space number
    int spaceNum;
    
public:
    
    //constructor
    Handcuffs(int r, int c, int num, Space*** board);

    //member functions:
    void addPlayer(Player &p1);
    Player movePlayer(Player &p1);
    int getSpaceNum();
};
#endif
