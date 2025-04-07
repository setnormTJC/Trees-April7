#include "Tree.h"

BinaryTree::BinaryTree(const std::string dataInTheRootNode)
{
	BinaryTree::pRoot = new TreeNode; 

	pRoot->dataOfInterest = dataInTheRootNode; 

	//EXPLICITLY set the left and the right to NULL (for now) 
	pRoot->left = nullptr; 
	pRoot->right = nullptr; 
}

void BinaryTree::addNode(const std::string& dataToAdd, TreeNode* pParent, bool isLeft)
{

	if (isLeft)
	{
		pParent->left = new TreeNode; 

		pParent->left->dataOfInterest = dataToAdd; 
	}

	else //isRightChild
	{
		pParent->right = new TreeNode;

		pParent->right->dataOfInterest = dataToAdd; 
	}
}
