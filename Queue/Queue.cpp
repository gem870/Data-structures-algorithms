

#include <iostream>
#include <chrono>
using namespace std;

class Node {  // ----> Node class where all Node are created.
public:
	int value;
	Node* next;

	Node(int value) {
		this->value = value;
		next = nullptr;
	}
};

class Queue {  // -----> Queue class where edges or connection are created for the Node class.
private:
	Node* first;
	Node* last;
	int length;

public:
	Queue(int value) { // -----> Queue constructor where new Nodes are created;
		Node* newNode = new Node(value);
		first = newNode;
		last = newNode;
		length = 1;
	}

	~Queue() {    // -----> Queue distractor that deletes all the Node in the Queue class.
		Node* temp = first;
		while (temp)
		{
			first = first->next;
			delete temp;
			temp = first;
		}
	}

	void printQueue() {  // ----> This function prints all the node values in the class.
		Node* temp = first;
		cout << "\n\n:::::::::::: PRINT QUEUE ::::::::::::" << endl;
		while (temp)
		{
			cout << ":::: Queue value: " << temp->value << endl;
			temp = temp->next;
		}
	}

	void enqueue(int value) {    // ------> This function adds a new Node from the back of the queue.
		Node* newNode = new Node(value);
		if (length == 0) {
			first = newNode;
			last = newNode;
		}
		else
		{
			last->next = newNode;
			last = newNode;
		}
		length++;
	}

	int dequeue() {     // ------> This function deletes Node from the front of the queue.
		if (length == 0) return INT_MIN;
		Node* temp = first;
		int dequeueValue = temp->value;
		if (length == 1) {
			first = nullptr;
			last = nullptr;
		}
		else
		{
			first = first->next;
		}
		delete temp;
		length--;
		return dequeueValue;
	}



};




int main()
{
	auto startTime = chrono::high_resolution_clock::now();
	Queue* myQueue = new Queue(20);
	myQueue->enqueue(40);
	myQueue->enqueue(50);
	myQueue->enqueue(60);
	myQueue->enqueue(70);


	myQueue->printQueue();
	auto endTime = chrono::high_resolution_clock::now();
	chrono::duration<double> timeComplexity = endTime - startTime;
	cout << "\n\n:::::::::::::: TIME COMPLEXITY ::::::::::::::" << endl;
	cout << "::::: Run Time: " << timeComplexity.count() << "ms" << endl;
}

