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

		// Divide in half

		// Compare by pairs

		// Create new growing list

		// Remplace the "list" argument with the new finished list 

	}
}

void Sort::divideInHalf(LinkedList& list)
{
	int len = list.size();
	int half = len / 2;

	LinkedList leftList;
	for (int i = 0; i < half; i++)
	{
		/*leftList.add();*/
	}

	LinkedList rightList;

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