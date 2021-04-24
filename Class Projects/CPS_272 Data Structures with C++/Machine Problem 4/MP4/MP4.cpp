//Hello!
//
//This program was created from some starter code. My job was to get the program to work and show that I understand the implementation of the Hash structure.
//There are a couple of added functions right above main(), meant to help me with my part of the code.
//The program will throw an exception if the file does not have the right format. What good is a user name without the password?
//I didn't create a header file because it was instructed that all of this is in the same cpp file.
//
//I hope you like my program!
//
//Diego F.Perez	CPS 272, 22OOCT2020
//





//--------------------------------------------------------------------
//
//                            listlnk.h
//
//--------------------------------------------------------------------
#pragma warning( disable : 4290 )
#include <stdexcept>
#include <new>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

template < class T >         // Forward declaration of the List class
class List;

//************this class will store the data, and it's pointer will point to the next node in the list. 
template < class T >
class ListNode                // Facilitator class for the List class
{
private:

	ListNode(const T& nodeData, ListNode* nextPtr);
	T dataItem;      // List data item
	ListNode* next;   // Pointer to the next list node

	friend class List<T>;
};

//--------------------------------------------------------------------


//**************
template < class T >
class List
{
public:

	List(int ignored = 0);
	~List();
	void insert(const T& newData) throw (bad_alloc);        // Insert after cursor
	void remove() throw (logic_error);                      // Remove data item
	void replace(const T& newData)  throw (logic_error);    // Replace data item
	void clear();

	bool isEmpty() const;
	bool isFull() const;

	// List iteration operations
	void gotoBeginning()   throw (logic_error);
	void gotoEnd()  throw (logic_error);
	bool gotoNext();
	bool gotoPrior();
	T getCursor() const throw (logic_error);                   // Return item
	void showStructure() const;
	void moveToBeginning() throw (logic_error);                    // Move to beginning
	void insertBefore(const T& newElement)  throw (bad_alloc);  // Insert before cursor

private:
	ListNode<T>* head,     // Pointer to the beginning of the list
		* cursor;   // Cursor pointer
};

//--------------------------------------------------------------------
//
//                          listlnk.cpp
//
//--------------------------------------------------------------------

template < class T >
ListNode<T>::ListNode(const T& nodeDataItem, ListNode<T>* nextPtr) : dataItem(nodeDataItem), next(nextPtr)
{}

//--------------------------------------------------------------------

template < class T >
List<T>::List(int ignored) : head(0), cursor(0)
{}

//--------------------------------------------------------------------

template < class T >
List<T>:: ~List()
{
	clear();
}

//--------------------------------------------------------------------

template < class T >
void List<T>::insert(const T& newDataItem) throw (bad_alloc)
{
	if (head == 0)             // Empty list
	{
		head = new ListNode<T>(newDataItem, 0);
		cursor = head;
	}
	else                         // After cursor
	{
		cursor->next = new ListNode<T>(newDataItem, cursor->next);
		cursor = cursor->next;
	}
}

//--------------------------------------------------------------------

template < class T >
void List<T>::remove() throw (logic_error)
{
	ListNode<T>* p,   // Pointer to removed node
		* q;   // Pointer to prior node

			  // Requires that the list is not empty
	if (head == 0)
		throw logic_error("list is empty");

	if (cursor == head)             // Remove first item
	{
		p = head;
		head = head->next;
		cursor = head;
	}
	else if (cursor->next != 0)     // Remove middle item
	{
		p = cursor->next;
		cursor->dataItem = p->dataItem;
		cursor->next = p->next;
	}
	else                              // Remove last item
	{
		p = cursor;
		for (q = head; q->next != cursor; q = q->next)
			;
		q->next = 0;
		cursor = head;
	}

	delete p;
}

//--------------------------------------------------------------------

template < class T >
void List<T>::replace(const T& newDataItem) throw (logic_error)
{
	if (head == 0)
		throw logic_error("list is empty");

	cursor->dataItem = newDataItem;
}

