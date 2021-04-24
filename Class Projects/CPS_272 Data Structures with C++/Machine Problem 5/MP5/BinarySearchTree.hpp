#pragma once

#include <string>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;


//struct to store data and point to other members.  It has three convenient constructors. 
struct Node
{
	Node *left, *right, *parent;
	string data;
	int height;
	
	Node() {
		parent = nullptr;
		left = nullptr;
		right = nullptr;
		data = "";
		height = 0;
		
	}

	Node(Node const* copyMeNode) {
		parent = copyMeNode->parent;
		left = copyMeNode->left;
		right = copyMeNode->right;
		data = copyMeNode->data;
		height = copyMeNode->height;
	}

	Node(string newData) {
		parent = nullptr;
		left = nullptr;
		right = nullptr;
		data = newData;
		height = 0;
	}

	bool isLeaf() {
		if (this->left == nullptr && this->right == nullptr)
			return true;
		else
			return false;
	}
	
	bool isEmpty() {
				
		return (data == "")? true : false;
	}

};


//This class will arrange element as a Binary Search Three (BST) and will store elements from the Node Class
 class BinarySearchTree
{
	Node* root = new Node;
	int maxHeight = 0;

public:
	void addData(string newData);	//uses the which way function to assign data
	void whichWay(Node *currentNode, string newData);
	void printTree() const;
	Node* top();		//returns root

	void preOrderTraverseNLR(Node* tempRoot, queue<Node*>& myQueue);//It puts the BST elements in the queue according to the traversal order
	void inOrderTraverseLNR(Node* tempRoot, queue<Node*>& myQueue);//It puts the BST elements in the queue according to the traversal order
	void postOrderTraverseLRN(Node* tempRoot, queue<Node*>& myQueue);//It puts the BST elements in the queue according to the traversal order
	void reverseOrderTraverseRNL(Node* tempRoot, queue<Node*>& myQueue);

	void levelOrderTraverse(Node* tempRoot, queue<Node*>& myQueue);
	
	void preOrderNewTree(BinarySearchTree&, Node*) const;
	void postOrderNewTree(BinarySearchTree&, Node*) const;
	void inOrderNewTree(BinarySearchTree&, Node*) const;


};









