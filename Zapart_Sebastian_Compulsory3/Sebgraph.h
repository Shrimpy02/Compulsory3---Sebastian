#pragma once
#include <vector>

class sebgraph
{
public:
	sebgraph()
	{
		// Initialize root node with no parent and rootData = -1
		Graphes.push_back(CreateNode(rootData));
	}

	struct Node
	{
		int data;
		std::vector<Node*> AdjacentNodes;
	};

	std::vector<Node*> Graphes;

	int rootData = -1;

	Node* CreateNode(int data)
	{
		Node* NewNode = new Node();
		NewNode->data = data;
		return NewNode;
	}
};