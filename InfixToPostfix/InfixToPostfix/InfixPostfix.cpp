// Napon Krassner (Jett)
// CSC 2430, Homework 1
// 04-14-2015
// Due: 04-20-2015
// Name: Infix to Postfix Expression Converter Implementation
// Description: This is the implementation file for the InfixPostfix class, contains all the function
//				definition and shows how each member functions and variables are implemented.
//				The InfixPostfix class uses the stack algorithm to store parenthesis and operators as it
//				traverses through all the chars inside the infix string and converts it to a postfix string

#include <iostream>
#include <string>
#include <stack>
#include "InfixPostfix.h"

using namespace std;
//********CONSTRUCTOR********
InfixPostfix::InfixPostfix()
{
	infx = "";
	pfx = "";
}

//********MUTATORS********
bool InfixPostfix::getInfx()
{
	infx = "";  // Re-init
	char ch;
	bool valid = false;

	// Get first char
	cout << "Enter infix expression with ; at end: ";
	cin >> ch;

	
	if (ch != ';')  // If first char is not semicolon
	{
		valid = true;

		// Keep storing chars into infx until ; is reached
		while (ch != ';')
		{
			infx += ch;
			cin >> ch;
		}
	}

	return valid;
}


//********ACCESSORS********
void InfixPostfix::showInfx()
{
	cout << "Infix: \t\t" << infx << endl;
}

void InfixPostfix::showPostfix()
{
	bool converted;
	converted = convertToPostfix();  // conversion success or not
	if (converted)
	{
		cout << "Postfix: \t" << pfx << endl;
	}
	else
	{
		cout << "Postfix conversion failed!" << endl;
	}
	
}

//********PRIVATE UTILITIES********
bool InfixPostfix::convertToPostfix()
{
	// Initialize pfx and stack
	pfx = "";
	stack<char> chStk;
	bool success = true;

	for (char sym : infx)  // C++11 range based loop
	{
		if (!isOperator(sym) && sym != '(' && sym != ')')  // If sym is operand
		{
			pfx += sym;  // Append
		}
		else if (sym == '(')
		{
			chStk.push(sym);
		}
		else if (sym == ')')
		{
			while (chStk.top() != '(' && !chStk.empty())  // While not the left paren and stack isn't empty
			{
				pfx += chStk.top();  // Append top element to pfx
				chStk.pop();  // Pop the top element
			}

			if (chStk.empty())  // Check for unbalanced paren if no left paren found
			{
				cout << "Error: The infix expression has unbalanced parentheses!" << endl;
				success = false;
				break;
			}
			else if (chStk.top() == '(')
			{
				chStk.pop();  // Pop the left paren
			}
		}
		else if (isOperator(sym)) // sym is an operator
		{
			// While stack not empty, top of stack is an operator, and top of stack has higher/equal precedence to sym
			while (!chStk.empty() && isOperator(chStk.top()) && precedence(chStk.top(), sym))
			{
				pfx += chStk.top();
				chStk.pop();
			}
			chStk.push(sym);
		}
	}

	// After processing, append the rest of the operators in stack if any
	while (!chStk.empty() && chStk.top() != '(')
	{
		if (chStk.top() != '(')  // Check for unbalanced paren
		{
			pfx += chStk.top();
			chStk.pop();
		}
		else
		{
			cout << "Error: The infix expression has unbalanced parentheses!" << endl;
			success = false;
			break;
		}

	}

	return success;
}

bool InfixPostfix::isOperator(char val)
{
	if (val == '*' || val == '/' || val == '+' || val == '-')
		return true;
	else
		return false;
}

bool InfixPostfix::precedence(char op1, char op2)
{
	int prOp1;
	int prOp2;

	// Determine precedence of op1 from the stack
	if (op1 == '+' || op1 == '-')
		prOp1 = 0;
	else if (op1 == '*' || op1 == '/')
		prOp1 = 1;

	// Determine precedence of op2 from sym
	if (op2 == '+' || op2 == '-')
		prOp2 = 0;
	else if (op2 == '*' || op2 == '/')
		prOp2 = 1;

	// Compare op1 and op2 precedence
	if (prOp1 >= prOp2)
		return true;
	else
		return false;
}