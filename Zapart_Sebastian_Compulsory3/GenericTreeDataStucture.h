#pragma once
#include <list>

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
		std::list<Node*> child;
	};

	//---------------------  Variables  ---------------------

	/**
	 * \brief Vector containing a dynamic amount of trees.
	 */
	std::list<Node*> Tree;

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
	Node* CreateNode(const int data)
	{
		Node* NewNode = new Node();
		NewNode->data = data;
		return NewNode;
	}

	/**
	 * \brief Creates a test tree using the constructed root
	 */
	void CreateTestTree()
	{
		/*		The tree to create
		*              -1
		*         /  /    \     \
		*        1  2      3      4
		*       / \        |   /  | \
		*      5   6       7   8  9  10
		*/

		//if (Tree.front()->child.front() =) return;

		// root 1
		Tree.front()->child.push_back(CreateNode(1));
		Tree.front()->child.front()->child.push_back(CreateNode(5));
		Tree.front()->child.front()->child.push_back(CreateNode(6));
		Tree.front()->child.push_back(CreateNode(2));
		Tree.front()->child.push_back(CreateNode(3));
		Tree.front()->child.back()->child.push_back(CreateNode(7));
		Tree.front()->child.push_back(CreateNode(4));
		Tree.front()->child.back()->child.push_back(CreateNode(8));
		Tree.front()->child.back()->child.push_back(CreateNode(9));
		Tree.front()->child.back()->child.push_back(CreateNode(10));
	}

	/**
	 * \brief Traverses the tree from the given node in a depth first manor
	 * \param root The node it starts traversing from.
	 */
	void DepthFirstPrintTree(Node* root)
	{
		if (root == nullptr) return;

		std::cout << root->data << " ";
		for (auto it = root->child.begin(); it != root->child.end(); ++it) {
			DepthFirstPrintTree(*it);
		}
	}

	/**
	 * \brief Traverses the tree from the given node in a breadth first manor
	 * \param root The node it starts traversing from.
	 */
	void BredthFirstPrintTree(Node* root)
	{
		if (root == nullptr) return;

		std::list<Node*> TempChildren;
		TempChildren.push_back(root);

		while (!TempChildren.empty())
		{
			int n = TempChildren.size();

			while (n > 0)
			{
				Node* p = TempChildren.front();
				TempChildren.erase(TempChildren.begin());
				std::cout << p->data << " ";

				for (auto it = p->child.begin(); it != p->child.end(); ++it) {
					TempChildren.push_back(*it);
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

	std::list<Node*> GetChildren()
	{
		
	}

	int GetSize()
	{
		
	}

	int GetDepth()
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
