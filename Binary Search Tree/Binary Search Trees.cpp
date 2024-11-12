

#include <iostream>
#include <chrono>

class Node {       // ------> This is a node class where all Nodes are formed.
public:
	int value;
	Node* left;
	Node* right;

	Node(int value) {
		this->value = value;
		left = nullptr;
		right = nullptr;
	}
};

class BinarySearchTree {   // -----> Binary Search Tree class that create edges or connection between Nodes.
private:
	Node* root;

public:
	BinarySearchTree() {   // ------> Binary Search Tree constructor where the root is set to nullptr. 
		root = nullptr;    //         No value created here when an instance is called on the main function.
	}

	void destroy(Node* currentNode) {      // ----> This is a recursive helper function that performs a post-order traversal to delete each Node in the binary search tree
		if (currentNode == nullptr) return;
		if (currentNode->left) destroy(currentNode->left); // ---> Here, if currentNode has a left child, the function calls itself on the left child, moving recursively down the left subtree
		if (currentNode->right) destroy(currentNode->right); // ---> After finishing the left subtree, it moves to the right subtree
		delete currentNode;        //---->  This recursive approach ensures that the leaf Nodes are deleted first, followed by their parent Nodes, and so on, up to the root.
	}

	~BinarySearchTree() { destroy(root); }  // -----> Distractor

	Node* getNode() {     // ----> Here is the get function for the Node values.
		return root;
	}

	bool imsert(int value) {   //------> This function creates and insert new Node in the Binary Search Tree.
		Node* newNode = new Node(value);
		if (root == nullptr) {
			root = newNode;
			return true;
		}
		Node* temp = root;
		while (true)
		{
			if (newNode->value == temp->value) return false;  // ---> Here comparison to check if Node values are equal to return false.
			if (newNode->value > temp->value) {  // ---> Here, if new Node value is greater, it checkes if the right part is empty before 
				if (temp->right == nullptr) {    //      inserting a new Node, else it moves the pointer to the right.
					temp->right = newNode;
					return true;
				}
				temp = temp->right;
			}
			else
			{
				if (newNode->value < temp->value) {  // ---> Here, if new Node value is less, it checkes if the left part is empty before 
					if (temp->left == nullptr) {     //      inserting a new Node, else it moves the pointer to the left.
						temp->left = newNode;
						return true;
					}
					temp = temp->left;
				}
			}
		}
	}

	bool contains(int value) {
		Node* temp = root;           // ---> This function is used to search for value in Binary Search Tree.
		while (temp)
		{
			if (value < temp->value) {
				temp = temp->left;
			}
			else if (value > temp->value) {
				temp = temp->right;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
	 

};






int main()
{
	auto startTime = std::chrono::high_resolution_clock::now();
	BinarySearchTree* BST = new BinarySearchTree();
	std::cout << "\n\n :::::::::: TREE VALUES :::::::::: \n\n";
	BST->imsert(20);
	BST->imsert(10);
	BST->imsert(30);
	BST->imsert(40);
	BST->imsert(50);
	BST->imsert(5);

	std::cout << "Root Node: " << BST->getNode()->value << std::endl;
	std::cout << "Left child: " << BST->getNode()->left->value << std::endl;
	std::cout << "right child: " << BST->getNode()->right->value << std::endl;
	std::cout << "Contains 40: " << (BST->contains(40) ? "True" : "False") << std::endl;
	std::cout << "Contains 100: " << (BST->contains(100) ? "True" : "False") << std::endl;


	auto endTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> timeComplexity = endTime - startTime;
	std::cout << "\n\n::::::::::::::: TIME COMPLEXITY :::::::::::::::" << std::endl;
	std::cout << "::::: Run Time: " << timeComplexity.count();
	system("pause > 0");
}


