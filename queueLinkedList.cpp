/*	Eddie Rangel					*/


#include <cstdlib>
#include <iostream>
using namespace std;

struct node
{
	double d;
	node *link;
};

class queue
{
		node *front,
			 *back;
		//enum {EMPTY = 0};
	public:
		queue();
		queue(const queue &);
		~queue();
		void put (double);
		double get();
		void release();
		double peekf() const{return front -> d;}
		double peekb() const{return back -> d;}
		bool empty() const;
};
queue::queue()
{
	front = back = NULL;
}
queue::queue(const queue &myque)
{
	node *src = myque.front,
		 **dest = &front;
	while(src != NULL)
	{
		*dest = new node;
		(*dest) -> d = src -> d;
		src = src -> link;
		dest = &((*dest) -> link);
	}
	*dest = NULL;
}
queue::~queue()
{
	release();
}
void queue::release()
{
	node *temp = NULL;
	while(front != 	NULL)
	{
		temp = front;
		front = front -> link;
		delete temp;
	}
	return;
}
void queue::put(double nmbr)
{
	node *temp = new node;
	temp -> d = nmbr;
	temp -> link = NULL;
	if(front == NULL)
	{
		front = temp;
	}
	else
	{
		back -> link = temp;
	}
	back = temp;
	return;
}
double queue::get()
{
	double r_val = front -> d;
	node *temp = front;
	front = front -> link;
	delete temp;
	return r_val;
}
bool queue::empty() const
{
	return front == NULL;
}
void sho_q(queue q);
main()
{
	double nmbr;
	char c;
	queue myque;
	myque.release();
	cout << "Please enter +, -, F, D, B, C, or Q: ";
	cin >> c;
	c = toupper(c);
	while(c != 'Q')
	{
		switch(c)
		{
			case '+':
				cout << "Please enter a number: ";
				cin >> nmbr;
				myque.put(nmbr);
				break;
			case '-':
				if(myque.empty())
					cout << "Your queue is empty\n";
				else
				{
					cout << "This is your number: ";
					cout << myque.get() << '\n';
				}
				break;
			case 'F':
				if(myque.empty())
					cout << "Your queue is empty\n";
				else
				{
					cout << "This is your number: ";
					cout << myque.peekf() << '\n';
				}
				break;
			case 'D':
				sho_q(myque);
				break;
			case 'B':
				if(myque.empty())
					cout << "Your queue is empty\n";
				else
				{
					cout << "This is your number: ";
					cout << myque.peekb() << '\n';
				}
				break;
			case 'C':
				myque.release();
				break;
			default:
				cout << "You have entered invalid data!\n";
		}
		cout << "Please enter +, -, F, D, B, C, or Q: ";
		cin >> c;
		c = toupper(c);
	}
	return 0;
}
void sho_q(queue myque)
{
	cout << "Current queue: ";
	while(!myque.empty())
		cout << myque.get() << " ";
	cout << '\n';
	myque.put(9.9);
	myque.put(7.7);
	cout << "Now the copy is: ";
	while(!myque.empty())
		cout << myque.get() << " ";
	cout << '\n';
	return;
}