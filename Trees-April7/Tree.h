#pragma once

#include<exception>
#include<sstream>
#include <string>


class MyException
{
	std::string message;
	std::string filename; 
	int lineNumber; 
public: 
	MyException() = delete; 
	MyException(const std::string message, const std::string& filename, const int lineNumber);
	//override std::exception's "what" method: 
	std::string what() const; 
};

class BinaryTreeNode
{
	std::string dataOfInterest;
	BinaryTreeNode* left; 
	BinaryTreeNode* right; 

	friend class BinaryTree;  //note the FRIEND keyword! (students haven't seen this in a while)

public: 
	BinaryTreeNode(const std::string& dataOfInterest, BinaryTreeNode* left, BinaryTreeNode* right);
};

class BinaryTree
{
private: 
	/*Member variable************************/
	BinaryTreeNode* pRoot;
	//int numberOfNodesInTree; //this COULD prove worth the space it occupies if insisting on non-recursive traversal 
public: 

	/*Member FUNCTIONS************************/
	BinaryTree() = default; 
	BinaryTree(const std::string dataInTheRootNode);

	BinaryTreeNode* getPRoot() const;

	/*preferentially adds to left - adds to the right if left is already occupied*/
	void addNode(const std::string& dataToAdd, BinaryTreeNode* pParent);

	/*NOTE: this does NOT work - just intended to demo the usefulness of recursion*/
	BinaryTreeNode* nonRecursiveFind(const std::string& dataToFind) const;
	/*a RECURSIVE function (more generally called "Depth-first search") @param pCurrent -> call with treeName.getPRoot()*/
	BinaryTreeNode* find(const std::string& dataToFind, BinaryTreeNode* pCurrent) const; 
	
};

