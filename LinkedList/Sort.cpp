#include "Sort.h"

void Sort::bubbleSort(LinkedList& list)
{
	bool moved = true;

	while (moved) {
		moved = false;
		int len = list.size();

		for (int i = 0; i < len - 1; i++)
		{
			if (list.at(i) > list.at(i + 1)) {
				list.swap(i, i + 1);

				moved = true;
			}
		}
	}
}

void Sort::selectionSort(LinkedList& list)
{
	int len = list.size();

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
}
