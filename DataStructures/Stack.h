#ifndef _STACK_H_
#define _STACK_H_

#include "LinkedList.h"
template <class T>
class Stack : public LinkedList<T> {
private:

	// Copy Constructor
	Stack(const Stack &other) { }

	// Assignment Operator
	Stack Stack<T>::operator=(const Stack &other) { }

	// Unique Identifier of Stack
	int referenceID;
public:
	// Constructor
	Stack() : referenceID(0) { }
	
	// Destructor
	virtual ~Stack() {
		if (head != 0) {
			RemoveAll();
		}
	}

	// Push - Add the new value to the top of the stack
	void Stack<T>::Push(T value) {
		InsertFront(value);
	}

	// Pop - Return the top-most element in the stack
	T Stack<T>::Pop() {
		return RemoveHead();
	}

	void Stack<T>::SetReferenceID(int value) {
		referenceID = value;
	}

	int Stack<T>::GetReferenceID() {
		return referenceID;
	}
};
#endif //_STACK_H_