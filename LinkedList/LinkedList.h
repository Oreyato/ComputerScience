#pragma once
#include <iostream>
#include <vector>

struct Node
{
	int value;
	Node* p_next;
};

class LinkedList
{
public:
	LinkedList();
	LinkedList(int num);
	//LinkedList(const LinkedList& otherList);

	void add(int num);
	void addList(LinkedList list);
	void addListPortion(LinkedList list, int from, int to);
	void insert(int num, int pos);
	void pushBack();
	void remove(int pos);
	int at(int pos);
	void swap(int from, int to);

	int size() { return listSize; }
	void display();

	Node* getStartNode() { return p_startNode; }

private:
	Node* atNode(Node* node, int pos);
	void sizeError();

	Node* p_startNode{ nullptr };

	int listSize{ 0 };
};

