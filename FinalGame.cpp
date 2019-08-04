/***************************************
 
 Name: Jake Seawell
 Date: 11/20/18
 Description:
 This is the header/class specification
 file for a class called FinalGame. The
 FinalGame class represents a game of
 Fugitive, where you are a cop looking
 for an escaped fugitive.
 
 **************************************/

//files needed
#include "FinalGame.hpp"
#include "Space.hpp"
#include "EmptySpace.hpp"
#include "Handcuffs.hpp"
#include "Flashlight.hpp"
#include "Trap.hpp"
#include "Armor.hpp"
#include "intVal.hpp"
#include "choiceFunction.hpp"

//libraries needed
#include <iostream>

using std::cin;
using std::cout;
using std::endl;


/***************************************
 FinalGame::FinalGame()
 **************************************/
FinalGame::FinalGame()
{
    //initialize rows, cols, difficulty
    rows = 10;
    cols = 10;
    difficulty = 0;
    
    //create board and fill with empty spaces
    int num = 1;
    board = new Space**[rows];
    for (int i = 0; i < rows; i++)
    {
        board[i] = new Space*[cols];
        for (int j = 0; j < cols; j++)
        {
            board[i][j] = new EmptySpace(i, j, num, board);
            num++;
        }
    }
    
}


/***************************************
 FinalGame::placePlayer()
 **************************************/
void FinalGame::placePlayer(Player p1)
{
    int playerRow = 0;
    int playerCol = 0;
    cout << "The search area consists of a 10x10 grid of possible hiding spaces." << endl;
    cout << "Where on the map would you like to start your search?" << endl;
    cout << "( Row:1, Column:1 represents the top left corner of the map )" << endl << endl;
    cout << "Row: " << endl;
    playerRow = minMaxValidation(integerValidation(),1,10);
    cout << "Column:" << endl;
    playerCol = minMaxValidation(integerValidation(), 1, 10);
    
    //add player to randomly chosen space on board
    board[playerRow - 1][playerCol - 1]->addPlayer(p1);
    
}


/***************************************
 FinalGame::placeFugitive()
 **************************************/
void FinalGame::placeFugitive()
{
    int fugRow = 0;
    int fugCol = 0;
    
    fugRow = minMaxRand(0, (rows - 1));
    fugCol = minMaxRand(0, (cols - 1));

    while (board[fugRow][fugCol]->getName() == 'P')
    {
    	fugRow = minMaxRand(0, (rows - 1));
    	fugCol = minMaxRand(0, (cols - 1));
    }   

    //add fugitive to random space on board
    board[fugRow][fugCol]->setName('F');
    
}


/***************************************
 FinalGame::addCuffs()
 **************************************/
void FinalGame::addCuffs()
{
    //find random row and col
    int cuffRow = 0;
    int cuffCol = 0;
    
    cuffRow = minMaxRand(0, (rows - 1));
    cuffCol = minMaxRand(0, (cols - 1));
   
     while (board[cuffRow][cuffCol]->getName() == 'P' || board[cuffRow][cuffCol]->getName() == 'F')
    {
    	cuffRow = minMaxRand(0, (rows - 1));
    	cuffCol = minMaxRand(0, (cols - 1));
    } 
 
    int numTemp;
	numTemp = board[cuffRow][cuffCol]->getSpaceNum();
    //delete empty space
    delete board[cuffRow][cuffCol];
    //add handcuff space
    board[cuffRow][cuffCol] = new Handcuffs(cuffRow, cuffCol, numTemp, board);
    
}


/***************************************
 FinalGame::addLight()
 **************************************/
