#pragma once
#include <vector>
#include <iostream>

/* TODO: 
	- COMPLETE WITH MINHEAPIFY
	- USE TEMPLATE CLASS
*/
class SampleHeap
{
private:
	std::vector<int> elems;
	std::vector<int> maxHeapify(std::vector<int> elems, int pos);
	std::vector<int> buildHeap(std::vector<int> elems);
public:
	SampleHeap(const std::vector<int>& elems);
	~SampleHeap();
	bool empty();
	int size();
	void push(int elem);
	int pop();
	void printHeap();
};

