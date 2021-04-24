#include "BinarySearchTree.hpp"

void BinarySearchTree::addData(string newData)
{//check if this node has not been initialized, and then set the new data to this node.  Otherwise, go left or right with the whichWay() function. 

	if (this->root->isEmpty() && this->root->parent == nullptr)
		root->data = newData;
	else
		whichWay(this->root, newData);
}


void BinarySearchTree::whichWay(Node* currentNode, string newData)
{//this function only gets called if the data stored in the root node is empty, which is done at the addData() function.

	//cout << "adding " << newData << endl;

	//Check if something slipped between the cracks
	if (currentNode->isEmpty())
		throw(logic_error("whichWay(Node<T> *currentNode, T newData) - Bad Function Call"));

	//Check which way to go and decide left or right.  If left or right are not nullptr, then go recursive
	if (newData < currentNode->data) {

		//cout << newData << '<' << currentNode->data << endl;

		if (currentNode->left == nullptr) {

			currentNode->left = new Node(newData);
			currentNode->left->parent = currentNode;
			currentNode->left->height = currentNode->height + 1;
			if (currentNode->left->height > this->maxHeight)
				this->maxHeight++;
		}
		else
			whichWay(currentNode->left, newData);

	}

	else if (newData >= currentNode->data) {

		if (currentNode->right == nullptr) {

			currentNode->right = new Node(newData);
			currentNode->right->parent = currentNode;
			currentNode->right->height = currentNode->height + 1;
			if (currentNode->right->height > this->maxHeight)
				this->maxHeight++;
		}
		else
			whichWay(currentNode->right, newData);
	}
}

void BinarySearchTree::printTree() const
{//There was a lot of thought into this function. Maybe there is an easier way.... This is level order traversal. 

	queue<Node*> myQ, myQ2;
	int currentHeight = 0;
	int count = 0;


	myQ.push(this->root);

	cout << "Level order traversal:\t";

	while (!myQ.empty()) {

		Node* temp = myQ.front();

		cout << temp->data << '\t';

		if (temp->left != nullptr)
			myQ.push(temp->left);

		if (temp->right != nullptr)
			myQ.push(temp->right);

		myQ2.push(myQ.front()); //We could had printed right away, but I wanted to keep the pointers for printing nicer.  
		myQ.pop();
	}


	cout << "\n\nHeights and leafs (*): " << endl;

	cout << "\nHeight: " << currentHeight << "\t";

	for (int i = 0, j = myQ2.size(); i < j; i++)
	{
		if (!myQ2.front()->isEmpty()) {

			if (myQ2.front()->height > currentHeight) {
				currentHeight++;
				cout << "\nHeight: " << currentHeight << "  ";
			}
			cout << setw(15) << right << (myQ2.front()->isLeaf() ? "*" : "") + myQ2.front()->data << '\t';
		}
		if (myQ2.front()->isLeaf())
			count++;
		myQ2.pop();
	}

	cout << "\n\nNumber of leafs : " << count << endl;
	
}

Node* BinarySearchTree::top()
{
	return root;
}


void BinarySearchTree::preOrderTraverseNLR(Node* tempRoot, queue<Node*> &myQueue) {

	if (tempRoot == nullptr)
		return;
	else
	{
		//cout << "preOrderCall =>\t" << tempRoot->data << '\n';
		myQueue.push(tempRoot);							//N
		preOrderTraverseNLR(tempRoot->left, myQueue);	//L
		preOrderTraverseNLR(tempRoot->right, myQueue);	//R
	}

}

void BinarySearchTree::inOrderTraverseLNR(Node* tempRoot, queue<Node*>& myQueue) {

	if (tempRoot == nullptr)
		return;
	else
	{
		inOrderTraverseLNR(tempRoot->left, myQueue);	//L
		myQueue.push(tempRoot);							//N
		inOrderTraverseLNR(tempRoot->right, myQueue);	//R
	}


}

void BinarySearchTree::postOrderTraverseLRN(Node* tempRoot, queue<Node*>& myQueue) {


	if (tempRoot == nullptr)
		return;
	else
	{
		postOrderTraverseLRN(tempRoot->left, myQueue);	//L
		postOrderTraverseLRN(tempRoot->right, myQueue);	//R
		myQueue.push(tempRoot);							//N
	}

}

void BinarySearchTree::reverseOrderTraverseRNL(Node* tempRoot, queue<Node*>& myQueue) {


	if (tempRoot == nullptr)
		return;
	else
	{
		reverseOrderTraverseRNL(tempRoot->right, myQueue);	//R
		myQueue.push(tempRoot);								//N
		reverseOrderTraverseRNL(tempRoot->left, myQueue);	//L
		
		
	}

}

void BinarySearchTree::levelOrderTraverse(Node* tempRoot, queue<Node*>& myQueue) {

	queue<Node*> myQ;

	myQ.push(this->root);

	while (!myQ.empty()) {

		Node* temp = myQ.front();

		cout << temp->data << '\t';

		if (temp->left != nullptr)
			myQ.push(temp->left);

		if (temp->right != nullptr)
			myQ.push(temp->right);

		myQueue.push(myQ.front()); 
		myQ.pop();
	}

}




void BinarySearchTree::preOrderNewTree(BinarySearchTree& newTree, Node* tempRoot) const
{
	if (tempRoot == nullptr)
		return;
	else
	{
		newTree.addData(tempRoot->data);
		preOrderNewTree(newTree, tempRoot->left);
		preOrderNewTree(newTree, tempRoot->right);
	}
}

void BinarySearchTree::postOrderNewTree(BinarySearchTree& newTree, Node* tempRoot) const
{
	if (tempRoot == nullptr)
		return;
	else
	{
		
		postOrderNewTree(newTree, tempRoot->left);
		postOrderNewTree(newTree, tempRoot->right);
		newTree.addData(tempRoot->data);
	}


}

void BinarySearchTree::inOrderNewTree(BinarySearchTree& newTree, Node* tempRoot) const
{
	if (tempRoot == nullptr)
		return;
	else
	{
		
		inOrderNewTree(newTree, tempRoot->left);
		newTree.addData(tempRoot->data);
		inOrderNewTree(newTree, tempRoot->right);
	}

}
