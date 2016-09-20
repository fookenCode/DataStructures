#ifndef _PSEUDO_QUEUE_H_
#define _PSEUDO_QUEUE_H_
#include "Stack.h"

class PseudoQueue {
private:
	// Copy Constructor
	PseudoQueue(const PseudoQueue &other) { }

	// Assignment Operator
	PseudoQueue operator=(const PseudoQueue &other) { }

	// Stack list objects to create Queue
	Stack<int> firstStack, secondStack;

public:
	// Constructor
	PseudoQueue() { }
	
	// Destructor
	virtual ~PseudoQueue() {
		// Clear the list, if there are any entries
		if (!firstStack.isEmpty()) {
			firstStack.RemoveAll();
		}
		// Clear the list, if there are any entries
		if (!secondStack.isEmpty()) {
			secondStack.RemoveAll();
		}
	}

	// Enqueue - Adds new item to the "Queue"s
	void Enqueue(int value) {
		// If both stacks empty, push onto second stack
		if (firstStack.isEmpty() && secondStack.isEmpty()) {
			secondStack.Push(value);
		}
		else {
			// Else - Pop off second stack, push onto first stack until empty
			while (!secondStack.isEmpty()) {
				int toMove = secondStack.Pop();
				firstStack.Push(toMove);
			}
			// Push new value into first stack
			firstStack.Push(value);
			// Finally - Pop off all first stack, push onto second stack until empty
			while (!firstStack.isEmpty()) {
				int toMove = firstStack.Pop();
				secondStack.Push(toMove);
			}
		}
	}

	// Dequeue - Removes the first item from the "Queue"
	int Dequeue() {
		// Pop off first entry in second stack
		if (secondStack.isEmpty()) {
			return 0;
		}
		else {
			// Return the first entry in-order
			return secondStack.Pop();
		}
	}

	void PrintAllEntries() {
		// Print all entries from the in-order Stack
		if (!secondStack.isEmpty()) {
			secondStack.PrintAll();
		}
	}
};
#endif //_PSEUDO_QUEUE_H_