#include "LinkedList.h"
using std::cout;
using std::endl;

LinkedList::LinkedList()
{
}

LinkedList::LinkedList(int num)
{
	add(num);
}

void LinkedList::add(int num)
{
	Node* node = new Node{ num, nullptr };

	// Is the list empty?
	if (listSize == 0) {
		p_startNode = node;
	}
	else {
		// Link the previous last node with the new one
		atNode(p_startNode, listSize - 1)->p_next = node;
	}

	listSize++;
}

void LinkedList::addList(LinkedList& list)
{
	int addedListSize = list.size();

	atNode(p_startNode, listSize - 1)->p_next = list.atNode(list.getStartNode(), 0);

	listSize += addedListSize;
}

void LinkedList::addListPortion(LinkedList& list, int from, int to)
{
	// In order to simplify the tests, from will always be the lowest value
	if (from > to) {
		int tmp = from;
		from = to;
		to = tmp;
	}

	// Testing if the destination pos exists within the list
	if (to > list.size() - 1) {
		sizeError();
	}
	else {
		int addedListSize = (to - from) + 1;

		atNode(p_startNode, listSize - 1)->p_next = list.atNode(list.getStartNode(), from);

		listSize += addedListSize;
		atNode(p_startNode, listSize - 1)->p_next = nullptr;
	}
}

void LinkedList::insert(int num, int pos)
{
	// Get node's adress at current position
	Node* currentNode = atNode(p_startNode, pos);
	// Create new node
	Node* newNode = new Node{ num, currentNode };

	// Testing if the position exists within the list
	if (pos > listSize - 1) {
		sizeError();
	}
	else {
		// Link the head node to the new one
		atNode(p_startNode, pos - 1)->p_next = newNode;
	}

	listSize++;
}

void LinkedList::pushBack()
{
	delete(atNode(p_startNode, listSize - 1));
	atNode(p_startNode, listSize - 2)->p_next = nullptr;

	listSize--;
}

void LinkedList::remove(int pos)
{
	// Testing if the position exists within the list
	if (pos > listSize - 1) {
		sizeError();
	}
	else {
		// Get node's adress at current position
		Node* currentNode = atNode(p_startNode, pos);

		if (pos == 0) {
			// Get the node's adress that will take this position
			Node* nextNode = atNode(p_startNode, pos + 1);
			// Delete first node
			delete(atNode(p_startNode, pos));
			// Update p_startNode
			p_startNode = nextNode;

			listSize--;
		}
		else if (pos == listSize - 1) {
			pushBack();
		}
		else {
			// Get the node's adress that will take this position
			Node* nextNode = atNode(p_startNode, pos + 1);
			// Delete the node at "pos"
			delete(atNode(p_startNode, pos));
			// Link the list again
			atNode(p_startNode, pos - 1)->p_next = nextNode;

			listSize--;
		}
	}
}

int LinkedList::at(int pos)
{
	// Testing if the position exists within the list
	if (pos > listSize - 1) {
		sizeError();
		cout << "-Output error-: ";

		return 0;
	}
	else {
		// Switch out of the user context
		return atNode(p_startNode, pos)->value;
	}
}

Node* LinkedList::atNode(Node* node, int pos)
{
	if (pos == 0)
	{
		return node;
	}

	atNode(node->p_next, pos - 1);
}

void LinkedList::swap(int from, int to)
{
	// Check if the user try to swap something with itself
	if (from == to) {
		std::cout << "You can't swap something with itself" << std::endl;
	}
	// In order to simplify the tests, from will always be the lowest value
	else if (from > to) {
		int tmp = from;
		from = to;
		to = tmp;
	}

	// Testing if the destination pos exists within the list
	if (to > listSize - 1) {
		sizeError();
	}
	else {
		// Get from node
		Node* fromNode = atNode(p_startNode, from);
		// Get to node
		Node* toNode = atNode(p_startNode, to);

		bool neighbours = false;
		// Testing if from and to are neighbours
		if (to - from == 1) {
			neighbours = true;
		} 

		// Get always existing neighbours
		Node* rightNeighFromNode = atNode(p_startNode, from + 1);
		Node* leftNeighToNode = atNode(p_startNode, to - 1);

		// Is the starting position the first one on the list?
		if (from == 0) {
			// Get remaining neighbour
			Node* rightNeighToNode = atNode(p_startNode, to + 1);

			// Link nodes
			if (!neighbours)
			{
				toNode->p_next = rightNeighFromNode;
				leftNeighToNode->p_next = fromNode;
			}
			else {
				toNode->p_next = fromNode;
			}
			fromNode->p_next = rightNeighToNode;

			p_startNode = toNode;
		}
		// Is the destination pos the last one on the list?
		else if (to == listSize - 1) {
			// Get remaining neighbour
			Node* leftNeighFromNode = atNode(p_startNode, from - 1);

			// Link nodes
			leftNeighFromNode->p_next = toNode;
			if (!neighbours)
			{
				toNode->p_next = rightNeighFromNode;
				leftNeighToNode->p_next = fromNode;
			}
			else {
				toNode->p_next = fromNode;
			}
			fromNode->p_next = nullptr;
		}
		else {
			// Get remaining neighbours 
			Node* leftNeighFromNode = atNode(p_startNode, from - 1);
			Node* rightNeighToNode = atNode(p_startNode, to + 1);

			// Link nodes
			leftNeighFromNode->p_next = toNode;
			if (!neighbours)
			{
				toNode->p_next = rightNeighFromNode;
				leftNeighToNode->p_next = fromNode;
			}
			else {
				toNode->p_next = fromNode;
			}
			fromNode->p_next = rightNeighToNode;
		}
	}
}

void LinkedList::display()
{
	cout << "Linked list: " << endl;
	Node* node = p_startNode;

	while (node != nullptr) 
	{
		if (node->p_next != nullptr) {
			// Get a copy of next node to get its value
			Node _node = *node->p_next;

			cout << "\t value: " << node->value << "\tcurr. adr.:" << node << "\tnext adr.: " << node->p_next << " (val.: " << _node.value << ")" << endl;
		}
		else {
			cout << "\t value: " << node->value << "\tcurr. adr.:" << node <<"\tnext adr.: " << node->p_next << endl;
		}
		node = node->p_next;
	}
	cout << endl;
}

void LinkedList::sizeError()
{
	cout << "\nThe position you entered doesn't exists" << endl;
	cout << "Try to enter a number between 0 and " << listSize - 1 << endl;
}
