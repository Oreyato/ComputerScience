#include "LinkedList.h"
using std::cout;
using std::endl;
using std::vector;

int main01() {
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

	// Print nodes values
	cout << nodes[0].value << endl;
	for (int i = 0; i < nodes.size() - 1; i++)
	{
		cout << nodes[i].nextPtr->value << endl;
	}

	return 0;
}