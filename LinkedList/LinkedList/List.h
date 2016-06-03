#pragma once

/*
 * Created by Bryan Fawber 06/02/2016
 * A generic list class using the Linked List data structure
 */

#ifndef __LIST_H__
#define __LIST_H__

#include "Node.h"

template<class T>
class List {
public:
	List()
	:
	head(new Node<T>),
	tail(head),
	size(0)
	{};

	List(Node<T>* head)
	:
	head(head),
	tail(head)
	{};

	~List() {
		makenull(head);
		delete(head);
	};

	/*
	 * The following add(...) functions provide the ability to add elements to the list
	 */

	/*
	 * Parameters:
	 * newNode - The node being added to the list
	 */
	virtual void add(Node<T>* newNode) {

		// Sanity Check
		if (newNode == nullptr) return;
		if (this->head == nullptr) return;

		// From "Node.h"
		insert(tail, newNode);
		tail = newNode;
		size++;
	};

	/*
	 * Parameters:
	 * position - The position you wish to add the node to the list
	 * newNode - The new node to add to the list
	 */
	virtual void add(int position, Node<T>* newNode) {

		// Sanity Check
		if (newNode == nullptr) return;
		if (this->head == nullptr) return;

		// To find the desired position
		Node<T>* current = this->head;

		for (int i = 0; i < position && current->next != nullptr; i++) {
			current = current->next;
		}

		// If it's the tail, increment properly
		if (current == tail) {
			add(newNode);
		}
		else {

			// From "Node.h"
			insert(current, newNode);
			size++;
		}
	};

	/*
	 * Parameters:
	 * node - The node in the list to add after
	 * newNode - The node to add to the list
	 */
	virtual void add(Node<T>* node, Node<T>* newNode) {

		// Sanity Check
		if (node == nullptr) return;
		if (newNode == nullptr) return;

		// if the node is the tail, increment properly
		if (node == tail) {
			add(newNode);
		}
		else {
			// From "Node.h"
			insert(node, newNode);
			size++;
		}
	};

	/*
	 * Parameters:
	 * data - The data that will be stored in the new node that is added
	 */
	virtual void add(T data) {

		// Sanity Check
		if (head == nullptr) return;

		// Frome "Node.h"
		insert(data, tail);

		// Keep track of tail
		incrementTail();

		size++;
	};

	/*
	 * Parameters:
	 * position - the position in the list the new nose should be added to
	 * data - the data the new node will hold
	 */
	virtual void add(int position, T data) {

		// Sanity Check
		if (head == nullptr) return;

		// To find the position
		Node<T>* current = head;

		// populate current with the desired node
		for (int i = 0; i < position && current->next != nullptr; i++) {
			current = current->next;
		}

		// if it's the tail, increment tail properly
		if (current == tail) {
			add(data);
		}
		else {
			// From "Node.h"
			insert(data, current);
			size++;
		}
	};

	/*
	* The following rem(...) functions provide the ability to remove elements from the list
	*/
	
	virtual void rem() {
		Node<T>* temp = tail->prev;
		remove(tail->prev);
		tail = temp;
		size--;
	};

	/*
	* Parameters:
	* data - The data of the node you want to remove. If more than one of these exists, removes the first one found
	*/
	virtual void rem(T data) {
		Node<T>* node = this->find(data);

		rem(node);
	};

	/*
	* Parameters:
	* node - The node to be removed
	*/
	virtual void rem(Node<T>* node) {
		if (node == nullptr) return;
		if (node == tail) rem();
		else {
			remove(node->prev);
			size--;
		}
	};

	/*
	* Clears the list of all elements
	*/
	virtual void clear() {
		Node<T>* i = tail;
		i = i->prev;
		while (i != nullptr) {
			delete(i->next);
			i = i->prev;
		}
		tail = head;
		head->next = nullptr;
		size = 0;
	};

	/*
	* Returns true if the list has no elements. Otherwise returns false.
	*/
	virtual bool isEmpty() { 
		return empty(this->head);
	};

	/*
	* The following functions will tell you if a given element/node is within the list.
	* Returns:
	* true if found. false if not
	*/

	/*
	* Parameters:
	* data - the data in the node to be found
	*/
	virtual bool contains(T data) { 
		Node<T>* current = head;

		while (current->next != nullptr) {
			if (current->next->data == data) return true;
			current = current->next;
		}

		return false;
	};

	/*
	* Parameters:
	* node - the node to be found
	*/
	virtual bool contains(Node<T>* node) { 
		Node<T>* current = head;

		while (current->next != nullptr) {
			if (current->next == node) return true;
			current = current->next;
		}

		return false;
	};

	/*
	* Finds the node that contains an element
	* Parameters:
	* data - The element in the node to find
	* Returns:
	* The Node<T> that contains the element data
	*/
	virtual Node<T>* find(T data) { 
		Node<T>* current = head;

		while (current->next != nullptr) {
			if (current->next->data == data) return current->next;
			current = current->next;
		}

		return nullptr;
	};
	
	/*
	* Returns the element at a given position
	* Parameters:
	* position - The position of the list to get the element from
	* Returns:
	* The element (Type T)
	*/
	virtual T get(int position) {
		if (head == nullptr) throw('n');

		try {

			if (position >= size) {
				throw(position);
			}

			// To find the position
			Node<T>* current = head;

			// populate current with the desired node
			for (int i = 0; i < position && current->next != nullptr; i++) {
				current = current->next;
			}

			if (current->next == nullptr) {
				throw(position);
			}

			return current->next->data;
		}
		catch (int x) {
			cout << "ERROR - index " << x << " out of bounds" << endl;
			return x;
		}
		catch (char x) {
			cout << "Head of list is null!" << endl;
		}
	}

	/*
	* Sets a position of the list to data
	* Parameters:
	* position - The position of the list to set data in
	* data - The data to be set in the list
	*/
	virtual void set(int position, T data) {
		if (head == nullptr) throw('n');

		try {

			if (position >= size) {
				throw(position);
			}

			// To find the position
			Node<T>* current = head;

			// populate current with the desired node
			for (int i = 0; i < position && current->next != nullptr; i++) {
				current = current->next;
			}

			if (current->next == nullptr) {
				throw(position);
			}

			current->next->data = data;
		}
		catch (int x) {
			cout << "ERROR - index " << x << " out of bounds" << endl;
		}
		catch (char x) {
			cout << "Head of list is null!" << endl;
		}
	}

	
	/*
	* Returns the size of the list
	* Returns:
	* An integer reperesenting the size of the list
	*/
	int length() {
		return size;
	}

	/*
	* Prints out each element of the list, and the size of it
	*/
	virtual void printL() {
		printList(head);
		cout << "The list is size " << size << endl;
	}



protected:
	Node<T>* head;
	Node<T>* tail;

	int size;

	/*
	* A helper function to move the tail forward if necessary
	*/
	virtual void incrementTail() {
		this->tail = this->tail->next;
	};
};

#endif //!__LIST_H__