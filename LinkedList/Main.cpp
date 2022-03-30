#include "LinkedList.h"
using std::cout;
using std::endl;
using std::vector;

int main() {
	#pragma region TEST
	// =============================================================
	// vvv TESTING PURPOSE =========================================
	// =============================================================
	/*
	std::vector<Node> nodes;

	// Create nodes
	Node node01 = { 0, nullptr };
	nodes.push_back(node01); // /!\ push_back does a COPY /!\ // 
	Node node02 = { 1, nullptr };
	nodes.push_back(node02);
	Node node03 = { 2, nullptr };
	nodes.push_back(node03);
	Node node04 = { 3, nullptr };
	nodes.push_back(node04);
	Node node05 = { 4, nullptr };
	nodes.push_back(node05);

	// Link nodes
	for (int i = 0; i < nodes.size() - 1; i++)
	{
		nodes[i].p_next = &nodes[i + 1];
	}

	// Print nodes values
	cout << nodes[0].value << endl;
	for (int i = 0; i < nodes.size() - 1; i++)
	{
		cout << nodes[i].p_next->value << endl;
	}

	// Print a specific node's value
	int value = 0;
	// ~on va choisir d'aller jusqu'au 3ième node

	*/
	// =============================================================
	// ^^^ TESTING PURPOSE =========================================
	// =============================================================  
	#pragma endregion

	LinkedList list(0);
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);

	list.display();

	cout << list.at(9);

	return 0;
}