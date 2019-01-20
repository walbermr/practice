#pragma once
#include <iostream>
#include <vector>


class SampleGraphNode
{
public:
	std::vector<int> connections;
	int key;

	SampleGraphNode(int key);
	SampleGraphNode();
	~SampleGraphNode();
};


class SampleGraph
{
private:
	std::vector<SampleGraphNode> nodes;
public:
	SampleGraph(std::vector<std::vector<int>> adjacent_list);
	~SampleGraph();
	void depthFirstSearch(int root);
	void breadthFirstSearch(int root);
	bool bidirectionalSearch(int start, int destiny);
};



