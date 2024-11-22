

#include <iostream>
#include <queue>
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

class BreadthFirstSearch {
private:
	queue<Node*> myQueue;
	Node* root = nullptr;
	void inOrderTraversal(Node* node) {
		if (node == nullptr) return;
		inOrderTraversal(node->left);
		cout << node->value << ", ";
		inOrderTraversal(node->right);
	}

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

	void BFS() {                          //       This function inserts the Node in a Queue.
		cout << ":::: BFS values: { ";
		myQueue.push(root);
		while (myQueue.size() > 0)      
		{
			Node* currentNode = myQueue.front();
			myQueue.pop();
			cout << currentNode->value << ", ";
			if (currentNode->left != nullptr) {
				myQueue.push(currentNode->left);
			}
			if (currentNode->right != nullptr) {
				myQueue.push(currentNode->right);
			}
		}
		cout << "} ::" << endl;
	}

};





int main()
{
	auto startTime = chrono::high_resolution_clock::now();
	cout << "\n\n";
	BreadthFirstSearch* BFS = new BreadthFirstSearch();
	BFS->rInsert(40);
	BFS->rInsert(30);
	BFS->rInsert(50);
	BFS->rInsert(80);
	BFS->rInsert(70);
	BFS->rInsert(90);
	BFS->rInsert(20);
	BFS->rInsert(10);
	BFS->rInsert(60);
	BFS->BFS();


	auto endTime = chrono::high_resolution_clock::now();
	chrono::duration<double> timeComplexity = endTime - startTime;
	cout << "\n\n::::::::::::: TIME COMPLEXITY :::::::::::::" << endl;
	cout << "::::: Run time: " << timeComplexity.count() << "ms" << endl;
}


