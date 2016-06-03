#include "Node.h"

// Default Constructor
template<class T>
Node<T>::Node()
	:
	next(nullptr),
	prev(nullptr),
	data(NULL)
{
	
}

// Destructor
template <class T>
Node<T>::~Node() {
	
}

