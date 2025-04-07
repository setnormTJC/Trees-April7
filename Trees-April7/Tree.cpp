#include "Tree.h"
#include <iostream>

MyException::MyException(const std::string message, const std::string& filename, const int lineNumber)
	:message(message), filename(filename), lineNumber(lineNumber)
{
}

std::string MyException::what() const
{
	std::ostringstream fullErrorMessage;
	fullErrorMessage << message 
		<< "\nException thrown in file: " << filename 
		<< "\nOn line number: " << lineNumber << "\n";
	
	return fullErrorMessage.str(); 
}


BinaryTreeNode::BinaryTreeNode(const std::string& dataOfInterest, BinaryTreeNode* left, BinaryTreeNode* right)
	:dataOfInterest(dataOfInterest), left(left), right(right)
{
}

BinaryTree::BinaryTree(const std::string dataInTheRootNode)
{
	BinaryTree::pRoot = new BinaryTreeNode(dataInTheRootNode, nullptr, nullptr); 
}

BinaryTreeNode* BinaryTree::getPRoot() const
{
	return pRoot;
}


void BinaryTree::addNode(const std::string& dataToAdd, BinaryTreeNode* pParent)
{
	//safety check
	if (pParent == nullptr)
	{
		throw MyException("Cannot add to a parent that does not exist!", __FILE__, __LINE__);
	}

	if (pParent->left == nullptr)
	{
		pParent->left = new BinaryTreeNode(dataToAdd, nullptr, nullptr); 
	}

	else if (pParent-> right == nullptr)
	{
		pParent->right = new BinaryTreeNode(dataToAdd, nullptr, nullptr); 
	}

	else //both children nodes are already occupied 
	{
		throw MyException("That parent already has two children! No overwriting (or overpopulation?)",
			__FILE__, __LINE__);
	}
}

BinaryTreeNode* BinaryTree::nonRecursiveFind(const std::string& dataToFind) const
{
	//start the search at the root: 
	if (pRoot->dataOfInterest == dataToFind)
	{
		return pRoot;
	}
	//look left
	else if (pRoot->left->dataOfInterest == dataToFind)
	{
		return pRoot->left; 
	}

	/*look right*/
	else if (pRoot->right->dataOfInterest == dataToFind)
	{
		return pRoot->right; 
	}

	/*...look left, left*/
	else if (pRoot->left->left->dataOfInterest == dataToFind)
	{
		return pRoot->left->left;
	}

	/*etc. add nauseum (COULD keep track of number of nodes examined and loop while(nodeCount < totalNodes))*/
	
	
	else //not in the entire tree 
	{
		return nullptr; 
	}
}

BinaryTreeNode* BinaryTree::find(const std::string& dataToFind, BinaryTreeNode* pCurrent) const
{
	if (pCurrent == nullptr) return nullptr; //do NOT attempt to get `dataOfInterest` on nullptr!

	/*OPTIONAL print (For algo visualization)*/
	std::cout << "Visiting node containing: " << pCurrent->dataOfInterest << "\n";
	//base case:
	if (pCurrent->dataOfInterest == dataToFind) return pCurrent;

	else
	{
		//recursively look left and right
		auto pLeft = find(dataToFind, pCurrent->left);
		if (pLeft != nullptr) //if pLeft IS nullptr, then move on to the RIGHT child
		{
			return pLeft; 
		}

		auto pRight = find(dataToFind, pCurrent->right);
		if (pRight != nullptr)
		{
			return pRight; 
		}

		return nullptr; //only reached if data is not found 
	}
}


