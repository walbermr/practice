// Practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ArrayPractice.h"
#include "SimpleTree.h"
#include "SimpleHeap.h"
#include <iostream>

int main()
{
	std::vector<int> v{ 1,2,-6,3,4,5 };
	////std::vector<int> v{ 1,2,3,4,5 };

	////maxSubTest(v);
	//std::vector<int> v1 = rotateArray(v, 1);
	//for (std::vector<int>::iterator i = v1.begin(); i != v1.end(); i++) {
	//	std::cout << *i << std::endl;
	//}

	////this tree sould print 1,2,3,4,5 in order
	//SimpleTree tree(1,
	//	new SimpleTree(2, nullptr, nullptr),
	//	new SimpleTree(3,
	//		new SimpleTree(4, nullptr, nullptr),
	//		new SimpleTree(5, nullptr, nullptr)));

	//tree.recursionWalk();
	//tree.stackWalk();

	//SimpleHeap heap(v);
	//heap.printHeap();

	//heap.push(6);
	//heap.push(11);
	//heap.printHeap();

	//heap.pop();
	//heap.printHeap();

	//printArrayOfArray(pascalTriangle(5));

	std::vector<std::vector<int>> a{ {1},{2},{3} };
	printArray(spiralOrder(a));

}

