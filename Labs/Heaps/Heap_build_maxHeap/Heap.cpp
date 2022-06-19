/* *~*~*
Implementation file for the Heap class: max-heap of integers
Written By: A. Student
Changed by: Rimma E.
IDE:  VS Code
*~**/

#include "Heap.h"

/* *~*~*
 The private member function _reHeapUp rearranges the heap after insert by moving the
 last item up to the correct location in the heap
 *~**/
void Heap::_reHeapUp(int lastndx)
{
	if (lastndx) // means lastndx != 0, i.e. newElement is not heap's root
	{
        int parentIndex;
		parentIndex = _findParent(lastndx);

        if (heapAry[parentIndex] < heapAry[lastndx]) { // swap
            int tmp = heapAry[lastndx];
            heapAry[lastndx] = heapAry[parentIndex];
            heapAry[parentIndex] = tmp;

            _reHeapUp(parentIndex);
        } 
	}
}

/* *~*~*
 The private member function _reHeapDown rearranges the heap after delete by moving the
 data in the root down to the correct location in the heap
 *~**/
void Heap::_reHeapDown(int rootdex)
{
	int left = _findLeftChild(rootdex);
    int right = _findRightChild(rootdex);
    int maxIndex = rootdex;

	if (left != -1) // if there's a left child
	{
        if (left < count && heapAry[left] > heapAry[maxIndex]) {
            maxIndex = left;
        } 
        if (right < count && heapAry[right] > heapAry[maxIndex]) {
            maxIndex = right;
        }
        if (maxIndex != rootdex) {  // swap if rootdex is not == min
            int tmp = heapAry[maxIndex];
            heapAry[maxIndex] = heapAry[rootdex];
            heapAry[rootdex] = tmp;

            _reHeapDown(maxIndex); 
        }
	}

}
/* *~*~*
 The public member function insertHeap inserts a new item into a heap.
 It calls _reheapUp.
 *~**/
bool Heap::insertHeap(int newItem)
{
	if (isFull())
		return false;
		
	heapAry[count] = newItem;
    _reHeapUp(count);
    count++;
	
	return true;
}

/* *~*~*
 The public member function deleteHeap deletes the root of the heap and
 passes back the root's data. It calls _reheapDown.
 *~**/
bool Heap::deleteHeap(int &returnItem)
{
	if (isEmpty())
		return false;
		
	returnItem = heapAry[0];
    count--;
    heapAry[0] = heapAry[count];
    _reHeapDown(0);

	return true;
}