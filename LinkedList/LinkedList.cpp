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

void LinkedList::display()
{
	cout << "Linked list: " << endl;
	Node* node = p_startNode;

	while (node != nullptr) 
	{
		if (node->p_next != nullptr) {
			// Get a copy of next node to get its value
			Node _node = *node->p_next;

			cout << "\t value: " << node->value << " | next adress: " << node->p_next << " (next adress' value: " << _node.value << ")" << endl;
		}
		else {
			cout << "\t value: " << node->value << " | next adress: " << node->p_next << endl;
		}
		node = node->p_next;
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

void LinkedList::sizeError()
{
	cout << "\nThe position you entered doesn't exists" << endl;
	cout << "Try to enter a number between 0 and " << listSize - 1 << endl;
}
