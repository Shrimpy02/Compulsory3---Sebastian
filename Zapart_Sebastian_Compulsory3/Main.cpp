
#include "Main.h"
#include <iostream>

using namespace std;

//int main()
//{
//	CompMain();
//}

CompMain::CompMain()
{
	//TestGenericTree();
	TestAdjacencyGraph();
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


	printString("GenericTree function examples");
	std::cout << std::endl;
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
	//printInt(AG_ptr->Graphes[0]->data);

	// create edge
		// creats a new node linked to 



	// ----------------------------------------
	//AG_ptr->addEdge(0,1);
	//AG_ptr->addEdge(0, 3);
	//AG_ptr->addEdge(0, 4);
	//AG_ptr->addEdge(1, 2);
	//AG_ptr->addEdge(3, 2);
	//AG_ptr->addEdge(4, 3);
	//AG_ptr->printGraph();

	//cout << endl;
	//AG_ptr->deleteVertex(0);
	//AG_ptr->printGraph();
}

void CompMain::printString(const std::string string)
{
	std::cout << string << " ";
}
void CompMain::printInt(const int number)
{
	std::cout << number << " ";
}

