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

	LinkedList bubbleList{ 4 };
	bubbleList.add(5);
	bubbleList.add(2);
	bubbleList.add(8);
	bubbleList.add(3);
	bubbleList.add(1);
	bubbleList.add(2);
	bubbleList.add(7);

	bubbleList.display();

	Sort::bubbleSort(bubbleList);

	cout << endl;
	bubbleList.display();

	return 0;
}