#include "Tree.h"
#include <iostream>
#include <queue>

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
	:contents(dataOfInterest), pLeft(left), pRight(right)
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

	if (pParent->pLeft == nullptr)
	{
		pParent->pLeft = new BinaryTreeNode(dataToAdd, nullptr, nullptr); 
	}

	else if (pParent-> pRight == nullptr)
	{
		pParent->pRight = new BinaryTreeNode(dataToAdd, nullptr, nullptr); 
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
	if (pRoot->contents == dataToFind)
	{
		return pRoot;
	}
	//look left
	else if (pRoot->pLeft->contents == dataToFind)
	{
		return pRoot->pLeft; 
	}

	/*look right*/
	else if (pRoot->pRight->contents == dataToFind)
	{
		return pRoot->pRight; 
	}

	/*...look left, left*/
	else if (pRoot->pLeft->pLeft->contents == dataToFind)
	{
		return pRoot->pLeft->pLeft;
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
	std::cout << "Visiting node containing: " << pCurrent->contents << "\n";
	//base case:
	if (pCurrent->contents == dataToFind) return pCurrent;

	else
	{
		//recursively look left and right
		auto pLeft = find(dataToFind, pCurrent->pLeft);
		if (pLeft != nullptr) //if pLeft IS nullptr, then move on to the RIGHT child
		{
			return pLeft; 
		}

		auto pRight = find(dataToFind, pCurrent->pRight);
		if (pRight != nullptr)
		{
			return pRight; 
		}

		return nullptr; //only reached if data is not found 
	}
}

BinaryTreeNode* BinaryTree::find_withBFS(const std::string& dataToFind) const
{
	//use a queue to hold all existing children nodes: 
	std::queue<BinaryTreeNode*> nodeQueue; 
	
	//first, insert ROOT: 
	nodeQueue.push(pRoot);

	//loop while nodeQueue is not empty (it will ONLY become empty if we SCAN the entire tree and do NOT find target)
	while (nodeQueue.empty() == false)
	{
		//get node at front: 
		auto pCurrentParent = nodeQueue.front(); 

		std::cout << "Visiting our dear friend: " << pCurrentParent->contents << "\n";

		//check if it contains the target value: 
		if (pCurrentParent->contents == dataToFind) return pCurrentParent;

		//remove the current front node (and move onto the next node in the next loop iteration): 
		nodeQueue.pop(); 

		//push left and right child into the queue (if they exist): 
		if (pCurrentParent->pLeft != nullptr) nodeQueue.push(pCurrentParent->pLeft);
		if (pCurrentParent->pRight != nullptr) nodeQueue.push(pCurrentParent->pRight);	
	}

	std::cout << dataToFind << " was NOT found in the tree.\n";
	return nullptr; 
}

void BinaryTree::printNodeDepth(const std::string dataToFind, BinaryTreeNode* pCurrent, int& currentDepth)
{
	if (pCurrent == nullptr)
		return; //avoid dereferencing nullptr

	if (pCurrent->contents == dataToFind) //base case
		std::cout << "Found " << dataToFind << " at depth = " << currentDepth << "\n";
	
	else //look left and right
	{
		currentDepth = currentDepth + 1; 
		printNodeDepth(dataToFind, pCurrent->pLeft, currentDepth);
		currentDepth = currentDepth - 1; 
		printNodeDepth(dataToFind, pCurrent->pRight, currentDepth);
	}
}

N_AryTree::N_AryTree(const std::string& valueInRoot)
{
	pRoot = new N_AryTreeNode(valueInRoot, {});//using empty vector to indicate ZERO children initially
}

N_AryTreeNode* N_AryTree::getRoot()
{
	return pRoot; 
}

N_AryTreeNode* N_AryTree::bfs(const std::string& valueToFind)
{
	std::queue<N_AryTreeNode*> q; 

	q.push(pRoot); 

	while (!q.empty())
	{
		auto pFront = q.front(); 

		//std::cout << "Visiting the node containing\n";
		// 
		if (this->isLeaf(pFront))
		{
			std::cout << pFront->contents << "\n";
		}


		if (pFront->contents == valueToFind)
			return pFront; 

		for (size_t i = 0; i < pFront->childrenLinks.size(); ++i)
			q.push(pFront->childrenLinks.at(i));

		q.pop(); 
	}

	std::cout << valueToFind << " not found in tree!\n";
	return nullptr; 
}

void N_AryTree::addNode(N_AryTreeNode* pParent, const std::string& valueToAdd)
{
	if (pParent == nullptr)
		throw MyException("Cannot add to a parent that does not exist!\n", __FILE__, __LINE__);

	auto newNode = new N_AryTreeNode(valueToAdd, {}); //as in the constructor, {} means no children initially

	pParent->childrenLinks.push_back(newNode);

	//return newNode; //one possible approach
	
}

bool N_AryTree::isLeaf(N_AryTreeNode* pNode)
{
	return (pNode->childrenLinks.size() == 0);
}

BinarySearchTree::BinarySearchTree(const std::string dataInTheRootNode)
	:BinaryTree(dataInTheRootNode)
{

}

BinaryTreeNode* BinarySearchTree::addBSTNode(const std::string& dataToAdd, BinaryTreeNode* pParent)
{
	if (pParent == nullptr) //base case
	{
		pParent = new BinaryTreeNode(dataToAdd, nullptr, nullptr);
		return pParent;
	}

	else
	{
		if (dataToAdd < pParent->contents)
			pParent->pLeft = addBSTNode(dataToAdd, pParent->pLeft);

		else if (dataToAdd > pParent->contents)
			pParent->pRight = addBSTNode(dataToAdd, pParent->pRight);
		//do NOTHING if dataToAdd == pParent-contents
		return pParent;
	}
}

N_AryTreeNode::N_AryTreeNode(const std::string& contents, const std::vector<N_AryTreeNode*>& childrenLinks)

	:contents(contents), childrenLinks(childrenLinks)
{

}
