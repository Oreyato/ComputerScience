#include "Sort.h"
using std::cout;
using std::endl;
using std::vector;

int main() {
	#pragma region FUNCTIONS TESTS
	// =============================================================
	// vvv TESTING FUNCTIONS =======================================
	// =============================================================
	/*
	LinkedList list(0);
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);

	list.insert(5, 2);

	list.pushBack();

	list.remove(0);
	list.remove(5);
	list.remove(1);

	cout << endl;
	list.display();

	list.add(10);
	list.add(11);
	list.insert(20, 2);

	cout << endl;
	list.display();

	list.swap(0, 3);
	list.swap(1, 2);
	list.swap(4, 5);

	cout << endl;
	list.display();
	*/
	// =============================================================
	// ^^^ TESTING FUNCTIONS =======================================
	// =============================================================  
	#pragma endregion

	//LinkedList list{ 4 };
	//list.add(5);
	//list.add(2);
	//list.add(8);

	//LinkedList list2{ 3 };
	//list2.add(3);
	//list2.add(1);
	//list2.add(2);
	//list2.add(7);

	//list.addListPortion(list2, 2, 3);
	//list.display();

	//Sort::bubbleSort(list);

	//Sort::selectionSort(list);

	//list.display();

	LinkedList list4;

	LinkedList list3{ 4 };
	list3.add(2);
	list3.add(7);
	list3.add(8);

	list3.display();
	list4.display();

	// ISSUE WITH ADD_LIST & ADD_LIST_PORTION
	list4.addList(list3);
	list4.addList(list3);

	list4.display();

	//Sort::mergeSort(list3);

	return 0;
}