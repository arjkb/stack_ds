/*
	Java console program to evaluate a postfix expression.

	326H14 -- Arjun Krishna Babu
*/

import java.util.*;

class Stack	{
	final int SIZE = 100;
	private int []A; // = new int[SIZE];
	private int top;

	Stack()	{
		A = new int[SIZE];
		top = -1;
	}

	public void push(int dd)	{
		A[++top] = dd;
	}

	public int pop()	{
		return A[top--];
	}
	
}

class postfix_eval_java	{

	static private boolean isOperand(char a)	{
		switch(a)	{
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '0': return true;
			default	: return false;
		}
	}

	static private boolean isOperator(char a)	{
		switch(a)	{
			case '+':
			case '-':
			case '*':
			case '/':	return true;
			default	: 	return false;
		}
	}

	static private int operate(int a, int b, char oper)	{
		switch(oper)	{
			case '+': return (a + b);
			case '-': return (a - b);
			case '*': return (a * b);
			case '/': return (a / b);
			default	: return 0;
		}
	}

	public static void main(String args[])	{
		char symb;
		int f, s, res;

		Scanner text = new Scanner(System.in);
		    String E = new String();
		     Stack S = new Stack();

		System.out.print("\n Enter a postfix expression: ");
		E = text.nextLine();

		for(int i = 0; i < E.length();  i++)	{

			symb = E.charAt(i);

			if( isOperand(symb)	)
				S.push( symb - '0' );
			else if( isOperator(symb) )	{
				s = S.pop();
				f = S.pop();
				
				res = operate(f, s, symb);

				S.push(res);
			}
		}
		
		System.out.println("\n Value = "  + S.pop() );

	  System.out.println();
	}
}
