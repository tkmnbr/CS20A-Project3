#ifndef PROJECT3_LTEST_H
#define PROJECT3_LTEST_H

#define MAKE_MEMBERS_PUBLIC

#include<iostream>
#include <fstream>
#include <sstream> 
#include<string>
#include<iterator>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<functional>

#ifdef _MSC_VER 
#define __func__ __FUNCTION__
#endif


// Comment this out if not using
#include"debugmem.h"

// Blank out macros if debugmem.h is not included
#ifndef DEBUG_NEW
#define DEBUG_NEW new 
#endif
#ifndef RESET()
#define RESET()
#endif
#ifndef GETMEMORYREPORT()
#define GETMEMORYREPORT()
#endif
#ifndef SIZE()
#define SIZE() 0
#endif
#include"list.h"



int runTest(std::function<int(int)> test, int testNum) {
	int retval = 0;
	try {
		retval = test(testNum);
	}
	catch (const std::runtime_error& re) {
		std::cerr << "Runtime error: " << re.what() << std::endl;
		retval = 1;
	}
	catch (const std::exception& ex) {
		std::cerr << "Error occurred: " << ex.what() << std::endl;
		retval = 1;
	}
	catch (...) {
		std::cerr << "Unknown failure occurred. Possible memory corruption" << std::endl;
		retval = 1;;
	}
	return retval;
}


