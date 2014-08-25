/*
	Java console program to implement a stack.

	125H14 -- Arjun Krishna Babu
*/

import java.util.*;

class Stack	{
	final int SIZE = 5;
	private int [] A = new int[SIZE];
	private int top;

	Stack()	{
		top = -1;
	}

	boolean isFull()	{
		if( top == (SIZE - 1) )
			return true;
		else
			return false;
	}

	boolean isEmpty()	{
		if( top == -1 )
			return true;
		else
			return false;
	}

	void push(int dd)	{
		if( isFull() )
			System.out.print("\n ERROR: Overflow!");
		else
			A[++top] = dd;
	}

	void pop()	{
		if( isEmpty() )
			System.out.println("\n ERROR: Underflow!");
		else
			top--;
	}

	int peek()	{
		if( isEmpty() )	{
			System.out.print("\n ERROR: Underflow!");
			return -1;
		}
		return A[top];
	}

	void dispAll()	{
		if( isEmpty() )
			System.out.print("\n ERROR: Underflow!");
		else	{
			for(int i = 0; i <= top; i++)
				System.out.print(" " + A[i]);
		}
	}
}

class stack_java	{

	public static void main(String args[])	{

		Scanner in = new Scanner(System.in);
		Stack S = new Stack();
		int choice;
		int num;

		do	{
			System.out.print("\n [STACK IMPLEMENTATION]");
			System.out.print("\n 1. Push");
			System.out.print("\n 2. Pop");
			System.out.print("\n 3. Peek");
			System.out.print("\n 4. Display all elements");
			System.out.print("\n 0. EXIT");
			System.out.print("\n Enter Your Choice: ");
			choice = in.nextInt();
	
			switch(choice)	{
				case 1: System.out.print("\n Enter element to push onto stack: ");
						num = in.nextInt();
						S.push(num);
						break;
				case 2: S.pop();
						break;
				case 3: System.out.print("\n Element at top: " + S.peek() );
						break;
				case 4: System.out.print("\n Elements of the stack: "); 
						S.dispAll();
						break;
				case 0: System.out.print("\n Thank You For Using This Program!");
						System.out.print("\n Program under development by Arjun Krishna Babu");
						System.out.print("\n https://github.com/arjunkbabu/stack_ds");
						break;
			   default: System.out.print("\n ERROR: Invalid Choice!");
			   			break;
			}
		  
		  System.out.print("\n\n");
		} while( choice != 0 );

	}	//end of main()
}
