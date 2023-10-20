#pragma once
#include <vector>


class AdjNode
{
public:
	int vertex;
	AdjNode* next;
	AdjNode(int data) {
		vertex = data;
		next = NULL;
	}
};

class AdjacencyGraph
{
private:
	int v;
	AdjNode** AdjacentNodes;

public:

	AdjacencyGraph(int vertices) {
		v = vertices;
		AdjacentNodes = new AdjNode * [v];
		for (int i = 0; i < v; ++i)
			AdjacentNodes[i] = NULL;
	}

	void addEdge(int source, int destination) {
		AdjNode* node = new AdjNode(destination);
		node->next = AdjacentNodes[source]; // Attach the new node to the existing linked list.
		AdjacentNodes[source] = node;
	}

	void addVertex(int vk, int source, int destination)
	{
		addEdge(source, vk);
		addEdge(vk, destination);
	}

	// Function to print the graph
	void printGraph() {
		for (int i = 0; i < v; ++i) {
			std::cout << i << " ";
			AdjNode* temp = AdjacentNodes[i];
			while (temp != NULL) {
				std::cout << "-> " << temp->vertex << " ";
				temp = temp->next;
			}
			std::cout << std::endl;
		}
	}

};
//
//int main()
//{
//
//	int V = 6;
//	AdjacencyGraph AdjacentNodes(V);
//	AdjacentNodes.addEdge(0, 1);
//	AdjacentNodes.addEdge(0, 3);
//	AdjacentNodes.addEdge(0, 4);
//	AdjacentNodes.addEdge(1, 2);
//	AdjacentNodes.addEdge(3, 2);
//	AdjacentNodes.addEdge(4, 3);
//
//	std::cout << "Initial adjacency list" << std::endl;
//	AdjacentNodes.printGraph();
//
//	return 0;
//}