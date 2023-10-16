
#include "Main.h"

#include <iostream>

using namespace std;

int main()
{
	CompMain();
}

CompMain::CompMain()
{
	CreateExampleTree();
	printExampleTree();

	print("DepthFirstPrint:");
	std::cout << std::endl;
	GT_ptr->DepthFirstPrintTree(GT_ptr->Tree[0]);
	std::cout << std::endl;

	print("BredthFirstPrint:");
	std::cout << std::endl;
	GT_ptr->BredthFirstPrintTree(GT_ptr->Tree[0]);
	std::cout << std::endl;

}

void CompMain::CreateExampleTree()
{
	/*   The tree to create
*              -1
*         /  /    \     \
*        1  2      3      4
*       / \        |   /  | \
*      5   6       7   8  9  10
*/

// root 1

	// root 1 - lvl 1
	GT_ptr->Tree[0]->child.push_back(GT_ptr->CreateNode(1));
	GT_ptr->Tree[0]->child.push_back(GT_ptr->CreateNode(2));
	GT_ptr->Tree[0]->child.push_back(GT_ptr->CreateNode(3));
	GT_ptr->Tree[0]->child.push_back(GT_ptr->CreateNode(4));

	// root 1 - lvl 2
	GT_ptr->Tree[0]->child[0]->child.push_back(GT_ptr->CreateNode(5));
	GT_ptr->Tree[0]->child[0]->child.push_back(GT_ptr->CreateNode(6));
	GT_ptr->Tree[0]->child[2]->child.push_back(GT_ptr->CreateNode(7));
	GT_ptr->Tree[0]->child[3]->child.push_back(GT_ptr->CreateNode(8));
	GT_ptr->Tree[0]->child[3]->child.push_back(GT_ptr->CreateNode(9));
	GT_ptr->Tree[0]->child[3]->child.push_back(GT_ptr->CreateNode(10));

}

void CompMain::printExampleTree()
{

	/*   The given tree to print
*              -1
*         /  /    \     \
*        1  2      3      4
*       / \        |   /  | \
*      5   6       7   8  9  10
*/

// root 1
	print("Exmaple Tree:");
	std::cout << std::endl;
	print(GT_ptr->Tree[0]->data);
	std::cout << std::endl;

	// root 1 - lvl 1
	print(GT_ptr->Tree[0]->child[0]->data);
	print(GT_ptr->Tree[0]->child[1]->data);
	print(GT_ptr->Tree[0]->child[2]->data);
	print(GT_ptr->Tree[0]->child[3]->data);
	std::cout << std::endl;

	// root 1 - lvl 2
	print(GT_ptr->Tree[0]->child[0]->child[0]->data);
	print(GT_ptr->Tree[0]->child[0]->child[1]->data);
	print(GT_ptr->Tree[0]->child[2]->child[0]->data);
	print(GT_ptr->Tree[0]->child[3]->child[0]->data);
	print(GT_ptr->Tree[0]->child[3]->child[1]->data);
	print(GT_ptr->Tree[0]->child[3]->child[2]->data);
	std::cout << std::endl;
}

void CompMain::print(const std::string string)
{
	std::cout << string << " ";
}
void CompMain::print(const int string)
{
	std::cout << string << " ";
}

