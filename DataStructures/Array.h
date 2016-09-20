#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <ostream>
using namespace std;
template <class T>
class Array {
private:
	// Copy Constructor
	Array(const Array &other) {}
	
	// Assignment Operator
	Array & operator= (const Array &other) {}

	// Internal variables
	T *dataStructure;
	int arraySize;
	int numElems;

	// Efficiency variables
	int personalComparisons;
	int personalSwaps;

	int bookComparisons;
	int bookSwaps;
	// End - Efficiency Variables

	const int C_BLANK_ENTRY = -1;
public:
	// Default Constructor
	Array(): dataStructure(0), arraySize(0) {}
	// Constructor - Creates Array the size of variable input
	Array(int size) : dataStructure(0), arraySize(size), numElems(0) {
		if (dataStructure != 0 || size != arraySize) {
			delete[] dataStructure;
		}
		dataStructure = new T[size];
		memset(dataStructure, C_BLANK_ENTRY, arraySize*sizeof(T));
	}

	// Deconstructor
	virtual Array<T>::~Array() {
		if (dataStructure != 0) {
			delete[] dataStructure;
			dataStructure = 0;
			numElems = 0;
		}
	}

	// Operator[] overload - Ease of access to indexes
	int & Array<T>::operator[](int index) {
		if (dataStructure != 0 && (index >= 0 && index < arraySize)) {
			return dataStructure[index];
		}
	}

	int Array<T>::GetNumElements() {
		return numElems;
	}

	// Insert - Adds item to Array in first available spot
	void Array<T>::Insert(T value) {
		for (int i = 0; i < arraySize; ++i) {
			if (dataStructure[i] == C_BLANK_ENTRY) {
				dataStructure[i] = value;
				numElems++;
				return;
			}
		}
	}

	// Insert - Adds item to Array in ascending order
	void Array<T>::InsertOrdered(T value) {
		if (numElems + 1 > arraySize) {
			return;
		}
		
		if (numElems == 0) {
			dataStructure[0] = value;
			numElems++;
			return;
		}

		for (int i = 0; i < arraySize; ++i) {
			if (dataStructure[i] == C_BLANK_ENTRY || value < dataStructure[i]) {
				T temp = dataStructure[i];
				dataStructure[i] = value;
				numElems++;
				for (int j = i+1; j < arraySize; ++j) {
					if (dataStructure[j] == C_BLANK_ENTRY) {
						dataStructure[j] = temp;
						return;
					}
					else {
						int hold = dataStructure[j];
						dataStructure[j] = temp;
						temp = hold;
					}
				}
			}
		}
	}

	// Remove - Clears all instances of the value found in the Array.  Returns the total number of instances cleared from Array.
	int Array<T>::Remove(T value) {
		if (numElems <= 0) {
			return 0;
		}
		int numRemoved = 0;
		for (int i = 0; i < arraySize; ++i) {
			if (dataStructure[i] == value) {
				numRemoved++;
				numElems--;
				dataStructure[i] = C_BLANK_ENTRY;
			}
		}
		return numRemoved;
	}

	// RemoveAll - Clear the contents of the entire array.
	void Array<T>::RemoveAll() {
		numElems = 0;
		memset(dataStructure, C_BLANK_ENTRY, arraySize * sizeof(T));
	}

	// PrintAll - Display all Array contents to STD Out
	void Array<T>::PrintAll() {
		for (int i = 0; i < arraySize; ++i) {
			if (dataStructure[i] != C_BLANK_ENTRY) {
				printf("Index: %d. Value: %d\n", i, dataStructure[i]);

			}
		}
	}

	// FindPeak - O(Log N) Search pattern to find a peak in the array.
	int Array<T>::FindPeak(int lowerBound, int upperBound) {
		if (upperBound - lowerBound <= 0) {
			return dataStructure[lowerBound];
		}

		int middle = (upperBound + lowerBound) / 2;
		if (dataStructure[middle] < dataStructure[middle + 1]) {
			// Move to the RIGHT
			FindPeak(middle+1, upperBound);
			// 0 1 2 3 4 5 6 7 8 9
		}
		else if (dataStructure[middle - 1] > dataStructure[middle]) {
			// Move to the LEFT
			FindPeak(lowerBound, middle-1);
		}
		else {
			return dataStructure[middle];
		}
	}

