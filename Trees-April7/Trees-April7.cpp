// Trees-April7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Tree.h"

int main()
{
	BinaryTree bt("root");

	bt.addNode("Left child data", bt.pRoot, true); 
	bt.addNode("Right child data", bt.pRoot, false); 


	//bt.pRoot->left->dataOfInterest = "left child of root";
	//bt.pRoot->left->left = nullptr; 

	//
	//bt.pRoot->right->dataOfInterest = "RIGHT child of root";


}

