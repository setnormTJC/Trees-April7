#pragma once
#include <string>


struct TreeNode
{
	std::string dataOfInterest;
	TreeNode* left; 
	TreeNode* right; 
};

class BinaryTree
{
private: 


public: 
	/*Member variable************************/
	TreeNode* pRoot;

	/*Member FUNCTIONS************************/
	BinaryTree() = default; 
	BinaryTree(const std::string dataInTheRootNode);
	void addNode(const std::string& dataToAdd, TreeNode* pParent, bool isLeft); 


};

