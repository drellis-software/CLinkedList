/*********************************************************                                         
*        Author: Devin Ellis                             *                                         
*        File: testLL.cpp                                *                                         
*********************************************************/

/*!	\file testLL.cpp 
*	\brief  Test Driver for CLinkedList class
*
*	This application tests the implementation of an Circular Linked list with iterator class.
*	The Circular Linked List is declared eltType. The iterator allows traversal and insertion/
*       removal of user inputted value.
*	
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "CLinkedList.h"


using namespace std;

//Prototype Functions

/*!
*	\brief Displays menu options
*
*	The menu() function displays the menu choices for the user to user within the
*       program.
*/

void menu();

/*!                                                                                                
*       \brief Prints Circular Linked List object forwards using iterator
*
*       \param CLinkedList<int> &cLL Circular Linked List object of type int
*                                                                                              
*       The forwardPrint() function prints the Circular Linked List from first node to last node
*       forwards using an iterator set to begining
*
*/

void forwardPrint(CLinkedList<int> &cLL);

/*!                                                                         
*       \brief Prints Circular Linked List object backwards using iterator and recursion
*                                                                                                  
*       \param CListItr<int> &itr Circular Linked List Iterator of type int                       
*                                                                                                  
*       The forwardPrint() function prints the Circular Linked List from last node to first node   
*       recursively using an iterator and is a helper function
*                                                                                                  
*/

void backwardPrint(CListItr<int> itr);

/*!                                                                                                
*       \brief Prints Circular Linked List backwards                    
*                                                                                                  
*       \param CLinkedList<int> &cLL Circular Linked List object of type int                       
*                                                                                                  
*       The forwardPrint() function prints the Circular Linked List from last node to first node   
*       recursively using an iterator and using a helper function                                
*                                                                                                  
*/

void recursion(CLinkedList<int> &cLL);

int main()
{
  CLinkedList<int> cLL;
  char sel;
  int val;

  
  do {
    menu();
    cin >> sel;
    switch(tolower(sel)) {
    case 'i':
      cout << "You have selected to Insert" << endl;
      cout << "Enter Value: ";
      cin >> val;
      cLL.insert(val);
      cout << "Inserted: " << val << endl;
      break;
    case 'r':
      cout << "You have selected Remove" << endl;
      cout << "Enter Value to Remove: ";
      cin >> val;
      cLL.remove(val);
      cout << "Removed: " << val << endl;
      break;
    case 'f':
      cout << "You have selected Forward Print" << endl;
      forwardPrint(cLL);
      cout << endl;
      break;
    case 'b':
      cout << "You have selected Backwards Print" << endl;
      recursion(cLL);
      cout << endl;
      break;
    case 'e':
      cout << "Exiting";
      break;
    }
  } while (sel != 'e');

return(0);
}

// Displays Menu Selections
void menu()
{
  // Menu until exit case
  cout << "LinkedList Test Driver" << endl << "I)nsert Integer" << endl;
  cout << "R)emove Integer" << endl << "F)orward print" << endl;
  cout << "B)ackward Print" << endl << "E)xit" << endl;
}

// Forward Print of CLinkedList &
void forwardPrint(CLinkedList<int> &cLL)
{
  CListItr<int> itr(cLL);
  itr.begin();
  while(!itr.isLastNode())
    {
      cout << *itr << " ";
      itr++;
    }
  cout << *itr << endl;

}

//Recusive Backwards print of CLinkedList &
void recursion(CLinkedList<int> &cLL)
{
  CListItr<int> itr(cLL);
  itr.begin();
  backwardPrint(itr);
  cout << *itr << endl;
}

//Helper to Recusrive to print
void backwardPrint(CListItr<int> itr)
{
  if(!itr.isLastNode())
    {
      backwardPrint(itr++);
      cout << *itr << " ";
    }
}
