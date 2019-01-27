#pragma once
#include <vector>
class SampleQueue
{
private:
	std::vector<int> elems;
public:
	SampleQueue();
	SampleQueue(std::initializer_list<int> elems);
	~SampleQueue();
	void push(int n);
	int pop();
	int size();
};

