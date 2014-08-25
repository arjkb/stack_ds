/*
	FILE:	inf_posf_conv.cpp
	------------------------------------------------------------------
	Program to convert an infix expression into a postfix expression.

	KNOWN BUGS:
		1. Seems to convert only if whole expresion is within parenthesis

	--------------------------------------
	CODER	: Arjun Krishna Babu
	DATE	: 25 - August - 2014

	COMPILER	: G++
	OS			: Ubuntu 12.04 LTS
	PROCESSOR	: 4th gen. Inter Core i5
	--------------------------------------
*/

#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

bool prcd(char A, char B);	//returns true if A has higher precedence than B,  false otherwise
bool isOperand(char);		//returns true if character is an operand, 		   false otherwise
bool isOperator(char);		//returns true if character is an operator, 	   false otherwise
bool isOpenBracket(char);	//returns true if character is an opening bracket, false otherwise
bool isCloseBracket(char);	//returns true if character is a closing bracket,  false otherwise

const int SIZE = 100;
class Stack	{
	char A[SIZE];
	int top;
public:
	Stack(): top(-1) { }
	bool isFull();
	bool isEmpty();
	void push(char);
	char pop();
	char peek();
	void dispAll();
};

int main()	{

	Stack S;

	char E[100];
	char P[100] = {'\0'}; int k = -1;

	int symb;
	int garb;

	cout<<"\n Enter an infix expression: "; gets(E);

	for( int i = 0; i < strlen(E); i++ )	{

		symb = E[i];

		if( isOperand(symb) )	{	//add to postfix is symbol is an operand
			cout<<"\n Pushing symbol "<<symb;
			P[++k] = symb;
		}
		else if( isOperator(symb) )	{
			cout<<"\n OPERATOR ELS";
			//pop till stack is empty/top is open bracket/top has lower precedence
			while( !S.isEmpty() && !isOpenBracket(S.peek()) && prcd(S.peek(), symb) )	{
				P[++k] = S.pop();		//push to postfix
			}
			
			if( isOpenBracket(S.peek()) )	//remove top element if it's a bracket
				garb = S.pop();			//get rid of it
			
			S.push(symb);

			S.dispAll();
		}

		else if( isOpenBracket(symb) )	{
			cout<<"\n OPEN-BRAC ELS";
			S.push(symb);
		}
	
		else if( isCloseBracket(symb) )	{
			
			cout<<"\n CLOSE-BRAC ELS";

			//if closing bracket is encountered, pop till you get an opening bracket
			while( !S.isEmpty() && !isOpenBracket(S.peek()) )	{
				P[++k] = S.pop();
			}
		}
	}	//end of for

	while( !S.isEmpty() )	{
		cout<<"\n OUTER WHILE!";
		P[++k] = S.pop();
	}

	cout<<"\n\n Postfix Expression: "<<P;
		
   cout<<"\n\n";
   return 0;
}

/*** MEMBER FUNCTION DEFINITIONS ***/
bool prcd(char a, char b)	{
	//returns true if A has higher precedence than B
	switch(a)	{
		case '^': return false;
		case '*':
		case '/': if(b == '^')
					return false;
				  else if( (b == '*') || (b == '/') )
					return true;
				  else if( (b == '+') || (b == '-') )
					return true;
		case '+':
		case '-': if(b == '^')
					return false;
				  else if( (b == '*') || (b == '/') )
					return false;
				  else if( (b == '+') || (b == '-') )
					return true;
	}
}

bool isOperand(char a)	{
	if( (a >= 'A') && (a <= 'z') )
		return true;
	else
		return false;
}

bool isOperator(char a)	{
	switch(a)	{
		case '+':
		case '-':
		case '*':
		case '/': return true;
		default	: return false;
	}
}
bool isOpenBracket(char b)	{
	if( (b == '(') || (b == '{') || (b == '[') )	
		return true;
	else
		return false;
}

bool isCloseBracket(char b)	{
	if( (b == ')') || (b == '}') || (b == ']') )
		return true;
	else
		return false;
}
/** STACK CLASS FUNCTION DEFINITIONS */
bool Stack::isEmpty()	{
	if( top == -1)	
		return true;
	else
		return false;
}
void Stack::push(char c)	{
	A[++top] = c;
}

char Stack::pop()	{
	return A[top--];
}

char Stack::peek()	{
	return A[top];
}

void Stack::dispAll()	{
	cout<<"\n STACL-ELEM:";
	for(int i = 0; i <= top; i++)	
		cout<<" "<<A[i];
}
/*	*	*	*	*	*	*	*	*	*/
