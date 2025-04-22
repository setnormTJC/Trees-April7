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

	//auto rootLoc = bt.find("root", pRoot);
	//auto leftLoc = bt.find("left", pRoot);
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

	if (pGibberish != nullptr)
	{
		std::cout << "Found the gibberish\n";
	}
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

	std::cout << "\n\n\n"
		<<"Beginning the search for gibberish text -  below, we should ONLY see SKILLS\n";
	

	std::string thingToSearchTreeFor = "asdfasdfasd";

	jokerSkillTree.bfs(thingToSearchTreeFor);

}

/*This is an n-ary tree*/
void demoVideoGameGenreTree()
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

/*as in : https://finalfantasy.fandom.com/wiki/Final_Fantasy_VII_battle_system?file=Yuffie_Encounter.jpg*/
void demoFF7ActionTree()
{
	N_AryTree partyTree("party root");

	auto pRoot = partyTree.getRoot(); 

	partyTree.addNode(pRoot, "Cloud");
	partyTree.addNode(pRoot, "Tifa");
	partyTree.addNode(pRoot, "Red XIII");

	//auto pCloud = partyTree.bfs("cloud"); //NULLPTR! (-1 if this were an array)
	auto pCloud = partyTree.bfs("Cloud");

	partyTree.addNode(pCloud, "Items"); 
	partyTree.addNode(pCloud, "Magic");

	//add item and magic to Tifa and Red XIII: 
	N_AryTreeNode* pTifa = partyTree.bfs("Tifa");
	partyTree.addNode(pTifa, "Items");
	//NOTE! Items are SHARED among characters, so this would be better implemented with 
	//a GRAPH data structure! 
	partyTree.addNode(pTifa, "Magic");

	auto pRed = partyTree.bfs("Red XIII");
	partyTree.addNode(pRed, "Items");
	partyTree.addNode(pRed, "Magic");

	std::cout << "Is Magicka a LEAF node? \n"; 
	std::cout << std::boolalpha; 
	auto pMagic = partyTree.bfs("Magic");
	std::cout << partyTree.isLeaf(pMagic) << "\n";

	std::cout << "What about the ROOT node? " << partyTree.isLeaf(pRoot) << "\n";

}

void demoBinarySearchTree()
{
	BinarySearchTree bst("Darth");

	std::vector<std::string> namesToInsertIntoBST =
	{
		"Alice", "Bob", "Carol", "Frank", "Eve", "Aaaah!", "Alice" //NOTE the second "Alice"
	};

	auto pRoot = bst.getPRoot();

	for (const std::string& currentName : namesToInsertIntoBST)
		bst.addBSTNode(currentName, pRoot); //NOTE: the return value of this fn is ignored (it will always be pRoot)

	std::string gibberishSearchValue = "124sdvjksdldkd";

	std::cout << "BREADTH-first search yields: \n";
	bst.find_withBFS(gibberishSearchValue);

	std::cout << "\n\nDEPTH-first search yields: \n";
	bst.find(gibberishSearchValue, pRoot);
}

void demoNodeDepth_andTreeHeight()
{
	BinarySearchTree bst("Darth");

	std::vector<std::string> namesToInsertIntoBST =
	{
		"Alice", "Bob", "Carol", "Frank", "Eve", "Aaaah!", "Alice" //NOTE the second "Alice"
	};

	auto pRoot = bst.getPRoot();

	for (const std::string& currentName : namesToInsertIntoBST)
		bst.addBSTNode(currentName, pRoot); //NOTE: the return value of this fn is ignored (it will always be pRoot)

	int startingDepth = 0; 
	//bst.printNodeDepth("Darth", pRoot, startingDepth);

	//bst.printNodeDepth("Alice", pRoot, startingDepth); //should have depth = 1

	//bst.printNodeDepth("Frank", pRoot, startingDepth); //should also have depth = 1

	std::string valueToSearchFor = "Darth";
	int depth = bst.getNodeDepth(valueToSearchFor, pRoot, startingDepth); 

	std::cout << "Depth of " << valueToSearchFor << ": " << depth << "\n";

	std::cout << "Overall tree height: " << bst.getTreeHeight() << "\n";
}

/*BST being "skewed" can result in WORST-case searching efficiency*/
void demoSkewedBST_andSearch()
{
	std::vector<std::string> orderedStrings = { "bravo", "charlie", "delta", "echo", "foxtrot"};

	BinarySearchTree bst("alpha");
	auto pRoot = bst.getPRoot(); 

	for (const std::string& currentString : orderedStrings)
		bst.addBSTNode(currentString, pRoot);
		
	std::cout << "Tree height: " << bst.getTreeHeight() << "\n";

	std::string valueToSearchFor = "charlie"; //near WORST case search value (WORST is not being in the tree at all)
	std::cout << "\n\nSearching for " << valueToSearchFor << " required this many comparisons: "
		<< bst.searchBST(valueToSearchFor) << "\n\n";
}


int main()
{
	try
	{
		demoBinarySearchTree(); 
		//demoNodeDepth_andTreeHeight(); 
		//demoSkewedBST_andSearch(); 
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

