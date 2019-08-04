/*********************************
 *         
 *         Choice Function
 * 
 * Name: Jake Seawell
 * Date: 09/24/18
 * Description: This is a choice
 * function that takes two string
 * arguments and makes them two
 * choice options.
 *
 * ******************************/
#include "choiceFunction.hpp"
#include "intVal.hpp"

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int choiceFunction(string title, string option1, string option2)
{
	int choice = 0;
	cout << endl;
	cout << title << ":" << endl;
	cout << "1: " << option1 << endl;
	cout << "2: " << option2 << endl;
	cout << endl;
	cout << "Enter choice:" << endl;
	choice = minMaxValidation(integerValidation(),1,2);//User enters choice
		
	//Option 1:
	if (choice == 1)
	{
		cout << endl;
		cout << option1 << endl;
		cout << endl;
		return 1;
	}
	//Option 2:
	else if (choice == 2)
	{	
		cout << endl;
		cout << option2 << endl;
		cout << endl;
		return 2;
	}
}

