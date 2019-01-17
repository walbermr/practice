#pragma once
#include <iostream>
#include <vector>


class SimpleTree
{
private:
	int key;
	SimpleTree *left;
	SimpleTree *right;
	void _recursionWalk(SimpleTree* tree);

public:
	SimpleTree(int key, SimpleTree* left, SimpleTree* right);
	~SimpleTree();
	void recursionWalk();
	void stackWalk();
};

