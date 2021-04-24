/*Hello!
* 
This is a simple implementation of a binary search tree.  The BinarySearchTree class stores data in a strut called Node, such as: the data itself, left and right node pointers,
the current height of the node, and a couple of functions stating if the node is empty, or if it is a leaf.

The main function in this document call on another function to take apart a sentence, and store it in the binary tree.  We then use the class functions to print the initial tree,
do postorder, preorder, and inorder traversal of the trees as they get transferred to new trees in a successive manner.  The end result is a tree where the nodes resemble a sorted linked list.
Initially, I tested the program with a sentence composed of numbers, so it is easier to track. Later, normal words were used and the string is sorted in a lexicographic way.

Please note, that the print function first shows the nodes in order, from left to right, then down to the next level and so on.  This is called level order traversal.
The tree is immediately printed again but showing the levels and will indicate if a node is a leaf or not.

I hope you like my program!

Diego F. Perez - 29OCT2020 - CPS 272

*/


//Edit,  I used this program to troubleshoot something else, and I ended up adding like four new methods.  The four new methods are the ones I should have usef from the get go. 
//These methods traverse the tree and put the data into a queue so you can simply do whatever you want with the queue. 17DEC2020
//Also, I now know a lot more about threes, and BTS suck.  Red-black trees is the way to go, just difficult to program. 

#include <iostream>
#include "BinarySearchTree.hpp"
using namespace std;

//This functiont takes a sentence and extracts the first word, mods the string. returns true or false depending if it did any work
bool extractFirstWord(string &sentence, string &word) {
      
    if (sentence.empty()) {
        return false;
    }
        
    else {

        if (sentence.find_first_not_of(" \t") != 0) {             //if it is different than 0, it means that there is either no spaces, or the first character is a space
            sentence.erase(0, sentence.find_first_not_of(" \t")); // trim leading spaces
        }
        if (sentence.empty()) {        //if the string is empty after trimming zeroes. 
            cout << "sentence is empty = " << '|' << sentence << '|' << endl;
            return false;

        }
        else {  //actuall substract the first word
            word = sentence.substr(0, sentence.find_first_of(" \t"));
            sentence.erase(0, sentence.find_first_of(" \t"));
        }

        
        ////Uncomment line below for troubleshooting purposes
        //cout << '|' << word << '|' << endl;
    }
    
    return true;
}

int main()
{
    BinarySearchTree T1,T2,T3,T4;
    queue<Node*> storage;

    //use sentence1 if you want to study the results of the binary tree closely
    string word, sentence1("5 9 8 3 2 6 1 7"), sentence2;



    try {

        cout << "Please enter sentence to be stored inside a binary search three:";
        getline(cin, sentence2);


        while (extractFirstWord(sentence2, word)) {

           T1.addData(word);
        }

        cout << "\n\nPrinting T1\n" << endl;
        T1.printTree();



        T1.preOrderTraverseNLR(T1.top(), storage);
        cout << "\n\nPrinting Preorder Level Traversal:\t" << endl;
        while (!storage.empty()) {

            cout << storage.front()->data << '\t';
            
            storage.pop();
        }


        T1.inOrderTraverseLNR(T1.top(), storage);
        cout << "\n\nPrinting Inorder Level Traversal:\t" << endl;
        while (!storage.empty()) {

            cout << storage.front()->data << '\t';

            storage.pop();
        }


        T1.postOrderTraverseLRN(T1.top(), storage);
        cout << "\n\nPrinting Postorder Level Traversal:\t" << endl;
        while (!storage.empty()) {

            cout << storage.front()->data << '\t';

            storage.pop();
        }


        T1.reverseOrderTraverseRNL(T1.top(), storage);
        cout << "\n\nPrinting Reverse Level Traversal:\t" << endl;
        while (!storage.empty()) {

            cout << storage.front()->data << '\t';

            storage.pop();
        }


        cout << "\n\nPrinting T1\n" << endl;
        T1.printTree();


        cout << "\n\nPrinting T2\n" << endl;
        T1.postOrderNewTree(T2, T1.top());
        T2.printTree();

        cout << "\n\nPrinting T3\n" << endl;
        T2.preOrderNewTree(T3, T2.top());
        T3.printTree();

        cout << "\n\nPrinting T4\n" << endl;
        T3.inOrderNewTree(T4, T3.top());
        T4.printTree();



    }
    catch (exception e) {
        cout << e.what();
    }


}