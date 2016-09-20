
#include <iostream>
using namespace std;
#include "Array.h"
#include "LinkedList.h"
#include "BinaryTree.h"
#include "PseudoQueue.h"
#include "TowersOfHanoi.h"
#include "Params.h"

const int C_ARRAY_SIZE = 10;
int steps;
void DemonstratePseudoQueue();
void DemonstrateBubbleSort();
void DemonstrateBookBubbleSort();
void DemonstrateMedianValue();
void DemonstrateSelectionSort();
void DemonstrateInsertionSort();
void DemonstrateBinaryTree();
int Triangle(int n);
int Factorial(int n);
void EatLine();
void doTowers(int nLevel, char from, char inter, char to);

int main()
{
	// 2 Stacks to create Queue 
	DemonstratePseudoQueue();
	 
	// Median Value
	DemonstrateMedianValue();
	
	// Bubble Sort
	DemonstrateBubbleSort();

	// Book Bubble Sort
	DemonstrateBookBubbleSort();

	// Selection Sort
	DemonstrateSelectionSort();
	 
	// Insertion Sort
	DemonstrateInsertionSort();
	 
	// Binary Tree
	DemonstrateBinaryTree();	

	// Triangle Recursion Calculation
	int result = Triangle(1000);
	cout << "Triangle Result (1000): " << result << endl;

	// Factorial Recursion Calculation
	result = Factorial(4);
	cout << "Factorial Result (4): " << result << endl;

	// Ordered Linked List
	LinkedList<int> list;
	cout << "Ordered LinkList: " << endl;
	list.InsertOrdered(10);
	list.InsertOrdered(42);
	list.InsertOrdered(38);
	list.InsertOrdered(2);
	list.InsertOrdered(78);
	list.InsertOrdered(38);
	list.PrintAll();


	// Ordered Array
	cout << "Ordered Array: " << endl;
	Array<int> array(6);
	array.InsertOrdered(10);
	array.InsertOrdered(42);
	array.InsertOrdered(38);
	array.InsertOrdered(2);
	array.InsertOrdered(78);
	array.InsertOrdered(38);
	array.PrintAll();


	// Merge Sort Array
	Array<int> mergeArray(6);
	mergeArray.Insert(10);
	mergeArray.Insert(42);
	mergeArray.Insert(38);
	mergeArray.Insert(2);
	mergeArray.Insert(78);
	mergeArray.Insert(38);
	cout << "Pre-Ordered (Merge Sort): " << endl;
	mergeArray.PrintAll();
	mergeArray.MergeSort();
	cout << "Post-Ordered (Merge Sort): " << endl;
	mergeArray.PrintAll();

	// Shell Sort Array
	Array<int> shellArray(6);
	shellArray.Insert(10);
	shellArray.Insert(42);
	shellArray.Insert(38);
	shellArray.Insert(2);
	shellArray.Insert(78);
	shellArray.Insert(38);
	cout << "Pre-Ordered (Shell Sort): " << endl;
	shellArray.PrintAll();
	shellArray.MergeSort();
	cout << "Post-Ordered (Shell Sort): " << endl;
	shellArray.PrintAll();


	// Partition Sort (Precursor to QuickSort)
	Array<int> partitionArray(7);
	partitionArray.Insert(10);
	partitionArray.Insert(42);
	partitionArray.Insert(38);
	partitionArray.Insert(2);
	partitionArray.Insert(78);
	partitionArray.Insert(38);
	partitionArray.Insert(55);
	int peakValue = partitionArray.FindPeak(0, partitionArray.GetNumElements());
	cout << "Peak Value: " << peakValue << endl;
	cout << "Pre-Ordered (Partition Sort): " << endl;
	partitionArray.PrintAll();
	partitionArray.QuickSort();
	cout << "Partition Sort Index: " << endl;
	partitionArray.PrintAll();
	int binarySearch = partitionArray.BinarySearch(38);
	cout << "Found Value: " << binarySearch << endl;
	peakValue = partitionArray.FindPeak(0, partitionArray.GetNumElements());
	cout << "Peak Value: " << peakValue << endl;
	BinaryTree tree;
	tree.Insert(5);
	tree.Insert(3);
	tree.Insert(9);
	tree.Insert(4);
	tree.Insert(10);
	tree.Insert(1);
	tree.Remove(5);
	tree.PrintAllNodesPreOrder();


	// Towers of Hanoi
	doTowers(5, '1', '2', '3');
	cout << "Steps: " << steps << endl;
	TowersOfHanoi tower(5);
	tower.Solve();

	// End Program
	return 0;
}

