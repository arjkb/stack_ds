/*
	FILE: brac_bal.cpp
	-------------------------------------------------------------------------------
	Program to check whether a given expression contains balanced set of parenthesis.
	
	-------------------------------------
	CODER	: Arjun Krishna Babu
	DATE	: 24 - August - 2013

	COMPILER	: G++
	OS			: Ubuntu 12.04 LTS
	PROCESSOR	: 4th gen. Intel Core i5
	-------------------------------------
*/
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

bool isOpenBracket(char);		//returns true if the character is an opening bracket, false otherwise
bool isCloseBracket(char);		//returns true if the character is a closing bracket, false otherwise
bool isMatch(char open, char close);	//returns true if the opening and closing brackets match, false otherwise

class Stack	{
private:
	char *A;
	int SIZE;
	int top;

	int pushcount;
public:

	Stack(int sz): top(-1), SIZE(sz), pushcount(0) { 
		A = new char[SIZE]; 	//dynamically allocate space (equal to length of expression) for A. 
	}

	bool isFull();
	bool isEmpty();
	void push(char b);
	void pop();
	char peek();
	int getPushcount();	//keeps track of the number of pushes made (0 indicates an expression without brackets)
	
	~Stack()	{	//deletes space dynamically allocated for A
		delete A;
	}
};

int main()	{

	char E[100];	//variable to store the original expression
	
	bool match = true; 	//flag

	cout<<"\n Enter an expression: ";	gets(E);

	Stack S( strlen(E) );				//dynamically initialize a stack with the size of the given expression
	
	for(int i = 0; i < strlen(E); i++)	{

		if( isOpenBracket(E[i]) )	
			S.push(E[i]);
		else if( isCloseBracket(E[i]) )	{
			if( S.isEmpty() || !isMatch(S.peek(), E[i]) )	{
				match = false;
				break;
			}
			else if(isMatch(S.peek(), E[i]))	{
				S.pop();
			}
		}
	}

	if( match && S.isEmpty() && (S.getPushcount() != 0) )
		cout<<"\n BALANCED!";
	else
		cout<<"\n UNBALANCED!";

   cout<<"\n\n";
   cout<<"\n Program developed by Arjun Krishna Babu";
   cout<<"\n https://github.com/arjunkbbabu/stack_ds \n";
   
   return 0;		
}

/*** MEMBER FUNCTION DEFINITIONS ***/
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

bool isMatch(char tp, char symb)	{
	switch(tp)	{
		case '(': return ((symb == ')')? true : false);
		case '{': return ((symb == '}')? true : false);
		case '[': return ((symb == ']')? true : false);
		default : return false;
	}
}

/*** STACK CLASS FUNCTION DEFINITIONS */
bool Stack::isFull()	{
	if( top == (SIZE - 1) )
		return true;
	else
		return false;
}

bool Stack::isEmpty()	{
	if( top == -1 )
		return true;
	else
		return false;
}

void Stack::push(char data)	{
	pushcount++;
	if( !isFull()	)
		A[++top] = data;
}

int Stack::getPushcount()	{
	return pushcount;
}

void Stack::pop()	{
	if( !isEmpty() )
		top--;
}

char Stack::peek()	{
	return A[top];
}
/**********************************/
