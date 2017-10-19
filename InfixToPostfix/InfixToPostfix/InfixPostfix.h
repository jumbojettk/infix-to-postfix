// Napon Krassner (Jett)
// CSC 2430, Homework 1
// 04-14-2015
// Due: 04-20-2015
// Name: Infix to Postfix Expression Converter Header
// Description: This is a header file for InfixPostfix class, contains all the member function and
//				member variable declarations and as well as a inline documentation showing how things work.

#ifndef _INFIXPOSTFIX_
#define _INFIXPOSTFIX_

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class InfixPostfix
{
public:
	//********CONSTRUCTOR********
	// Parameters:
	// Return:
	// Description: Default constructor, initializes InfixPostfix object.
	//				Set infx = ""
	InfixPostfix();

	//********DESTRUCTOR********
	// Don't need one since not allocating any memory from the heap.

	//********MUTATORS********
	// Parameters: None
	// Return: True - if expression was entered, False - if ";" was entered.
	// Description: Prompts user for infix string, stores the string in "infx".
	bool getInfx();

	//********ACCESSORS********
	// Parameters: None
	// Return: Nothing
	// Description: Outputs the infx string value using cout
	void showInfx();

	// Parameters: None
	// Return: Nothing
	// Description: Calls the convert function to create postfix from the infix.
	//				Then outputs the pfx value
	void showPostfix();

private:
	// Private member variables
	string infx;
	string pfx;

	//********PRIVATE UTILITIES********
	// Parameters: None
	// Return: True - if conversion is success, False if error encountered.
	// Description: Converts infx string to the postfix string and store it in pfx.
	// Note: Assume infix error free.
	bool convertToPostfix();

	// Parameters: char to determine if operator
	// Return: True if operator, false if not
	// Description: Determines if the char passed in is an operator or not
	bool isOperator(char);

	// Parameters: first operator, second operator
	// Return: True - if op1 is higher or equal precedence than op2, false otherwise.
	// Description: Determines the precedence between the 2 operators.
	// Note: (+ and -) are low, (* and /) are high precedence.
	bool precedence(char, char);
};

#endif