void DemonstratePseudoQueue() {
	/////////////////////////////////////////////////////////////////////
	// #1 - 2 Stacks implemented to create a Queue
	PseudoQueue queueImposter;
	for (int i = C_ARRAY_SIZE; i > 0; --i) {
		queueImposter.Enqueue(i);
	}
	cout << "Fake Queue: " << endl;
	queueImposter.PrintAllEntries();
	/////////////////////////////////////////////////////////////////////
}
void DemonstrateBubbleSort() {
	/////////////////////////////////////////////////////////////////////
	// #2 - Bubble Sort
	Array<int> test(C_ARRAY_SIZE);
	for (int i = C_ARRAY_SIZE; i > 0; --i) {
		test.Insert(i);
	}
	cout << "PreSorted: " << endl;
	test.PrintAll();
	test.BubbleSort();
	cout << "PostSorted: " << endl;
	test.PrintAll();
	/////////////////////////////////////////////////////////////////////
}
void DemonstrateBookBubbleSort() {
	/////////////////////////////////////////////////////////////////////
	// #4 - Book Bubble Sort
	Array<int> test(C_ARRAY_SIZE);
	for (int i = C_ARRAY_SIZE; i > 0; --i) {
		test.Insert(i);
	}
	cout << "Book PreSorted: " << endl;
	test.PrintAll();
	test.BookBubbleSort();
	cout << "Book PostSorted: " << endl;
	test.PrintAll();
	/////////////////////////////////////////////////////////////////////
}
void DemonstrateMedianValue() {
	/////////////////////////////////////////////////////////////////////
	// #3 - Median Value
	Array<int> test(C_ARRAY_SIZE);
	for (int i = C_ARRAY_SIZE; i > 0; --i) {
		test.Insert(i);
	}
	float medianValue = test.Median();
	cout << "Median Value: " << medianValue << endl;
	/////////////////////////////////////////////////////////////////////
}
void DemonstrateSelectionSort() {
	/////////////////////////////////////////////////////////////////////
	// #5 - Selection Sort
	Array<int> test(C_ARRAY_SIZE);
	for (int i = C_ARRAY_SIZE; i > 0; --i) {
		test.Insert(i);
	}
	cout << "SelectionSort PreSorted: " << endl;
	test.PrintAll();
	test.SelectionSort();
	cout << "SelectionSort PostSorted: " << endl;
	test.PrintAll();
	/////////////////////////////////////////////////////////////////////
}
void DemonstrateInsertionSort() {
	/////////////////////////////////////////////////////////////////////
	// #6 - Insertion Sort
	Array<int> test(C_ARRAY_SIZE);
	for (int i = C_ARRAY_SIZE; i > 0; --i) {
		test.Insert(i);
	}
	cout << "InsertionSort PreSorted: " << endl;
	test.PrintAll();
	test.InsertionSort();
	cout << "InsertionSort PostSorted: " << endl;
	test.PrintAll();
	/////////////////////////////////////////////////////////////////////
}
void DemonstrateBinaryTree() {
	/////////////////////////////////////////////////////////////////////
	// #7 - Binary Tree
	BinaryTree tree;
	tree.AddItem(5);
	tree.AddItem(3);
	tree.AddItem(9);
	cout << "\nTree In-Order Output: \n";
	tree.PrintAllNodesInOrder();
	cout << "\nTree Pre-Order Output: \n";
	tree.PrintAllNodesPreOrder();
	cout << "\nTree Post-Order Output: \n";
	tree.PrintAllNodesPostOrder();
	tree.RemoveAll();
	/////////////////////////////////////////////////////////////////////
}

int Triangle(int n) {
	if (n == 1) {
		return 1;
	}
	return n + Triangle(n - 1);
}

int Factorial(int n) {
	if (n == 0) {
		return 1;
	}

	return (n * Factorial(n - 1));
}

void doTowers(int nLevel, char from, char inter, char to) {
	steps++;
	if (nLevel == 1) {
		cout << "Moving Disc 1 from " << from << " to " << to << endl;
	}
	else {
		doTowers(nLevel - 1, from, to, inter);

		cout << "Moving Disc " << nLevel << " from " << from << " to " << to << endl;

		doTowers(nLevel - 1, inter, from, to);
	}
}

void EatLine() {
	cin.clear();
	while (cin.get() != '\n') {}
}