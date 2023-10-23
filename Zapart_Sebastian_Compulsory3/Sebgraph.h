#pragma once
#include <vector>


class sebgraph
{
public:
	sebgraph()
	{
		
	}





};

 struct Node
 {
 	int id;
 	int data;

	Node(int _id, int _data) : id(_id), data(_data) {}
 };

 void AddEdge(std::vector<std::vector<std::pair<Node, int>>>& verts, Node& from, Node& to, int weight) {
	 verts[from.id].push_back(std::make_pair(to, weight));
	 verts[to.id].push_back(std::make_pair(from, weight));
 }

void printGraph(std::vector<std::vector<std::pair<Node, int>>>& verts)
{
	for (int u = 0; u < verts.size(); u++)
	{
		std::cout << "Node " << u << " makes an edge with:\n";
		for (const auto& pair : verts[u])
		{
			const Node& v = pair.first;
			int w = pair.second;
			std::cout << "\tNode " << v.id << " with edge weight = " << w << "\n";
		}
		std::cout << std::endl;
	}
}

void printNodeData(std::vector<std::vector<std::pair<Node, int>>>& verts, int nodeID)
 {
	for (int u = 0; u < verts.size(); u++)
	{
		for (const auto& pair : verts[u])
		{
			if(pair.first.id == nodeID)
			{
				std::cout << "Node data is: " << pair.first.data << "\n";
			}
		}
	}
 }

int main()
{
	Node Node0(0, 100);
	Node Node1(1, 200);
	Node Node2(2, 300);

	std::vector<std::vector<std::pair<Node,int>>> vertexes(3);

	AddEdge(vertexes,Node0,Node1,10);
	AddEdge(vertexes, Node0, Node2, 20);
	
	printGraph(vertexes);

	printNodeData(vertexes, 1);

	return 0;
};