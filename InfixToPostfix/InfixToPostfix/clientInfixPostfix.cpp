// Napon Krassner (Jett)
// CSC 2430, Homework 1
// 04-14-2015
// Due: 04-20-2015
// Name: Infix to Postfix Expression Converter Client
// Description: This is a client program that tests the InfixPostfix class InfixPostfix 
//				class to prompt, store, and convert infix expression to postfix expression
//				until the user exits the program.

#include <iostream>
#include <string>
#include "InfixPostfix.h"

using namespace std;

int main()
{
	cout << "Welcome to Infix to Postfix Expression Converter by Napon Krassner (Jett)" << endl << endl;

	InfixPostfix infixExpr;  // Declare class variable

	bool exprOk = infixExpr.getInfx();  // Prompt user for infix expression

	while (exprOk)  // Loop until user quits
	{
		// Show infix and postfix strings
		infixExpr.showInfx();
		infixExpr.showPostfix();
		cout << endl;

		// Prompt user again until quits
		exprOk = infixExpr.getInfx();
	}

	return 0;
}