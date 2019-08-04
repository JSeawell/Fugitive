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

#ifndef EmptySpace_hpp
#define EmptySpace_hpp

//files needed
#include "Player.hpp"

//inherits from:
#include "Space.hpp"

//libraries needed
#include <string>
#include <vector>
using std::string;
using std::vector;

class EmptySpace : public Space
{

protected:
   
    //holds player
	vector <Player> playerVect; 
    
    //set space number
    int spaceNum;
    
public:
    
    //constructor
    EmptySpace(int r, int c, int num, Space*** board);

	~EmptySpace();

    //member functions:
    void addPlayer(Player &p1);
    Player movePlayer(Player &p1);
    void moveFugitive();
    int getSpaceNum();
    
    
};
#endif
