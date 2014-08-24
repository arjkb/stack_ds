/*
	FILE: postfix_eval.cpp
	-------------------------------------------------
	Program to evaluate a given postfix expression.


	CODER	: Arjun Krishna Babu
	DATE	: 24 - August - 2014

	COMPILER	: G++
	OS			: Ubuntu 12.04 LTS
	PROCESSOR	: 4th gen. Intel Core i5
*/

#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

bool isOperand(char);		//returns true is the character is an operand, false otherwise
bool isOperator(char);		//returns true if the character is an operator, false otherwise
int  operate(int, int, char);

class Stack	{
	int *A;
	int SIZE;
	int top;
	bool isFull();
	bool isEmpty();
public:
	Stack(int sz):	top(-1)	{
		SIZE = sz + 10;
		A = new int[SIZE];
	}
	void push(int);
	int  pop();
};

int main()	{
	
	int f = 0, s = 0;		//variables to store the first and second operands
	int res;		//variable  to store intermediate results

	char E[100], symb;

	cout<<"\n Enter a postfix expression: "; gets(E);
	Stack S( strlen(E) );

	for(int i = 0; i < strlen(E); i++)	{
		symb = E[i];
		if( isOperand(symb) )	{
//			cout<<"\n IN IF \n";
			S.push(symb - '0');				//pushes integer equivalent of a character to stack
		}
		else if( isOperator(symb) )	{
//			cout<<"\n IN ELSE \n";
			s = S.pop();
			f = S.pop();
			res = operate(f, s, symb );
			S.push(res);
		}
	}
	
	cout<<"\n Result: "<<S.pop();

   cout<<"\n\n";
   return 0;
}
/*** MEMBER FUNCTION DEFINITIONS ***/
bool isOperand(char c)	{
/*	if((c >= '0') && (c <= '1'))	{
		cout<<"\n "<<c<<" OPERAND! \n";
		return true;
	}
	else	{
		cout<<"\n "<<c<<" NOT OPERAND! \n";
		return false;
	}
*/
	switch(c)	{
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '0': //cout<<"\n "<<c<<" OPERAND \n"; 
				  return true;
		default	: //cout<<"\n NOT OPERAND! \n";	 
				  return false;
	}
}

bool isOperator(char c)	{
	switch(c)	{
		case '+':
		case '-':
		case '*':
		case '/': //cout<<"\n "<<c<<" OPERATOR! \n"; 	  
				  return true;
		default	: //cout<<"\n "<<c<<" NOT OPERATOR \n"; 
		     	  return false;
	}
}

int operate(int a, int b, char oper)	{
	switch(oper)	{
		case '+':	return (a + b);
		case '-':	return (a - b);
		case '*':	return (a * b);
		case '/':	return (a / b);
	   	default	: 	return 0;
	}
}

/** STACK FUNCTION DEFINITIONS */
bool Stack::isFull()	{
	if( top == (SIZE - 1) )
		return true;
	else
		return false;
}

bool Stack::isEmpty()	{
	if( top == -1)
		return true;
	else
		return false;
}

void Stack::push(int c)	{
	if( !isFull() )
		A[++top] = c;
}

int Stack::pop()	{
	if( !isEmpty() )
		return A[top--];
}
/*	*	*	*	*	*	*	*	*	*/
