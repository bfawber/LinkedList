#pragma once

/*
 * Created by Bryan Fawber 06/01/2016
 * A basic node class to create doubly linked lists, and the basic functions for those lists!
 */

#ifndef __NODE_H__
#define __NODE_H__

template<class T>
class Node {

	public:

		// Default Constructor
		Node() {};

		// Destructor
		~Node() {};
	
		Node<T>* next;
		Node<T>* prev;

		T data;
};

/* 
 * Basic Linked List Insert Function
 * 
 * Parameters:
 * node - The node to insert after
 * newNode - The new node to insert
 */
template<class T>
void insert(Node<T>* node, Node<T>* newNode) {
	if (node == nullptr) {
		return;
	}

	Node<T>* temp = node->next;
	node->next = newNode;
	node->next->next = nullptr;
	node->next->prev = node;
}

/*
 * Basic Linked List Insert Function
 * 
 * Parameters:
 * node - The node to insert after
 * x - The data in the new node that is inserted
 * 
 * Note: A new node will be created in this function with data value x
 */
template<class T>
void insert(T x, Node<T>* node) {
	Node<T>* temp = node->next;
	node->next = new Node<T>;
	node->next->data = x;
	node->next->next = temp;
	node->next->prev = node;
}

/*
 * A function to find the end of a linked list
 * 
 * Parameters:
 * head - The head of the list
 *
 * Returns:
 * The last Node<T>* in the list
 */
template<class T>
Node<T>* end(Node<T>* head) {
	Node<T>* i = head;
	while (i->next != nullptr) {
		i = i->next;
	}
	return i;
}

/*
 * Check if a List is empty
 * Parameters:
 * head - The head of the list
 *
 * Returns:
 * A boolean that's true if the list is empty, otherwise false
 */
template<class T>
bool empty(Node<T>* head) {
	if (head->next == nullptr) {
		return true;
	}
	return false;
}

/*
 * Print the contents of a list
 * 
 * Parameters:
 * head - The head of the list
 */
template<class T>
void printList(Node<T>* head) {
	Node<T>* i;

	if (empty(head)) return;

	cout << "The list contains: " << endl;
	i = head;
	while (i->next != nullptr) {
		cout << i->next->data << " ";
		i = i->next;
	}
	cout << endl;
}

/*
 * A function that makes a linked list null
 *
 * Parameters:
 * head - The head of the linked list
 */
template<class T>
void makenull(Node<T>* head) {
	Node<T>* i = end(head);
	i = i->prev;
	while (i != nullptr) {
		delete(i->next);
		i = i->prev;
	}
	head->next = nullptr;
}

/*
 * Removes a node from the list
 *
 * Parameters:
 * node - the node before the node that will be removed
 */
template<class T>
void remove(Node<T>* node) {
	if (node->next == nullptr) return;

	Node<T>* temp = node->next->next;
	if(temp != nullptr)
		temp->prev = node;
	delete(node->next);
	node->next = temp;
}

/*
 * A function to locate an element in a linked list
 *
 * Parameters:
 * x - The element being searched for
 * head - The head of the list
 *
 * Returns:
 * The node before the node containing the element if located. Otherwise returns false.
 */
template<class T>
Node<T>* locate(T x, Node<T>* head) {
	Node<T>* i;

	i = head;
	while (i->next != nullptr) {
		if (i->next->data == x) {
			return i;
		}
		i = i->next;
	}
	return nullptr;
}
#endif // !__NODE_H__

