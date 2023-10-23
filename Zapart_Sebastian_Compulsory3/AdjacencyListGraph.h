#pragma once
#include <memory>
#include <vector>


class AdjacencyListGraph
{
public:

	//--------------------- Class initialization ---------------------

	AdjacencyListGraph()
	{
		vertexes.resize(AmountOfVertexes);
	}

	struct Node
	{
		int id;
		int data;
		Node(int _id, int _data) : id(_id), data(_data) {}
	};

	//---------------------  Variables  ---------------------

private:

	std::vector<std::vector<std::pair<std::shared_ptr<Node>, int>>> vertexes;

	std::vector<std::shared_ptr<Node>> nodes;

	int AmountOfVertexes = 0;

public:

	//---------------------  Test Functions  ---------------------

	void printGraph()
	{
		for (int u = 0; u < vertexes.size(); u++)
		{
			std::cout << "Node " << u << " makes an edge with:\n";
			for (const auto& pair : vertexes[u])
			{
				const std::shared_ptr<Node>& v = pair.first;
				int w = pair.second;
				std::cout << "\tNode " << v->id << " with edge weight = " << w << "\n";
			}
			std::cout << std::endl;
		}
	}

	//---------------------  Member Functions  ---------------------
private:

	void resizeGraph()
	{
		vertexes.resize(AmountOfVertexes);
	}

public:

	std::shared_ptr<Node> CreateNode(int nodeID, int nodeData)
	{
		std::shared_ptr<Node> newNode = std::make_shared<Node>(nodeID, nodeData);
		nodes.push_back(newNode);
		AmountOfVertexes++;
		resizeGraph();

		return newNode;
	}

	void AddEdge(const std::shared_ptr<Node>& from, const std::shared_ptr<Node>& to, int weight) {
		vertexes[from->id].push_back(std::make_pair(to, weight));
		vertexes[to->id].push_back(std::make_pair(from, weight));
	}

	void DeleteNode()
	{

	}

	void DeleteEdge()
	{

	}

	void DepthTraversal()
	{

	}

	void BredthTraversal()
	{

	}

	void ModifyData()
	{

	}

	// ---------------------  Getters  ---------------------

	int GetNodeData(const std::shared_ptr<Node>& node)
	{
		auto outdata = node->data;
		return outdata;
	}

	void GetAdjacentNodes()
	{

	}

	void GetAdjacentNodeEdgeWeight()
	{

	}

	void GetEdges()
	{

	}

	void GetAllGraphVertecies()
	{

	}

	void GetAllGraphEdges()
	{

	}

	void GetSize()
	{

	}

	// ---------------------  Checkers  ---------------------

	void isEmpty()
	{

	}

};
