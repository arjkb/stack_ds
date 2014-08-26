/*
	Java console program to check whether an expression has a balanced set of parenthesis.

	326H14 -- Arjun Krishna Babu
*/
import java.util.*;
class Stack	{
	final int SIZE = 100;
	private char []A = new char[SIZE];
	private int top;
	private boolean push_status;
	Stack()	{
		top = -1;
		push_status = false;
	}

	public boolean isEmpty()	{
		if( top == -1)
			return true;
		else
			return false;
	}

	public void push(char dd)	{
		push_status = true;
		A[++top] = dd;
	}

	public void pop()	{
		top--;
	}

	public char peek()	{
		return A[top];
	}

	public boolean getPushstatus()	{
		return push_status;
	}
}

class brac_bal_java	{

	private static boolean isOpenBracket(char b)	{
		if( (b == '(') || (b == '{') || (b == '[') )
			return true;
		else
			return false;
	}

	private static boolean isCloseBracket(char b)	{
		if( (b == ')') || (b == '}') || (b == ']')	)
			return true;
		else
			return false;
	}

	private static boolean isMatch(char a, char b)	{
		switch(a)	{
			case '(': return (b == ')')? true : false;
			case '{': return (b == '}')? true : false;
			case '[': return (b == ']')? true : false;
		   default 	: return false;
		}
	}
	
	private static void SOP(String S)	{
		System.out.print(S);
	}

	public static void main(String args[])	{
		Stack S = new Stack();
				
		Scanner text = new Scanner(System.in);
		Scanner in 	 = new Scanner(System.in);

		String E = new String();
		
		boolean match = true;
			
		SOP("\n Enter an expression: ");
		E = text.nextLine();

		for(int i = 0; i < E.length(); i++)	{

			if( isOpenBracket(E.charAt(i)) )
				S.push( E.charAt(i) );
			else if( isCloseBracket(E.charAt(i)) )	{

				if( S.isEmpty() || !isMatch( S.peek(), E.charAt(i) ) )	{
					match = false;
					break;
				}

				else if ( isMatch(S.peek(), E.charAt(i)) )
					S.pop();
			}
		}

		if( S.isEmpty() && (match == true) && S.getPushstatus() )
			System.out.print("\n BALANCED!");
		else
			System.out.print("\n UNBALANCED!"); 

	  System.out.print("\n\n");
	}
}
