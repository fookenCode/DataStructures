#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
template <class T>
class LinkedList {
private:
	struct Node {
		Node *next;
		T data;
	};

	// Copy Constructor
	LinkedList<T>::LinkedList(const LinkedList &other) { }

	// Assignment Operator
	LinkedList LinkedList<T>::operator=(const LinkedList &other) { }

protected:
	// Pointer to beginning of LinkedList
	Node *head;
	int numElems;

public:
	// Constructor
	LinkedList() : head(0), numElems(0) { }
	// Destructor
	virtual LinkedList<T>::~LinkedList() {
		if (head != 0) {
			RemoveAll();
		}
	}

	// IsEmpty - Determines if the LinkedList contains any items
	bool LinkedList<T>::isEmpty() {
		return (head == 0);
	}

	// GetNumElems - Returns the total number of elements inserted
	int LinkedList<T>::GetNumElems() {
		return numElems;
	}

	// InsertOrdered - Adds new item to the LinkedList in ascending order
	void LinkedList<T>::InsertOrdered(T value) {
		Node *toAdd = new Node();
		toAdd->data = value;
		toAdd->next = 0;

		// List is empty
		if (head == 0) {
			head = toAdd;
			numElems++;
			return;
		}
		else {
			Node *traverse = head;
			Node *previous = 0;
			while (traverse != 0 && traverse->data < toAdd->data) {
				previous = traverse;
				traverse = traverse->next;
			}
			// if there is no value greater than input, end of list
			// if there is no value lower than input, beginning of list
			// if the new input is in middle of list

			if (traverse == 0) {
				previous->next = toAdd;
			}
			else if (previous == 0) {
				toAdd->next = head;
				head = toAdd;
			} 
			else {
				toAdd->next = previous->next;
				previous->next = toAdd;
			}
			numElems++;
		}
	}

	// InsertFront - Adds the new item to the beginning of the LinkedList
	void LinkedList<T>::InsertFront(T value) {
		Node *toAdd = new Node();
		toAdd->data = value;
		toAdd->next = 0;

		if (head == 0) {
			head = toAdd;
		}
		else {
			toAdd->next = head;
			head = toAdd;
		}
		numElems++;
	}

	// InsertRear - Adds the new item to the end of the LinkedList
	void LinkedList<T>::InsertRear(int value) {
		Node *toAdd = new Node();
		toAdd->data = value;
		toAdd->next = 0;
		
		if (head != 0) {
			Node *iterator = head;
			while (iterator->next != 0) {
				iterator = iterator->next;
			}
			iterator->next = toAdd;
		}
		else {
			head = toAdd;
		}
		numElems++;
	}

	// RemoveHead - Removes and returns the head element from the LinkedList
	T LinkedList<T>::RemoveHead() {
		if (head == 0) {
			return 0;
		}
		else {
			T returnValue;
			returnValue = head->data;
			Node *toDelete = head;
			head = head->next;
			delete toDelete;
			numElems--;
			return returnValue;
		}
	}

	// RemoveTail - Removes and returns the tail element from the LinkedList
	T LinkedList<T>::RemoveTail() {
		if (head == 0) {
			return 0;
		}
		else {
			T returnValue;
			Node *iter = head;
			Node *prev = 0;
			while (iter->next != 0) {
				prev = iter;
				iter = iter->next;
			}
			prev->next = 0;
			returnValue = iter->data;
			delete iter;
			numElems--;
			return returnValue;
		}
	}

	// RemoveItem - Searches the list for the suggested value, removes and returns the first element found
	// NOTE - List is unchanged if element is not found!
	void LinkedList<T>::RemoveItem(T valueToRemove) {
		Node *iterator = head;
		Node *previous = 0;
		while (iterator != 0) {
			if (iterator->data == valueToRemove) {
				if (previous != 0) {
					previous->next = iterator->next;
				}
				else {
					head = iterator->next;
				}

				delete iterator;
				numElems--;
				iterator = previous->next;
			}
			previous = iterator;
			iterator = iterator->next;
		}
	}

	// PeekHead - Returns the head element without removing from list
	T LinkedList<T>::PeekHead() {
		if (head == 0) {
			return 0;
		}
		return head->data;
	}

	// PeekTail - Returns the tail element without removing from the list
	T LinkedList<T>::PeekTail() {
		if (head == 0) {
			return 0;
		}

		Node *iter = head;
		while (iter->next != 0) {
			iter = iter->next;
		}
		return iter->data;
	}

	// RemoveAll - Clears the full list and releases all memory claimed by LinkedList
	void LinkedList<T>::RemoveAll() {
		while (head != 0) {
			Node *toDelete = head;
			head = toDelete->next;
			delete toDelete;
		}
		numElems = 0;
	}

	// PrintAll - Iterates through list and prints each element to STD Out
	void LinkedList<T>::PrintAll() {
		Node *iterator = head;
		while (iterator != 0) {
			printf("%d\n", iterator->data);
			iterator = iterator->next;
		}
	}
};
#endif //_LINKED_LIST_H_