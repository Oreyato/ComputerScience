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
