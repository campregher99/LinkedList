#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
private:
	Node<T>* prev;
	Node<T>* next;
	T* element;
public:
	Node();
	Node(T* _element): element {_element} {};
	Node(T* _element, Node* _prev, Node* _next): prev {_prev}, next {_next}, element {_element} {};
	~Node();
	Node* getPrev();
	Node* getNext();
	T* getElement();
	void setPrev(Node* _prevNode);
	void setNext(Node* _nextNode);
	void setElement(T* element);
};

template <typename T>
Node<T>::~Node()
{
    delete(element);
}

template <typename T>
Node<T>* Node<T>::getPrev()
{
	return prev;
}

template <typename T>
Node<T>* Node<T>::getNext()
{
	return next;
}

template <typename T>
T* Node<T>::getElement()
{
	return element;
}

template <typename T>
void Node<T>::setPrev(Node* _prev)
{
	prev=_prev;
}

template <typename T>
void Node<T>::setNext(Node* _next)
{
	next=_next;
}

template <typename T>
void Node<T>::setElement(T* _element)
{
	element=_element;
}
#endif
