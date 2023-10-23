#pragma once
#include <vector>

class AdjacencyGraph
{
public:
	//--------------------- Class initialization ---------------------

	AdjacencyGraph(int vertices) {
		v = vertices;
		AdjacentNodes = new AdjNode * [v];
		for (int i = 0; i < v; ++i)
			AdjacentNodes[i] = NULL;
	}

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

	//---------------------  Variables  ---------------------

	int v;

	AdjNode** AdjacentNodes;



	//---------------------  Test Functions  ---------------------

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

	//---------------------  Member Functions  ---------------------

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

	void deleteVertex(int vertexToDelete)
	{
		// Iterate through all vertexes to find the one to delete.
		for(int i = 0; i < 6; ++i)
		{
			AdjNode* Temp = AdjacentNodes[i];
			if(i == vertexToDelete)
			{
				AdjacentNodes[i] = Temp->next;
				Temp = AdjacentNodes[i];
			}

			// Delete the vertex using the linked list
			while(Temp != nullptr)
			{
				if (Temp->vertex == vertexToDelete)
					break;

				AdjNode* prev = Temp;
				Temp = Temp->next;
				if(Temp == nullptr)
					continue;

				prev->next = Temp->next;
				Temp = nullptr;
			}
		}
	}

	// ---------- Getters ----------



	// ---------- Checkers ----------

};
