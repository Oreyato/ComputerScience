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


	if (pos > listSize - 1) {
		sizeError();
	}
	else {

	}

	listSize++;
}

void LinkedList::pushBack(int num)
{
}

void LinkedList::remove(int num, int pos)
{
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

			cout << "\t value: " << node->value << " | next adress: " << node->p_next << " (supposed value: " << _node.value << ")" << endl;
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
