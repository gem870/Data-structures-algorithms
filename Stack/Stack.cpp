

#include <iostream>
#include <chrono>
using namespace std;


class Node {    // ----->> This is a Node class where all Nodes are generated.
public:
	int value;
	Node* next;

	Node(int value) {
		this->value = value;
		next = nullptr;
	}
};

class Stack {     // ----->> Stack class
private:
	Node* top;
	int height;

public:

	Stack(int value) {     // ----->> Stack constructor where new Nodes are created.
		Node* newNode = new Node(value);
		top = newNode;
		height = 1;
	}

	~Stack() {     // ----->> Stack distractor that deletes all the Nodes;
		Node* temp = top;
		while (temp)
		{
			top = top->next;
			delete temp;
			temp = top;
		}
	}

	void printStack() {  // ----->> Stack function that prints all Node values.
		Node* temp = top;
		cout << "\n\n::::::::::::: STACK VALUES :::::::::::::" << endl;
		while (temp)
		{
			cout << "::: -> " << temp->value << endl;
			temp = temp->next;
		}
	}

	void push(int value) {  // ----->> This function adds a new items in the stack;
		Node* newNode = new Node(value);
		newNode->next = top;
		top = newNode;
		height++;
	}

	int pop() {      // ----->> This function delete items in the stack;
		if (height == 0) return INT_MIN;
		Node* temp = top;
		int poppedValue = temp->value;
		top = top->next;
		delete temp;
		height--;
		return poppedValue;
	}

};









int main()
{
	auto startTime = chrono::high_resolution_clock::now();
	Stack* myStack = new Stack(20);
	myStack->push(30);
	myStack->push(40);
	myStack->push(50);
	myStack->push(60);

	myStack->printStack();
	auto endTime = chrono::high_resolution_clock::now();
	chrono::duration<double> timeComplexity = endTime - startTime;
	cout << "\n\n:::::::::::::: TIME COMPLEXITY ::::::::::::::" << endl;
	cout << "::::: Run Time: " << timeComplexity.count() << "ms" << endl;


}