void FinalGame::addLight()
{
    //find random row, col
    int lightRow = 0;
    int lightCol = 0;
    
    lightRow = minMaxRand(0, (rows - 1));
    lightCol = minMaxRand(0, (cols - 1));
    
    while (board[lightRow][lightCol]->getName() == 'P' || board[lightRow][lightCol]->getName() == 'F' || board[lightRow][lightCol]->getName() == 'C')
    {
        lightRow = minMaxRand(0, (rows - 1));
        lightCol = minMaxRand(0, (cols - 1));
    }
    
    int numTemp;
    numTemp = board[lightRow][lightCol]->getSpaceNum();
    //delete empty space
    delete board[lightRow][lightCol];
    //add light space to board
    board[lightRow][lightCol] = new Flashlight(lightRow, lightCol, numTemp, board);
   
    // Light #2
    // same as above
    if (difficulty == 3)
    {
    	int light2Row = minMaxRand(0, (rows - 1));
    	int light2Col = minMaxRand(0, (cols - 1));
    
    	while (board[light2Row][light2Col]->getName() == 'P' || board[light2Row][light2Col]->getName() == 'F' || board[light2Row][light2Col]->getName() == 'C' || board[light2Row][light2Col]->getName() == 'L')
    	{
        	light2Row = minMaxRand(0, (rows - 1));
        	light2Col = minMaxRand(0, (cols - 1));
    	}
    
    	numTemp;
    	numTemp = board[light2Row][light2Col]->getSpaceNum();
    	delete board[light2Row][light2Col];
   	 board[light2Row][light2Col] = new Flashlight(light2Row, light2Col, numTemp, board);
    }

 
}


/***************************************
 FinalGame::addTraps : adds 5 traps to map
 **************************************/
void FinalGame::addTraps()
{
    
    //Trap #1
    //find random row, col
    int trap1Row = 0;
    int trap1Col = 0;
    
    trap1Row = minMaxRand(0, (rows - 1));
    trap1Col = minMaxRand(0, (cols - 1));
    
    while (board[trap1Row][trap1Col]->getName() == 'P' || board[trap1Row][trap1Col]->getName() == 'F' || board[trap1Row][trap1Col]->getName() == 'C' || board[trap1Row][trap1Col]->getName() == 'L' || board[trap1Row][trap1Col]->getName() == 'T')
    {
        trap1Row = minMaxRand(0, (rows - 1));
        trap1Col = minMaxRand(0, (cols - 1));
    }
    
    int numTemp;
    numTemp = board[trap1Row][trap1Col]->getSpaceNum();
    //delete empty space
    delete board[trap1Row][trap1Col];
    //add trap space
    board[trap1Row][trap1Col] = new Trap(trap1Row, trap1Col, numTemp, board);
    
    //Trap #2
    //same as above
    int trap2Row = 0;
    int trap2Col = 0;
    
    trap2Row = minMaxRand(0, (rows - 1));
    trap2Col = minMaxRand(0, (cols - 1));
    
    while (board[trap2Row][trap2Col]->getName() == 'P' || board[trap2Row][trap2Col]->getName() == 'F' || board[trap2Row][trap2Col]->getName() == 'C' || board[trap2Row][trap2Col]->getName() == 'L' || board[trap2Row][trap2Col]->getName() == 'T')
    {
        trap2Row = minMaxRand(0, (rows - 1));
        trap2Col = minMaxRand(0, (cols - 1));
    }
    
    numTemp = board[trap2Row][trap2Col]->getSpaceNum();
    delete board[trap2Row][trap2Col];
    board[trap2Row][trap2Col] = new Trap(trap2Row, trap2Col, numTemp, board);
    
    //Trap #3
    //same as above
    int trap3Row = 0;
    int trap3Col = 0;
    
    trap3Row = minMaxRand(0, (rows - 1));
    trap3Col = minMaxRand(0, (cols - 1));
    
    while (board[trap3Row][trap3Col]->getName() == 'P' || board[trap3Row][trap3Col]->getName() == 'F' || board[trap3Row][trap3Col]->getName() == 'C' || board[trap3Row][trap3Col]->getName() == 'L' || board[trap3Row][trap3Col]->getName() == 'T')
    {
        trap3Row = minMaxRand(0, (rows - 1));
        trap3Col = minMaxRand(0, (cols - 1));
    }
    
    numTemp = board[trap3Row][trap3Col]->getSpaceNum();
    delete board[trap3Row][trap3Col];
    board[trap3Row][trap3Col] = new Trap(trap3Row, trap3Col, numTemp, board);
    
    //Trap #4
    //same as above
    int trap4Row = 0;
    int trap4Col = 0;
    
    trap4Row = minMaxRand(0, (rows - 1));
    trap4Col = minMaxRand(0, (cols - 1));
    
    while (board[trap4Row][trap4Col]->getName() == 'P' || board[trap4Row][trap4Col]->getName() == 'F' || board[trap4Row][trap4Col]->getName() == 'C' || board[trap4Row][trap4Col]->getName() == 'L' || board[trap4Row][trap4Col]->getName() == 'T')
    {
        trap4Row = minMaxRand(0, (rows - 1));
        trap4Col = minMaxRand(0, (cols - 1));
    }
    
    numTemp = board[trap4Row][trap4Col]->getSpaceNum();
    delete board[trap4Row][trap4Col];
    board[trap4Row][trap4Col] = new Trap(trap4Row, trap4Col, numTemp, board);



    //Trap #5
    //same as above
    if (difficulty == 3)
    {
	int trap5Row = 0;
    	int trap5Col = 0;

    	trap5Row = minMaxRand(0, (rows - 1));
    	trap5Col = minMaxRand(0, (cols - 1));

    	while (board[trap5Row][trap5Col]->getName() == 'P' || board[trap5Row][trap5Col]->getName() == 'F' || board[trap5Row][trap5Col]->getName() == 'C' || board[trap5Row][trap5Col]->getName() == 'L' || board[trap5Row][trap5Col]->getName() == 'T')
    	{
        	trap5Row = minMaxRand(0, (rows - 1));
        	trap5Col = minMaxRand(0, (cols - 1));
    	}

    	numTemp = board[trap5Row][trap5Col]->getSpaceNum();
    	delete board[trap5Row][trap5Col];
    	board[trap5Row][trap5Col] = new Trap(trap5Row, trap5Col, numTemp, board);
    }
}


