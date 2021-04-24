#pragma once
#include <memory>
#include <iostream>

//this is an implementation of a linked list.  I have a few funcions which are self descripting,
//but there are comments explaining their internal process if needed.
//Diego F. Perez - 21SEP2020


template <class T>
class LinkedListNode
{
	//variable to store needed data
	T nodeData = T();

public:

	//creating two class pointers to traverse the list later on.
	//I used smart pointers to avoid memory leaks down the road.

	LinkedListNode<T>* nextNode;
	LinkedListNode<T>* previousNode;
	   
	LinkedListNode() 
	{
		nextNode = nullptr;
		previousNode = nullptr;
	}
	
	LinkedListNode(T data)
	{
		LinkedListNode();
		nodeData = data;
	}

	LinkedListNode<T>* findTail(); //returns the pointer to the last element
	LinkedListNode<T>* findHead(); // returns the pointer to the first element
	LinkedListNode<T>* findData(T); // returns the pointer to the first element with the desired value
	void pushFront(LinkedListNode<T>*); //allows the list to grow from the front
	void pushBack(LinkedListNode<T>*); //allows the list to grow from the back
	void insertNode(LinkedListNode<T>*); // inserts a node anywhere in the line;
	void removeNode(); //removes a node, except the head if the list is empty.
	void setData(T);
	T returnData() const;
	void sortList(); //sort the nodes according to value from low to high
	void rSortList(); //sort the nodes in reverse order
	void removeDuplicates();
	void appendList(LinkedListNode<T>&);


};

template<class T>
inline LinkedListNode<T>* LinkedListNode<T>::findTail()
{
	LinkedListNode<T>* tempNode = this;

	while (true)
	{
		if (tempNode->nextNode == nullptr)
			return tempNode;
		else
		{
			tempNode = tempNode->nextNode;
		}
	}
}

template<class T>
inline LinkedListNode<T>* LinkedListNode<T>::findHead()
{
	LinkedListNode<T>* tempNode = this;

	while (true)
	{
		if (tempNode->previousNode == nullptr)
			return tempNode;
		else
		{
			tempNode = tempNode->previousNode;
		}
	}
}

template<class T>
inline LinkedListNode<T>* LinkedListNode<T>::findData(T findThisValue)
{
	LinkedListNode<T>* tempNode = this->findHead();

	while (true)
	{
		if (tempNode->returnData() == findThisValue)
			return tempNode;

		else if (tempNode->nextNode == nullptr) // data was not found
			return nullptr;
			
		else
		{
			tempNode = tempNode->nextNode;
		}
	}

}

template<class T>
inline void LinkedListNode<T>::pushFront(LinkedListNode<T>* listObj)
{

	LinkedListNode<T>* head = this->findHead();

	head->previousNode = listObj;
	listObj->nextNode = head;


}

template<class T>
inline void LinkedListNode<T>::pushBack(LinkedListNode<T>*listObj)
{
	
	LinkedListNode<T>* tail = this->findTail();

	tail->nextNode = listObj;
	listObj->previousNode = tail;

}

template<class T>
inline void LinkedListNode<T>::insertNode(LinkedListNode<T>* node)
{
	this->nextNode = node;
	node->previousNode = this;

}


