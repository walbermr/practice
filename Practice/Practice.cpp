// Practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ArrayPractice.h"
#include "SampleTree.h"
#include "SampleHeap.h"
#include "SampleGraph.h"
#include "SampleQueue.h"
#include <vector>
#include <iostream>

// todo: add initializer_list to all classes

bool BinarySearchIterative(std::vector<int> v, int n)
{
	int ret = 0;
	int begin = 0, end = v.size() - 1, middle = (v.size() - 1)/2;

	while (begin <= end)
	{
		if (v[middle] == n)
			return true;
		else if (v[middle] > n)
			end = middle - 1;
		else
			begin = middle + 1;

		middle = (end + begin) / 2;
	}

	if (v[middle] == n)
		return true;

	return false;
}

int main()
{
	//std::vector<int> v{ 1,2,-6,3,4,5 };
	////std::vector<int> v{ 1,2,3,4,5 };

	////maxSubTest(v);
	//std::vector<int> v1 = rotateArray(v, 1);
	//for (std::vector<int>::iterator i = v1.begin(); i != v1.end(); i++) {
	//	std::cout << *i << std::endl;
	//}

	////this tree sould print 1,2,3,4,5 in order
	//SampleTree tree(1,
	//	new SampleTree(2, nullptr, nullptr),
	//	new SampleTree(3,
	//		new SampleTree(4, nullptr, nullptr),
	//		new SampleTree(5, nullptr, nullptr)));

	//tree.recursionWalk();
	//tree.stackWalk();

	//SampleHeap heap(v);
	//heap.printHeap();

	//heap.push(6);
	//heap.push(11);
	//heap.printHeap();

	//heap.pop();
	//heap.printHeap();

	//printArrayOfArray(pascalTriangle(5));

	//std::vector<std::vector<int>> a{ {1},{2},{3} };
	//printArray(spiralOrder(a));

	//std::vector<std::vector<int>> adjacent_list{ {1,2,3}, {0,4}, {0,4}, {0,4}, {1,2,3} };
	//SampleGraph graph(adjacent_list);
	////graph.depthFirstSearch(0);
	////graph.breadthFirstSearch(0);
	//int a = 0, b = 4;
	//std::cout <<"There is any route from " << a << " to " << b << "? " << graph.bidirectionalSearch(a, b) << std::endl;

	//SampleQueue queue({ 1,2,3,4 });
	//queue.push(5);

	//while(queue.size() > 0)
	//	std::cout << queue.pop() << std::endl;
}

