#include "TreeLogics.h"
#include <iostream>

int main()
{
	Node* root = nullptr;
	InsertNumber(root, 10);
	InsertNumber(root, 5);
	InsertNumber(root, 15);
	InsertNumber(root, 3);
	InsertNumber(root, 6);
	InsertNumber(root, 12);
	InsertNumber(root, 16);
	PrintTree(root);
	std::cout << std::endl << std::endl;
	DeleteNumber(root, 5);
	PrintTree(root);
	std::cout << std::endl << std::endl;
}
