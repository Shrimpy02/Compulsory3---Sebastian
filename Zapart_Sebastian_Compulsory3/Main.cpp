
#include "Main.h"
#include <iostream>

using namespace std;

int main()
{
	CompMain();
}

CompMain::CompMain()
{
	// --------------- What data Structure? -----------------
	// choice constants
	int choice = 0;
	int choice2 = 0;
	int choice3 = 0;

	cout << "Witch Datastructure would you like to test?" << endl;
	cout << "1. GenericTree" << endl;
	cout << "2. AdjacencyListGraph" << endl;
	cout << "1-2: ";
	cin >> choice;

	cout << endl;
	cout << endl;

	switch (choice)
	{
	case 0:
		cout << endl;
		cout << "Incorrect Data type" << endl;
		cout << "Exit on Code " << choice << endl;

		exit(choice);
	case 1:
		cout << "Do you want to see a random tree or an example tree and it's functions?" << endl;
		cout << "1. Random Generic Tree" << endl;
		cout << "2. Example Generic Tree" << endl;
		cout << "1-2: " << endl;
		cin >> choice2;

		cout << endl;
		cout << endl;

		switch (choice2)
		{
		case 0:
			cout << endl;
			cout << "Incorrect Data type" << endl;
			cout << "Exit on Code " << choice2 << endl;

			exit(choice2);
		case 1:
			printString("Random Graph: ");
			cout << endl;
			RandomGenericTree();

			break;
		case 2:
			cout << "ExampleGraph: " << endl;
			ExampleGenericTree();

			break;
		default:
			cout << endl;
			cout << "That input was not 1 or 2" << endl;
			cout << endl;

			exit(choice2);
		}

		break;
	case 2:
		
		cout << "Do you want to see a random graph or an example graph and it's functions?" << endl;
		cout << "1. RandomGraph" << endl;
		cout << "2. ExampleGraph" << endl;
		cout << "1-2: " << endl;
		cin >> choice3;

		cout << endl;
		cout << endl;

		switch (choice3)
		{
		case 0:
			cout << endl;
			cout << "Incorrect Data type" << endl;
			cout << "Exit on Code " << choice3 << endl;

			exit(choice3);
		case 1:
			printString("Random Graph: ");
			cout << endl;
			RandomAdjacencyGraph();

			break;
		case 2:
			cout << "Example Graph: " << endl;
			ExampleAdjacencyGraph();

			break;
		default:
			cout << endl;
			cout << "That input was not 1 or 2" << endl;
			cout << endl;

			exit(choice3);
		}

		break;
	default:
		cout << endl;
		cout << "That input was not 1 or 2" << endl;
		cout << endl;

		exit(choice);
	}
	cout << endl;
}

void CompMain::RandomGenericTree()
{
	printString("---------------------------------");
	std::cout << std::endl;

	// Generate Random Tree
	std::cout << std::endl;
	printString("Randomly Generated Tree: ");
	std::cout << std::endl;
	GT_ptr->GenerateRandomTree(GT_ptr->Tree[0], 5, 0);
	GT_ptr->BredthFirstPrintTree(GT_ptr->Tree[0]);

	std::cout << std::endl;
	printString("---------------------------------");
}

