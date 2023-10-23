#pragma once

#include <iostream>

#include "GenericTreeDataStructure.h"
#include "AdjacencyListGraph.h"

using namespace std;

class CompMain
{
public:
	/**
	 * \brief Class constructor.
	 */
	CompMain();

	/**
	 * \brief Smart pointer to the Generic tree class.
	 */
	shared_ptr<GenericTree>	GT_ptr = make_shared<GenericTree>();

	/**
	 * \brief Smart pointer to the AdjacencyListGraph class.
	 */
	shared_ptr<AdjacencyListGraph> AG_ptr = make_shared<AdjacencyListGraph>();

	/**
	 * \brief Tests the generic tree that uses lists.
	 */
	void TestGenericTree();

	void TestAdjacencyGraph();

	/**
	 * \brief Prints the given input.
	 * \param string The string to print.
	 */
	void printString(const std::string string);

	/**
	 * \brief Print the given input.
	 * \param number The int to print.
	 */
	void printInt(const int number);

};

