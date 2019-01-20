#include "SampleGraph.h"



SampleGraph::SampleGraph(std::vector<std::vector<int>> adjacent_list)
{
	for (int i = 0; i < adjacent_list.size(); i++)
	{
		SampleGraphNode new_node(i);
		for (int j = 0; j < adjacent_list[i].size(); j++)
			new_node.connections.push_back(adjacent_list[i][j]);

		this->nodes.push_back(new_node);
	}
}


SampleGraph::~SampleGraph()
{
}


void SampleGraph::depthFirstSearch(int root)
{
	std::vector<bool> visited(this->nodes.size(), false);
	std::vector<bool> scheduled(this->nodes.size(), false);
	std::vector<int> stack({root});
	SampleGraphNode node;
	int node_index;

	//get a better check case
	if (root > (this->nodes.size() - 1))
		throw std::out_of_range("underflow");

	while (!stack.empty())
	{
		//change to stack class
		node_index = stack[stack.size() - 1];
		stack.pop_back();

		if (!visited[node_index])
		{
			node = this->nodes[node_index];
			visited[node_index] = true;
			std::cout << node.key;
			std::cout << " - connections: ";

			for (std::vector<int>::iterator i = node.connections.begin(); i != node.connections.end(); i++)
			{
				std::cout << *i << " ";
				if (!scheduled[*i])
				{
					scheduled[*i] = true;
					stack.push_back(*i);
				}

			}
			std::cout << std::endl;
		}
	}
}


void SampleGraph::breadthFirstSearch(int root)
{
	std::vector<int> visited(this->nodes.size(), false); 
	std::vector<int> scheduled(this->nodes.size(), false);
	std::vector<int> queue({ root });
	SampleGraphNode node;
	int node_index;
	
	//get a better check case
	if (root > (this->nodes.size() - 1))
		throw std::out_of_range("underflow");

	scheduled[root] = true;

	for (int i = 0; i < queue.size(); i++)
	{
		node_index = queue[i];

		if (!visited[node_index])
		{
			node = this->nodes[node_index];
			visited[node_index] = true;
			std::cout << node_index << " ";
			std::cout << " - connections: ";

			for (std::vector<int>::iterator j = node.connections.begin(); j != node.connections.end(); j++)
			{
				std::cout << *j << " ";
				if (!scheduled[*j])
				{
					scheduled[*j] = true;
					queue.push_back(*j);
				}
			}
			std::cout << std::endl;
		}
	}
}


bool SampleGraph::bidirectionalSearch(int start, int destiny)
{
	//todo: increase code modularity
	std::vector<int> visited_start(this->nodes.size(), false);
	std::vector<int> scheduled_start(this->nodes.size(), false);
	std::vector<int> queue_start({ start });

	std::vector<int> visited_destiny(this->nodes.size(), false);
	std::vector<int> scheduled_destiny(this->nodes.size(), false);
	std::vector<int> queue_destiny({ destiny });

	SampleGraphNode next_node_start;
	SampleGraphNode next_node_destiny;
	int next_index_start;
	int next_index_destiny;

	scheduled_start[start] = true;
	scheduled_destiny[destiny] = true;


	for (int i = 0, j = 0; i < queue_start.size() || j < queue_destiny.size(); i++, j++)
	{
		if (i < queue_start.size())
		{
			next_index_start = queue_start[i];
			if (!visited_start[next_index_start])
			{
				next_node_start = this->nodes[next_index_start];
				visited_start[next_index_start] = true;
				std::cout << next_index_start << " ";
				std::cout << " - connections: ";

				for (std::vector<int>::iterator k = next_node_start.connections.begin(); k != next_node_start.connections.end(); k++)
				{
					std::cout << *k << " ";
					if (!scheduled_start[*k])
					{
						scheduled_start[*k] = true;
						queue_start.push_back(*k);
					}
				}
				std::cout << std::endl;
			}
		}

		if (j < queue_destiny.size())
		{
			next_index_destiny = queue_destiny[j];
			if (!visited_destiny[next_index_destiny])
			{
				next_node_destiny = this->nodes[next_index_destiny];
				visited_destiny[next_index_destiny] = true;
				std::cout << next_index_destiny << " ";
				std::cout << " - connections: ";

				for (std::vector<int>::iterator k = next_node_destiny.connections.begin(); k != next_node_destiny.connections.end(); k++)
				{
					std::cout << *k << " ";
					if (!scheduled_destiny[*k])
					{
						scheduled_destiny[*k] = true;
						queue_destiny.push_back(*k);
					}
				}
				std::cout << std::endl;
			}
		}

		for (int k = 0; k < this->nodes.size(); k++)
		{
			if (visited_start[k] && visited_destiny[k])
				return true;
		}
	}

	if ((visited_start[start] && visited_start[destiny]) || (visited_destiny[start] && visited_destiny[destiny]))
		return true;

	return false;
}


SampleGraphNode::SampleGraphNode(int key)
{
	this->key = key;
}


SampleGraphNode::SampleGraphNode()
{

}


SampleGraphNode::~SampleGraphNode()
{

}


