/*********************************************************
*        Author: Devin Ellis                             *
*        File: CLinkedList.h                             *
*********************************************************/


/*!	\file CLinkedList.h 
*	\brief  
*
*	This application holds the class definitions and member functions of the Circular Linked
*       List, CListIter, and node Classes. 
*      
*/

#include <iostream>
#include <iomanip>
#include <cassert>
#ifndef CLINKEDLIST_H
#define CLINKEDLIST_H


using namespace std;
// Need to prototype template classes if they are to be friends
template <typename eltType> class CLinkedList;
template <typename eltType> class CListItr;

//template <typename eltType>ostream& operator<<(ostream &os,const eltType &l);

/*!	
 *	\class node
 *	\brief Definition of a container for a node and its data
 *
 *      The node class holds the pointer to next and the linking to the next node, along with
 *      the definition of the eltType data member.
 */

template <typename eltType> class node
{       private:
                node(eltType info, node* link = NULL ) :
                                               data(info), next(link) {};
                eltType data;
                node *next;
        friend class CLinkedList<eltType>;
        friend class CListItr<eltType>;
};
/*!                                                                                                
 *      \class CLinkedList                                                                        
 *      \brief Definition of a Circularly Linked List 
 *
 *      The CLinkedList holds the constructor, destructor, insert, remove, and linked list pointer
 *      for the implementation in testLL.cpp. CListItr<eltType> is declared a friend of this class
 *      and is used in the ostream << operator and the driver file.
 *
 */

template <typename eltType> class CLinkedList
{
        public:
                // Construct empty LinkedList
                /*!
		 * \fn Constructor
		 * 
		 * Last Node default to NULL.
		 **************************************************************************/
                CLinkedList();
                // Construct deep copy of another LinkedList
                /*!
		 * CLinkedList
		 * \param CLinkedList&
		 * copys CLinkedList last node to new CLinkedList
		 * inspector
		 **************************************************************************/  
                CLinkedList(CLinkedList&);

                // destroy LinkedList
                  // Construct deep copy of another LinkedList                                       
                /*!                                                                                
                 * \fn Destructor                                                            
                 * Destroys CLinkedList last node 
                 *                                                                        
                 **************************************************************************/
                ~CLinkedList();

                // Assign another LinkedList to this LinkedList; deep copy
                /*!
		 * operator = - assignment operator
		 * 
		 **************************************************************************/
                CLinkedList& operator=(const CLinkedList&);

                /*!
		 * insert - Inserts user value into sorted CLinkList
		 * \param Const eltType
		 **************************************************************************/
                void insert(eltType);

                /*!                                                                                
                 * remove - Removes user value from sorted CLinkList                               
                 * \param Const eltType                                                            
                 **************************************************************************/
                void remove(eltType);

                /*!                                                                                
                 * empty - checks if CLinkedList is empty                               
                 *                                                            
                 **************************************************************************/
                bool empty();
  
		  
        private:
                /*!
		 *	Declaring node pointer of last
		 */
                // linked list pointer
                node<eltType>*  last;

                // Get a copy of a (deep) node
                /*!
		 *	Gets copy of a node
		 */
                node<eltType>*  copy(node<eltType> *);

                // Free nodes of a linked list
                /*!
		 *     \fn
		 *     destroy - destroys node pointer
		 */
                void    destroy(node<eltType> *);
            // Free nodes of a linked list                                                     
                /*!                                                                                
                 *     \fn                                                                         
                 *     destroyHelper - Recursive helper function for destroy                       
                 */
                void destroyHelper(node<eltType> *);

        // Needed to use a list iterator
        friend class CListItr<eltType>;
};

/*!
 * operator<< - overloaded operator for outputting CLinkedList's data
 * facilitator
 **************************************************************************/
template <typename eltType> ostream &operator<< ( ostream &os, const CLinkedList<eltType> &l);

/*!                                                                                                
 *      \class CListItr                                                                         
 *      \brief Definition of a iterator of the Circularly Linked List                                              
 *                                                                                                 
 *      The CLinkedList holds the constructor, and other member functions to navigate and access 
 *      data within the CLinkedList. Used in printing in testLL.cpp and traversal in testLL.cpp 
 *      Declares itr of CLinkedList and a node* curr
 *                                                                                                 
 */
