

#include <iostream>
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

class BFSTraversal {
private:
	Node* root = nullptr;

public:

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

	void DFSPreOrder(Node* currentNode) {
		cout << ":::: Pre-order value: { " << currentNode->value << " } ::::" << endl;
		if (currentNode->left != nullptr) {
			DFSPreOrder(currentNode->left);
		}
		if (currentNode->right != nullptr) {
			DFSPreOrder(currentNode->right);
		}
	}

	void DFSPreOrder() {
		DFSPreOrder(root);
	}

	void DFSPostOrder(Node* currentNode) {
		if (currentNode->left != nullptr) {
			DFSPostOrder(currentNode->left);
		}
		if (currentNode->right != nullptr) {
			DFSPostOrder(currentNode->right);
		}
		cout << ":::: Post-order value: { " << currentNode->value << " } ::::" << endl;
	}

	void DFSPostOrder() {
		DFSPostOrder(root);
	}

	void DFSInOrder(Node* currentNode) {
		if (currentNode->left != nullptr) {
			DFSInOrder(currentNode->left);
		}
		cout << ":::: InOrder value: { " << currentNode->value << " } ::::" << endl;
		if (currentNode->right != nullptr) {
			DFSInOrder(currentNode->right);
		}
	}

	void DFSInOrder() {
		DFSInOrder(root);
	}
};





int main()
{
	auto startTime = chrono::high_resolution_clock::now();
	cout << "\n\n";
	BFSTraversal* DFS = new BFSTraversal();
	DFS->rInsert(40);
	DFS->rInsert(30);
	DFS->rInsert(50);
	DFS->rInsert(80);
	DFS->rInsert(70);
	DFS->rInsert(90);
	DFS->rInsert(20);
	DFS->rInsert(10);
	DFS->rInsert(60);

	DFS->DFSPreOrder();
	cout << "\n:::::::::::::::::::::::::::::::::::::\n" << endl;
	DFS->DFSPostOrder();
	cout << "\n:::::::::::::::::::::::::::::::::::::\n" << endl;
	DFS->DFSInOrder();

	auto endTime = chrono::high_resolution_clock::now();
	chrono::duration<double> timeComplexity = endTime - startTime;
	cout << "\n\n::::::::::::: TIME COMPLEXITY :::::::::::::" << endl;
	cout << "::::: Run time: " << timeComplexity.count() << "ms" << endl;
}


