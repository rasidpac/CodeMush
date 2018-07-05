#include "stdafx.h"
#include "MushyT.h"

namespace Tree
{
	MushyT::MushyT()
	{
		size = 0;
		root = NULL;
	}

	MushyT::~MushyT()
	{
		Destroy(root);
	}

	node** MushyT::GetRoot()
	{
		return &root;
	}

	void MushyT::Destroy(node *index)
	{
		if (index != NULL)
		{
			Destroy(index->left);
			Destroy(index->right);
			delete index;
		}
	}

	void MushyT::Insert(node** index, int val)
	{
		if (*index == NULL)
		{
			*index = new node;
			if (root == NULL)
				root = *index;
			(*index)->data = val;
			return;
		}
		else if (val == (*index)->data)
			return;
		else if (val > (*index)->data)
		{
			Insert(&(*index)->right, val);
		}
		else
		{
			Insert(&(*index)->left, val);
		}
	}

	void MushyT::Delete(int val)
	{

	}

	void MushyT::Display(node* index)
	{
		if (index != NULL)
		{
			Display(index->right);
			cout << "\t";
			Display(index->left);
			cout << "\t";
			cout << index->data << endl;
		}
	}

	void RunT()
	{
		MushyT myT;
		int input;
		while (true)
		{
			cout << "Insert a number in the tree and 0 to show and -1 to exit: ";
			cin >> input;
			if (input == 0)
			{
				myT.Display(*myT.GetRoot());
			}
			else if (input == -1)
				break;
			else
			{
				myT.Insert(myT.GetRoot(), input);
			}
		}
	}
}