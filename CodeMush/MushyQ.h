#pragma once
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

namespace Queue
{
	struct node {
		int data;
		node *next, *prev;
	};

	class MushyQ
	{
	private:
		int size;
		node *front, *rear;
	public:
		MushyQ();
		~MushyQ();
		void Push(int);
		int Pop(void);
		void Display(void);
	};

	void RunQ(void);
}