/***************************************
 FinalGame::addArmor()
 **************************************/
void FinalGame::addArmor()
{
    //find random row, col
    int armRow = 0;
    int armCol = 0;
    
    armRow = minMaxRand(0, (rows - 1));
    armCol = minMaxRand(0, (cols - 1));
    
    while (board[armRow][armCol]->getName() == 'P' || board[armRow][armCol]->getName() == 'F' || board[armRow][armCol]->getName() == 'C' || board[armRow][armCol]->getName() == 'L' || board[armRow][armCol]->getName() == 'T')
    {
        armRow = minMaxRand(0, (rows - 1));
        armCol = minMaxRand(0, (cols - 1));
    }
    
    int numTemp;
    numTemp = board[armRow][armCol]->getSpaceNum();
    //delete empty space
    delete board[armRow][armCol];
    //add armor space
    board[armRow][armCol] = new Armor(armRow, armCol, numTemp, board);
}


/***************************************
 FinalGame::linkSpaces()
 
 This functions linkes all of the spaces
 on the board to point to the adjacent
 spaces around them.
 
 **************************************/
void FinalGame::linkSpaces()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i > 0 && i < (rows - 1) && j > 0 && j < (cols - 1))
            {
                //set normally
                board[i][j]->setUp(i, j, board);
                board[i][j]->setUpRight(i, j, board);
                board[i][j]->setRight(i, j, board);
                board[i][j]->setDownRight(i, j, board);
                board[i][j]->setDown(i, j, board);
                board[i][j]->setDownLeft(i, j, board);
                board[i][j]->setLeft(i, j, board);
                board[i][j]->setUpLeft(i, j, board);
            }
            else if (i == 0 && j > 0 && j < (cols - 1))
            {
                //nothing up, all else normal
                board[i][j]->setRight(i, j, board);
                board[i][j]->setDownRight(i, j, board);
                board[i][j]->setDown(i, j, board);
                board[i][j]->setDownLeft(i, j, board);
                board[i][j]->setLeft(i, j, board);
            }
            else if (i == (rows - 1) && j > 0 && j < (cols - 1))
            {
                //nothing down, all else normal
                board[i][j]->setUp(i, j, board);
                board[i][j]->setUpRight(i, j, board);
                board[i][j]->setRight(i, j, board);
                board[i][j]->setLeft(i, j, board);
                board[i][j]->setUpLeft(i, j, board);
            }
            else if (j == 0 && i > 0 && i < (rows - 1))
            {
                //nothing left, all else normal
                board[i][j]->setUp(i, j, board);
                board[i][j]->setUpRight(i, j, board);
                board[i][j]->setRight(i, j, board);
                board[i][j]->setDownRight(i, j, board);
                board[i][j]->setDown(i, j, board);
            }
            else if (j == (cols - 1) && i > 0 && i < (rows - 1))
            {
                //nothing right, all else normal
                board[i][j]->setUp(i, j, board);
                board[i][j]->setDown(i, j, board);
                board[i][j]->setDownLeft(i, j, board);
                board[i][j]->setLeft(i, j, board);
                board[i][j]->setUpLeft(i, j, board);
            }
            else if (i == 0 && j == 0)
            {
                //only down, right, and downRight
                board[i][j]->setRight(i, j, board);
                board[i][j]->setDownRight(i, j, board);
                board[i][j]->setDown(i, j, board);
            }
            else if (i == 0 && j == (cols - 1))
            {
                //only down, left, and downLeft
                board[i][j]->setDown(i, j, board);
                board[i][j]->setDownLeft(i, j, board);
                board[i][j]->setLeft(i, j, board);
            }
            else if (i == (rows - 1) && j == 0)
            {
                //only up, right, and upRight
                board[i][j]->setUp(i, j, board);
                board[i][j]->setUpRight(i, j, board);
                board[i][j]->setRight(i, j, board);
            }
            else if (i == (rows - 1) && j == (cols - 1))
            {
                //only up, left, and upLeft
                board[i][j]->setUp(i, j, board);
                board[i][j]->setLeft(i, j, board);
                board[i][j]->setUpLeft(i, j, board);
            }
        }
    }
}


