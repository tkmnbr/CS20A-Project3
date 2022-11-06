#ifndef F22_CS20A_LIST_H
#define F22_CS20A_LIST_H

#include<iostream>
#include<assert.h>
// Linked List object that maintains both m_front and m_rear pointers
// and the m_size of the list.  Note that you have to keep the m_front,
// m_rear and m_size consistent with the intended state of the List 
// otherwise very bad things happen. 
template<typename Type>
class List {
public:

	List();

	List(const List<Type>& other);

	List<Type>& operator=(const List<Type>& other);

	~List();

	void	print() const;
	bool	empty() const;

	void	push_front(const Type &value);
	void	push_rear(const Type &value);
	void	push_at(int idx, const Type &value);

	// Note that the user must m_front ensure the list is not empty
	// prior to calling these functions. 
	Type	front() const;
	Type	rear() const;
	Type	at(int idx) const;

	int		size() const;
	int		count(const Type &value) const;

	int		find(const Type &value) const;

	bool	pop_front();
	bool	pop_rear();
	bool	pop_at(int idx);
	int		pop_value(const Type &value);

#ifndef MAKE_MEMBERS_PUBLIC
private:
#endif
	// Forward declare the nodes for our List.
	// Will be implemented along with list
	// member functions
	class DLNode;

	// We'll have both m_front and m_rear points for 
	// Fast insertion/deletion from both ends.
	DLNode*	m_front;
	DLNode*	m_rear;

	// Keep track of number of nodes in the list
	int		m_size;
};


/* List Implementation
//
//  Since List is a template class (which is not an actual
//  class yet, not until we actually instantiate the list)
//  we need to keep the implementation together with
//  the definition.  There are ways to simulate having
//  separate "implementation/definition" with templates,
//  but they aren't necessary and can be confusing.
*/

/* DLNode definition
//		Already implemented, nothing to do here but to use it.
//		Make note of the fact the the member variables are private
*/
template<typename Type>
class List<Type>::DLNode {
public:
	DLNode() :nxt(nullptr), prv(nullptr) {}
	DLNode(Type v, DLNode* p, DLNode* n) : val(v), nxt(n), prv(p) {}

	DLNode * next() const { return nxt; } // Access the address of the next node
	void	 next(DLNode *n) { nxt = n; } // Modify the address of the next node

	DLNode * prev() const { return prv; } // Access the address of the previous node
	void	 prev(DLNode *p) { prv = p; } // Modify the address of the previous node

	Type value() const { return val; }		// Access the value stored in the current node
	void value(const Type &v) { val = v; }	// Modify the value stored in the current node

private:
	Type  val;
	DLNode* nxt;
	DLNode* prv;
};


//List Ctor
template<typename Type>
List<Type>::List() :m_front(nullptr), m_rear(nullptr), m_size(0) {
}


//Copy Ctor
template<typename Type>
List<Type>::List(const List<Type>& other) {


	/*   TODO   */

}

//Overload assignment operator
template<typename Type>
List<Type>& List<Type>::operator=(const List<Type>& other) {


	/*   TODO   */

	return *this;
}

//List Dtor
template<typename Type>
List<Type>::~List() {


	/*   TODO   */
}

//List print
template<typename Type>
void List<Type>::print() const {
	DLNode* curr = m_front;
	while (curr->next() != nullptr) {
		std::cout << curr->value() << " ";
		curr = curr->next();
	}
	std::cout << curr->value();
}

//List empty
template<typename Type>
bool List<Type>::empty() const {
	if (m_size == 0)
		return true;
	return false;
}

//List push Front
template<typename Type>
void List<Type>::push_front(const Type &value) {
	DLNode* node = new DLNode;
	if (m_size == 0)
	{
		m_front = node;
		m_rear = node;
		node->value(value);
		m_size++;
		return;
	}
	node->value(value);
	node->prev(nullptr);
	node->next(m_front);
	node->next()->prev(node);
	m_front = node;
	m_size++;
}

//List push rear
template<typename Type>
void List<Type>::push_rear(const Type &value) {
	if (m_size == 0) {
		push_front(value);
		return;
	}
	DLNode* node = new DLNode;
	node->value(value);
	node->next(nullptr);
	node->prev(m_rear);
	node->prev()->next(node);
	m_rear = node;
	m_size++;
}

//List push at
//If the index <= 0, add front.
//If the index >= m_size, add rear.
//Otherwise, push at the index indicated.
template<typename Type>
void List<Type>::push_at(int idx, const Type &value) {
	if (idx <= 0) {
		push_front(value);
		return;
	}
	if (idx >= m_size) {
		push_rear(value);
		return;
	}
	DLNode* node = new DLNode;
	DLNode* p = m_front;
	node->value(value);
	for (int i = 1; i < idx; i++)
		p = p->next();
	node->prev(p);
	node->next(p->next());
	p->next()->prev(node);
	p->next(node);
	m_size++;
}

//List front
//Return the value of the first node
template<typename Type>
Type List<Type>::front() const {
	assert(m_front != nullptr);
	return(m_front->value());
}

//List rear
template<typename Type>
Type List<Type>::rear() const {

	// Force check that the m_rear is pointing to a DLNode
	// Typical solution for deployement code is to throw
	// exceptions, since we haven't covered that yet
	// we'll make due with assert, which is used for testing
	assert(m_rear != nullptr);

	/*   TODO   */

	Type retval;
	return retval;

}

//List at
template<typename Type>
Type List<Type>::at(int idx) const {

	// Force index to be correct before getting the Type
	// Typical solution for deployement code is to throw
	// exceptions, since we haven't covered that yet
	// we'll make due with assert, which is used for testing
	assert(idx >= 0 && idx < m_size);

	/*   TODO   */

	Type retval;
	return retval;
}

//List size
//Return the size of m_size
template<typename Type>
int List<Type>::size() const {
	return(m_size);
}

//List count
//Return the total # of the values in the list
template<typename Type>
int List<Type>::count(const Type &value) const {


	/*   TODO   */

	int retval = 9000000;
	return retval;

}

//List find
template<typename Type>
int List<Type>::find(const Type &value) const {

	/*   TODO   */


	int retval = 8675309;
	return retval;

}

//List pop front
template<typename Type>
bool List<Type>::pop_front() {

	/*   TODO   */

	bool retval = false;
	return retval;
}

//List pop rear
//If the value was deleted return true, otherwise return false
template<typename Type>
bool List<Type>::pop_rear() {
	if (m_front == nullptr)
		return false;
	if (m_size == 1) {
		delete m_front;
		m_front == nullptr;
		m_size--;
		return true;
	}
	DLNode* p = m_rear;
	m_rear = p->prev();
	p->prev()->next(nullptr);
	delete p;
	m_size--;
	return true;
}

//List pop at
template<typename Type>
bool List<Type>::pop_at(int idx) {


	/*   TODO   */

	bool retval = false;
	return retval;

}

//List pop value
template<typename Type>
int List<Type>::pop_value(const Type &value) {

	/*   TODO   */

	int retval = 42;
	return retval;

}


#endif



























































































// _X_XMMXXI