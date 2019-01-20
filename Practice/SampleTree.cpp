#include "SampleTree.h"



SampleTree::SampleTree(int key, SampleTree *left, SampleTree *right)
{
	this->key = key;
	this->left = left;
	this->right = right;
}


SampleTree::~SampleTree()
{
}


void SampleTree::recursionWalk()
{
	this->_recursionWalk(this);
	std::cout << std::endl;
}


void SampleTree::_recursionWalk(SampleTree* tree)
{
	if (tree == nullptr)
		return;
	else {
		std::cout << tree->key << " ";
		this->_recursionWalk(tree->left);
		this->_recursionWalk(tree->right);
	}
}


void SampleTree::stackWalk() {
	std::vector<SampleTree*> stack;
	SampleTree* tree;
	stack.push_back(this);

	while (!stack.empty()){
		tree = stack[stack.size()-1];
		stack.pop_back();

		if (tree != nullptr) {
			std::cout << tree->key << " ";
			stack.push_back(tree->right);
			stack.push_back(tree->left);
		}
	}
	std::cout << std::endl;
}

//todo Morris Traversal
