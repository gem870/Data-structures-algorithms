

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

class Heap {
private:
	vector<int> heap;
	int leftChild(int index) {
		return 2 * index + 1;
	}

	int rightchild(int index) {
		return 2 * index + 2;
	}

	int parent(int index) {
		return (index - 1) / 2;
	}

	void swap(int index1, int index2) {
		int temp = heap[index2];
		heap[index2] = heap[index1];
		heap[index1] = temp;
	}

	void sinkDown(int index) {
		int maxIndex = index;
		while (true)
		{
			int leftIndex = leftChild(index);
			int rightIndex = rightchild(index);

			if (leftIndex < heap.size() && heap[leftIndex] > heap[maxIndex]) {
				maxIndex = leftIndex;
			}

			if (rightIndex < heap.size() && heap[rightIndex] > heap[maxIndex]) {
				maxIndex = rightIndex;
			}

			if (maxIndex != index) {
				swap(index, maxIndex);
				index = maxIndex;
			}
			else
			{
				return;
			}
		}
	}

public:
	void insert(int value) {
		heap.push_back(value);
		int current = heap.size() - 1;
		while (current > 0 && heap[current] > heap[parent(current)])
		{
			swap(current, parent(current));
			current = parent(current);
		}
	}

	void print() {
		cout << "\n\n:::::::::::::: Print Heaps **************" << endl;
		cout << " { ";
		for (size_t i = 0; i < heap.size()-1; i++)
		{
			cout << heap[i];
			if (i < heap.size() - 1) {
				cout << ", ";
			}
		}
		cout << "}" << endl;
	}

	int remove() {
		if (heap.empty()) return INT_MIN;
		int maxValue = heap.front();
		if (heap.size() == 1) {
			heap.pop_back();
		}
		else
		{
			heap[0] = heap.back();
			heap.pop_back();
			sinkDown(0);
		}
	}

	

};




int main()
{
	auto startTime = chrono::high_resolution_clock::now();
	Heap* hp = new Heap();
	cout << "\n\n";
	hp->insert(40);
	hp->insert(60);
	hp->insert(90);
	hp->insert(80);
	hp->insert(20);
	hp->insert(40);
	hp->insert(100);

	hp->print();

	hp->remove();
	hp->print();
	hp->remove();
	hp->print();

	auto endTime = chrono::high_resolution_clock::now();
	chrono::duration<double> timeComplexity = endTime - startTime;
	cout << "\n\n::::::::::::: TIME COMPLEXITY :::::::::::::" << endl;
	cout << "::::: Run time: " << timeComplexity.count() << endl;
}