	// BinarySearch - O(Log N) Searches for the value specified in the array.  Returns 0 if the value is not found.
	int Array<T>::BinarySearch(int valueToFind) {
		if (numElems <= 0) {
			return 0;
		}

		int lowerBound = 0, upperBound = numElems;
		int middle = 0;
		int steps = 0;
		while (upperBound - lowerBound >= 0) {
			steps++;
			middle = (upperBound + lowerBound) / 2;
			if (dataStructure[middle] > valueToFind) {
				upperBound = middle - 1;
			}
			else if (dataStructure[middle] < valueToFind) {
				lowerBound = middle + 1;
			}
			else {
				cout << "Steps Taken in Binary Search: " << steps << endl;
				return dataStructure[middle];
			}
		}
		cout << "Steps Taken in Binary Search: " << steps << endl;
		return 0;
	}

	// BubbleSort - O(N*N) Simplest algorithm.  Compares each object through to end of Array swapping when appropriate.
	void Array<T>::BubbleSort() {
		personalComparisons = 0;
		personalSwaps = 0;
		for (int i = 0; i < arraySize; ++i) {
			for (int j = i + 1; j < arraySize; ++j) {
				if (dataStructure[i] > dataStructure[j]) {
					Swap(i, j);
					personalSwaps++;
				}
				personalComparisons++;
			}
		}

		printf("PersonalBubbleSort Stats: %d comparisons with %d swaps!\n", personalComparisons, personalSwaps);
	}

	// BubbleSort - O(N*N) Simplest algorithm.  Compares each object through to end of Array swapping when appropriate.
	void Array<T>::BookBubbleSort() {
		bookComparisons = 0;
		bookSwaps = 0;
		for (int out = arraySize - 1; out > 0; out--) {
			for (int in = 0; in < out; in++) {
				if (dataStructure[in] > dataStructure[in + 1]) {
					Swap(in, in + 1);
					bookSwaps++;
				}
				bookComparisons++;
			}
		}
		printf("BookBubbleSort Stats: %d comparisons with %d swaps!\n", bookComparisons, bookSwaps);

	}

	// SelectionSort - O(N*N) Loops over Array to find lowest value then stores in appropriate spot.  Loops from lowest to highest value.
	void Array<T>::SelectionSort() {
		int in, out, min;
		int comparisonCount, swapCount;
		swapCount = comparisonCount = 0;
		for (out = 0; out < arraySize -1; out++) {
			min = out;

			for (in = out + 1; in < arraySize; ++in) {
				if (dataStructure[in] < dataStructure[min]) {
					min = in;
				}
				comparisonCount++;
			}
			Swap(out, min);
			swapCount++;
		}
		printf("SelectionSort Stats: %d comparisons with %d swaps!\n", comparisonCount, swapCount);
	}

	// InsertionSort - O(N*N) with in-place swaps.  Does well with partially-ordered data.  Loops through array and swaps only when necessary.
	//					Comparison totals match Bubble/Selection Sorts, but Swaps are fewer.  This is optimal when copying the object is inefficient.
	void Array<T>::InsertionSort() {
		int in, out;
		T temp;

		for (out = 1; out < arraySize; ++out) {
			temp = dataStructure[out];

			in = out;

			while (in > 0 && dataStructure[in-1] >= temp) {
				dataStructure[in] = dataStructure[in - 1];
				--in;
			}
			dataStructure[in] = temp;
		}
	}

	// MergeSort - Beginning and Setup for Merge Sort Algorithm
	void Array<T>::MergeSort() {
		// Create Array for performing MergeSort
		Array<T> workspace(arraySize);

		RecMergeSort(workspace, 0, arraySize-1);
	}

	// RecMergeSort - Recursive function to perform Merge Sort.  Divides the Array until single element, then recursively pieces the array back together in Workspace Array
	void Array<T>::RecMergeSort(Array &workspace, int lowerBound, int upperBound) {
		if (lowerBound == upperBound) {
			return;
		}

		int mid = (lowerBound + upperBound) / 2;
		RecMergeSort(workspace, lowerBound, mid);

		RecMergeSort(workspace, mid + 1, upperBound);

		Merge(workspace, lowerBound, mid + 1, upperBound);
	}

