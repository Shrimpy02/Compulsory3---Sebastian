#pragma once
#include <vector>

class GenericTree
{
public:
	//--------------------- Class initialization ---------------------
	/**
	 * \brief Constructor creates the root for the first of the tree Arrays
	 */
	GenericTree()
	{
		Tree.push_back(CreateNode(rootData));
	}

	/**
	 * \brief Node Struct
	 */
	struct Node
	{
		int data;
		std::vector<Node*> child;
	};

	//---------------------  Variables  ---------------------

	/**
	 * \brief Vector containing a dynamic amount of trees. 
	 */
	std::vector<Node*> Tree;

	/**
	 * \brief Common Data for all root nodes
	 */
	const int rootData = -1;

	//---------------------  Member Functions  ---------------------

	/**
	 * \brief Create's a new node
	 * \param data Data the new Node is to hold
	 * \return returns the new node created
	 */
	Node* CreateNode(int data)
	{
		Node* NewNode = new Node();
		NewNode->data = data;
		return NewNode;
	}

	/**
	 * \brief Traverses the tree from the given node in a depth first manor
	 * \param root The node it starts traversing from.
	 */
	void DepthFirstPrintTree(Node* root)
	{
		if (root == nullptr) return;

		std::cout << root->data << " ";
		for (int i = 0; i < root->child.size(); i++)
		{
			DepthFirstPrintTree(root->child[i]);
		}
	
	}

	/**
	 * \brief Traverses the tree from the given node in a breadth first manor
	 * \param root The node it starts traversing from.
	 */
	void BredthFirstPrintTree(Node* root)
	{
		if (root == nullptr) return;

		std::vector<Node*> TempChildren;
		TempChildren.push_back(root);

		while (!TempChildren.empty())
		{
			int n = TempChildren.size();

			while (n > 0)
			{
				Node* p = TempChildren.front();
				TempChildren.erase(TempChildren.begin());
				std::cout << p->data << " ";

				for (int i = 0; i < p->child.size(); i++)
				{
					TempChildren.push_back(p->child[i]);
				}
				n--;
			}
			std::cout << std::endl;
		}
	}

	Node* GetRoot()
	{
		
	}

	Node* GetParent()
	{
		
	}

	std::vector<Node*> GetChildren()
	{
		
	}

	int GetSize()
	{
		
	}

	bool IsEmpty()
	{
		
	}

	bool IsRoot()
	{
		
	}

	bool Isleaf()
	{
		
	}

	void insertNode()
	{
		// the same as creating a new node considering dynamic vectors
	}

	void DeleteNode()
	{
		
	}
};
