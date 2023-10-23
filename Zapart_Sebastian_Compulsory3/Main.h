#pragma once

#include <iostream>

#include "GenericTreeDataStructure.h"
#include "AdjacencyListGraph.h"

using namespace std;

class CompMain
{
public:

	CompMain();

	shared_ptr<GenericTree>	GT_ptr = make_shared<GenericTree>();

	shared_ptr<AdjacencyListGraph> AG_ptr = make_shared<AdjacencyListGraph>();

	/**
	 * \brief Tests the generic tree that uses lists.
	 */
	void TestGenericTree();

	void TestAdjacencyGraph();

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