//--------------------------------------------------------------------

template < class T >
void List<T>::clear()
{
	ListNode<T>* p,      // Points to successive nodes
		* nextP;                  // Points to next node
	p = head;
	while (p != 0)
	{
		nextP = p->next;
		delete p;
		p = nextP;
	}

	head = 0;
	cursor = 0;
}

//--------------------------------------------------------------------

template < class T >
bool List<T>::isEmpty() const
{
	return (head == 0);
}
//--------------------------------------------------------------------

template < class T >
bool List<T>::isFull() const
{
	T testDataItem;
	ListNode<T>* p;

	try
	{
		p = new ListNode<T>(testDataItem, 0);
	}
	catch (bad_alloc)
	{
		return true;
	}

	delete p;
	return false;
}

//--------------------------------------------------------------------

template < class T >
void List<T>::gotoBeginning() throw (logic_error)
{
	if (head != 0)
		cursor = head;
	else
		throw logic_error("list is empty");
}

//--------------------------------------------------------------------

template < class T >
void List<T>::gotoEnd() throw (logic_error)
{
	if (head != 0)
		for (; cursor->next != 0; cursor = cursor->next)
			;
	else
		throw logic_error("list is empty");
}

//--------------------------------------------------------------------

template < class T >
bool List<T>::gotoNext()
{
	bool result;   // Result returned

	if (cursor->next != 0)
	{
		cursor = cursor->next;
		result = true;
	}
	else
		result = false;

	return result;
}

//--------------------------------------------------------------------

template < class T >
bool List<T>::gotoPrior()

// If the cursor is not at the beginning of a list, then moves the
// cursor to the preceeding item in the list and returns 1.
// Otherwise, returns 0.

{
	ListNode<T>* p;   // Pointer to prior node
	int result;        // Result returned

	if (cursor != head)
	{
		for (p = head; p->next != cursor; p = p->next)
			;
		cursor = p;
		result = true;
	}
	else
		result = false;

	return result;
}

//--------------------------------------------------------------------

template < class T >
T List<T>::getCursor() const throw (logic_error)
{
	if (head == 0)
		throw logic_error("list is empty");

	return cursor->dataItem;
}

//--------------------------------------------------------------------

template < class T >
void List<T>::showStructure() const
{
	ListNode<T>* p;   // Iterates through the list

	if (head == 0)
		cout << "Empty list" << endl;
	else
	{
		for (p = head; p != 0; p = p->next)
			if (p == cursor)
				cout << "[" << p->dataItem << "] ";
			else
				cout << p->dataItem << " ";
		cout << endl;
	}
}

//--------------------------------------------------------------------

template < class T >
void List<T>::moveToBeginning() throw (logic_error)

// Removes the item marked by the cursor from a list and
// reinserts it at the beginning of the list. Moves the cursor to the
// beginning of the list.
{
	ListNode<T>* p;   //  Pointer to prior node
					  // Requires that the list is not empty
	if (head == 0)
		throw logic_error("list is empty");

	if (cursor != head)
	{
		for (p = head; p->next != cursor; p = p->next)
			;
		p->next = cursor->next;
		cursor->next = head;
		head = cursor;
	}
}

//--------------------------------------------------------------------

template < class T >
void List<T>::insertBefore(const T& newDataItem)
throw (bad_alloc)

// Inserts newDataItem before the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) item in the list.
// In either case, moves the cursor to newDataItem.

{
	if (head == 0)             // Empty list
	{
		head = new ListNode<T>(newDataItem, 0);
		cursor = head;
	}
	else                         // Before cursor
	{
		cursor->next = new ListNode<T>(cursor->dataItem, cursor->next);
		cursor->dataItem = newDataItem;
	}
}

//--------------------------------------------------------------------
//                        hashtbl.h
//--------------------------------------------------------------------


