#include "LinkedList.h"
using std::cout;
using std::endl;
using std::vector;

int main() {
	LinkedList list;

	// Create nodes
	Node node01 = { 0, nullptr };
	Node node02 = { 1, nullptr };
	Node node03 = { 2, nullptr };
	Node node04 = { 3, nullptr };
	Node node05 = { 4, nullptr };

	// Link nodes
	//for (int i = 0; i < 5; i++)
	//{
	//	nodes[i].nextPtr = &nodes[i + 1];
	//}

	// Print nodes values
	cout << node01.value << endl;
	//for (int i = 0; i < 4; i++)
	//{
	//	cout << nodes[i].nextPtr->value << endl;
	//}

	return 0;
}