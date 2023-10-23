#pragma once
#include <vector>


class sebgraph
{
public:

	sebgraph(int NumNodes = 0)
	{
		vertexes.resize(NumNodes);
	}

	struct Node
	{
		int id;
		int data;

		Node(int _id, int _data) : id(_id), data(_data) {}
	};

	std::shared_ptr<Node> CreateNode(int nodeID,int nodeData)
	{
		std::shared_ptr<Node> newNode = std::make_shared<Node>(nodeID, nodeData);
		nodes.push_back(newNode);
		return newNode;
	}

	void AddEdge(const std::shared_ptr<Node>& from, const std::shared_ptr<Node>& to, int weight) {
		vertexes[from->id].push_back(std::make_pair(to, weight));
		vertexes[to->id].push_back(std::make_pair(from, weight));
	}

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

	void printNodeData(int nodeID)
	{
		for (int u = 0; u < vertexes.size(); u++)
		{
			for (const auto& pair : vertexes[u])
			{
				if (pair.first->id == nodeID)
				{
					std::cout << "Node data is: " << pair.first->data << "\n";
				}
			}
		}
	}


private:
	std::vector<std::vector<std::pair<std::shared_ptr<Node>, int>>> vertexes;
	std::vector<std::shared_ptr<Node>> nodes;


};



// 
//
//int main()
//{
//	sebgraph graph(3);
//
//	sebgraph::Node Node0(0, 100);
//	sebgraph::Node Node1(1, 200);
//	sebgraph::Node Node2(2, 300);
//
//	graph.AddEdge(Node0, Node1, 10);
//	graph.AddEdge(Node0, Node2, 20);
//
//	graph.printGraph();
//	graph.printNodeData(1);
//
//	return 0;
//};