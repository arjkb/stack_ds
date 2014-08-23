/*
	FILE  : linklistclass.cpp
	--------------------------------------------------
	Program to implement a stack in C++ (using arrays)

	CODER : Arjun Krishna Babu
	DATE  : 23 - August - 2014

	COMPILER  : G++
	OS	      : Ubuntu 12.04 LTS
	PROCESSOR : 4th gen. Intel i5

*/

#include<iostream>

#define OVERFLOW_MESSAGE  cout<<"\n ERROR: Overflow!"
#define UNDERFLOW_MESSAGE cout<<"\n ERROR: Underflow!"

using namespace std;

const int SIZE = 5;		//max size of stack

class Stack	{
private:
	int A[SIZE];
	int top;
	bool isFull(void);	//returns true if the stack is full, false otherwise
	bool isEmpty(void); //returns true if the stack is empty, false otherwise
public:
	Stack(): top(-1) { }

	void push(int data);
	int  pop(void);	
	int  peek(void);
	void dispAll(void);	
	void clear(void);	//clears the stack (sets top to -1)
};

int main()	{
	Stack S;
	int choice;
	int item;
	
	do	{
		cout<<"\n 1. Push";
		cout<<"\n 2. Pop";
		cout<<"\n 3. Peek";
		cout<<"\n 4. Display all elements";
		cout<<"\n 5. Clear Stack";
		cout<<"\n 0. EXIT";
		cout<<"\n Enter Your Choice: "; cin>>choice;
		
		switch(choice)	{
			case 1: cout<<"\n Enter an item to push onto stack: ";
					cin>>item;
					S.push(item);
					break;
			case 2: cout<<"\n Deleting element: "<<S.pop();		
					break;
			case 3: cout<<"\n Element at top: "<<S.peek();
					break;
			case 4: cout<<"\n The elements in the stack: "; S.dispAll();
					break;
			case 5: S.clear();
					cout<<"\n The stack had been cleared!";
					break;
			case 0: cout<<"\n Thank you for using this program!";
		
					break;
		   default: cout<<"\n ERROR: Invalid Choice!";
		   			break;
		}
		cout<<"\n\n";
	}while(choice != 0);

   cout<<"\n\n";
   return 0;
}

/***** MEMBER FUNCTION DEFINITION *****/
bool Stack::isFull()	{
	//returns true if top is equal to (size - 1), or false otherwise
	return (top == (SIZE - 1))? true : false;
}

bool Stack::isEmpty()	{
	//returns true if top equals -1, or false otherwise
	return (top == -1)? true : false;
}

void Stack::push(int data)	{	
	if( isFull() )
		OVERFLOW_MESSAGE;
	else
		A[++top] = data;
}

int Stack::pop()	{
	if( isEmpty() )	{
		UNDERFLOW_MESSAGE;
		return -1;
	}
	else
		return A[top--];
}

int Stack::peek()	{
	if( isEmpty() )
		UNDERFLOW_MESSAGE;
	else
		return A[top];
}

void Stack::dispAll()	{
	if( isEmpty() )
		UNDERFLOW_MESSAGE;
	else	{
		for(int i = 0; i <= top; i++)
			cout<<" "<<A[i];
	}
}

void Stack::clear()	{
	top = -1;
}