template < class T, class KF >
class HashTbl
{
public:
	HashTbl(int initTableSize);
	~HashTbl();

	void insert(const T& newDataItem) throw (bad_alloc);
	bool remove(KF searchKey);
	bool retrieve(KF searchKey, T& dataItem);
	void clear();

	bool isEmpty() const;
	bool isFull() const;

	void showStructure() const;

private:
	int tableSize;
	List<T>* dataTable;
};

//--------------------------------------------------------------------
//                        hashtbl.cpp
//--------------------------------------------------------------------

template < class T, class KF >
HashTbl<T, KF>::HashTbl(int initTableSize) : tableSize(initTableSize)
{
	dataTable = new List<T>[tableSize];
}

template < class T, class KF >
HashTbl<T, KF>:: ~HashTbl()
{
	delete[] dataTable;
}

template < class T, class KF >
void HashTbl<T, KF>::insert(const T& newDataItem) throw (bad_alloc)
{
	int index = 0;
	index = newDataItem.hash(newDataItem.getKey()) % tableSize;

	if (dataTable[index].isEmpty())
		dataTable[index].insert(newDataItem);
	else
	{
		dataTable[index].gotoBeginning();
		do
		{
			if (dataTable[index].getCursor().getKey() == newDataItem.getKey())
			{
				dataTable[index].replace(newDataItem);
				return;
			}
		} while (dataTable[index].gotoNext());

		dataTable[index].insert(newDataItem);
	}
}

template < class T, class KF >
bool HashTbl<T, KF>::remove(KF searchKey)
{
	T temp;
	int index = 0;
	index = temp.hash(searchKey) % tableSize;

	if (dataTable[index].isEmpty())
		return false;

	dataTable[index].gotoBeginning();
	do
	{
		if (dataTable[index].getCursor().getKey() == searchKey)
		{
			dataTable[index].remove();
			return true;
		}
	} while (dataTable[index].gotoNext());

	return false;
}

template < class T, class KF >
bool HashTbl<T, KF>::retrieve(KF searchKey, T& dataItem)
{
	// apply two hash functions:
	// convert string (searchkey) to integer
	// and use the remainder method (% tableSize) to get the index

	int index = 0;
	index = dataItem.hash(searchKey) % tableSize;

	if (dataTable[index].isEmpty())
		return false;

	dataTable[index].gotoBeginning();
	do
	{
		if (dataTable[index].getCursor().getKey() == searchKey)
		{
			dataItem = dataTable[index].getCursor();
			return true;
		}
	} while (dataTable[index].gotoNext());

	return false;
}

template < class T, class KF >
void HashTbl<T, KF>::clear()
{
	for (int i = 0; i < tableSize; i++)
	{
		dataTable[i].clear();
	}
}

template < class T, class KF >
bool HashTbl<T, KF>::isEmpty() const
{
	for (int i = 0; i < tableSize; i++)
	{
		if (!dataTable[i].isEmpty())
			return false;
	}

	return true;
}

template < class T, class KF >
bool HashTbl<T, KF>::isFull() const
{
	for (int i = 0; i < tableSize; i++)
	{
		if (!dataTable[i].isFull())
			return false;
	}

	return true;
}

template < class T, class KF >
void HashTbl<T, KF>::showStructure() const
{
	cout << "The Hash Table has the following entries" << endl;
	for (int i = 0; i < tableSize; i++)
	{
		cout << i << ": ";
		if (dataTable[i].isEmpty())
			cout << "_";
		else
		{
			dataTable[i].gotoBeginning();
			do
			{
				cout << dataTable[i].getCursor().getKey() << " ";
			} while (dataTable[i].gotoNext());
		}
		cout << endl << endl;
	}
}

//--------------------------------------------------------------------
//                         login.cpp
//
//  program that reads in username/login pairs and then
//  performs authentication of usernames.
//--------------------------------------------------------------------

//This will be the data stored in the HashTbl (class T)
struct Password
{
	void setKey(string newKey) { username = newKey; }
	string getKey() const { return username; }

