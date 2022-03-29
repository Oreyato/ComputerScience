#include "LinkedList.h"

LinkedList::LinkedList()
{
}

LinkedList::LinkedList(int n)
{
	add(n);
}

void LinkedList::add(int num)
{
	Node node = { num, nullptr };
	addNode(node);
}

void LinkedList::insert(int num, int pos)
{
}

void LinkedList::pushBack(int num)
{
}

void LinkedList::remove(int num, int pos)
{
}

int LinkedList::at(int pos)
{
	return 0;
}

void LinkedList::addNode(Node node)
{

}
