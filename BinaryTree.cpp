#include <iostream>
#include <string>
using namespace std;

struct Tree
{
	char data;
	Tree *left;
	Tree *right;
};

class btree {
public:
	btree();
	void insert(char data_i);
	Tree *search(char data_i);
	void destroy_tree();
private:
	void destroy_tree(Tree *leaf);
	void insert(char data_i, Tree *leaf);
	Tree *search(char data_i, Tree *leaf);
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

void btree::insert(char data_i, Tree *leaf)
{
	if (data_i < leaf->data)
	{
		if (leaf->left != NULL)
			insert(data_i, leaf->left);
		else
		{
			leaf->left = new Tree;
			leaf->left->data = data_i;
			leaf->left->left = NULL; //sets the left child of the child node to null
			leaf->left->right = NULL; //sets the right child of the child node to null
		}
	}
	else if (data_i >= leaf->data)
	{
		if (leaf->right != NULL)
			insert(data_i, leaf->right);
		else
		{
			leaf->right = new Tree;
			leaf->right->data = data_i;
			leaf->right->left = NULL; //sets the left child of the child node to null
			leaf->right->right = NULL; //sets the right child of the child node to null
		}
	}
}

Tree *btree::search(char data_i, Tree *leaf)
{
	if (leaf != NULL)
	{
		if (data_i == leaf->data)
			return leaf;
		if (data_i < leaf->data)
			return search(data_i, leaf->left);
		else
			return search(data_i, leaf->right);
	}
}

void btree::insert(char data_i) 
{
	if (root != NULL)
		insert(data_i, root);
	else
	{
		root = new Tree;
		root->data = data_i;
		root->left = NULL;
		root->right = NULL;
	}
}

Tree *btree::search(char data_i)
{
	return search(data_i, root);
}

void btree::destroy_tree()
{
	destroy_tree(root);
}

int main()
{
	cout << "Hello World" << endl;
};