//Test empty
int test_empty(int testNum) {
	std::cout << __func__ << testNum << std::endl;
	std::string name = std::string(__func__);
	switch (testNum) {
	case 0: {

		List<int> * l = new List<int>;

		assert(l->empty() == true);

		break;
	}
	case 1: {

		//Make some control nodes
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;
		List<std::string>::DLNode* second = new List<std::string>::DLNode;
		List<std::string>::DLNode* third = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(second);

		second->value("second");
		second->prev(m_front);
		second->next(third);

		third->value("third");
		third->prev(second);
		third->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;

		assert(l->empty() == false);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}
	return 0;
}


//Test push_front
int test_push_front(int testNum) {
	std::cout << __func__ << testNum << std::endl;
	std::string name = std::string(__func__);

	switch (testNum) {
	case 0: {

		List<int> * l = new List<int>;

		l->push_front(99);

		assert(l->m_front != nullptr);
		assert(l->m_rear != nullptr);

		assert(l->m_front->prev() == nullptr);
		assert(l->m_front->next() == nullptr);

		assert(l->m_front->value() == 99);
		assert(l->m_size == 1);

		break;
	}
	case 1: {

		//Make some control nodes
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;
		List<std::string>::DLNode* second = new List<std::string>::DLNode;
		List<std::string>::DLNode* third = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(second);

		second->value("second");
		second->prev(m_front);
		second->next(third);

		third->value("third");
		third->prev(second);
		third->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;

		//Now with the list given a complete and correct starting state
		//We can test various member functions for correctness.
		//For example we can use this as one test for push_front;
		l->push_front("Zero");

		//Examing the final state of our list after call
		assert(l->m_size == 4);
		assert(l->m_front != nullptr);
		assert(l->m_front->prev() == nullptr);
		assert(l->m_front == m_front->prev());
		assert(l->m_front->next() == m_front);
		assert(l->m_front->value() == "Zero");
		assert(l->m_rear == third);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}
	return 0;
}

//Test push_rear
int test_push_rear(int testNum) {
	std::cout << __func__ << testNum << std::endl;
	std::string name = std::string(__func__);
	switch (testNum) {
	case 0: {

		List<int> * l = new List<int>;

		l->push_rear(99);
		assert(l->m_front != nullptr);
		assert(l->m_rear != nullptr);
		assert(l->m_front->prev() == nullptr);
		assert(l->m_front->next() == nullptr);
		assert(l->m_front->value() == 99);
		assert(l->m_size == 1);
		break;
	}
	case 1: {

		//Make some control nodes
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;
		List<std::string>::DLNode* second = new List<std::string>::DLNode;
		List<std::string>::DLNode* third = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(second);

		second->value("second");
		second->prev(m_front);
		second->next(third);

		third->value("third");
		third->prev(second);
		third->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;

		//Now with the list given a complete and correct starting state
		//We can test various member functions for correctness.
		//For example we can use this as one test for push_rear;
		l->push_rear("forth");

		//Examing the final state of our list after call
		assert(l->m_size == 4);
		assert(l->m_front != nullptr);
		assert(l->m_rear != nullptr);
		assert(l->m_front == m_front);
		assert(l->m_rear->next() == nullptr);
		assert(l->m_rear->value() == "forth");
		assert(l->m_rear->prev() == third);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}
	return 0;
}

//Test push_at
int test_push_at(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl;
	switch (testNum) {
	case 0: {

		List<int> * l = new List<int>;

		l->push_at(0, 1);

		assert(l->m_front != nullptr);
		assert(l->m_rear != nullptr);

		assert(l->m_size == 1);
		assert(l->m_front->value() == 1);
		assert(l->m_front == l->m_rear);

		assert(l->m_front->next() == nullptr);
		assert(l->m_front->prev() == nullptr);
		break;

	}
	case 1: {

		List<int> * l = new List<int>;

		l->push_at(-1, 1);

		assert(l->m_front != nullptr);
		assert(l->m_rear != nullptr);

		assert(l->m_size == 1);
		assert(l->m_front->value() == 1);
		assert(l->m_front == l->m_rear);

		assert(l->m_front->next() == nullptr);
		assert(l->m_front->prev() == nullptr);
		break;
	}
	case 2: {
		List<int> * l = new List<int>;

		l->push_at(99, 1);

		assert(l->m_front != nullptr);
		assert(l->m_rear != nullptr);
		assert(l->m_front->value() == 1);
		assert(l->m_size == 1);
		assert(l->m_front == l->m_rear);
		assert(l->m_front->next() == nullptr);
		assert(l->m_front->prev() == nullptr);
		break;
	}
	case 3: {
		//Make some control nodes
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;
		List<std::string>::DLNode* second = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(second);

		second->value("second");
		second->prev(m_front);
		second->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = second;
		l->m_size = 2;

		l->push_at(0, "Zero");

		//Examing the final state of our list after call
		assert(l->m_front != nullptr);
		assert(l->m_rear != nullptr);
		assert(l->m_size == 3);
		assert(l->m_front->prev() == nullptr);
		assert(l->m_front == m_front->prev());
		assert(l->m_front->next() == m_front);
		assert(l->m_front->value() == "Zero");
		assert(l->m_rear == second);

		break;
	}
	case 4: {
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;
		List<std::string>::DLNode* second = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(second);

		second->value("second");
		second->prev(m_front);
		second->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = second;
		l->m_size = 2;

		l->push_at(-1, "Zero");

		//Examing the final state of our list after call
		assert(l->m_front != nullptr);
		assert(l->m_rear != nullptr);
		assert(l->m_size == 3);
		assert(l->m_front->prev() == nullptr);
		assert(l->m_front == m_front->prev());
		assert(l->m_front->next() == m_front);
		assert(l->m_front->value() == "Zero");
		assert(l->m_rear == second);

		break;
	}
	case 5: {
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;
		List<std::string>::DLNode* second = new List<std::string>::DLNode;

		//Link together to make a valid linked list
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(second);

		second->value("second");
		second->prev(m_front);
		second->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = second;
		l->m_size = 2;

		l->push_at(4, "third");

		//Examing the final state of our list after call
		assert(l->m_front != nullptr);
		assert(l->m_rear != nullptr);
		assert(l->m_size == 3);
		assert(l->m_front == m_front);
		assert(l->m_rear->next() == nullptr);
		assert(l->m_rear->value() == "third");
		assert(l->m_rear->prev() == second);
		break;
	}
	case 6: {
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;
		List<std::string>::DLNode* second = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(second);

		second->value("second");
		second->prev(m_front);
		second->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = second;
		l->m_size = 2;

		l->push_at(1, "half");

		//Examing the final state of our list after call
		assert(l->m_size == 3);
		assert(l->m_front == m_front);

		assert(l->m_front != nullptr);
		assert(l->m_rear != nullptr);

		assert(l->m_front->prev() == nullptr);
		assert(l->m_front->next()->value() == "half");
		assert(l->m_rear->prev() == l->m_front->next());
		assert(l->m_rear == second);
		assert(l->m_rear->next() == nullptr);
		assert(l->m_front->next()->next() == l->m_rear);
		assert(l->m_front == l->m_rear->prev()->prev());
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}
	return 0;
}

//Test find
int test_find(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl;
	switch (testNum) {
	case 0: {
		List<int> * l = new List<int>;

		assert(l->find(100) == -3);

		break;
	}
	case 1: {
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;
		List<std::string>::DLNode* second = new List<std::string>::DLNode;
		List<std::string>::DLNode* third = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(second);

		second->value("second");
		second->prev(m_front);
		second->next(third);

		third->value("third");
		third->prev(second);
		third->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;

		//Examing the final state of our list after call
		assert(l->find("Zero") == -3);

		break;
	}
	case 2: {
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;
		List<std::string>::DLNode* second = new List<std::string>::DLNode;
		List<std::string>::DLNode* third = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(second);

		second->value("second");
		second->prev(m_front);
		second->next(third);

		third->value("third");
		third->prev(second);
		third->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;

		//Examing the final state of our list after call

		assert(l->find("first") == 0);

		break;
	}
	case 3: {
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;
		List<std::string>::DLNode* second = new List<std::string>::DLNode;
		List<std::string>::DLNode* third = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(second);

		second->value("second");
		second->prev(m_front);
		second->next(third);

		third->value("third");
		third->prev(second);
		third->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;

		//Examing the final state of our list after call

		assert(l->find("second") == 1);

		break;
	}
	case 4: {
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;
		List<std::string>::DLNode* second = new List<std::string>::DLNode;
		List<std::string>::DLNode* third = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(second);

		second->value("second");
		second->prev(m_front);
		second->next(third);

		third->value("third");
		third->prev(second);
		third->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;

		//Examing the final state of our list after call
		assert(l->find("third") == 2);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;


	}
	return 0;
}

//Test front
int test_front(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl;
	switch (testNum) {
	case 0: {
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;

		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(nullptr);


		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = m_front;
		l->m_size = 1;

		assert(l->front() == "first");
		break;
	}
	case 1: {
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;
		List<std::string>::DLNode* second = new List<std::string>::DLNode;
		List<std::string>::DLNode* third = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(second);

		second->value("second");
		second->prev(m_front);
		second->next(third);

		third->value("third");
		third->prev(second);
		third->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;

		assert(l->front() == "first");
		break;
	}

	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;


	}
	return 0;
}


//Test rear
int test_rear(int testNum) {
	std::string name = std::string(__func__);

	std::cout << __func__ << testNum << std::endl;
	switch (testNum) {
	case 0: {
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;
		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = m_front;
		l->m_size = 1;

		assert(l->rear() == "first");
		break;
	}
	case 1: {
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;
		List<std::string>::DLNode* second = new List<std::string>::DLNode;
		List<std::string>::DLNode* third = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(second);

		second->value("second");
		second->prev(m_front);
		second->next(third);

		third->value("third");
		third->prev(second);
		third->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;

		assert(l->rear() == "third");
		break;
	}

	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}
	return 0;
}
//Test at
int test_at(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl;
	switch (testNum) {
	case 0: {
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(nullptr);


		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = m_front;
		l->m_size = 1;

		assert(l->at(0) == "first");
		break;
	}
	case 1: {
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;
		List<std::string>::DLNode* second = new List<std::string>::DLNode;
		List<std::string>::DLNode* third = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(second);

		second->value("second");
		second->prev(m_front);
		second->next(third);

		third->value("third");
		third->prev(second);
		third->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;

		assert(l->at(0) == "first");
		assert(l->at(1) == "second");
		assert(l->at(2) == "third");
		break;
	}

	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
	}
	return 0;
}

//Test pop_front
int test_pop_front(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl;
	switch (testNum) {
	case 0: {
		List<int> * l = new List<int>;
		assert(l->pop_front() == false);
		break;
	}
	case 1: {
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(nullptr);


		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = m_front;
		l->m_size = 1;

		assert(l->pop_front() == true);
		assert(l->m_size == 0);
		assert(l->m_front == nullptr);
		assert(l->m_rear == nullptr);
		break;
	}
	case 2: {
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;
		List<std::string>::DLNode* second = new List<std::string>::DLNode;
		List<std::string>::DLNode* third = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(second);

		second->value("second");
		second->prev(m_front);
		second->next(third);

		third->value("third");
		third->prev(second);
		third->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;

		assert(l->pop_front() == true);
		assert(l->m_size == 2);
		assert(l->m_front == second);
		assert(l->m_rear == third);
		assert(l->m_front->prev() == nullptr);
		break;
	}

	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}
	return 0;
}
//Test pop_rear
int test_pop_rear(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl;
	switch (testNum) {
	case 0: {
		List<int> * l = new List<int>;
		assert(l->pop_rear() == false);
		break;

	}
	case 1: {
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(nullptr);


		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = m_front;
		l->m_size = 1;

		assert(l->pop_rear() == true);
		assert(l->m_size == 0);
		assert(l->m_front == nullptr);
		assert(l->m_rear == nullptr);
		break;
	}
	case 2: {
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;
		List<std::string>::DLNode* second = new List<std::string>::DLNode;
		List<std::string>::DLNode* third = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(second);

		second->value("second");
		second->prev(m_front);
		second->next(third);

		third->value("third");
		third->prev(second);
		third->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;

		assert(l->pop_rear() == true);
		assert(l->m_size == 2);
		assert(l->m_front == m_front);
		assert(l->m_rear == second);
		assert(l->m_rear->next() == nullptr);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
	}
	return 0;
}


int test_pop_at(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {
		List<int> * l = new List<int>;
		assert(l->pop_at(-1) == false);
		break;
	}
	case 1: {
		List<int> * l = new List<int>;
		assert(l->pop_at(9999) == false);
		break;
	}
	case 2: {
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = m_front;
		l->m_size = 1;

		assert(l->pop_at(-1) == false);

		break;
	}
	case 3: {
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(nullptr);


		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = m_front;
		l->m_size = 1;

		assert(l->pop_at(9999) == false);

		break;
	}
	case 4: {
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(nullptr);


		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = m_front;
		l->m_size = 1;

		assert(l->pop_at(0) == true);
		assert(l->m_size == 0);
		assert(l->m_front == nullptr);
		assert(l->m_rear == nullptr);
		break;
	}
	case 5: {
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;
		List<std::string>::DLNode* second = new List<std::string>::DLNode;
		List<std::string>::DLNode* third = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(second);

		second->value("second");
		second->prev(m_front);
		second->next(third);

		third->value("third");
		third->prev(second);
		third->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;

		assert(l->pop_at(0) == true);
		assert(l->m_size == 2);
		assert(l->m_front == second);
		assert(l->m_front->prev() == nullptr);
		assert(l->m_rear == third);
		break;

	}
	case 6: {
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;
		List<std::string>::DLNode* second = new List<std::string>::DLNode;
		List<std::string>::DLNode* third = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(second);

		second->value("second");
		second->prev(m_front);
		second->next(third);

		third->value("third");
		third->prev(second);
		third->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;

		assert(l->pop_at(2) == true);
		assert(l->m_size == 2);
		assert(l->m_front == m_front);
		assert(l->m_rear->next() == nullptr);
		assert(l->m_rear == second);
		break;

	}
	case 7: {
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;
		List<std::string>::DLNode* second = new List<std::string>::DLNode;
		List<std::string>::DLNode* third = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(second);

		second->value("second");
		second->prev(m_front);
		second->next(third);

		third->value("third");
		third->prev(second);
		third->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;

		assert(l->pop_at(1) == true);
		assert(l->m_size == 2);

		assert(l->m_front == m_front);
		assert(l->m_rear == third);

		assert(l->m_front->next() == third);
		assert(l->m_rear->prev() == m_front);
		break;


	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}
	return 0;
}

int test_pop_value(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {//Test with empty list
		List<int> * l = new List<int>;
		assert(l->pop_value(1) == -3);
		break;
	}
	case 1: {
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = m_front;
		l->m_size = 1;

		assert(l->pop_value("second") == -2);

		break;
	}

	case 2: {
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(nullptr);


		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = m_front;
		l->m_size = 1;

		assert(l->pop_value("first") == 0);
		assert(l->m_size == 0);
		assert(l->m_front == nullptr);
		assert(l->m_rear == nullptr);
		break;
	}
	case 3: {
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;
		List<std::string>::DLNode* second = new List<std::string>::DLNode;
		List<std::string>::DLNode* third = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(second);

		second->value("second");
		second->prev(m_front);
		second->next(third);

		third->value("third");
		third->prev(second);
		third->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;

		assert(l->pop_value("first") == 0);
		assert(l->m_size == 2);
		assert(l->m_front == second);
		assert(l->m_front != nullptr);
		assert(l->m_front->prev() == nullptr);
		assert(l->m_rear == third);
		break;

	}
	case 4: {
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;
		List<std::string>::DLNode* second = new List<std::string>::DLNode;
		List<std::string>::DLNode* third = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(second);

		second->value("second");
		second->prev(m_front);
		second->next(third);

		third->value("third");
		third->prev(second);
		third->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;

		assert(l->pop_value("third") == 2);
		assert(l->m_size == 2);
		assert(l->m_front == m_front);
		assert(l->m_rear != nullptr);
		assert(l->m_rear->next() == nullptr);
		assert(l->m_rear == second);
		break;

	}
	case 5: {
		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;
		List<std::string>::DLNode* second = new List<std::string>::DLNode;
		List<std::string>::DLNode* third = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value("first");
		m_front->prev(nullptr);
		m_front->next(second);

		second->value("second");
		second->prev(m_front);
		second->next(third);

		third->value("third");
		third->prev(second);
		third->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;

		assert(l->pop_value("second") == 1);
		assert(l->m_size == 2);

		assert(l->m_front == m_front);
		assert(l->m_rear == third);

		assert(l->m_front != nullptr);
		assert(l->m_rear != nullptr);
		assert(l->m_front->next() == third);
		assert(l->m_rear->prev() == m_front);

		break;


	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}
	return 0;
}
int test_print(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {

		std::string test_string1("Tom Dick Mary");
		std::stringstream buffer(test_string1);
		std::vector<std::string> test_vector{ std::istream_iterator<std::string>(buffer), std::istream_iterator<std::string>() };
		buffer.str("");

		List<std::string>::DLNode* m_front = new List<std::string>::DLNode;
		List<std::string>::DLNode* second = new List<std::string>::DLNode;
		List<std::string>::DLNode* third = new List<std::string>::DLNode;

		//Link together to make a valid linked list 
		m_front->value(test_vector[0]);
		m_front->prev(nullptr);
		m_front->next(second);

		second->value(test_vector[1]);
		second->prev(m_front);
		second->next(third);

		third->value(test_vector[2]);
		third->prev(second);
		third->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;

		std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());

		l->print();
		std::cout.rdbuf(old);

		std::string text = buffer.str();

		std::vector<std::string> ret{ std::istream_iterator<std::string>(buffer),
			std::istream_iterator<std::string>() };

		assert(text.length() == test_string1.length());
		assert(text == test_string1);
		for (int i = 0; i < ret.size(); i++) {
			assert(ret[i] == test_vector[i]);
		}



		break;

	}
	case 1: {

		std::string test_string1("");
		std::stringstream buffer(test_string1);
		std::vector<std::string> test_vector{ std::istream_iterator<std::string>(buffer), std::istream_iterator<std::string>() };
		buffer.str("");

		//Assume Constructor Correctly Implemented
		List<std::string> * l = new List<std::string>;

		//hijack cout buffer
		std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());

		l->print();

		//restore cout buffer
		std::cout.rdbuf(old);

		std::string text = buffer.str();
		std::vector<std::string> ret{ std::istream_iterator<std::string>(buffer),
			std::istream_iterator<std::string>() };

		assert(text.length() == test_string1.length());
		assert(text == test_string1);
		for (int i = 0; i < ret.size(); i++) {
			assert(ret[i] == test_vector[i]);
		}

		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}
	return 0;

}
int test_size(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {

		List<int>::DLNode* m_front = new List<int>::DLNode;
		List<int>::DLNode* second = new List<int>::DLNode;
		List<int>::DLNode* third = new List<int>::DLNode;

		//Link together to make a valid linked list 
		m_front->value(2);
		m_front->prev(nullptr);
		m_front->next(second);

		second->value(4);
		second->prev(m_front);
		second->next(third);

		third->value(76);
		third->prev(second);
		third->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<int> * l = new List<int>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;

		assert(l->size() == 3);

		break;

	}
	case 1: {
		List<std::string> * l = new List<std::string>;
		assert(l->size() == 0);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}
	return 0;

}
int test_count(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {

		List<int>::DLNode* m_front = new List<int>::DLNode;
		List<int>::DLNode* second = new List<int>::DLNode;
		List<int>::DLNode* third = new List<int>::DLNode;

		//Link together to make a valid linked list 
		m_front->value(2);
		m_front->prev(nullptr);
		m_front->next(second);

		second->value(4);
		second->prev(m_front);
		second->next(third);

		third->value(76);
		third->prev(second);
		third->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<int> * l = new List<int>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;

		assert(l->count(42) == 0);

		break;

	}
	case 1: {
		List<int> * l = new List<int>;
		assert(l->count(10) == 0);
		break;
	}
	case 2: {

		List<int>::DLNode* m_front = new List<int>::DLNode;

		//Link together to make a valid linked list 
		m_front->value(2);
		m_front->prev(nullptr);
		m_front->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<int> * l = new List<int>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = m_front;
		l->m_size = 1;

		assert(l->count(8) == 0);
		break;
	}
	case 3: {

		List<int>::DLNode* m_front = new List<int>::DLNode;

		//Link together to make a valid linked list 
		m_front->value(2);
		m_front->prev(nullptr);
		m_front->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<int> * l = new List<int>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = m_front;
		l->m_size = 1;

		assert(l->count(2) == 1);
		break;
	}
	case 4: {

		List<int>::DLNode* m_front = new List<int>::DLNode;
		List<int>::DLNode* second = new List<int>::DLNode;
		List<int>::DLNode* third = new List<int>::DLNode;

		//Link together to make a valid linked list 
		m_front->value(2);
		m_front->prev(nullptr);
		m_front->next(second);

		second->value(4);
		second->prev(m_front);
		second->next(third);

		third->value(76);
		third->prev(second);
		third->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<int> * l = new List<int>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;

		assert(l->count(2) == 1);
		break;
	}
	case 5: {

		List<int>::DLNode* m_front = new List<int>::DLNode;
		List<int>::DLNode* second = new List<int>::DLNode;
		List<int>::DLNode* third = new List<int>::DLNode;

		//Link together to make a valid linked list 
		m_front->value(2);
		m_front->prev(nullptr);
		m_front->next(second);

		second->value(2);
		second->prev(m_front);
		second->next(third);

		third->value(2);
		third->prev(second);
		third->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<int> * l = new List<int>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;

		assert(l->count(2) == 3);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}
	return 0;

}

int test_copyCtor(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {

		List<int> * l = new List<int>;
		List<int> * p = new List<int>(*l);

		//Set up the initial state of the list to test
		assert(p->m_front == nullptr);
		assert(p->m_rear == nullptr);
		assert(p->m_size == 0);

		break;

	}

	case 1: {


		List<int>::DLNode* m_front = new List<int>::DLNode;
		List<int>::DLNode* second = new List<int>::DLNode;
		List<int>::DLNode* third = new List<int>::DLNode;

		//Link together to make a valid linked list 
		m_front->value(2);
		m_front->prev(nullptr);
		m_front->next(second);

		second->value(4);
		second->prev(m_front);
		second->next(third);

		third->value(76);
		third->prev(second);
		third->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<int> * l = new List<int>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;

		List<int> * p = new List<int>(*l);

		assert(p->m_front != nullptr);
		assert(p->m_rear != nullptr);
		assert(p->m_size == 3);

		assert(p->m_front->value() == m_front->value());
		assert(p->m_front->next()->value() == second->value());
		assert(p->m_rear->prev()->value() == second->value());
		assert(p->m_rear->value() == third->value());

		assert(p->m_front != m_front);
		assert(p->m_rear != third);

		break;


	}
	case 2: {
		List<int>::DLNode* m_front = new List<int>::DLNode;
		List<int>::DLNode* second = new List<int>::DLNode;
		List<int>::DLNode* third = new List<int>::DLNode;

		//Link together to make a valid linked list 
		m_front->value(2);
		m_front->prev(nullptr);
		m_front->next(second);

		second->value(4);
		second->prev(m_front);
		second->next(third);

		third->value(76);
		third->prev(second);
		third->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<int> * l = new List<int>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;

		List<int> * p = new List<int>(*l);

		assert(p->m_front != nullptr);
		assert(p->m_rear != nullptr);
		assert(p->m_size == 3);

		assert(p->m_front->value() == m_front->value());
		assert(p->m_front->next()->value() == second->value());
		assert(p->m_rear->prev()->value() == second->value());
		assert(p->m_rear->value() == third->value());


		//check aliasing
		assert(p->m_front != m_front);
		assert(p->m_front != second);
		assert(p->m_front != third);

		assert(p->m_front->next() != m_front);
		assert(p->m_front->next() != second);
		assert(p->m_front->next() != third);

		assert(p->m_rear != m_front);
		assert(p->m_rear != second);
		assert(p->m_rear != third);

		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}
	return 0;

}


int test_assgnOper(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {

		List<int> * l = new List<int>;
		List<int> * p = new List<int>;

		*p = *l;
		//Set up the initial state of the list to test

		assert(p->m_front == nullptr);
		assert(p->m_rear == nullptr);
		assert(p->m_size == 0);

		break;

	}

	case 1: {

		List<int>::DLNode* m_front = new List<int>::DLNode;
		List<int>::DLNode* second = new List<int>::DLNode;
		List<int>::DLNode* third = new List<int>::DLNode;

		//Link together to make a valid linked list 
		m_front->value(2);
		m_front->prev(nullptr);
		m_front->next(second);

		second->value(4);
		second->prev(m_front);
		second->next(third);

		third->value(76);
		third->prev(second);
		third->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<int> * l = new List<int>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;

		List<int> * p = new List<int>;

		*p = *l;

		assert(p->m_front != nullptr);
		assert(p->m_rear != nullptr);
		assert(p->m_size == 3);

		assert(p->m_front->value() == m_front->value());
		assert(p->m_front->next()->value() == second->value());
		assert(p->m_rear->prev()->value() == second->value());
		assert(p->m_rear->value() == third->value());

		assert(p->m_front != m_front);
		assert(p->m_rear != third);

		break;


	}

	case 2: {
		List<int>::DLNode* m_front = new List<int>::DLNode;
		List<int>::DLNode* second = new List<int>::DLNode;
		List<int>::DLNode* third = new List<int>::DLNode;

		//Link together to make a valid linked list 
		m_front->value(2);
		m_front->prev(nullptr);
		m_front->next(second);

		second->value(4);
		second->prev(m_front);
		second->next(third);

		third->value(76);
		third->prev(second);
		third->next(nullptr);

		//Assume Constructor Correctly Implemented
		List<int> * l = new List<int>;

		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;

		List<int> * p = new List<int>;

		*p = *l;

		assert(p->m_front != nullptr);
		assert(p->m_rear != nullptr);
		assert(p->m_front->next() != nullptr);
		assert(p->m_rear->prev() != nullptr);

		assert(p->m_size == 3);

		assert(p->m_front->value() == m_front->value());
		assert(p->m_front->next()->value() == second->value());
		assert(p->m_rear->prev()->value() == second->value());
		assert(p->m_rear->value() == third->value());


		//check aliasing
		assert(p->m_front != m_front);
		assert(p->m_front != second);
		assert(p->m_front != third);

		assert(p->m_front->next() != m_front);
		assert(p->m_front->next() != second);
		assert(p->m_front->next() != third);

		assert(p->m_rear != m_front);
		assert(p->m_rear != second);
		assert(p->m_rear != third);

		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}
	return 0;

}


int test_mem_destructor(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {
		RESET();
		List<int>::DLNode* m_front = DEBUG_NEW List<int>::DLNode;
		List<int>::DLNode* second = DEBUG_NEW List<int>::DLNode;
		List<int>::DLNode* third = DEBUG_NEW List<int>::DLNode;

		//Link together to make a valid linked list 
		m_front->value(2);
		m_front->prev(nullptr);
		m_front->next(second);

		second->value(4);
		second->prev(m_front);
		second->next(third);

		third->value(76);
		third->prev(second);
		third->next(nullptr);

		//Assume Constructor Correctly Implemented
		{
			List<int> * l = new List<int>;

			//Set up the initial state of the list to test
			l->m_front = m_front;
			l->m_rear = third;
			l->m_size = 3;

			//destructor
			delete l;
		}

		//GETMEMORYREPORT();
		if (SIZE() != 0) {
			std::cerr << "Destructor: Memory Leak detected" << std::endl;
		}
		assert(SIZE() == 0);

		break;

	}

	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;

	}
	return 0;
}

int test_mem_assgnOper(int testNum) {
	std::string name = std::string(__func__);
	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {
		//Assume Constructor Correctly Implemented
		List<int> * l = new List<int>;
		List<int> * p = new List<int>;

		RESET();

		List<int>::DLNode* m_front = DEBUG_NEW List<int>::DLNode;
		List<int>::DLNode* second = DEBUG_NEW List<int>::DLNode;
		List<int>::DLNode* third = DEBUG_NEW List<int>::DLNode;

		//Link together to make a valid linked list 
		m_front->value(2);
		m_front->prev(nullptr);
		m_front->next(second);

		second->value(4);
		second->prev(m_front);
		second->next(third);

		third->value(76);
		third->prev(second);
		third->next(nullptr);


		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;

		*l = *p;

		//GETMEMORYREPORT();
		if (SIZE() != 0) {
			std::cerr << "Assign Op: Memory Leak detected" << std::endl;
		}
		assert(SIZE() == 0);
		break;
	}
	case 1: {

		//Assume Constructor Correctly Implemented
		List<int> * l = new List<int>;

		RESET();
		List<int>::DLNode* m_front = DEBUG_NEW List<int>::DLNode;
		List<int>::DLNode* second = DEBUG_NEW List<int>::DLNode;
		List<int>::DLNode* third = DEBUG_NEW List<int>::DLNode;

		//Link together to make a valid linked list 
		m_front->value(2);
		m_front->prev(nullptr);
		m_front->next(second);

		second->value(4);
		second->prev(m_front);
		second->next(third);

		third->value(76);
		third->prev(second);
		third->next(nullptr);


		//Set up the initial state of the list to test
		l->m_front = m_front;
		l->m_rear = third;
		l->m_size = 3;
		//GETMEMORYREPORT();

		*l = *l;
		if (SIZE() != 3) {
			std::cerr << "Assign Op: Improper assignment" << std::endl;
		}
		assert(SIZE() == 3);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
	}
	return 0;

}


#endif
