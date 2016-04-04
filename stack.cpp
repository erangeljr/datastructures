/*	Eddie Rangel					*/
/*	COMS B35 OOP C++				*/
/*	CH4-B.CPP						*/
/*	2-13-03							*/
/*	Asks user for a double			*/
/*	HEX value in each byte			*/


#include<iostream.h>
#include<conio.h>
#include<ctype.h>

const int max_len = 5;
enum {EMPTY = -1, FULL = max_len - 1};
enum boolean{false,true}; 			/* This is for B.C. commons only */

class stack
{
	public:
		void reset(stack &stk);
		void push(double, stack &stk);
		double pop(stack &stk);
		double peek(const stack &stk);
		boolean full(const stack &stk);
		boolean empty(const stack &stk);
	private:
		double d[max_len];
		int top;
};

main()
{
	double nmbr;
	char c;
	stack mystack;
	clrscr();
	mystack.reset(mystack);
	cout << "Please enter +, -, P, C, or Q: ";
	cin >> c;
	c = toupper(c);
	while(c != 'Q')
	{
		switch(c)
		{
			case '+':
				if(mystack.full(mystack))
					cout << "Your stack is full\n";
				else
				{
					cout << "Please enter a number: ";
					cin >> nmbr;
					mystack.push(nmbr, mystack);
				}
				break;
			case '-':
				if(mystack.empty(mystack))
					cout << "Your stack is empty\n";
				else
				{
					cout << "This is your number: ";
					cout << mystack.pop(mystack) << '\n';
				}
				break;
			case 'P':
				if(mystack.empty(mystack))
					cout << "Your stack is empty\n";
				else
				{
					cout << "This is your number: ";
					cout << mystack.peek(mystack) << '\n';
				}
				break;
			case 'C':
				mystack.reset(mystack);
				break;
			default:
				cout << "You have entered invalid data!";
		}
		cout << "Please enter +, -, P, C, or Q: ";
		cin >> c;
		c = toupper(c);
	}
	return 0;
}
void stack::reset(stack &stk)
{
	stk.top = EMPTY;
	return;
}
void stack::push(double nmbr, stack &stk)
{
	stk.d[++stk.top] = nmbr;
	return;
}
double stack::pop(stack &stk)
{
	return stk.d[stk.top--];
}
double stack::peek(const stack &stk)
{
	return stk.d[stk.top];
}
boolean stack::full(const stack &stk)
{
	return (boolean)(stk.top == FULL);
}
boolean stack::empty(const stack &stk)
{
	return (boolean)(stk.top == EMPTY);
}





