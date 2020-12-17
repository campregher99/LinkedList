#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
template <typename T>
class LinkedList
{
	//member variables
private:
	Node<T>* initialNode=nullptr;
	Node<T>* lastNode=nullptr;
	unsigned int length = 0;

	//member function
public:
	LinkedList() {};
	~LinkedList();

	int size();

	bool addFirst(T* _element);
	bool addLast(T* _element);
	bool addMiddle(T* _element, unsigned int _index);

	bool delFirst();
	bool delLast();
	bool delMiddle(unsigned int _index);

	Node<T>* getFirst();
	Node<T>* getLast();
	Node<T>* getMiddle(unsigned int _index);


protected:
	Node<T>* searchNode(unsigned int _index);
};

/*
 *	destructor that deletes all the node
*/
template <typename T>
LinkedList<T>::~LinkedList()
{
	Node<T> *node = initialNode, *nextNode;
	do
	{
		nextNode=node->getNext();
		delete(node);
		node=nextNode;
	}while(node==lastNode);
}

/*
 *	returns the number of the LinkedList members
 *
 *	return type: int
 *	    the number of nodes in the LinkedList
*/
template <typename T>
int LinkedList<T>::size()
{
	return length;
}

/*
 *	function that adds an element of type T at the first place
 *	
 *	parameter : 
 *		-_element: T* 
 *			pointer of type T that points to the element to add
 *	return type : bool
 *		the function returns true if all goes right 
*/
template <typename T>
bool LinkedList<T>::addFirst(T* _element)
{
	Node<T>* newNode = new Node<T>(_element);
	if(initialNode!=nullptr)
	{
		newNode->setNext(initialNode);
		initialNode->setPrev(newNode);
	}else
	{
		lastNode=newNode;
	}
	initialNode=newNode;
	length++;
	return true;
}

/*
 *  function that adds an element at the last place
 *
 *  parameter:
 *      -element: T*
 *          pointer that points at an element of type T
 *  return type: bool
 *      returns true if go all right
 */
template <typename T>
bool LinkedList<T>::addLast(T* _element)
{
	Node<T>* newNode = new Node<T>(_element);
	if(lastNode!=nullptr)
	{
		newNode->setPrev(lastNode);
		lastNode->setNext(newNode);
	}else
	{
		initialNode=newNode;
	}
	lastNode=newNode;
	length++;
	return true;
}

/*
 *  function that inserts an element at the marked place, it takes
 *  the current element after that it inserts
 *
 *  parameter:
 *      -_element: T*
 *          element that is inserted
 *      -_index: unsigned int
 *          index of place whare place the element
 *
 *  return type: bool
 *      return true if it goes right
 */
template <typename T>
bool LinkedList<T>::addMiddle(T* _element, unsigned int _index)
{
	if(_index>=length)
		return false;
	Node<T>* newNode = new Node<T>(_element);
	Node<T>* node = searchNode(_index);
	newNode->setNext(node);
	node=node->getprev();
	newNode->setPrev(node);
	if(_index!=0||_index!=length-1)
	{
		newNode->getNext()->setPrev(newNode);
		newNode->getPrev()->setNext(newNode);
	}
	else if(_index==0)
	{
		newNode->getNext()->setPrev(newNode);
		initialNode=newNode;
	}
	else
	{
		newNode->getPrev()->setNext(newNode);
		lastNode=newNode;
	}

	length++;
	return true;
}

/*
 *  deletes the first element and the second one becomes the first
 *
 *  return type: bool
 *      returns true if it goes right
 */
template <typename T>
bool LinkedList<T>::delFirst()
{
	if(initialNode==nullptr)
		return false;
	Node<T>* delNode=initialNode;
	if(length>1)
	{
		initialNode=initialNode->getNext();
		initialNode->setPrev(nullptr);
	}
	delete(delNode);
	length--;
	return true;
}

/*
 *  deletes the last element and the second last becomes the last
 *
 *  return type: bool
 *      returns true if it goes right
 */
template <typename T>
bool LinkedList<T>::delLast()
{
	if(lastNode==nullptr)
		return false;
	Node<T>* delNode=lastNode;
	if(length>1)
	{
		lastNode=lastNode->getPrev();
		lastNode->setNext(nullptr);
	}
	delete(delNode);
	length--;
	return true;
}

/*
 *  deletes an element in a specified place
 *
 *  parameter:
 *      -_index: unsigned int
 *          the index of the element to delete
 *
 *  return type: bool
 *      return true if it goes right
 */
template <typename T>
bool LinkedList<T>::delMiddle(unsigned int _index)
{
	if(_index>=length)
		return false;
	Node<T>* delNode=searchNode(_index);
	if(_index!=0||_index!=length-1)
	{
		delNode->getNext()->setPrev(delNode->getPrev());
		delNode->getPrev()->setNext(delNode->getNext());
	}
	else if(_index==0)
	{
		if(length>1)
		{
			delNode->getNext()->setPrev(delNode->getPrev());
		}
		initialNode=delNode->getNext();
	}
	else
	{
		delNode->getPrev()->setNext(delNode->getNext());
		lastNode=delNode->getPrev();
	}
	delete(delNode);
	length--;
	return true;
}

/*
 *  rteurns a pointer to the first node of the LinkedList
 *
 *  return type: Node<T>*
 *      a pointer that points to the first node
 */
template <typename T>
Node<T>* LinkedList<T>::getFirst()
{
	if(initialNode==nullptr)
		return nullptr;
	return initialNode;
}

/*
 *  returns a pointer to the last node of the LinkedList
 *
 *  return type: Node<T>*
 *      a pointer which points to the last node of the LinkedList
 */
template <typename T>
Node<T>* LinkedList<T>::getLast()
{
	if(lastNode==nullptr)
		return nullptr;
	return lastNode;
}

/*
 *  returns a pointer to a node that is placed in a determined position
 *
 *  parameter:
 *      -_index: unsigned int
 *          the index of the position of the node
 *
 *  return type: Node<T>*
 *      returns a pointer which points to the elements in the index position
 */
template <typename T>
Node<T>* LinkedList<T>::getMiddle(unsigned int _index)
{
	if(_index>=length)
		return nullptr;
	return searchNode(_index);
}

/*
 *  rwtuens the pointer to the node in the index position
 *
 *  parameter:
 *      -_index: unsigned int
 *          the position where is the node
 *
 *  return type: Node<T>*
 *      the pointer which points to the node in the index position
 */
template <typename T>
Node<T>* LinkedList<T>::searchNode(unsigned int _index)
{
	if(_index>=length)
		return nullptr;
	Node<T>* actualNode;
	if(_index>length/2)
	{
		actualNode=lastNode;
		for(int i=length-1; i> _index; i--)
		{
			actualNode=actualNode->getPrev();
		}
	}else
	{
		actualNode=initialNode;
		for(int i=0; i> _index; i++)
		{
			actualNode=actualNode->getNext();
		}
	}
	return actualNode;
}
#endif
