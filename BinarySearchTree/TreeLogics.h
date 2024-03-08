#pragma once

struct Node
{
	int value;
	Node* right;
	Node* left;
};

Node* CreateNode(int number);
void InsertNumber(Node*& root, int number);
void PrintTree(Node* root);
Node* FindNumber(Node* root, int number);
Node* DeleteNumber(Node* root, int number);