template <typename eltType> class CListItr
{
        public:
                // Construct a List Iterator
                /*!                                                                                
                 * \fn Constructor                                                                 
                 *  \param CLinkedList &l                                                         
                 * Contructs itr to CLinkedList &l and curr pointing to l's last node             
                 **************************************************************************/
                CListItr(const CLinkedList<eltType> &l);
                // Set curr to point at the first node of itr
                /*!                                                                                
                 *     \fn                                                                         
                 *     begin() - Sets curr pointer to CLinkedList "head"                       
                 */
                void begin();
                // Is list empty?
                 /*!                                                                              
                 *     \fn                                                                         
                 *     isEmpty() = checks if last is equal to NULL        
                 */
                bool isEmpty();
                // Is node at first?
                 /*!                                                                             
                 *     \fn                                                                         
                 *     isFirstNode() - Checks if curr is equal to the first node           
                 */
                bool isFirstNode();
                //Is node at Last?
                 /*!                                                                               
                 *     \fn                                                                         
                 *     isLastNode() - Checks if curr is equal to the last node                   
                 */
                bool isLastNode();
                //Returns data of curr node
                 /*!                                                                            
                 *     \fn                                                                         
                 *     operator * const - Returns curr's data
		 *     \return curr->data
                 */
                eltType operator *(void) const
                  { 
                    return curr->data;
                  }
                 /*!                                                                               
                 *     \fn                                                                         
                 *     operator * - Returns curr's data                                      
		 *     \return curr->data
                 */
                eltType operator *(void)
                  {
                    return curr->data;
                  }
  
                // pre increment operator
                 /*!                                                                             
                 *     \fn                                                                         
                 *     operator ++() - Pre Increments curr
		 *     \return itr                                     
                 */
                CListItr operator++();
                // post increment operator
                 /*!                                                                               
                 *     \fn                                                                         
                 *     operator ++(int) - Post Increments curr                                     
                 *     \return (*this)                                                             
                 */
                CListItr operator++(int);
        private:
                 /*!                                                                                                *      Declaring referenced itr of CLinkedList                                    
                 */
                const CLinkedList<eltType> &itr;
                 /*!                                                                              
                 *      Declaring node pointer of curr                                             
                 */
                node<eltType> *curr;

        friend class CLinkedList<eltType>;

};

#endif

// Construct empty LinkedList                                                      
/*!                                                                                
 * \fn Constructor                                                                 
 *                                                                                 
 * Last Node default to NULL.                                                      
 **************************************************************************/
template <typename eltType> CLinkedList<eltType>::CLinkedList() : last(NULL)
{}

// Copy constructor. copy() does the deep copy
/*!                                                                                
 * CLinkedList                                                                     
 * \param CLinkedList&                                                             
 * copys CLinkedList last node to new CLinkedList                                  
 * inspector                                                                       
 **************************************************************************/
template <typename eltType>
        CLinkedList<eltType>::CLinkedList(CLinkedList<eltType> &cl)
{last = copy( cl.last );}

// Free all nodes
/*!                                                                                
 * \fn Destructor                                                                  
 * Destroys CLinkedList last node                                                  
 *                                                                                 
 **************************************************************************/
template <typename eltType> CLinkedList<eltType>::~CLinkedList()
{destroy(last);}

// Assignment operator: copy() does the deep copy
/*!                                                           
 * operator = - assignment operator                                                
 *                                                                                 
 **************************************************************************/
template <typename eltType> CLinkedList<eltType>
        &CLinkedList<eltType>::operator =(const CLinkedList<eltType>& cl)
{       if (this != &cl)
        {       destroy(last);
                last = copy(cl.last);
        }
        return *this;
}


// The deep copy. Copy the source list l, one node at a time
/*!                                                                                 
 *      Gets copy of a node                                                         
 */
template <typename eltType>
        node<eltType>* CLinkedList<eltType>::copy(node<eltType> *l)
{       node<eltType>* first = NULL;    // ptr to beginning of copied LinkedList
        node<eltType>* last = NULL;     // ptr to last item insert in the copy
        if (l != NULL)
        {       assert((first=last=new node<eltType>(l->data,NULL)) != NULL);
                for (node<eltType>* source=l->next;source!=NULL;
                                        source=source->next,last=last->next)
                {       last->next = new node<eltType>(source->data,NULL);
                        assert(last->next);
                }
        }
        return first;
}


// Checks if list is empty

/*!                                                                               
* empty - checks if CLinkedList is empty
*                                                                                                  *************************************************************************/
template <typename eltType> inline bool CLinkedList<eltType>::empty()
{return (last == NULL);}

