#pragma once
#include "LinkedList.h"

class Sort
{
public:
	static void bubbleSort(LinkedList& list);
	static void selectionSort(LinkedList& list);
	static void mergeSort(LinkedList& list);

private:
	static void divideInHalf(LinkedList& list);
	static void merge(LinkedList& lList, LinkedList& rList);

	static bool sizeError(int len);
};

