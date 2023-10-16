#pragma once

#include <iostream>

#include "GraphLibrary.h"
#include "TreeLibrary.h"

using namespace std;

class CompMain
{
public:

	CompMain();

	shared_ptr<TreeLibrary>	Tree = make_shared<TreeLibrary>();
	
	shared_ptr<GraphLibrary> Graph = make_shared<GraphLibrary>();

	void print(const std::string string);
};
