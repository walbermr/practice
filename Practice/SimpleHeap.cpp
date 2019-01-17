#include "SimpleHeap.h"



SimpleHeap::SimpleHeap(const std::vector<int>& elems)
{
	this->elems = elems;
	this->elems = buildHeap(elems);
}


SimpleHeap::~SimpleHeap()
{
}


bool SimpleHeap::empty()
{
	return this->elems.empty();
}


int SimpleHeap::size()
{
	return this->elems.size();
}


void SimpleHeap::push(int elem)
{
	this->elems.push_back(elem);
	int new_elem_pos = this->elems.size() - 1;

	//this make heapify bottom up, using the modified branch
	for (int i = new_elem_pos; i > -1; i = (i - 1) / 2)
	{
		this->elems = this->maxHeapify(this->elems, i);
		if (i == 0)
			break;
	}
}


std::vector<int> SimpleHeap::maxHeapify(std::vector<int> elems, int i)
{
	/* This funciton intends to keep the heap properties
	*/
	int left = 2 * i + 1, right = 2 * i + 2, biggest;
	int aux;

	if (left < elems.size() && elems[left] > elems[i])
		biggest = left;
	else
		biggest = i;

	if (right < elems.size() && elems[right] > elems[biggest])
		biggest = right;

	if (biggest != i)
	{
		aux = elems[biggest];
		elems[biggest] = elems[i];
		elems[i] = aux;
		return maxHeapify(elems, biggest);
	}

	return elems;
}


std::vector<int> SimpleHeap::buildHeap(std::vector<int> elems)
{
	for (int i = (elems.size() - 1) / 2; i >= 0; i -= 1)
	{
		elems = maxHeapify(elems, i);
	}
	return elems;
}


void SimpleHeap::printHeap()
{
	//why this need class
	for (class std::vector<int>::iterator i = this->elems.begin(); i != this->elems.end(); i++)
		std::cout << *i << " ";

	std::cout << std::endl;
}

int SimpleHeap::pop()
{
	//make first element the return value, swap first with last, pop last, heapify first
	int aux = this->elems[0];
	this->elems[0] = this->elems[this->size() - 1];
	this->elems.pop_back();
	this->elems = maxHeapify(this->elems, 0);
	return aux;
}
