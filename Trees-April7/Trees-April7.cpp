// Trees-April7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Tree.h"

void demoDepthFirstSearch()
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


int main()
{
	//demoDepthFirstSearch(); 

	//std::cout << "Any key to continue\n";
	//std::cin.get(); 

	try
	{

		BinaryTree bt("root");

		bt.addNode("left", bt.getPRoot());
		bt.addNode("right", bt.getPRoot());

		//bt.addNode("THIRD child???", bt.getPRoot()); //throws!

		auto pRoot = bt.getPRoot(); 

		auto rootLoc = bt.find("root", pRoot); 
		auto leftLoc = bt.find("left", pRoot); 
		auto rightLoc = bt.find("right", pRoot);

		auto rightRightLoc = bt.find("right, right", pRoot);
		if (rightRightLoc == nullptr) std::cout << "right, right not found\n";

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

