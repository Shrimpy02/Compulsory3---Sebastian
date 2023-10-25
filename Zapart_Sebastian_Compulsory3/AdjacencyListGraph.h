#pragma once
#include <memory>
#include <unordered_set>
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

	void DeleteNode(const std::shared_ptr<Node>& NodeToDelete)
	{
		if (NodeToDelete == nullptr) return;
		int NodeID = NodeToDelete->id;

		if(NodeID >= 0 && NodeID < AmountOfVertexes)
		{
			// Delete the node itself
			nodes[NodeID].reset();

			// Clear connected edges
			vertexes[NodeID].clear();

			// Update the adjacency list of other nodes to remove references to deleted node
			// Creates an adjacentList based on vertexes
			for (auto adjacentList : vertexes)
			{
				// Iterates through the adjacentList and if the id of the adjacent node matches 
				// the deleted node, the element gets deleted removing the edge reference.
				for (auto it = adjacentList.begin(); it != adjacentList.end(); )
				{
					if(it->first->id == NodeID)
					{
						it = adjacentList.erase(it);
					} else
					{
						++it;
					}
				}
			}
			// Resizes the amount of vertexes after one has been deleted. 
			AmountOfVertexes--;
			resizeGraph();
		}
	}

	void DeleteEdge(const std::shared_ptr<Node>& from, const std::shared_ptr<Node>& to)
	{
		// Remove Edge from the "from" nodes index.

		// Accesses the adjacency list from the "from" node where from->id is the index used
		// it then calls erase with standard library remove_if function, that removes elements from the range vertexes[from].begin to vertexes[from].end
		vertexes[from->id].erase(std::remove_if(vertexes[from->id].begin(), vertexes[from->id].end(),
			
			// the third argument [&to] is a lambda function that defines the condition for removing elements from the range.
			// A lambda function is small function called within other functions to encapsulate a few lines of code and return an immediate value.
			// the lambda function takes an argument "edge" witch is an element in the adjacency list.
			// [&to] is captured by reference so that it can be used inside the lambda function
			[&to](const std::pair<std::shared_ptr<Node>, int>& edge) {

				// condition used by lambda function that checks if the first member of the edge (shared_ptr<Node>) is equal to the "to" smart pointer
				// in other words it compares if the edge connects from the "from" node to the "to" node. 
				return edge.first == to;

				// the lambda function returns the first iteration in the range that should be removed. And passes it to the erase function.
				// the erase function can then delete all iterations that connect "from" too "to" with in the range of vertexes[from].end
		}), vertexes[from->id].end());

		// Then remove Edge from the "to" nodes index.
		vertexes[to->id].erase(std::remove_if(vertexes[to->id].begin(), vertexes[to->id].end(),
			[&from](const std::pair<std::shared_ptr<Node>, int>& edge) {
				return edge.first == from;
			}), vertexes[to->id].end());
	}

	// visits all visitable nodes from the start node
	void DepthTraversal(const std::shared_ptr<Node>& startNode, std::vector<bool>& visited)
	{
		// base case; returns if the start node is null or node has been visited already. 
		if (!startNode || visited[startNode->id]) return;

		// sets the visited array of the index of the node currently being visited too true and prints. 
		visited[startNode->id] = true;
		std::cout << "Visited Node " << startNode->id << std::endl;

		// Iterates through the linked list and recursively calls depth first traversal for each neighbor
		for (const auto& edge : vertexes[startNode->id])
		{
			const std::shared_ptr<Node>& neighbor = edge.first;
			DepthTraversal(neighbor, visited);
		}
	}

	void BredthTraversal(const std::shared_ptr<Node>& startNode)
	{
		// Base case; returns if the start node is null.
		if (!startNode) return;

		// Initiates a visited vector to check if nodes have been visited.
		// Also initiates a temp vector to store the nodes to visit in the right order.
		std::unordered_set<int> visitedSet;
		std::vector<std::shared_ptr<Node>> TempNodes;

		// Sets the visited to true and pushes this node to the temp nodes.
		TempNodes.push_back(startNode);
		visitedSet.insert(startNode->id);

		// While there are nodes to visit the while loop runs.
		while (!TempNodes.empty())
		{
			// Deques the front node and possesses it
			const std::shared_ptr<Node>& current = TempNodes.front();
			TempNodes.erase(TempNodes.begin());

			// Prints if it has visited it.
			std::cout << "Visited Node " << current->id << std::endl;

			// Checks if the node shares an edge, if it does the node connected is pushed to the queue
			for (const auto& edge : vertexes[current->id])
			{
				const std::shared_ptr<Node>& neighbor = edge.first;
				if(visitedSet.find(neighbor->id) == visitedSet.end())
				{
					visitedSet.insert(neighbor->id);
					TempNodes.push_back(neighbor);
				}
			}
		}
	}

	void ModifyData(const std::shared_ptr<Node>& node, int newdata)
	{
		node->data = newdata;
	}

	// ---------------------  Getters  ---------------------

	int GetNodeData(const std::shared_ptr<Node>& node)
	{
		auto outdata = node->data;
		return outdata;
	}

	//std::vector<std::shared_ptr<Node>> GetAdjacentNodes(const std::shared_ptr<Node>& node)
	//{
	//	std::vector<std::shared_ptr<Node>> AdjacentNodes;
	//
	//	return
	//}

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

	int GetAmountOfVertexes()
	{
		return AmountOfVertexes;
	}

	// ---------------------  Checkers  ---------------------

	void isEmpty()
	{

	}

};
