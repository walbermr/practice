#include "SampleQueue.h"



SampleQueue::SampleQueue()
{
}


SampleQueue::SampleQueue(std::initializer_list<int> elems)
{
	for (std::initializer_list<int>::iterator i = elems.begin(); i != elems.end(); i++)
		this->push(*i);
}


SampleQueue::~SampleQueue()
{
}


void SampleQueue::push(int n)
{
	this->elems.push_back(n);
}


int SampleQueue::pop()
{
	int ret = this->elems[0];
	for (int i = 1; i < this->elems.size(); i++)
		this->elems[i - 1] = this->elems[i];

	this->elems.pop_back();
	return ret;
}


int SampleQueue::size()
{
	return this->elems.size();
}