/***************************************
 FinalGame::printBoard()
 
 this function prints the board and all
 spaces (names)
 
 **************************************/
void FinalGame::printBoard()
{
    	cout << endl;
        cout << " __________________________________________________" << endl;
	for (int i = 0; i < rows; i++)
    	{
        	cout << "|";
		for (int j = 0; j < cols; j++)
        	{
            		cout << "  " << board[i][j]->getName() << "  ";
        	}
        	cout << "|" << endl;
		if (i < (rows - 1))
			cout << "|                                                  " << "|" << endl;
    	}
	cout << " --------------------------------------------------" << endl;

}


/***************************************
 FinalGame::printHiddenBoard()
 
 this function prints a version of the
 board with all names hidden except
 the player (P)
 
 **************************************/
void FinalGame::printHiddenBoard()
{
    cout << endl;
    cout << " __________________________________________________" << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "|";
	for (int j = 0; j < cols; j++)
        {
            if (board[i][j]->getName() == 'P')
                cout << "  " << board[i][j]->getName() << "  ";
            else
                cout << "  " << " " << "  ";
        }
	cout << "|" << endl;
		if (i < (rows - 1))
			cout << "|                                                  " << "|" << endl; 
    }
    cout << " --------------------------------------------------" << endl;
}



/***************************************
 FinalGame::printChosenBoard()
 
 this function prints a version of the
 board with all names hidden except
 the player (P) and chosen object
 
 **************************************/
