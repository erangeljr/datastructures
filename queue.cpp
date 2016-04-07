/*	Eddie Rangel					*/


#include <cstdlib>
#include <iostream>
using namespace std;

const int max_len = 5;

class queue
{
		enum {EMPTY = 0, FULL = max_len};
	public:
    
        //Clears the contents of a queue
        //Sets Front and count to empty
		void reset(){front = EMPTY;	count = EMPTY;}
        
        //Inserts a 
		void put(double);
		double get();
		double peekf() const{return d[front];}
		double peekb() const{return d[((front + count) - 1) % max_len];}
		bool full(){return (bool)(count >= FULL);}
		bool empty(){return (bool)(count <= EMPTY);}
	private:
		double d[max_len];
		int front,
			count;
};
main()
{
	double nmbr;
	char c;
	queue myque;
	myque.reset();
	cout << "Please enter +, -, F, B, C, or Q: ";
	cin >> c;
	c = toupper(c);
	while(c != 'Q')
	{
		switch(c)
		{
			case '+':
				if(myque.full())
					cout << "Your queue is full\n";
				else
				{
					cout << "Please enter a number: ";
					cin >> nmbr;
					myque.put(nmbr);
				}
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
				myque.reset();
				break;
			default:
				cout << "You have entered invalid data!\n";
		}
		cout << "Please enter +, -, F, B, C, or Q: ";
		cin >> c;
		c = toupper(c);
	}
	return 0;
}
void queue::put(double nmbr)
{
	d[(front + count) % max_len] = nmbr;
	++count;
	return;
}
double queue::get()
{
	 double e = d[front];
	 ++front;
	 front %= max_len;
	 --count;
	 return e;
}









