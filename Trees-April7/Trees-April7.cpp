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

	bt.addNode("right, left", rightLoc);


	auto rightRightLoc = bt.find("right, left", pRoot);
	if (rightRightLoc == nullptr) std::cout << "right, left not found\n";
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

	std::cout << "Searching for \"right\"...\n";
	std::cout << "The stuff that gets printed after this should make it clear why the term \"depth first \" is used:\n";

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

void demoPersona5SkillTree()
{
	N_AryTree jokerSkillTree("Joker's root");  //from P5 (from Atlus)

	auto pJokerRoot = jokerSkillTree.getRoot();
	//add persona "Arsène" (note the accented 'e')
	jokerSkillTree.addNode(pJokerRoot, "Arsene persona");

	auto pArsene = jokerSkillTree.bfs("Arsene persona"); //get Arsène's address so he can have "children" (AKA: skills)
	//add skills to persona "Arsène":
	jokerSkillTree.addNode(pArsene, "Cleave");
	jokerSkillTree.addNode(pArsene, "Sukunda");
	jokerSkillTree.addNode(pArsene, "Dream Needle");


	//Now add persona "Alice": 
	jokerSkillTree.addNode(pJokerRoot, "Alice");
	auto pAlice = jokerSkillTree.bfs("Alice");

	jokerSkillTree.addNode(pAlice, "Mamudoon");
	jokerSkillTree.addNode(pAlice, "Dekunda");
	jokerSkillTree.addNode(pAlice, "Die for me!");
	jokerSkillTree.addNode(pAlice, "Megidolaon");
	jokerSkillTree.addNode(pAlice, "Concentrate");

	std::cout << "Ro?\n";

}

int main()
{
	try
	{
		N_AryTree videoGameTree("root of the tree");


		auto pRoot = videoGameTree.getRoot();

		/*Level 1 of the tree is GENRES*/
		videoGameTree.addNode(pRoot, "RPG");
		videoGameTree.addNode(pRoot, "FPS");
		videoGameTree.addNode(pRoot, "Sports");

		/*Level 2 of the (n-ary) tree is examples in the genres given above*/

		auto pRPG = videoGameTree.bfs("RPG");
		videoGameTree.addNode(pRPG, "Final Fantasy X");

		videoGameTree.addNode(pRPG, "Persona 5");

		//let's add children to "FPS" genre
		auto pFPS = videoGameTree.bfs("FPS");
		videoGameTree.addNode(pFPS, "Call of Duty - the bro's game");
		videoGameTree.addNode(pFPS, "Halo"); 

		auto pSports = videoGameTree.bfs("Sports");
		videoGameTree.addNode(pSports, "NBA 2K");
		videoGameTree.addNode(pSports, "FIFA something or other");


		//is the ROOT of this tree a LEAF? 
		std::cout << std::boolalpha; 
		std::cout << "Is Root a leaf?\n" << videoGameTree.isLeaf(pRoot) << "\n";

		auto pNBA2K = videoGameTree.bfs("NBA 2K");
		std::cout << "Is NBA 2K a leaf? " << videoGameTree.isLeaf(pNBA2K) << "\n";

		//let's print all of the LEAF nodes (which are all game titles) 
		std::cout << "\n\n";
		videoGameTree.bfs("adsfasfasdfasdf"); //this is NOT in the tree -> this FORCES complete traversal 
		
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

