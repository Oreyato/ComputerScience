#include "LinkedList.h"
using std::cout;
using std::endl;
using std::vector;

int main() {
	// =============================================================
	// vvv TESTING PURPOSE =========================================
	// =============================================================

	std::vector<Node> nodes;

	// Create nodes
	Node node01 = { 0, nullptr };
	nodes.push_back(node01);
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
		nodes[i].nextPtr = &nodes[i + 1];
	}

	Node* test = node01.nextPtr;
	Node** testRef = &node01.nextPtr;

	if (test == nullptr) {
		cout << "Node*: NULL_PTR" << endl;
	}
	else if (testRef == nullptr) {
		cout << "Node**: NULL_PTR" << endl;
	}

	// Print nodes values
	cout << nodes[0].value << endl;
	for (int i = 0; i < nodes.size() - 1; i++)
	{
		cout << nodes[i].nextPtr->value << endl;
	}

	// Print a specific node's value
	int value = 0;
	// ~on va choisir d'aller jusqu'au 3ième node


	// =============================================================
	// ^^^ TESTING PURPOSE =========================================
	// =============================================================

	return 0;
}