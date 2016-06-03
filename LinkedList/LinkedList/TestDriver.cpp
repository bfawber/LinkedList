/*
 * Created by Bryan Fawber 06/01/216
 * 
 * The purpose of this driver is to test the functionality the self defined linked lists.
 * If a new function is added to manipulate/retrieve data from the list, a test should be added here.
 *
 * TESTS
 * ---------------------------------------------------------------------------------------------------
 * 
 * Node.h
 * -------
 * insert 
 * end
 * empty
 * makenull
 * remove
 * locate
 * -------
 *
 * List.h
 * -------
 * add
 * rem
 * contains
 * get
 * find
 * 
 */

#include<iostream>
#include "Node.h"
#include "List.h"

using namespace std;

int main(void) {
	char x;
	Node<int>* head;
	Node<int>* tail;
	cout << "Which tests are your running? (L|l for List, N | n for Node)" << endl;
	cin >> x;

	if (x == 'N' || x == 'n') {

		// START insert(T x, Node<T>* node) test
		cout << "START insert(T x, Node<T>* node) test" << endl;
		head = new Node<int>;

		insert(0, head);
		insert(1, head->next);
		insert(2, head->next->next);

		printList(head);

		cout << "END insert(T x, Node<T>* node) test" << endl << endl;
		// END insert(T x, Node<T>* node) test

		// START end(Node<T>* head) test
		cout << "START end(Node<T>* head) test" << endl;
		tail = end(head);

		insert(3, tail);

		printList(head);
		cout << "END end(Node<T>* head) test" << endl << endl;
		// END end(Node<T>* head) test

		// START insert(Node<T>* node, Node<T>* newNode) test
		cout << "START insert(Node<T>* node, Node<T>* newNode) test" << endl;

		Node<int>* t = new Node<int>;
		t->data = 4;

		insert(tail->next, t);
		printList(head);

		cout << "END insert(Node<T>* node, Node<T>* newNode) test" << endl << endl;
		// END insert(Node<T>* node, Node<T>* newNode) test

		// START remove(Node<T>* node) test
		cout << "START remove(Node<T>* node) test" << endl;

		remove(head);
		printList(head);

		cout << "END remove(Node<T>* node) test" << endl << endl;
		// END remove(Node<T>* node) test

		// START locate(T x, Node<T>* head) test
		cout << "START locate(T x, Node<T>* head) test" << endl;

		Node<int>* z = locate(3, head);

		if (z != nullptr) {
			cout << z->next->data << " was found!" << endl;
		}

		z = locate(10, head);
		if (z == nullptr) {
			cout << "10 was not found!" << endl;
		}

		cout << "END locate(T x, Node<T>* head) test" << endl << endl;
		// END locate(T x, Node<T>* head) test


		// START makenull(Node<T>* head) && empty(Node<T>* head) test
		cout << "START makenull(Node<T>* head) && empty(Node<T>* head) test" << endl;

		if (!empty(head)) {
			cout << "Before makenull PASS" << endl;
		}

		makenull(head);

		if (empty(head)) {
			cout << "After makenull PASS" << endl;
		}

		cout << "END makenull(Node<T>* head) && empty(Node<T>* head) test" << endl << endl;
		delete(head);
	}

	// List Tests
	else if (x == 'L' || x == 'l') {

		// START List<T> add function tests
		cout << "START List<T> add function tests" << endl;
		List<int> testList;
		Node<int>* n = new Node<int>;
		n->data = 3;
		Node<int>* n2 = new Node<int>;
		n2->data = 900;

		// add(T data)
		testList.add(1);

		// add(int position, T data)
		testList.add(0, 0);

		// add(int position, Node<T>* newNode)
		testList.add(2, n);

		// add(Node<T>* node, Node<T>* newNode)
		testList.add(n, n2);

		testList.printL();

		cout << "END List<T> add function tests" << endl << endl;
		// END List<T> add function tests

		// START List<T> contains function tests
		cout << "START List<T> contains function tests" << endl;

		if (testList.contains(1)) {
			cout << "The list contains 1" << endl;
		}
		if (testList.contains(n)) {
			cout << "The list contains n" << endl;
		}
		if (!testList.contains(5)) {
			cout << "The list does not contain 5" << endl;
		}
		Node<int>* q = new Node<int>;
		if (!testList.contains(q)) {
			cout << "The list does not contain q" << endl;
		}

		testList.printL();
		delete(q);

		cout << "END List<T> contains function tests" << endl << endl;
		// END List<T> contains function tests

		// START List<T> get function test
		cout << "START List<T> get function test" << endl;

		// Valid
		cout << testList.get(1) << endl;

		// Invalid
		testList.get(4);

		testList.printL();

		cout << "END List<T> get function test" << endl << endl;
		// END List<T> get function test

		// START List<T> rem function tests
		cout << "START List<T> rem function tests" << endl;

		// rem()
		testList.rem();

		// rem(Node<T>* node)
		testList.rem(n);

		// rem(T data) && find(T data)
		testList.rem(0);

		testList.printL();

		cout << "END List<T> rem function tests" << endl << endl;
		// END List<T> rem function tests

		testList.clear();

		if (testList.isEmpty()) {
			cout << "The list is empty!" << endl;
		}

		testList.printL();

		// START List<T> set function
		cout << "START List<T> set function" << endl;

		for (int i = 0; i < 20; i++) {
			testList.add(i);
		}

		// Valid
		testList.set(5, 95);

		//Invalid
		testList.set(20, 4);

		testList.printL();

		cout << "END List<T> set function" << endl << endl;

	}
	cin >> x;
	return 0;
}