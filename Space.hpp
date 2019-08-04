/***************************************
 
 Name: Jake Seawell
 Date: 11/20/18
 Description:
 This is the header/class specification
 file for a class called Space. The
 Space class represents spaces on a
 game board, and contains a pointer
 to its current occupant, as well as
 pointers to all its adjacent spaces.
 
 **************************************/

#ifndef Space_hpp
#define Space_hpp

#include "Player.hpp"

#include <string>
#include <vector>
using std::string;
using std::vector;

class Space
{

protected:
    
    //member variables
    char name;
    
    //pointers to every direction
    Space* up;
    Space* upRight;
    Space* right;
    Space* downRight;
    Space* down;
    Space* downLeft;
    Space* left;
    Space* upLeft;

    //board location
    int row;
    int column;
    
    //space number
    int spaceNum;

public:

    //constructor
    Space(int r, int c, Space*** board);

    //member functions:
    
    //currently blank
    virtual void addPlayer(Player &p1);
    virtual Player movePlayer(Player &p1);
    virtual void moveFugitive();

    //getters
    virtual char getName();
    
    virtual int getSpaceNum();
    
    virtual Space* getUp();
    virtual Space* getUpRight();
    virtual Space* getRight();
    virtual Space* getDownRight();
    virtual Space* getDown();
    virtual Space* getDownLeft();
    virtual Space* getLeft();
    virtual Space* getUpLeft();
    
    virtual int getRow();
    virtual int getColumn();
    
    //setters
    virtual void setName(char c);
    virtual void setUp(int r, int c, Space*** board);
    virtual void setUpRight(int r, int c, Space*** board);
    virtual void setRight(int r, int c, Space*** board);
    virtual void setDownRight(int r, int c, Space*** board);
    virtual void setDown(int r, int c, Space*** board);
    virtual void setDownLeft(int r, int c, Space*** board);
    virtual void setLeft(int r, int c, Space*** board);
    virtual void setUpLeft(int r, int c, Space*** board);
    
    
};
#endif
