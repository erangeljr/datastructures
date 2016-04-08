/*	Eddie Rangel					*/


#include <cstdlib>
#include <iostream>
using namespace std;

struct node
{
	double d;
	node *link;
};

class stack
{
		node *entry;
		//enum {EMPTY = 0};
	public:
		stack();
		stack(const stack &);
		~stack();
		void push (double);
		double pop();
		void release();
		double peek() const {return entry -> d;}
		bool empty() const;
};
stack::stack()
{
	entry = NULL;
}
stack::stack(const stack &mystk)
{
	node *src = mystk.entry,
		 **dest = &entry;
	while(src != NULL)
	{
		*dest = new node;
		(*dest) -> d = src -> d;
		src = src -> link;
		dest = &((*dest) -> link);
	}
	*dest = NULL;
}
stack::~stack()
{
	release();
}
void stack::release()
{
	while(!empty())
		pop();
	return;
}
bool stack::empty() const
{
	return (bool)(entry == NULL);
}
void stack::push(double dbl)
{
	node *temp = new node;
	temp -> link = entry;
	temp -> d = dbl;
	entry = temp;
	return;
}
double stack::pop()
{
	double r_val = entry -> d;
	node *temp = entry;
	entry = entry -> link;
	delete temp;
	return r_val;
}
void sho_stack(stack mystk);

main()
{
	double nmbr;
	char c;
	stack mystk;
	mystk.release();
	cout << "Please enter +, -, P, C, D, or Q: ";
	cin >> c;
	c = toupper(c);
	while(c != 'Q')
	{
		switch(c)
		{
			case '+':
				cout << "Please enter a number: ";
				cin >> nmbr;
				mystk.push(nmbr);
				break;
			case '-':
				if(mystk.empty())
					cout << "Your stack is empty\n";
				else
				{
					cout << "This is your number: ";
					cout << mystk.pop() << '\n';
				}
				break;
			case 'P':
				if(mystk.empty())
					cout << "Your stack is empty\n";
				else
				{
					cout << "This is your number: ";
					cout << mystk.peek() << '\n';
				}
				break;
			case 'D':
				sho_stack(mystk);
				break;
			case 'C':
				mystk.release();
				break;
			default:
				cout << "You have entered invalid data!\n";
		}
		cout << "Please enter +, -, P, C, D, or Q: ";
		cin >> c;
		c = toupper(c);
	}
	return 0;
}

void sho_stack(stack mystk)
{
	cout << "Current stack: ";
	while(!mystk.empty())
		cout << mystk.pop() << " ";
	cout << '\n';
	mystk.push(9.9);
	mystk.push(7.7);
	cout << "Now the copy is: ";
	while(!mystk.empty())
		cout << mystk.pop() << " ";
	cout << '\n';
	return;
}