

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

class Node {
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

class RecursiveBinarySearchTree {
public:
	Node* root = nullptr;
	void inOrderTraversal(Node* node) {
		if (node == nullptr) return;
		inOrderTraversal(node->left);
		cout << node->value << ", ";
		inOrderTraversal(node->right);
	}

public:

	void printTree() {
		Node* temp = root;
		cout << "All the tree values -> { ";
		inOrderTraversal(temp);
		cout << "}" << endl;
	}

	Node* rInsert(Node* currentNode, int value) {           // --> This is a recursive function that insert Nodes on the left and the right side in the search binary tree.
		if (currentNode == nullptr) return new Node(value);
		if (value < currentNode->value) {
			currentNode->left = rInsert(currentNode->left, value);  // Here traverse to the left side of the tree for Node insertion.
		}
		else if (value > currentNode->value) {
			currentNode->right = rInsert(currentNode->right, value);  // Here traverse to the right side of the tree for Node insertion.
		}
		return currentNode;
	}

	void rInsert(int value) {
		if (root == nullptr) root = new Node(value);
		rInsert(root, value);
	}

	bool rContains(Node* currentNode, int value) { // --> This function checks if values are found in the binary tree.
		if (currentNode == nullptr) return false;
		if (currentNode->value == value) return true;
		if (value < currentNode->value) {
			return rContains(currentNode->left, value);
		}
		else
		{
			return rContains(currentNode->right, value);
		}
	}

	bool rContains(int  value) {
		return rContains(root, value);
	}

	int minValue(Node* currentNode) {           // --> This function ransverse to the left side of the tree and return the minimum value.
		while (currentNode->left != nullptr)
		{
			currentNode = currentNode->left;
		}
		return currentNode->value;
	}


	Node* rDeleteNode(Node* currentNode, int value) {  // ---> This function recursively insert new Node in the tree.
		if (currentNode == nullptr) return nullptr;
		if (value < currentNode->value) {
			currentNode->left = rDeleteNode(currentNode->left, value);
		}
		else {
			if (currentNode->left == nullptr && currentNode->right == nullptr) {
				delete(currentNode);          // ---> This ensures that the Node to be deleted is pointing to null before deleted.
				return nullptr;
			}
			else if (currentNode->left == nullptr) { // ---> This ensures that if eletement is on the right part of the parent Node
				Node* temp = currentNode->right;     //      the temp then holds the value of the right Node before the parent Node is deleted.
				delete(currentNode);
				return temp;
			} if (currentNode->right == nullptr) {   // ---> This ensures that if eletement is on the left part of the parent Node
				Node* temp = currentNode->left;      //      the temp then holds the value of the left Node before the parent Node is deleted.
				delete(currentNode);
				return temp;
			}
			else
			{
				int subTreeMin = minValue(currentNode->right); // ---> This function deletes Node that has leafs Node (Left & right child) at both side of the parent Node 
				currentNode->value = subTreeMin;               //      to mentain the tree structure.
				currentNode->right = rDeleteNode(currentNode->right, subTreeMin);
			}
		}

		return currentNode;
	}

	void rDeleteNode(int value) {
		root = rDeleteNode(root, value);
	}

};





int main()
{
	auto startTime = chrono::high_resolution_clock::now();
	cout << "\n\n";
	RecursiveBinarySearchTree* rBST = new RecursiveBinarySearchTree();
	rBST->rInsert(40);
	rBST->rInsert(30);
	rBST->rInsert(50);
	rBST->rInsert(80);
	rBST->rInsert(70);
	rBST->rInsert(90);
	rBST->rInsert(20);
	rBST->rInsert(10);
	rBST->rInsert(60);
	rBST->printTree();
	cout << (rBST->rContains(20) ? "Contain 20 -> True!" : "Contain 20 -> False!") << endl;
	cout << (rBST->rContains(90) ? "Contain 90 -> True!" : "Contain 90 -> False!") << endl;
	cout << (rBST->rContains(200) ? "Contain 200 -> True!" : "Contain 200 -> False!") << endl;
	cout << ":::: Mini Value: " << rBST->minValue(rBST->root) << endl;

	auto endTime = chrono::high_resolution_clock::now();
	chrono::duration<double> timeComplexity = endTime - startTime;
	cout << "\n\n::::::::::::: TIME COMPLEXITY :::::::::::::" << endl;
	cout << "::::: Run time: " << timeComplexity.count() << "ms" << endl;
}


