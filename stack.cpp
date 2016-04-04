/*	Eddie Rangel					*/

#include <cstdlib>
#include <iostream>
using namespace std;

const int max_len = 5;
enum {EMPTY = -1, FULL = max_len - 1};

class stack
{
	public:
		void reset(stack &stk);
		void push(double, stack &stk);
		double pop(stack &stk);
		double peek(const stack &stk);
		bool full(const stack &stk);
		bool empty(const stack &stk);
	private:
		double d[max_len];
		int top;
};

main()
{
	double nmbr;
	char c;
	stack mystack;
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
bool stack::full(const stack &stk)
{
	return (bool)(stk.top == FULL);
}
bool stack::empty(const stack &stk)
{
	return (bool)(stk.top == EMPTY);
}





