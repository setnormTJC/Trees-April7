#pragma once

#include<exception>
#include<sstream>
#include <string>
#include <vector>

#pragma warning (push)
#pragma warning (disable: 4820)

class MyException
{
	std::string message;
	std::string filename;
	int lineNumber;
public: 
	MyException() = delete; 
	MyException(const std::string message, const std::string& filename, const int lineNumber);
	std::string what() const; 
};
#pragma warning(pop)  

class BinaryTreeNode
{
	std::string contents;
	BinaryTreeNode* pLeft; 
	BinaryTreeNode* pRight; 

	friend class BinaryTree;  //note the FRIEND keyword! (students haven't seen this in a while)
	friend class BinarySearchTree; 

public: 
	BinaryTreeNode(const std::string& dataOfInterest, BinaryTreeNode* left, BinaryTreeNode* right);
};

class BinaryTree
{
protected: //protected gives access to CHILLUNS
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

	/*BFS means BREADTH-first search (the recursive find is DEPTH-first search)*/
	BinaryTreeNode* find_withBFS(const std::string& dataToFind) const;

	/*A nice other example of recursion*/
	//int getHeight(); //does this need parameters? 
};

/*Overrides its parent's `addNode` function*/
class BinarySearchTree : public BinaryTree
{
public: 

	BinarySearchTree(const std::string dataInTheRootNode);

	/*
	* NOTE: this function ASSUMES no duplicate node value is inserted!
	@param dataToAdd -> if LESS than parent node, insert to the LEFT, else insert to the RIGHT*/
	BinaryTreeNode* addBSTNode(const std::string& dataToAdd, BinaryTreeNode* pParent);
};


class N_AryTreeNode
{
	std::string contents; 
	std::vector<N_AryTreeNode*> childrenLinks; 

	friend class N_AryTree;

public: 
	N_AryTreeNode(const std::string& contents, const std::vector<N_AryTreeNode*>& childrenLinks);
};

class N_AryTree
{
	
	N_AryTreeNode* pRoot; 

public: 
	N_AryTree() = delete; 
	N_AryTree(const std::string& valueInRoot); 


	N_AryTreeNode* getRoot(); 

	/*breadth-first search*/
	N_AryTreeNode* bfs(const std::string& valueToFind);

	void addNode(N_AryTreeNode* pParent, const std::string& valueToAdd);

	bool isLeaf(N_AryTreeNode* pNode);
};