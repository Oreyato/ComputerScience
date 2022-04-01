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

		// Remplace the "list" argument with the new finished list 

	}
}

void Sort::divideInHalf(LinkedList& list)
{
	int len = list.size();
	int half = len / 2;

	// Fill a new list with half the initial list
	LinkedList leftList;
	for (int i = 0; i < half; i++)
	{
		leftList.addListPortion(list, 0, half);
	}

	// Fill an other list with the other half of the initial list
	LinkedList rightList;
	for (int i = 0; i < len; i++)
	{
		rightList.addListPortion(list, half + 1, len - 1);
	}

	// Test if there is more than one element in the lists
	if (leftList.size() > 1) 
	{
		divideInHalf(leftList);
	}
	if (rightList.size() > 1) {
		divideInHalf(rightList);
	}

	merge(leftList, rightList); 
}

void Sort::merge(LinkedList& lList, LinkedList& rList)
{
	//v IDEE =========================================================

	// On part du nombre le plus à gauche de la liste de gauche lList

	// On le compare avec le nombre le plus à gauche de la liste de droite rList

	// Tant qu'il est plus grand on continue, jusqu'à avoir fait toute la liste
	//										^ on place entre temps le nombre plus petit tout à droite d'une nouvelle liste

	// Par contre, s'il est plus petit, c'est lui qui part au plus à droite de la nouvelle liste et on passe à nombre suivant de la liste de gauche
	//^ IDEE =========================================================
	//v PSEUDO CODE ==================================================
	
	//^ PSEUDO CODE ==================================================
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