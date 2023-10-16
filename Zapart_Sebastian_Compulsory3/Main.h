#pragma once

#include <iostream>

#include "GraphLibrary.h"
#include "GenericTreeDataStucture.h"

using namespace std;

class CompMain
{
public:

	CompMain();

	shared_ptr<GenericTree>	GT_ptr = make_shared<GenericTree>();
	
	shared_ptr<GraphLibrary> Graph = make_shared<GraphLibrary>();

	/**
	 * \brief Creates a hardcoded 
	 */
	void CreateExampleTree();

	/**
	 * \brief prints a hardcoded example tree
	 */
	void printExampleTree();



	/**
	 * \brief prints the given input
	 * \param string the string to print
	 */
	void print(const std::string string);
	/**
	 * \brief print the given input
	 * \param string the int to print
	 */
	void print(const int string);

};