void FinalGame::printChosenBoard(char chosen)
{
    cout << endl;
    cout << " __________________________________________________" << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "|";
	for (int j = 0; j < cols; j++)
        {
            if (board[i][j]->getName() == 'P' || board[i][j]->getName() == chosen)
                cout << "  " << board[i][j]->getName() << "  ";
            else
                cout << "  " << " " << "  ";
        }
	cout << "|" << endl;
		if (i < (rows - 1))
			cout << "|                                                  " << "|" << endl; 
    }
    cout << " --------------------------------------------------" << endl;
}







/***************************************
 FinalGame::printFlashBoard()
 
 this function prints a version of the
 board showing all of the spaces (names)
 adjacent to the player. This is activated
 by the flashlight
 
 **************************************/
void FinalGame::printFlashBoard()
{
    cout << endl;
    cout << " __________________________________________________" << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "|";
	for (int j = 0; j < cols; j++)
        {
            if ((board[i][j]->getName() == 'P' && i == 0 && j == 0) || (board[i][j]->getName() == 'P' && i == 0 && j == (cols - 1)) || (board[i][j]->getName() == 'P' && i == (rows - 1) && j == 0) || (board[i][j]->getName() == 'P' && i == (rows - 1) && j == (cols - 1)) || (board[i][j]->getName() == 'P' && i == 0) || (board[i][j]->getName() == 'P' && i == (rows - 1)) || (board[i][j]->getName() == 'P' && j == 0) || (board[i][j]->getName() == 'P' && j == (cols - 1)))
                cout << "  " << board[i][j]->getName() << "  ";
            else if (board[i][j]->getName() == 'P')
                cout << "  " << board[i][j]->getName() << "  ";
            else if (board[i][j]->getLeft() != NULL && board[i][j]->getLeft()->getName() == 'P' || board[i][j]->getUpLeft() != NULL && board[i][j]->getUpLeft()->getName() == 'P' || board[i][j]->getUp() != NULL && board[i][j]->getUp()->getName() == 'P' || board[i][j]->getUpRight() != NULL && board[i][j]->getUpRight()->getName() == 'P' || board[i][j]->getRight() != NULL && board[i][j]->getRight()->getName() == 'P' || board[i][j]->getDownRight() != NULL && board[i][j]->getDownRight()->getName() == 'P' || board[i][j]->getDown() != NULL && board[i][j]->getDown()->getName() == 'P' || board[i][j]->getDownLeft() != NULL && board[i][j]->getDownLeft()->getName() == 'P')
                cout << "  " << board[i][j]->getName() << "  ";
            else
                cout << "  " << " " << "  ";
        }
        cout << "|" << endl;
		if (i < (rows - 1))
			cout << "|                                                  " << "|" << endl; 
    }
    cout << " --------------------------------------------------" << endl;
}


/***************************************
 FinalGame::playGame()
 **************************************/
