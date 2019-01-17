#include "SimpleTree.h"



SimpleTree::SimpleTree(int key, SimpleTree *left, SimpleTree *right)
{
	this->key = key;
	this->left = left;
	this->right = right;
}


SimpleTree::~SimpleTree()
{
}


void SimpleTree::recursionWalk()
{
	this->_recursionWalk(this);
	std::cout << std::endl;
}


void SimpleTree::_recursionWalk(SimpleTree* tree)
{
	if (tree == nullptr)
		return;
	else {
		std::cout << tree->key << " ";
		this->_recursionWalk(tree->left);
		this->_recursionWalk(tree->right);
	}
}


void SimpleTree::stackWalk() {
	std::vector<SimpleTree*> stack;
	SimpleTree* tree;
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