void CompMain::ExampleGenericTree()
{

	/*		The tree example
	*              -1
	*         /  /    \     \
	*        1  2      3      4
	*       / \        |   /  | \
	*      5   6       7   8  9  10
	*/

	printString("---------------------------------");
	std::cout << std::endl;
	std::cout << std::endl;

	GT_ptr->CreateTestTree();

	// BredthFirstPrint ----------
	printString("BredthFirstPrint of Tree:");
	std::cout << std::endl;
	GT_ptr->BredthFirstPrintTree(GT_ptr->Tree.front());
	std::cout << std::endl;

	// ModifyValue ----------
	printString("Modified Value from 5 to 11:");
	GT_ptr->ModifyNode(GT_ptr->Tree.front()->child.front()->child.front(), 11);
	std::cout << std::endl;

	// DepthFirstPrint ----------
	std::cout << std::endl;
	printString("DepthFirstPrint of Tree with modified value:");
	std::cout << std::endl;
	GT_ptr->DepthFirstPrintTree(GT_ptr->Tree.front());
	std::cout << std::endl;

	// ---------- Getters ----------

	std::cout << std::endl;
	printString("------ Getters ---------");
	std::cout << std::endl;

	// GetSize ----------
	std::cout << std::endl;
	printString("Tree size as num Nodes:");
	printInt(GT_ptr->GetSize(GT_ptr->Tree.front()));
	std::cout << std::endl;

	// GetDepth ----------
	std::cout << std::endl;
	printString("Tree depth:");
	printInt(GT_ptr->GetDepth(GT_ptr->Tree.front()));
	std::cout << std::endl;

	// GetNodeData ----------
	std::cout << std::endl;
	printString("Get Node data of node 1:");
	printInt(GT_ptr->GetNodeData(GT_ptr->Tree.front()->child.front()));
	std::cout << std::endl;

	// GetChildren ----------
	std::cout << std::endl;
	printString("Children of node with data value 1:");
	GT_ptr->testGetChildren(GT_ptr->GetChildren(GT_ptr->Tree.front()->child.front()));
	std::cout << std::endl;

	// GetParent ----------
	std::cout << std::endl;
	GT_ptr->testGetParent(GT_ptr->Tree.front()->child.front()->child.front());
	std::cout << std::endl;

	// GetRoot ----------
	std::cout << std::endl;
	GT_ptr->testGetRoot(GT_ptr->Tree.front());
	std::cout << std::endl;

	// ---------- Checkers ----------

	std::cout << std::endl;
	printString("------ Checkers ---------");
	std::cout << std::endl;

	// IsEmpty ----------
	std::cout << std::endl;
	printString("checks if tree is Empty:");
	if (GT_ptr->IsEmpty())
		printString("true");
	else
		printString("false");
	std::cout << std::endl;

	// IsRoot ----------
	std::cout << std::endl;
	printString("Checks if node with data value '1' Is Root:");
	if (GT_ptr->IsRoot(GT_ptr->Tree.front()->child.front()))
		printString("true");
	else
		printString("false");
	std::cout << std::endl;

	// IsLeaf ----------
	std::cout << std::endl;
	printString("Checks if node with data value '11' Is Leaf:");
	if (GT_ptr->Isleaf(GT_ptr->Tree.front()->child.front()->child.front()))
		printString("true");
	else
		printString("false");
	std::cout << std::endl;

	// ---------- Delete function ----------

	std::cout << std::endl;
	printString("------ Deletion ---------");
	std::cout << std::endl;

	// DepthFirstPrint of tree with deleted node ----------
	std::cout << std::endl;
	GT_ptr->DeleteNode(GT_ptr->Tree.front()->child.front());
	printString("DepthFirstPrint of tree with deleted node with data value '1':");
	std::cout << std::endl;
	GT_ptr->DepthFirstPrintTree(GT_ptr->Tree.front());

	std::cout << std::endl;
	printString("---------------------------------");
}

void CompMain::RandomAdjacencyGraph()
{
	printString("---------------------------------");
	std::cout << std::endl;
	std::cout << std::endl;

	AG_ptr->GenerateRandomGraph(6, 50);
	AG_ptr->printGraph();

	printString("---------------------------------");
}

