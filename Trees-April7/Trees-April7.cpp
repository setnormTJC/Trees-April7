// Trees-April7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Tree.h"
#include <vector>

#include<filesystem>


/*Intended to be a simple first "tree-planting" exercise*/
void firstDemo()
{
	BinaryTree bt("root");

	bt.addNode("left", bt.getPRoot());
	bt.addNode("right", bt.getPRoot());

	//bt.addNode("THIRD child???", bt.getPRoot()); //throws!

	auto pRoot = bt.getPRoot();

	auto rootLoc = bt.find("root", pRoot);
	auto leftLoc = bt.find("left", pRoot);
	auto rightLoc = bt.find("right", pRoot);

	bt.addNode("right, right", rightLoc);


	auto rightRightLoc = bt.find("right, right", pRoot);
	if (rightRightLoc == nullptr) std::cout << "right, right not found\n";
}

/*Intending to convey the DEPTH in the "Depth-first search"*/
void secondDemo()
{
	BinaryTree skewedBT("root"); 
	auto pRoot = skewedBT.getPRoot(); 

	skewedBT.addNode("left", pRoot);
	skewedBT.addNode("right", pRoot);

	/*Now add a few more levels to the left ONLY (to illustrate "DEPTH" first search)*/
	auto pLeft = skewedBT.find("left", pRoot);
	skewedBT.addNode("left, left", pLeft); 

	auto pLeftLeft = skewedBT.find("left, left", pRoot); 
	skewedBT.addNode("left, left, left", pLeftLeft);

	std::cout << "\n\n\nSearching now for \"right\"\n";
	auto pRight = skewedBT.find("right", pRoot);

	if (pRight != nullptr) std::cout << "\n\nRight was FOUND\n";
	else std::cout << "\n\nRight was NOT found\n";

}

void thirdDemo()
{
	BinaryTree bt("root"); //not to be confused with "Beached Thing" from Death Stranding
	auto pRoot = bt.getPRoot();

	bt.addNode("left", pRoot);
	bt.addNode("right", pRoot);

	auto pLeft = bt.find_withBFS("left");
	//add two children to left node (note: BinaryTree::addNode will do safety check for pLeft != nullptr)
	bt.addNode("left, left", pLeft);
	bt.addNode("left, right", pLeft);

	//now add a (right) child to right: 
	auto pRight = bt.find_withBFS("right");
	bt.addNode("right, left", pRight);

	/*ATTEMPT to find a node value that does not exist*/
	auto pGibberish = bt.find_withBFS("adfsadfasdf");
}


int main()
{
	try
	{
		//secondDemo(); 
		thirdDemo(); 
	}

	catch (const MyException& e)
	{
		std::cout << e.what() << "\n";
	}

	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}

}