	//this hash converts a string to an integer
	int hash(const string str) const
	{
		int val = 0;

		for (unsigned int i = 0; i < str.length(); i++)
			val += str[i];
		return val;
	}
	string username,
		password;
};


//sets a Password object to its initial values
void clearPassword(Password& passObj) {
	Password* temp = new Password();

	passObj = *temp;

	delete temp;
}

//check the string has the right format, and breaks it down into two words
void processString(string& inputString, string &word1, string &word2) {

	//if it finds a tab in each line of code, then we asume there is an user name and password.
	if (inputString.find('\t') != -1) {

		word1 = inputString.substr(0,inputString.find('\t'));
		word2 = inputString.substr(inputString.rfind('\t')+1);
	}
	else {//if there werent any spaces, then we can't load a user name and password, so throw and exception. 

		throw(logic_error("bad file format"));
	}
	

}

int main()
{
	HashTbl<Password, string> passwords(10);
	Password tempPass;
	string name;      // user-supplied name
	string pass;      // user-supplied password
					  //bool userFound;   // is user in table?

	vector<string> roster;	//for storing the usernames read from the file.  Not a requirement for it is nice to have for other uses. 
	string inputString;	//for reading the file

					  //*********************************************************
					  // Step 1: Read in the password file
					  //*********************************************************
	ifstream passFile("password.txt");

	if (!passFile)
	{
		cout << "Unable to open 'password.txt'!" << endl;
		exit(0);
	}
	
	try {
		while (!passFile.eof() && !passwords.isFull())
		{
			//**add line here to insert passwords into the HashTbl

			getline(passFile, inputString);
		
			//breaking down the string.
			processString(inputString, tempPass.username, tempPass.password);
	
			//storing all usernames.
			roster.push_back(tempPass.username);	

			passwords.insert(tempPass);			

			////Uncomment next line if you want to display the contents from the file as it read
			//cout << "|" << tempPass.username << "|" << "\t\t\t" << "|" << tempPass.password << "|" << endl;

			clearPassword(tempPass); //clearing the tempPass Object, just to be safe
		}

	}
	catch (exception e) {

		cout << "A problem has occurred: " << e.what() << endl;
		exit(0);
	}

	cout << "Printing the hash table:..." << endl;
	//**add line here to show (print) the HashTbl

	//I am not sure how you wanted this done, so I did it two ways. Both of them are used one after the other. 

	//Method one, use just the buildin function for the HashTbl class.
	
	cout << "\n\nUsing the HashTbl showStructure() function\n\n" << endl;
	passwords.showStructure();

	//Method two.  This is a bit longer, but it allows me to format the table as I please, but it does require I know the 
	//list of usernames.  I stored it in a vector while reading from the file. 
	
	cout << "\n\nUsing a secret roster of usernames and retrieving from the hash table\n\n" << endl;
	for (auto rosterEntry : roster) {
		
		if(passwords.retrieve(rosterEntry,tempPass))
			cout << setw(15) << left << tempPass.getKey() << tempPass.password << endl;
			clearPassword(tempPass);
	}

	
	//*********************************************************
	// Step 2: Prompt for a Login and Password and check if valid
	//*********************************************************


	cout << "\n\n\nLogin: ";
	while (cin >> name)  // to quit, type CTRL Z in Visual C++
	{
		//**add line here to retrieve user from HashTbl


		cout << "Password: ";
		cin >> pass;

		

		//**add lines here to compare retrieved user password to
		//**input password and print "Authentication failure"
		//**or "Authentication successful"

		if (passwords.retrieve(name, tempPass) && tempPass.password == pass)
			cout << "Authentication successful\n" << endl;
		else
			cout << "Authentication failure\n" << endl;

		clearPassword(tempPass); //clearing the tempPass Object, just to be safe
		cout << "Login: ";

		
	}
	cout << endl;
	return 0;
}
