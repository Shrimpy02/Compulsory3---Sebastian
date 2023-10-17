
#include "Main.h"

#include <iostream>

using namespace std;

int main()
{
	CompMain();
}

CompMain::CompMain()
{
	print("Generic tree example");
	std::cout << std::endl;
	print("---------------------");
	std::cout << std::endl;
	std::cout << std::endl;

	GT_ptr->CreateTestTree();

	print("BredthFirstPrint:");
	std::cout << std::endl;
	GT_ptr->BredthFirstPrintTree(GT_ptr->Tree.front());
	std::cout << std::endl;

	print("DepthFirstPrint:");
	std::cout << std::endl;
	GT_ptr->DepthFirstPrintTree(GT_ptr->Tree.front());
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

