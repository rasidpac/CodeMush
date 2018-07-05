#pragma once
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

namespace Tree
{
	struct node {
		int data;
		node *left = NULL;
		node *right = NULL;
	};

	class MushyT
	{
	private:
		int size;
		node *root;
	public:
		MushyT();
		~MushyT();
		node** GetRoot(void);
		void Insert(node**, int);
		void Delete(int);
		void Display(node*);
		void Destroy(node*);
	};

	void RunT(void);
}
