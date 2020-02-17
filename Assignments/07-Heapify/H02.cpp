//////////////////////////////////////////////////////////////////////
//
// Author:           Jose Soto
// Email:            josesoto56@icloud.com
// Label:            H02
// Title:            Homework 02 - HEAP
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//       This program will insert items into a heap class and
//		 remove one item.
//
//////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

/**
 * Class Heap
 *
 * @methods:
 *      constructors:
 *          Heap        : default constructor
 *          Heap(int)   : overload constructor with heap size
 *      private:
 *          BubbleUp    : move inserted item
 *          Left        : sets index to left child
 *          OnHeap      : if in bounds of heap
 *          Parent      : sets index to parent
 *          Right       : sets index to right child
 *          Swap        : swaps two different positions
 *			Value		: returns value from heap
 *          /// Fix These:
 *          SinkDown    : Moving item down into the heap
 *          PickChild   : Decide which child needs to be switched
 *      public:
 *          Insert      : Puts value in heap
 *          Print       : Prints heap
 *          Remove      : Removes value from heap
 */
class Heap {
private:
	int size; // size of the array
	int* H;   // array pointer
	int end;  // 1 past last item in array

	/**
   * BubbleUp
   *
   * @description:
   *    This puts one value into its proper
   *    place in the heap.
   *
   * @param  {int} index : index to start bubbling at
   * @return             : void
   */
	void BubbleUp(int index) {
		// check parent is not of beginning of array
		if (Parent(index) >= 1) {
			// index is on array and value is less than parent
			while (index > 1 && H[index] < H[Parent(index)]) {
				// do a swap
				Swap(index, Parent(index));

				// update index to values new position
				index = Parent(index);
			}
		}
	}

	/**
	 * Left
	 * @description:
	 *      Calculates index of left child.
	 *
	 * @param  {int} index : index of parent
	 * @return {int}       : index of left child
	 */
	int Left(int index) {
		return 2 * index;
	}

	/**
	 * OnHeap
	 * @description:
	 *      Checks if an index is on the array (past the end).
	 *
	 * @param  {int} index : index to check
	 * @return {bool}      : 0 = off heap / 1 = on heap
	 */
	bool OnHeap(int index) {
		return index < end;
	}

	/**
	 * Parent
	 * @description:
	 *      Calculates parent of a given index.
	 *
	 * @param  {int} index : index to check
	 * @return {int}       : parent index
	 */
	int Parent(int index) {
		return index / 2;
	}

	/**
	 * Right
	 * @description:
	 *      Calculates index of right child.
	 *
	 * @param  {int} index : index of parent
	 * @return {int}       : index of right child
	 */
	int Right(int index) {
		return 2 * index + 1;
	}

	/**
	 * Swap
	 *
	 * @description:
	 *      Swaps to values in the heap
	 *
	 * @param  {int} i  : index in array
	 * @param  {int} j  : index in array
	 * @return          : void
	 */
	void Swap(int i, int j) {
		int temp = H[i];
		H[i] = H[j];
		H[j] = temp;
	}

	////////////////////////////
	//Fix These Methods
	////////////////////////////

	/**
	 * Heapify
	 * @description:
	 *			Will convert an unordered array to heap order

	 * @param  {int*} A   :  array pointer with unsorted values to
	 *						 make into a heap
	 * @param  {int} size :  size of new heap
	 */
	void Heapify(int* A, int size) {
		Heap Temp(size);

		for (int i = 1; i < size - 1; i++)
		{
			Temp.Insert(A[1]);
		}
		for (int i = 1; i < size - 1; i++) {
			A[i] = Temp.Value(i);
		}
	}
	/**
	* Value
	* @description:
	*   	returns value in heap with given index
	* 
	* @param  {int}     : position
	* @return {int}		: value in heap
    */
	int Value(int index) {
		return H[index];
	}

	/**
	 * SinkDown
	 * @description:
	 *      Places one heap item into its proper place in the heap
	 *      by bubbling it down to it proper location.
	 *
	 * @param  {int} index  : index to start from in the array
	 * @return              : void
	 */
	void SinkDown(int index) {
		int temp;
		while (Left(index) < end && Right(index) < end)  {
			temp = PickChild(index);
			if (H[temp] < H[index]) {
				Swap(index, temp);
				index = temp;
			}
			else {
				return;
			}
		}
	}

	/**
	 * PickChild
	 * @description:
	 *      If one child exists, return it.
	 *      Otherwise, return the smaller of the two.
	 *
	 * @param  {int} index  : index of parent in the array
	 * @return              : index to child
	 */
	int PickChild(int index) {
		if (end % 2 == 1) {
			// no right child
			return Left(index);
		}
		else {
			// got two children
			if (Right(index) < end) {
				if (H[Right(index)] > H[Left(index)]) {
					return Left(index);
				}
				else {
					return Right(index);
				}
			}
		}
	}

public:
	/**
   * Heap constructor
   */
	Heap() {
		size = 100;
		H = new int[size];
		end = 1;
	}

	/**
   * Heap constructor
   *
   * @param  {int} s : heap size
   */
	Heap(int s) {
		size = s;
		H = new int[s];
		end = 1;
	}

	/**
   * Insert
   *
   * @description:
   *        Add a value to the heap.
   *
   * @param  {int} x : value to Insert
   * @return         : void
   */
	void Insert(int x) {
		H[end] = x;
		BubbleUp(end);
		end++;
	}

	/**
	 * For test our heap !!!
	 */
	void Print() {
		for (int i = 1; i <= end - 1; i++) {
			cout << H[i];
			if (i < end - 1) {
				cout << "->";
			}
		}
	}

	/**
	 * Remove
	 * @description:
	 *      Removes item from top of heap
	 *
	 * @return {int}  : top of heap
	 */
	int Remove() {
		int temp = H[1];
		H[1] = H[end-1];
		end--;
		SinkDown(1);

		return temp;
	}
};

int main() {
	Heap H;

	H.Insert(17);
	H.Insert(11);

	for (int i = 1; i <= 10; i++) {
		H.Insert(i);
	}

	H.Remove();
	H.Print();
}