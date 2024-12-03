

#include <iostream>
#include <chrono>
using namespace std;




void bubbleSort(int array[], int size) {
	for (int i = size -1; i > 0; i--)
	{
		for (int j = 0; j < i; j++) {
			if (array[j] < array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void bubbleSort() {
	int arrayNumbers[] = { 10, 5, 2, 4, 7, 6, 9, 50, 10 };
	int size = sizeof(arrayNumbers) / sizeof(arrayNumbers[0]);
	bubbleSort(arrayNumbers, size);
	cout << "\n\n::::::::::::::::::::::::::::::::::::::::::::::" << endl;
	cout << "*** Numbers in asending order." << endl;
	cout << "\t";
	for (auto& values : arrayNumbers) {
		cout << values << " ";
	}
}


int main()
{
	auto startTime = chrono::high_resolution_clock::now();
	cout << "\n\n";
	bubbleSort();
	
	auto endTime = chrono::high_resolution_clock::now();
	chrono::duration<double> timeComplexity = endTime - startTime;
	cout << "\n\n::::::::::::: TIME COMPLEXITY :::::::::::::" << endl;
	cout << "::::: Run time: " << timeComplexity.count() << "ms" << endl;
}


