#define RUN ELSE //RUN1 RUN2 RUN3 


#ifdef RUN0

#include"list.h"
#include"studentinfo.h"
#include<iostream>

int main() {
	std::cout << StudentInfo::name() << std::endl;
	std::cout << StudentInfo::id() << std::endl;

	List<int> * l = new List<int>;;
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

	List<std::string> * l = new List<std::string>; 

	l->push_rear("Hello");
	l->push_front("World");
	l->push_front("Bob");
	l->push_front("2");
	l->print();
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

int main() {

	List<int> * l = new List<int>;
	l->push_front(99);


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

int main() {

	List<std::string>::DLNode* m_front = new List<std::string>::DLNode;
	List<std::string>::DLNode* second = new List<std::string>::DLNode;
	List<std::string>::DLNode* third = new List<std::string>::DLNode;

	
	m_front->value("first");
	m_front->prev(nullptr);
	m_front->next(second);

	second->value("second");
	second->prev(m_front);
	second->next(third);

	third->value("third");
	third->prev(second);
	third->next(nullptr);

	List<std::string> * l = new List<std::string>;
	l->m_front = m_front;
	l->m_rear = third;
	l->m_size = 3;

	l->push_front("Zero");

	assert(l->m_size == 4);
	assert(l->m_front->prev() == nullptr);
	assert(l->m_front == m_front->prev());
	assert(l->m_front->next() == m_front);
	assert(l->m_front->value() == "Zero");
	assert(l->m_rear == third);

	return 0;
}

#else


#include"listtests_f22.h"
int main() {
	runTest(test_empty, 0);
	runTest(test_empty, 1);

	runTest(test_push_front, 0);
	runTest(test_push_front, 1);

	runTest(test_push_rear, 0);
	runTest(test_push_rear, 1);

	runTest(test_push_at, 0);
	runTest(test_push_at, 1);
	runTest(test_push_at, 2);
	runTest(test_push_at, 3);
	runTest(test_push_at, 4);
	runTest(test_push_at, 5);
	runTest(test_push_at, 6);

	runTest(test_find, 0);
	runTest(test_find, 1);
	runTest(test_find, 2);
	runTest(test_find, 3);
	runTest(test_find, 4);

	runTest(test_front, 0);
	runTest(test_front, 1);
	
	runTest(test_rear, 0);
	runTest(test_rear, 1);
	
	runTest(test_at, 0);
	runTest(test_at, 1);

	runTest(test_pop_front, 0);
	runTest(test_pop_front, 1);
	runTest(test_pop_front, 2);

	runTest(test_pop_rear, 0);
	runTest(test_pop_rear, 1);
	runTest(test_pop_rear, 2);

	runTest(test_pop_at, 0);
	runTest(test_pop_at, 1);
	runTest(test_pop_at, 2);
	runTest(test_pop_at, 3);
	runTest(test_pop_at, 4);
	runTest(test_pop_at, 5);
	runTest(test_pop_at, 6);
	runTest(test_pop_at, 7);

	runTest(test_pop_value, 0);
	runTest(test_pop_value, 1);
	runTest(test_pop_value, 2);
	runTest(test_pop_value, 3);
	runTest(test_pop_value, 4);
	runTest(test_pop_value, 5);

	runTest(test_print, 0);
	runTest(test_print, 1);

	runTest(test_size, 0);
	runTest(test_size, 1);

	runTest(test_count, 0);
	runTest(test_count, 1);
	runTest(test_count, 2);
	runTest(test_count, 3);
	runTest(test_count, 4);
	runTest(test_count, 5);

	runTest(test_copyCtor, 0);
	runTest(test_copyCtor, 1);
	runTest(test_copyCtor, 2);

	runTest(test_assgnOper, 0);
	runTest(test_assgnOper, 1);
	runTest(test_assgnOper, 2);

	runTest(test_mem_destructor, 0);

	runTest(test_mem_assgnOper, 0);
	runTest(test_mem_assgnOper, 1);


	return 0;
}

#endif