	// Merge - Divide & Conquer Sort O(N*LogN) but requires duplicate sized array for workspace
	void Array<T>::Merge(Array &workspace, int lowPtr, int highPtr, int upperBound) {

		int j = 0;
		int lowerBound = lowPtr;
		int mid = highPtr-1;
		int n = (upperBound - lowerBound + 1);

		while (lowPtr <= mid && highPtr <= upperBound) {
			if (dataStructure[lowPtr] < dataStructure[highPtr]) {
				workspace[j++] = dataStructure[lowPtr++];
			}
			else {
				workspace[j++] = dataStructure[highPtr++];
			}
		}

		while (lowPtr <= mid) {
			workspace[j++] = dataStructure[lowPtr++];
		}

		while (highPtr <= upperBound) {
			workspace[j++] = dataStructure[highPtr++];
		}

		for (int j = 0; j < n; ++j) {
			dataStructure[lowerBound+j] = workspace[j];
		}
	}

	// Shell Sort - Requires pre-computation of the H-index with serves as the "step" to compare 3 elements at a time and swap them appropriately to partition then sort once the
	//				H becomes closer to value '1'.
	void Array<T>::ShellSort() {
		int inner, outer;
		T temp;

		int h = 0;
		// Calculate the h values
		while (h <= numElems / 3) {
			h = h * 3 + 1;
		}

		while (h > 0) {
			for (outer = h; outer < numElems; ++outer) {
				temp = dataStructure[outer];
				inner = outer;
				while (inner > h - 1 && dataStructure[inner - h] >= temp) {
					dataStructure[inner] = dataStructure[inner - h];
					inner -= h;
				}
				dataStructure[inner] = temp;
			}
			h = (h - 1) / 3;
		}
	}

	// Partition Array (Precursor to Quicksort) - Returns the index of the partition split
	int Array<T>::PartitionArray(int left, int right, T pivot) {
		int leftPtr = left;
		int rightPtr = right - 1;

		while (true) {
			while (dataStructure[++leftPtr] < pivot) {
				// no op
			}
			while (dataStructure[--rightPtr] > pivot) {
				// no op
			}

			if (leftPtr >= rightPtr) {
				break;
			} else {
				Swap(leftPtr, rightPtr);
			}
		}
		Swap(leftPtr, right-1);

		return leftPtr;
	}

	// QuickSort - O(N*LogN).  Best all-purpose Sorting algorithm.  Beginning and Setup function.
	void Array<T>::QuickSort() {
		RecQuickSort(0, numElems-1);
	}

	// RecQuickSort - Recursive function called to Partition and Sort Array.
	void Array<T>::RecQuickSort(int left, int right) {
		int size = right - left + 1;
		if (size <= 3) {
			// Manual sort
		}
		else {
			int median = MedianOfThree(left, right);
			int partition = PartitionArray(left, right, median);
			RecQuickSort(left, partition-1);
			RecQuickSort(partition + 1, right);
		}
	}

	// MedianOfThree - Of the 3 Indexes (Left, Center, Right) swaps the values appropriately and returns the next to last object for the Pivot value.
	T Array<T>::MedianOfThree(int left, int right) {
		int center = (left + right) / 2;

		if (dataStructure[left] > dataStructure[center]) {
			Swap(left, center);
		}
		if (dataStructure[left] > dataStructure[right]) {
			Swap(left, right);
		}
		if (dataStructure[center] > dataStructure[right]) {
			Swap(center, right);
		}
		Swap(center, right - 1);
		return dataStructure[right - 1];
	}

	// ManualSort - Sort to handle the edge cases of QuickSort when the Array is not large enough for the MedianOfThree approach.
	void Array<T>::ManualSort(int left, int right) {
		int size = right - left + 1;

		if (size <= 1) {
			return;
		}
		else if (size == 2) {
			if (dataStructure[left] > dataStructure[right]) {
				Swap(left, right);
				return;
			}
		} else {
			if (dataStructure[left] > dataStructure[right - 1]) {
				Swap(left, right - 1);
			}
			if (dataStructure[left] > dataStructure[right]) {
				Swap(left, right);
			}
			if (dataStructure[right - 1] > dataStructure[right]) {
				Swap(right - 1, right);
			}
		}
	}

	// Swap - Switches the values stored in the first and second index provided.
	void Array<T>::Swap(int first, int second) {
		T swapHolder = dataStructure[first];
		dataStructure[first] = dataStructure[second];
		dataStructure[second] = swapHolder;
	}

	// Median - Finds the median value of the Array.
	float Array<T>::Median() {
		BubbleSort();
		int index = arraySize / 2;
		if (arraySize % 2 == 0) {
			return (dataStructure[index] + dataStructure[index - 1]) / 2.0f;
		}

		return dataStructure[index]/1.0f;
	}
};
#endif // _ARRAY_H_