// Place x into the list in order
/*!                                                                                
 * insert - Inserts user value into sorted CLinkList                               
 * \param Const eltType                                                            
 **************************************************************************/
template <typename eltType>
void CLinkedList<eltType>::insert( eltType v)
{
  if (empty())
    {
      last = new node<eltType>(v,last);
      last->next = last;
    }
  else if (last->data < v)
    {
      last->next = new node<eltType> (v, last->next);
      last = last->next;
    }
  
  else  // start at 2nd node...already checked first node
    {       node<eltType>*  p       = last->next; // head;
                node<eltType>*  trailp  = last; // NULL;
                while (p != last && v > p->data)
                {       trailp = p;
                        p = p->next;
                }
                trailp->next = new node<eltType>(v,p);
        }
}

//RECURSIVELY
// Remove all nodes in the linked list, starting at l
/*!                                                                                
 *     destroy - destroys node pointer                                             
 */
template <typename eltType> void CLinkedList<eltType>::destroy(node<eltType> *l)
{
  destroyHelper(l->next);
}
// Helper for destroy()
/*!                                                                                
 *     \fn                                                                         
 *     destroyHelper - Recursive helper function for destroy                       
 */
template <typename eltType> void CLinkedList<eltType>::destroyHelper(node<eltType> *l)
{
  node<eltType> *doomed = l;
  if(l == NULL)
    {
      return;
    }
  destroyHelper(l->next);
  delete doomed;
}


// Remove a node in an ordered list
// Pre: Node will be found
/*!                                                                                
 * remove - Removes user value from sorted CLinkList                               
 * \param Const eltType                                                            
 **************************************************************************/
template <typename eltType> void CLinkedList<eltType>::remove(eltType x)
{       assert( !empty() );
        node<eltType>*  p = last->next;
        node<eltType>*  trailp = last;
        while ( p != last && p->data != x )
        {       trailp = p;
                p = p->next;
        }
        assert(p != NULL); // x is not in the LinkedList
        if (p == last)
	  {
	    trailp->next = last->next; // x is last in the LinkedList
	    delete p;
	    last = trailp;
	  }
        else
	  trailp->next = p->next; // x is farther down in the LinkedList
}



// Output a linked list, using a list iterator
template <typename eltType>
ostream& operator<< ( ostream &os, const CLinkedList<eltType> &l)
{       CListItr<eltType>        itr(l);
  if(itr.isEmpty())
    {
      return os;
    }
  
  os << l << " ";
  return os;
}

// Iterator Constructor
/*!                                                                                 
 * \fn Constructor                                                                 
 *  \param CLinkedList &l                                                          
 * Contructs itr to CLinkedList &l and curr pointing to l's last node              
 **************************************************************************/
template <typename eltType>
CListItr<eltType>::CListItr(const CLinkedList<eltType> &l): itr(l),curr(l.last)
{}

// Set to begining
/*!                                                                               
 *     \fn                                                                         
 *     isEmpty() = checks if last is equal to NULL                                 
 */
template <typename eltType> void CListItr<eltType>::begin()
{curr = itr.last->next;}

// Check if list is empty
/*!                                                                               
 *     \fn                                                                         
 *     isFirstNode() - Checks if curr is equal to the first node                   
 */
template <typename eltType> bool CListItr<eltType>::isEmpty()
{return (curr == NULL);}

// Check if iterator is on the first
/*!                                                                                                 *     \fn                                                                         
 *     isLastNode() - Checks if curr is equal to the last node                     
 */
template <typename eltType> bool CListItr<eltType>::isFirstNode()
{return (curr == itr.last->next);}

// Check if iterator is on the last node

/*!                                                                               
 *     \fn                                                                         
 *     isLastNode() - Checks if curr is equal to the last node                    
 */
template <typename eltType> bool CListItr<eltType>::isLastNode()
{return (curr == itr.last);}

// Pre Increment itr
/*!                                                                               
 *     \fn                                                                         
 *     operator ++(int) - Post Increments curr                                     
 *     \return (*this)                                                             
 */
template <typename eltType> CListItr<eltType>
        CListItr<eltType>::operator ++()
{
  curr = curr->next;
  return itr;
}

//Post Increment itr
/*!                                                                               
 *     \fn                                                                         
 *     operator ++(int) - Post Increments curr                                     
 *     \return (*this)                                                             
 */
template <typename eltType> CListItr<eltType>
        CListItr<eltType>::operator ++(int)
{
 curr = curr->next;
 return(*this);
}