template<class T>
inline void LinkedListNode<T>::removeNode()
{
	T tempData = this->returnData();
	LinkedListNode<T>* tempNode = nullptr;


	// check if this node is the head, in between, or the tail and act accordingly. 

	//this method is can't be used to delete the list entirely.
	//If this is the head, but the list is not empty, print to console to let the programmer know what happened.
	if (this->previousNode == nullptr && this->nextNode == nullptr)
	{
		std::cout << "can't delete list with this method\n";
		exit(-1);
	}

	//if we are deleting the head, we go about it copying the data of the nextNode to the head, then removing the nextNode. 
	else if (this->previousNode == nullptr && this->nextNode != nullptr)
	{
		tempNode = this->nextNode;							//copying the next node for the time being
		this->setData(this->nextNode->returnData()); 		//copying value from the next node to this one;
		this->nextNode = this->nextNode->nextNode;		//copying the pointer of two nodes over
		std::free(tempNode);						//deleting what we dont need
	}

	//if not the head nor the tail		   
	else if (this->nextNode != nullptr && this->previousNode != nullptr)
	{
		this->nextNode->previousNode = this->previousNode;
		this->previousNode->nextNode = this->nextNode;
		std::free(this);
	}

	//if it is the tail
	else if (this->nextNode == nullptr && this->previousNode != nullptr)
	{
		this->previousNode->nextNode = nullptr;
		std::free(this);
	}
	//std::cout << "Node deleted " << tempData << std::endl;
}


template<class T>
inline void LinkedListNode<T>::setData(T data)
{
	this->nodeData = data;
}

template<class T>
inline T LinkedListNode<T>::returnData() const
{
	return this->nodeData;
}

template<class T>
inline void LinkedListNode<T>::sortList()
{
	int sortCount = 0;
	LinkedListNode<int>* temp = this;

	while (true)
	{
		//if we are in the last element, and the count didnt increase, exit the function.
		//this would be true for the head or tail.
		if (temp->nextNode == nullptr && sortCount == 0)
			return;

	

		//if this is the last element, and the count is not zero, reset count and and pointer, then go back to the beginning. 
		else if (temp->nextNode == nullptr && sortCount != 0)
		{
			sortCount = 0;
			temp = this;
			continue;
		}

		//if the other two conditions are not true, see if the data ahead is small than the current data	
		//then continue to evaluate again without having to move one step up.  
		else if (temp->returnData() > temp->nextNode->returnData())
		{
			std::swap(temp->nodeData, temp->nextNode->nodeData);
			++sortCount;
			continue;
		}

		temp = temp->nextNode;

	}

}

template<class T>
inline void LinkedListNode<T>::rSortList()
{
	int sortCount = 0;
	LinkedListNode<int>* temp = this;

	while (true)
	{
		//if we are in the last element, and the count didnt increase, exit the function.
		//this would be true for the head or tail.
		if (temp->nextNode == nullptr && sortCount == 0)
			return;



		//if this is the last element, and the count is not zero, reset count and and pointer, then go back to the beginning. 
		else if (temp->nextNode == nullptr && sortCount != 0)
		{
			sortCount = 0;
			temp = this;
			continue;
		}

		//if the other two conditions are not true, see if the data ahead is small than the current data	
		//then continue to evaluate again without having to move one step up.  
		else if (temp->returnData() < temp->nextNode->returnData())
		{
			std::swap(temp->nodeData, temp->nextNode->nodeData);
			++sortCount;
			continue;
		}

		temp = temp->nextNode;

	}
}

template<class T>
inline void LinkedListNode<T>::removeDuplicates()
{

	int removeCount = 0;
	LinkedListNode<int>* temp = this;

	while (true)
	{
		//if we are in the last element, and the count didnt increase, exit the function.
		//this would be true for the head or tail.
		if (temp->nextNode == nullptr && removeCount == 0)
			return;



		//if this is the last element, and the count is not zero, reset count and and pointer, then go back to the beginning. 
		else if (temp->nextNode == nullptr && removeCount != 0)
		{
			removeCount = 0;
			temp = this;
			continue;
		}

		//if the other two conditions are not true, see if the data ahead is small than the current data	
		//then continue to evaluate again without having to move one step up.  
		else if (temp->returnData() == temp->nextNode->returnData())
		{
			temp->nextNode->removeNode();
			++removeCount;
			continue;
		}

		temp = temp->nextNode;

	}
}

template<class T>
inline void LinkedListNode<T>::appendList(LinkedListNode<T> &nextList)
{
	//join the head and the tail
	this->findTail()->nextNode = nextList.findHead();
	nextList.findHead()->previousNode = this->findTail();

}

