


// Choose which run to compile
#define RUN0 //RUN1 RUN2 RUN3 


#ifdef RUN0

#include"list.h"
#include"studentinfo.h"
#include<iostream>

int main() {
	std::cout << StudentInfo::name() << std::endl;
	std::cout << StudentInfo::id() << std::endl;

	List<int> * l = new List<int>;; //List of integers
	l->push_front(5);
	l->push_front(7);
	l->push_front(9);
	l->push_front(8);
	l->push_front(42);

	List<int> *r = new List< int >;;
	*r = *l;
	r->print();
	std::cout << "\n";
	delete l;
	r->print();
	std::cout << "\n";
	std::cout << r->size();


	//std::cout << l->at(2) << "\n";
	//l->print();

	/*l->push_at(-1, 7);
	std::cout << l->count(7);
	l->print();*/

	

	return 0;

}

#elif defined RUN1

#include"list.h"
#include"studentinfo.h"
#include<iostream>
#include<string>

int main() {

	std::cout << StudentInfo::name() << std::endl;
	std::cout << StudentInfo::id() << std::endl;

	List<std::string> * l = new List<std::string>; //List of integers

	l->push_rear("Hello");
	l->push_front("World");
	l->push_front("Bob");
	l->push_front("2");
	l->print();// 2 Bob World Hello
	std::cout << "\n";


	std::cout << l->pop_value("World") << "\n";
	l->print();

	/*l->pop_at(1);
	l->print();*/

	//l->push_at(-1, "Noboru");
	//l->print(); // 2 bob world 
	//std::cout << l->size();
	return 0;

}

#elif defined RUN2

#define MAKE_MEMBERS_PUBLIC
#include"list.h"
#include<assert.h>

//Unit test example for push_font on initially empty list

int main() {

	// Step 1: Initial state
	// Assume that constructor implemented properly
	// If you're not sure if the constructor is 
	// implemented properly, STOP, go back and make
	// sure. Luckily the default constructor is 
	// done for you.  But the point remains, never,
	// ever, use a function in a test that isn't itself
	// verified to function according to spec.
	List<int> * l = new List<int>;


	// Step 2: Execute the function to test
	l->push_front(99);

	// Step 3: Verify what you expect to observe.
	// You must know what is supposed to happen in
	// order to analyze for correctness. Generally, 
	// you must permute all possible combinations
	// of all member variables.
	assert(l->m_front != nullptr);
	assert(l->m_rear != nullptr);
	assert(l->m_size == 1);
	assert(l->m_front->prev() == nullptr);
	assert(l->m_front->next() == nullptr);
	assert(l->m_front->value() == 99);

	return 0;
}

#elif defined RUN3

#define MAKE_MEMBERS_PUBLIC
#include"list.h"
#include<assert.h>
#include<string>

//Unit test example for push_font on initially non empty list

int main() {

	// Step 1: Initial state
	// Same as above, except we must m_front populate the list
	// However, since we are testing push_front, we cannot
	// use it to generate the initial state of our list
	// to test.  So we have to manually set the initial state
	// in this case we are creating a list with three nodes.
	List<std::string>::DLNode* m_front = new List<std::string>::DLNode;
	List<std::string>::DLNode* second = new List<std::string>::DLNode;
	List<std::string>::DLNode* third = new List<std::string>::DLNode;

	// We have to manually linked everything together:
	m_front->value("first");
	m_front->prev(nullptr);
	m_front->next(second);

	second->value("second");
	second->prev(m_front);
	second->next(third);

	third->value("third");
	third->prev(second);
	third->next(nullptr);

	// Now we create  List object and inject the initial control state:
	List<std::string> * l = new List<std::string>;
	l->m_front = m_front;
	l->m_rear = third;
	l->m_size = 3;

	// Step 2: Now with the list given a complete and correct starting state
	// We can test various member functions for correctness.
	// For example we can use this as one test for push_front;
	l->push_front("Zero");

	// Step 3: Verify:  Technically, we should examine all 
	// member variables, and all nodes' value, nxt, prv pointers
	// to ensure that the push_front didn't mangle any of the
	// internal nodes.  But, this is mostly just to illustrate
	// how you might develop your own tests.  
	assert(l->m_size == 4);
	assert(l->m_front->prev() == nullptr);
	assert(l->m_front == m_front->prev());
	assert(l->m_front->next() == m_front);
	assert(l->m_front->value() == "Zero");
	assert(l->m_rear == third);

	return 0;
}

#else


// You will have to count the tests when you go through them yourself
// You can post them on the disucssion forum to help our your classmates
// and earn participcation
#include"listtests_f22.h"
int main() {
	runTest(test_empty, 0);
	
	return 0;
}

#endif