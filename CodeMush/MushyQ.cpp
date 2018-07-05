#include "stdafx.h"
#include "MushyQ.h"

namespace Queue
{
	MushyQ::MushyQ()
	{
		size = 0;
		front = NULL;
		rear = NULL;
	}

	MushyQ::~MushyQ()
	{
		node *temp = front;
		while (temp != NULL)
		{
			front = temp->next;
			delete temp;
			temp = front;
		}
		size = 0;
		rear = NULL;
	}

	void MushyQ::Push(int val)
	{
		node *temp = new node;
		temp->data = val;
		if (size == 0)
		{
			front = temp;
			rear = temp;
			temp->next = NULL;
			temp->prev = NULL;
		}
		else
		{
			temp->prev = rear;
			rear->next = temp;
			rear = temp;
			temp->next = NULL;
		}
		size++;
	}

	int MushyQ::Pop()
	{
		node *temp = front;
		front = front->next;
		int val = temp->data;
		delete temp;
		return val;
	}

	void MushyQ::Display()
	{
		node *temp = front;
		while (temp != NULL)
		{
			cout << temp->data << "  ";
			temp = temp->next;
		}
		cout << endl;
	}

	void RunQ()
	{
		MushyQ myQ;
		int input;
		while (true)
		{
			cout << "Push a number in the queue and 0 to show and -1 to exit: ";
			cin >> input;
			if (input == 0)
			{
				myQ.Display();
			}
			else if (input == -1)
				break;
			else
			{
				myQ.Push(input);
			}
		}
	}
}