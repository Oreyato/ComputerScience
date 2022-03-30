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

	void add(int num);
	void insert(int num, int pos);
	void pushBack(int num);
	void remove(int num, int pos);
	int at(int pos);

	int size() { return listSize; }
	void display();

private:
	Node* atNode(Node* node, int pos);
	void sizeError();

	Node* p_startNode{ nullptr };

	int listSize{ 0 };
};

