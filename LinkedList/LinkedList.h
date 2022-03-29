#pragma once
#include <iostream>
#include <vector>

struct Node
{
	int value;
	Node* nextPtr;
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

private:
	void add(Node node);

	std::vector<Node> list;
};