void CompMain::ExampleAdjacencyGraph()
{
	/*		The Graph example
	*                   
	*			 0 - 1
	*		   / | /
	*		   | 2 - 3
	*		    \   /
	*			  4
	*/


	printString("---------------------------------");
	std::cout << std::endl;
	std::cout << std::endl;

	// Create Test Graph
	// Creating the nodes.
	std::shared_ptr<AdjacencyListGraph::Node> node0 = AG_ptr->CreateNode(0, 100);
	std::shared_ptr<AdjacencyListGraph::Node> node1 = AG_ptr->CreateNode(1, 200);
	std::shared_ptr<AdjacencyListGraph::Node> node2 = AG_ptr->CreateNode(2, 300);
	std::shared_ptr<AdjacencyListGraph::Node> node3 = AG_ptr->CreateNode(3, 400);
	std::shared_ptr<AdjacencyListGraph::Node> node4 = AG_ptr->CreateNode(4, 500);
	// Creating the edges
	AG_ptr->AddEdge(node0, node1, 10);
	AG_ptr->AddEdge(node0, node2, 20);
	AG_ptr->AddEdge(node0, node4, 30);
	AG_ptr->AddEdge(node1, node2, 40);
	AG_ptr->AddEdge(node2, node3, 50);
	AG_ptr->AddEdge(node3, node4, 60);

	// printing the graph
	printString("Printed Graph:");
	std::cout << std::endl;
	AG_ptr->printGraph();

	// ModifyData ----------
	printString("Node 1 data:");
	printInt(node1->data);
	std::cout << std::endl;
	printString("Modified Data of node 1 from 200 too 250:");
	AG_ptr->ModifyData(node1, 250);
	std::cout << std::endl;
	printString("New node 1 data:");
	printInt(node1->data);
	std::cout << std::endl;

	// DepthFirstPrint ----------
	std::cout << std::endl;
	printString("Depth First Traversal of graph: ");
	std::cout << std::endl;
	std::vector<bool> visited(AG_ptr->GetSize(), false);
	AG_ptr->DepthTraversal(node0, visited);

	// BreadthFirstPrint ----------
	std::cout << std::endl;
	printString("Breadth First Traversal of graph: ");
	std::cout << std::endl;
	AG_ptr->BreadthTraversal(node0);

	// ---------- Getters ----------

	std::cout << std::endl;
	printString("------ Getters ---------");
	std::cout << std::endl;

	// GetSize ----------
	std::cout << std::endl;
	printString("Size of graph in amount of vertexes(Nodes):");
	printInt(AG_ptr->GetSize());
	std::cout << std::endl;

	// GetNodeData ----------
	std::cout << std::endl;
	printString("Node data of node 1:");
	printInt(AG_ptr->GetNodeData(node1));
	std::cout << std::endl;

	// GetAdjacentNodes ----------
	std::cout << std::endl;
	printString("Node 2's Adjacent nodes are: ");
	AG_ptr->printData(AG_ptr->GetAdjacentNodes(node2));
	std::cout << std::endl;

	// GetNodeEdges ----------
	std::cout << std::endl;
	printString("Node 2's edges weights are: ");
	AG_ptr->printEdge(AG_ptr->GetEdges(node2));
	std::cout << std::endl;

	// GetAdjacentNodeEdges ----------
	std::cout << std::endl;
	printString("Node 2's adjacent nodes with edge weights are: ");
	std::cout << std::endl;
	AG_ptr->printAdjacentNodeEdges(AG_ptr->GetAdjacentNodeEdges(node2));

	// GetAllNodes ----------
	printString("All Nodes in graph: ");
	AG_ptr->printData(AG_ptr->GetGraphVertices());
	std::cout << std::endl;

	// GetAllEdges ----------
	std::cout << std::endl;
	printString("All Edges in graph: ");
	AG_ptr->printEdge(AG_ptr->GetGraphEdges());
	std::cout << std::endl;

	// GetAllVertexes ----------
	std::cout << std::endl;
	printString("All vertexes/entire graph: ");
	AG_ptr->printCompleteGraph(AG_ptr->GetGraphVertexes());
	std::cout << std::endl;

	// ---------- Checkers ----------

	printString("------ Checkers ---------");
	std::cout << std::endl;

	// IsEmpty ----------
	std::cout << std::endl;
	printString("Checks if tree is Empty:");
	if (GT_ptr->IsEmpty())
		printString("true");
	else
		printString("false");
	std::cout << std::endl;

	// ---------- Delete function ----------

	std::cout << std::endl;
	printString("------ Deletion ---------");
	std::cout << std::endl;

	// Deleted Edge ----------
	AG_ptr->DeleteEdge(node0,node2);
	std::cout << std::endl;

	printString("Printed graph edge between Node 0 and Node 2 has been deleted: ");
	std::cout << std::endl;
	AG_ptr->printGraph();

	// Deleted Node ----------
	AG_ptr->DeleteNode(node2);

	printString("Printed graph where Node 2 has been deleted: ");
	std::cout << std::endl;
	AG_ptr->printGraph();

	// GetAllNodes ----------
	printString("All updated Nodes in graph: ");
	AG_ptr->printData(AG_ptr->GetGraphVertices());

	std::cout << std::endl;
	std::cout << std::endl;
	printString("---------------------------------");
}

void CompMain::printString(const std::string string)
{
	std::cout << string << " ";
}

void CompMain::printInt(const int number)
{
	std::cout << number << " ";
}

