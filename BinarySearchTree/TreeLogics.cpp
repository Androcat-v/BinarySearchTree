#include <iostream>
#include "TreeLogics.h"
#include "Readers.h"

Node* CreateNode(int number)
{
	Node* newNode = new Node;
	newNode->value = number;
	newNode->right = nullptr;
	newNode->left = nullptr;
	return newNode;
}

void InsertNumber(Node*& root, int number)
{
	if (root == nullptr)
	{
		root = CreateNode(number);
		return;
	}
	else if (number < root->value)
	{
		if (root->left == nullptr)
		{
			root->left = CreateNode(number);
			return;
		}
		else
		{
			InsertNumber(root->left, number);
		}
	}
	else if (number > root->value)
	{
		if (root->right == nullptr)
		{
			root->right = CreateNode(number);
			return;
		}
		else
		{
			InsertNumber(root->right, number);
		}
	}
}

void PrintTree(Node* root)
{
	if (root != nullptr)
	{
		std::cout << root->value << "  ";
		PrintTree(root->left);
		PrintTree(root->right);
	}
}

Node* FindNumber(Node* root, int number)
{
	if (root->value == number)
	{
		return root;
	}
	else if (root->value < number)
	{
		FindNumber(root->left, number);
	}
	else if (root->value > number)
	{
		FindNumber(root->right, number);
	}
	else if (root == nullptr)
	{
		return 0;
	}
}

Node* DeleteNumber(Node* root, int number)
{
	if (root == nullptr)
		return root;

	if (root->value > number)
	{
		root->left = DeleteNumber(root->left, number);
		return root;
	}
	else if (root->value < number)
	{
		root->right = DeleteNumber(root->right, number);
		return root;
	}

	if (root->left == nullptr)
	{
		Node* temp = root->right;
		delete root;
		return temp;
	}
	else if (root->right == nullptr)
	{
		Node* temp = root->left;
		delete root;
		return temp;
	}
	else
	{
		Node* parent = root;
		Node* child = root->right;
		while (child->left != nullptr) {
			parent = child;
			child = child->left;
		}

		if (parent != root)
		{
			parent->left = child->right;
		}
		else
		{
			parent->right = child->right;
		}

		root->value = child->value;

		delete child;
		return root;
	}
}
