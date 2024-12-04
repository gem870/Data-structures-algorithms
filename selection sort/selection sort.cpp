

#include <iostream>
#include <chrono>
using namespace std;




void selectionSort(int array[], int size) {                   // ---> Here is the main sorting function.
	for (int i = 0; i < size; i++) {
		int minIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (array[j] < array[minIndex]) {
				minIndex = j;
			}
		}
		int temp = array[i];
		array[i] = array[minIndex];
		array[minIndex] = temp;
	}
}

void selectionSort() {
	int arrayNumbers[] = { 10, 5, 2, 4, 7, 6, 9, 50, 10 };    
	int size = sizeof(arrayNumbers) / sizeof(arrayNumbers[0]);
	selectionSort(arrayNumbers, size);                           // ---> Here is the function call
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
	selectionSort();
	
	auto endTime = chrono::high_resolution_clock::now();
	chrono::duration<double> timeComplexity = endTime - startTime;
	cout << "\n\n::::::::::::: TIME COMPLEXITY :::::::::::::" << endl;
	cout << "::::: Run time: " << timeComplexity.count() << "ms" << endl;
}


