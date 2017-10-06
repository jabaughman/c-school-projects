// IP5_Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <istream>
#include <string>
using namespace std;

struct Tree
{
	int data;
	Tree *left;
	Tree *right;
};

class btree {
public:
	btree();
	void insert(int data_h, string data_i, int data_j);
	Tree *search(int data_h, string data_i, int data_j);
	void destroy_tree();
private:
	void destroy_tree(Tree *leaf);
	void insert(int data_h, string data_i, int data_j, Tree *leaf);
	Tree *search(int data_h, string data_i, int data_j, Tree *leaf);
	Tree *root;
};

btree::btree()
{
	root = NULL;
}

void btree::destroy_tree(Tree *leaf)
{
	if (leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void btree::insert(int data_h, string data_i, int data_j, Tree *leaf)
{
	if (data_h < leaf->data)
	{
		if (leaf->left != NULL)
			insert(data_h, data_i, data_j, leaf->left);
		else
		{
			leaf->left = new Tree;
			leaf->left->data = data_h, data_i, data_j;
			leaf->left->left = NULL; //sets the left child of the child node to null
			leaf->left->right = NULL; //sets the right child of the child node to null
		}
	}
	else if (data_h >= leaf->data)
	{
		if (leaf->right != NULL)
			insert(data_h, data_i, data_j, leaf->right);
		else
		{
			leaf->right = new Tree;
			leaf->right->data = data_h, data_i, data_j;
			leaf->right->left = NULL; //sets the left child of the child node to null
			leaf->right->right = NULL; //sets the right child of the child node to null
		}
	}
}

Tree *btree::search(int data_h, string data_i, int data_j, Tree *leaf)
{
	if (leaf != NULL)
	{
		if (data_h == leaf->data)
			return leaf;
		if (data_h < leaf->data)
			return search(data_h, data_i, data_j, leaf->left);
		else
			return search(data_h, data_i, data_j, leaf->right);
	}
}

void btree::insert(int data_h, string data_i, int data_j)
{
	if (root != NULL)
		insert(data_h, data_i, data_j, root);
	else
	{
		root = new Tree;
		root->data = data_h, data_i, data_j;
		root->left = NULL;
		root->right = NULL;
	}
}

Tree *btree::search(int data_h, string data_i, int data_j)
{
	return search(data_h, data_i, data_j, root);
}

void btree::destroy_tree()
{
	destroy_tree(root);
}

int main()
{
	btree bt;
	int DataCode;
	string TitleData;
	int CostData;
	char choice;
	do
	{
		cout << "This is a Binary Tree" << endl;
		cout << "Select an Option;" << endl;
		cout << "A)    List Tree data" << endl;
		cout << "B)    Insert new data" << endl;
		cout << "C)    Delete data" << endl;
		cin >> choice;
		if (choice == 'A' || choice == 'a')
		{
			cout << "Code: ";
			cout << DataCode << " " << endl;
			cout << "Title: ";
			cout << TitleData << " " << endl;
			cout << "Price, in Dollars: ";
			cout << CostData << " " << endl;

		}
		else if (choice == 'B' || choice == 'b')
		{
			cout << "Input data code: ";
			cin >> DataCode;
			cout << "Input title to insert: ";
			cin >> TitleData;
			cout << "Input cost to insert: ";
			cin >> CostData;
			cout << endl;
			bt.insert(DataCode, TitleData, CostData);
		}
		else if (choice == 'C' || choice == 'c')
		{
			bt.destroy_tree();
		}
	} while (true);
};
