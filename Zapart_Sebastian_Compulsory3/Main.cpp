
#include "Main.h"
#include <iostream>

using namespace std;

int main()
{
	CompMain();
}

CompMain::CompMain()
{
	cout << "Witch Datastructure would you like to test?" << endl;
	cout << "1. GenericTree" << endl;
	cout << "2. AdjacencyListGraph" << endl;
	cout << "1-2: ";
	int choice = 0;
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
		printString("GenericTree, function examples");
		cout << endl;
		TestGenericTree();

		break;
	case 2:
		cout << "Adjacency List Graph, function examples" << endl;
		cout << endl;
		TestAdjacencyGraph();

		break;
	default:
		cout << endl;
		cout << "That input was not 1 or 2" << endl;
		cout << endl;

		exit(choice);
	}
	cout << endl;
	cout << endl;
	cout << "Do you want to try again?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cout << "1-2: ";
	cin >> choice;
	cout << endl;

	switch (choice)
	{
	case 0:
		cout << endl;
		cout << "Incorrect Data type" << endl;
		cout << "Exit on Code " << choice << endl;

		exit(choice);
	case 1:
		CompMain();

		break;
	case 2:
		exit(choice);

	default:
		cout << endl;
		cout << "That input was not 1 or 2" << endl;
		cout << endl;

		exit(choice);
	}
}

void CompMain::TestGenericTree()
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

		// DepthFirstPrint of tree with deleted node ----------
	std::cout << std::endl;

	GT_ptr->DeleteNode(GT_ptr->Tree.front()->child.front());
	printString("DepthFirstPrint of tree with deleted node with data value '1':");
	std::cout << std::endl;
	GT_ptr->DepthFirstPrintTree(GT_ptr->Tree.front());

	std::cout << std::endl;
	std::cout << std::endl;
	printString("---------------------------------");
}

void CompMain::TestAdjacencyGraph()
{
	printString("---------------------------------");
	std::cout << std::endl;
	std::cout << std::endl;

	std::shared_ptr<AdjacencyListGraph::Node> node0 = AG_ptr->CreateNode(0, 100);
	std::shared_ptr<AdjacencyListGraph::Node> node1 = AG_ptr->CreateNode(1, 200);
	std::shared_ptr<AdjacencyListGraph::Node> node2 = AG_ptr->CreateNode(2, 300);

	AG_ptr->AddEdge(node0, node1, 10);
	AG_ptr->AddEdge(node0, node2, 30);
	AG_ptr->printGraph();

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

