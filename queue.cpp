#include <queue>
#include <iostream>

using namespace std;


int main()
{
	queue <int> myqueue;
	do
	{
		
		char choice;
		int i;
		cout << "Queue Options:" << endl;
		cout << "A)   Enqueue Data into Queue" << endl;
		cout << "B)   Dequeue all data from the queue" << endl;
		cout << "C)   Print Data at the front of the Queue" << endl;
		cout << "D)   Print Data at the back of the Queue" << endl;
		cout << "E)   Print the entire Queue" << endl;
		cout << "F)   Check if the Queue is empty" << endl;
		cout << "G)   Print the number of elements in the Queue" << endl;
		cout << "H)   Exit the program" << endl;
		cout << "Enter selection: ";
		cin >> choice;
		

		if (choice == 'A' || choice == 'a')
		{
			cout << "Enter a value to enqueue: ";
			cin >> i;
			myqueue.push(i);
		}
		else if (choice == 'B' || choice == 'b')
		{
			cout << "Dequeing queue... " << endl;
			while (!myqueue.empty())
			{
				myqueue.pop();
			}
		}
		else if (choice == 'C' || choice == 'c')
		{
			cout << "The value at the front of the queue is: ";
			cout << myqueue.front();
			cout << endl;
		}
		else if (choice == 'D' || choice == 'd')
		{
			cout << "The value at the back of the queue is: ";
			cout << myqueue.back();
			cout << endl;
		}
		else if (choice == 'E' || choice == 'e')
		{
			while (!myqueue.empty())
			{
				cout << myqueue.front() << " ";
				myqueue.pop();
			}
			cout << endl;
		}
		else if (choice == 'F' || choice == 'f')
		{
			if (myqueue.empty()) {
				cout << "Queue is empty" << endl;
			}
			else {
				cout << "Queue is not empty" << endl;
			}
		}
		else if (choice == 'G' || choice == 'g')
		{
			cout << "The size of the queue is: ";
			cout << myqueue.size();
			cout << endl;
		}
		else if (choice == 'H' || choice == 'h')
		{
			return 0;
		}
		else {
			cout << "Choice was invalid" << endl;
		}
	} while (true);
}
