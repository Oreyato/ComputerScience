#include "Sort.h"

void Sort::bubbleSort(LinkedList& list)
{
	int len = list.size();

	if (!sizeError(len)) {
		std::cout << "Bubble sort" << std::endl;

		bool moved = true;

		while (moved) {
			moved = false;

			for (int i = 0; i < len - 1; i++)
			{
				if (list.at(i) > list.at(i + 1)) {
					list.swap(i, i + 1);

					moved = true;
				}
			}
		}

		list.display();
	}
}

void Sort::selectionSort(LinkedList& list)
{
	int len = list.size();

	if (!sizeError(len)) {
		std::cout << "Selection sort" << std::endl;

		for (int i = 0; i < len - 1; i++)
		{
			int lowest = list.at(i);
			int swapIndex = 0;

			for (int j = i + 1; j < len; j++)
			{
				if (lowest > list.at(j)) {
					lowest = list.at(j);
					swapIndex = j;
				}
			}

			if (lowest != list.at(i)) {
				list.swap(i, swapIndex);
			}
		}

		list.display();
	}
}

void Sort::mergeSort(LinkedList& list)
{
	int len = list.size();

	if (!sizeError(len)) {
		std::cout << "Merge sort" << std::endl;

		// Divide in half and merge inside
		divideInHalf(list);
	}
}

void Sort::divideInHalf(LinkedList& list)
{
	int len = list.size();
	int half = len / 2;

	// Fill a new list with half the initial list
	LinkedList leftList;
	leftList.addListPortion(list, 0, half - 1);

	LinkedList testList;
	testList.addListPortion(list, 0, len - 1);

	// Fill an other list with the other half of the initial list
	LinkedList rightList;
	rightList.addListPortion(list, half, len - 1);

	// Test if there is more than one element in the lists
	if (leftList.size() > 1) 
	{
		divideInHalf(leftList);
	}
	if (rightList.size() > 1) {
		divideInHalf(rightList);
	}

	merge(leftList, rightList).display(); 
}

LinkedList& Sort::merge(LinkedList& lList, LinkedList& rList)
{
	LinkedList newList;
	
	// Get left and right lists sizes
	const int lSize = lList.size();
	const int rSize = rList.size();

	// Initialize left and right lists first values
	int lValue = 0;
	int rValue = 0;

	// Initialise indexes
	int lIndex = 0;
	int rIndex = 0;

	bool completedRList = false;

	for (int i = 0; i < lSize; i++)
	{
		lIndex = i;
		lValue = lList.at(i);

		if (!completedRList)
		{
			for (int j = rIndex; j < rSize; j++)
			{
				rIndex = j;
				rValue = rList.at(j);

				if (lValue >= rValue) {
					newList.add(rList.at(j));

					if (j = rSize) {
						completedRList = true;
					}
				}
				else {
					newList.add(lList.at(i));
					break;
				}
			}
		}
		
		newList.add(lList.at(i));
	}

	return newList;
}

bool Sort::sizeError(int len)
{
	if (len == 0)
	{
		std::cout << "You can't sort an empty list";
		return true;
	}
	else if (len == 1) {
		std::cout << "There is only one item in this list, thus it is already sorted" << std::endl;
		return true;
	}
	else return false;
}