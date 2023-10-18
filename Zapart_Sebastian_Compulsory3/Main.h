#pragma once

#include <iostream>

#include "GraphLibrary.h"
#include "GenericTreeDataStructure_list.h"

using namespace std;

class CompMain
{
public:

	CompMain();

	shared_ptr<GenericTreeList>	GT_list_ptr = make_shared<GenericTreeList>();

	//shared_ptr<GenericTreeVector>	GT_vector_ptr = make_shared<GenericTreeVector>();
	
	shared_ptr<GraphLibrary> Graph = make_shared<GraphLibrary>();

	/**
	 * \brief Tests the generic tree that uses lists.
	 */
	void TestGenericTreeUsingLists();

	/**
	 * \brief prints the given input
	 * \param string the string to print
	 */
	void printString(const std::string string);

	/**
	 * \brief print the given input
	 * \param number the int to print
	 */
	void printInt(const int number);

};

