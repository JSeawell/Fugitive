/***************************************
 
 Name: Jake Seawell
 Date: 11/20/18
 Description:
 This is the class implementation
 file for a class called Space. The
 Space class represents spaces on a
 game board, and contains a pointer
 to its current occupant, as well as
 pointers to all its adjacent spaces.
 
 **************************************/

#include "Space.hpp"

/***************************************
 Space::Space()
 **************************************/
Space::Space(int r, int c, Space*** board) : row(r), column(c)
{
    name = 'S';
    
    //initialize all pointers to NULL
    up = NULL;
    upRight = NULL;
    right = NULL;
    downRight = NULL;
    down = NULL;
    downLeft = NULL;
    left = NULL;
    upLeft = NULL;
}



/***************************************
 Space::addPlayer()
 **************************************/
void Space::addPlayer(Player &p1)
{
    
}

/***************************************
 Space::movePlayer()
 **************************************/
Player Space::movePlayer(Player &p1)
{

}

/***************************************
 Space::moveFugitive()
 **************************************/
void Space::moveFugitive()
{

}


              //GETTERS:

/***************************************
 EmptySpace::getSpaceNum
 **************************************/
int Space::getSpaceNum()
{
    return spaceNum;
}


/***************************************
 Space::getName
 **************************************/
char Space::getName()
{
    return name;
}

/***************************************
 Space::getUp
 **************************************/
Space* Space::getUp()
{
    return up;
}

/***************************************
 Space::getUpRight
 **************************************/
Space* Space::getUpRight()
{
    return upRight;
}

/***************************************
 Space::getRight
 **************************************/
Space* Space::getRight()
{
    return right;
}

/***************************************
 Space::getDownRight
 **************************************/
Space* Space::getDownRight()
{
    return downRight;
}

/***************************************
 Space::getDown
 **************************************/
Space* Space::getDown()
{
    return down;
}

/***************************************
 Space::getDownLeft
 **************************************/
Space* Space::getDownLeft()
{
    return downLeft;
}

/***************************************
 Space::getLeft
 **************************************/
Space* Space::getLeft()
{
    return left;
}

/***************************************
 Space::getUpLeft
 **************************************/
Space* Space::getUpLeft()
{
    return upLeft;
}

/***************************************
 Space::getRow
 **************************************/
int Space::getRow()
{
    return row;
}

/***************************************
 Space::getColumn
 **************************************/
int Space::getColumn()
{
    return column;
}







             //SETTERS:

/***************************************
 Space::setName
 **************************************/
void Space::setName(char c)
{
    name = c;
}

/***************************************
 Space::setUp
 **************************************/
void Space::setUp(int r, int c, Space*** board)
{
    up = board[r - 1][c];
}

/***************************************
 Space::setUpRight
 **************************************/
void Space::setUpRight(int r, int c, Space*** board)
{
    upRight = board[r - 1][c + 1];
}

/***************************************
 Space::setRight
 **************************************/
void Space::setRight(int r, int c, Space*** board)
{
    right = board[r][c + 1];
}

/***************************************
 Space::setDownRight
 **************************************/
void Space::setDownRight(int r, int c, Space*** board)
{
    downRight = board[r + 1][c + 1];
}

/***************************************
 Space::setDown
 **************************************/
void Space::setDown(int r, int c, Space*** board)
{
    down = board[r + 1][c];
}

/***************************************
 Space::setDownLeft
 **************************************/
void Space::setDownLeft(int r, int c, Space*** board)
{
    downLeft = board[r + 1][c - 1];
}

/***************************************
 Space::setLeft
 **************************************/
void Space::setLeft(int r, int c, Space*** board)
{
    left = board[r][c - 1];
}

/***************************************
 Space::setUpLeft
 **************************************/
void Space::setUpLeft(int r, int c, Space*** board)
{
    upLeft = board[r - 1][c - 1];
}