void FinalGame::playGame()
{
    cout << endl << "Press enter to continue." << endl;
    cin.ignore();
	cout << "\033[2J";
    
    cout << "Choose your game difficulty:" << endl;
    cout << "1: Easy" << endl << "2: Moderate" << endl << "3: Challenging" << endl;
	difficulty = minMaxValidation(integerValidation(), 1,3);

    //show user what board looks like
    printBoard();
    
    //create/place player on board
    Player p1;
    placePlayer(p1);
    
    //place fugitive on board
    placeFugitive();
    
    //add handcuffs to board
    addCuffs();
    
    //add light(s) to board
    if (difficulty > 1)
	addLight();
    
    //add 5 traps to board
    addTraps();
    addArmor();
    
    //link all spaces to adjacent spaces
    linkSpaces();
   
    //show user initial board
    if (difficulty < 3)
    {	
	printBoard();
    }
    else
    {
    	int choice = 0;
	cout << endl << endl << "You can choose to see the starting location of one object before you start moving." << endl;
	cout << "What object would you like to see the location of?" << endl;
	cout << "1: Flashlights (L)" << endl << "2: Handcuffs (C)" << endl << "3: Fugitive (F)" << endl << "4: Traps (T)" << endl << "5: Body-armor (A)" << endl; 
	choice = minMaxValidation(integerValidation(),1,5);
	if (choice == 1)
		printChosenBoard('L');
	else if (choice == 2)
		printChosenBoard('C');
	else if (choice == 3)
		printChosenBoard('F');
	else if (choice == 4)
		printChosenBoard('T');
	else if (choice == 5)
		printChosenBoard('A');
    }
	cout << endl;



    if (difficulty > 1)
    {
	cout << "Look carefully, you're about to lose all visibility," << endl;
	cout << "until you can find the flashlight!" << endl;
    }


    //health
    int health;
    health = 100;

    //time limit = 50 mins	
    int mins;
    int extraTime = 10;
    mins = (rows * cols / 2);
    
    //track if fugitive is found
    bool fugFound = false;   

    //loops until time or health ends, or fugitive is found
    while (mins > 0 && health > 0 && fugFound == false) //for each game step
    {

	//show players belt
        cout << endl;
        p1.displayBelt();

        //show health/time remaining
        cout << "Health remaining: " << health << "%" << endl;
        cout << "Minutes remaining: " << mins << endl << endl;
     
        bool flag = false;
        for (int i = 0; i < rows; i++)
    	{
        	for (int j = 0; j < cols; j++)
        	{
			if (board[i][j]->getName() == 'P')
			{			
				//move player on board
                board[i][j]->movePlayer(p1);
                //after moving, break from whole loop so as not to move multiple times
				flag = true;
			}
			if (flag == true)
				break;
		}
		if (flag == true)
			break;
    	}	
    
        flag = false;
    
    	fugFound = true;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (board[i][j]->getName() == 'F')
                {
                    //move player on board
                    board[i][j]->moveFugitive();
                    //after moving, break from whole loop so as not to move multiple times
                    fugFound = false;
                    flag = true;
                }
                if (flag == true)
                    break;
            }
            if (flag == true)
                break;
        }

        //show board after player moves
        if (p1.hasLight())
            printFlashBoard();
        else
        {
            if (difficulty == 1)
                printBoard();
            else if (difficulty > 1)
                printHiddenBoard();
        }
        
	
        //decrement time elapsed
        if (p1.hasArmor() && extraTime > 0)
		cout << "Time is frozen for " << extraTime << " more minutes." << endl;
	else if (!p1.hasArmor() && extraTime <= 0)
		mins --;
	else
		mins --;

	if (p1.hasArmor())
		extraTime --;
        
        //take away any damage taken
        health = (100 - p1.getDamageTaken());

    }
    
    cout << endl << "Game Over!" << endl << endl;
   
    //show final board
    printBoard();
    
    //if game ends in win
    if (fugFound == true)
    {
        cout << "Congratulations - you found the fugitive with" << endl;
        cout << mins << " minutes to spare! Great work, Officer." << endl;
    }
    //if player runs out of time
    else if (mins == 0)
    {
        cout << "Unfortunately, you weren't able to capture the fugitive," << endl;
        cout << "and they got away. Better luck next time." << endl;
    }
    //if player loses too much health
    else if (health <= 0)
    {
	if (health <= -200)
		cout << "Unfortunately, the fugitive got away. Better luck next time." <<endl;
	else
	{
		cout << "Unfortunately, you were too badly wounded to continue your search." << endl;
		cout << "Medics are on their way, but the fugitive escaped." << endl;
    	}
    }
    cout << endl;
	
}


/***************************************
 FinalGame::~FinalGame()
 **************************************/
FinalGame::~FinalGame()
{
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (board[i][j] != NULL)
            {
                delete board[i][j];
            }
        }
        // delete rows
        delete [] board[i];
    }
    // delete board
    delete [] board;

    return;
}
