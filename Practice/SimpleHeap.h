#pragma once
#include <vector>
#include <iostream>

/* TODO: 
	- COMPLETE WITH MINHEAPIFY
	- USE TEMPLATE CLASS
*/
class SimpleHeap
{
private:
	std::vector<int> elems;
	std::vector<int> maxHeapify(std::vector<int> elems, int pos);
	std::vector<int> buildHeap(std::vector<int> elems);
public:
	SimpleHeap(const std::vector<int>& elems);
	~SimpleHeap();
	bool empty();
	int size();
	void push(int elem);
	int pop();
	void printHeap();
};

