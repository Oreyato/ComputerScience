#include "Sort.h"
using std::cout;
using std::endl;
using std::vector;

int main() {
	LinkedList list{ 5 };
	list.add(2);
	list.add(3);
	list.add(8);
	list.add(4);
	list.add(6);

	Sort::bubbleSort(list);

	return 0;
}