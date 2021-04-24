#include <iostream>
#include "LinkedListNode.hpp"
#include <iomanip>


//I wrote my own implementation of a linked list in the LinkedListNode class.  The purpose is to create two linked lists, fill them with numbers, sort them, and then merge the lists. 
//When all of that is done, the new list will be sorted again, and any duplicate numbers will be removed.  This implementation uses templates for greater flexibility
//Diego F. Perez  23 Sep 2020


//This function simply fills the list with random data
template <typename T>
void fillList(LinkedListNode<T> &list, int size)
{
    list.setData(rand() % 100 +1);
    int count = 0;
    
    while (count < size -1 )
    {
        list.pushBack(new LinkedListNode<T>(rand() % 100 + 1));
        ++count;
    }
}

//This function prints the list contents of the array
template <typename T>
void printList(LinkedListNode<T> &list)
{
    LinkedListNode<int>* temp = &list;
    while (true)
    {
        std::cout << std::setw(5) << temp->returnData();

        if (temp->nextNode == nullptr)
        {
            break;
        }

        else
            temp = temp->nextNode;
    }
    std::cout << "\tEnd of list"  << std::endl;
}


//function to calculate the average and total sum of the list
template <typename T>
void calculate(int &total, int &count, float &average, LinkedListNode<T> &list)
{
    LinkedListNode<T>* tempNode = nullptr;
    tempNode = &list;
    while (tempNode != nullptr)
    {
        total += tempNode->returnData();
        ++count;
        //std::cout << count << ".  total + " << tempNode->returnData() << "  =  " << total << std::endl;
        tempNode = tempNode->nextNode;

    }
    average = (float)total / count;

}


int main()
{
    srand(time(0));

    int count = 0, total = 0;
    float average = 0.0;
    

    //creating two lists with random numbers in them
   
    LinkedListNode<int> list1;
    LinkedListNode<int> list2;

    fillList(list1, 20);
    fillList(list2, 15);

    //output data
    std::cout << "\n\nList1 Contents, sorted, and duplicates removed:\n";
    printList(list1);
    list1.sortList();
    printList(list1);
    list1.removeDuplicates();
    printList(list1);

    std::cout << "\n\nList2 Contents, sorted, and duplicates removed:\n";
    printList(list2);
    list2.sortList();
    printList(list2);
    list2.removeDuplicates();
    printList(list2);

    //adding list 2 to list one
    std::cout << "\n\nConsolidated list contents, sorted, and duplicates removed:\n";
    list1.appendList(list2);
    printList(list1);
    list1.sortList();
    printList(list1);
    list1.removeDuplicates();
    printList(list1);


    std::cout << "\n\nConsolidated list after removing the head:\n";
    list1.removeNode();
    printList(list1);
       
    std::cout << "\n\nConsolidated list after removing any value <= 20:\n";
    for (int i = 0; i <= 20; i++)
    {
        LinkedListNode<int>* temp = list1.findData(i);

        if (temp != nullptr)
            temp->removeNode();
    }
    printList(list1);

    std::cout << "\n\nConsolidated list reverse sorted:\n";
    list1.rSortList();
    printList(list1);
    
    calculate(total, count, average, list1);

    std::cout << "\n\n" << std::setw(32) << std::left << "Consolidated list total value:  " << std::setw(10) << std::right << total << std::endl;
    std::cout << std::setw(32) << std::left << "Consolidated list total nodes:  " << std::setw(10) << std::right << count << std::endl;
    std::cout << std::setw(32) <<  std::left <<  "Consolidated list average:  " << std::setw(10) << std::right << average << std::endl;

    return 0;

}
