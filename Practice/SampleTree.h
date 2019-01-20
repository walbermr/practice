#pragma once
#include <iostream>
#include <vector>


class SampleTree
{
private:
	int key;
	SampleTree *left;
	SampleTree *right;
	void _recursionWalk(SampleTree* tree);

public:
	SampleTree(int key, SampleTree* left, SampleTree* right);
	~SampleTree();
	void recursionWalk();
	void stackWalk();
};

