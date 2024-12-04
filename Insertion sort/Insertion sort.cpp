

#include <iostream>
#include <chrono>
using namespace std;




void insertionSort(int array[], int size) {                   // ---> Here is the main sorting function.
	for (int i = 1; i < size; i++) {
		int temp = array[i];
		int j = i - 1;
		while (temp < array[j]) {
			array[j + 1] = array[j];
			array[j] = temp;
			j--;
		}
	}
}

void insertionSort() {
	int arrayNumbers[] = { 10, 5, 2, 4, 7, 6, 9, 50, 10, 1 };    
	int size = sizeof(arrayNumbers) / sizeof(arrayNumbers[0]);
	insertionSort(arrayNumbers, size);                           // ---> Here is the function call
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
	insertionSort();
	
	auto endTime = chrono::high_resolution_clock::now();
	chrono::duration<double> timeComplexity = endTime - startTime;
	cout << "\n\n::::::::::::: TIME COMPLEXITY :::::::::::::" << endl;
	cout << "::::: Run time: " << timeComplexity.count() << "ms" << endl;
}


