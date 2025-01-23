

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;


void merge(int array[], int leftIndex, int minIndex, int rightIndex) {
	int leftArraySize = midIndex - leftIndex + 1; // Merge compares the value to know the one less than the other
	int rightArraySize = rightIndex - midIndex;  // and place it at the correct index of the main array.

	int leftArray[leftArraySize];
	int rightArray[rightArraySize];

	for (int i = 0; i < leftArraySize; i++)
		leftArray[i] = array[leftIndex + i];

	for (int j = 0; j < rightArraySize; j++)
		rightArray[j] = array[midIndex + 1 + j];

	int index = leftIndex;
	int i = 0;
	int j = 0;

	while (i < leftArraySize && j < rightArraySize) {
		if (leftArray[i] <= rightArray[j]) {
			array[index] = leftArray[i];
			index++;
			i++;
		}
		else {
			array[index] = rightArray[j];
			index++;
			j++;
		}
	}

	while (i < leftArraySize) {
		array[index] = leftArray[i];
		index++;
		i++;
	}

	while (j < rightArraySize) {
		array[index] = rightArray[j];
		index++;
		j++;
	}
	
}

void mergeSort(int array[], int leftIndex, int rightIndex) { // Here is the resursive call of the merge sort
	if (leftIndex >= rightIndex) return;					 // that divides an array in half to it's base case
															 // before the merge function is called.
	int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
	mergeSort(array, leftIndex, midIndex);
	mergeSort(array, midIndex + 1, rightIndex);
	merge(array, leftIndex, midIndex, rightIndex);
}








int main()
{
	auto startTime = chrono::high_resolution_clock::now();
	
	int myArray[] = { 3,1,4,2 };
	int size = sizeof(myArray) / sizeof(myArray[0]);
	int leftIndex = 0;
	int rightIndex = size - 1;

	mergeSort(myArray, leftIndex, rightIndex);
	for (auto& value : myArray)
	{
		cout << "::)= " << value << ", ";
	}

	auto endTime = chrono::high_resolution_clock::now();
	chrono::duration<double> timeComlexity = endTime - startTime;
	cout << "\n\n:::::::::::::: TIME COMPLEXITY ::::::::::::::" << endl;
	cout << "::::: Run Time: " << timeComlexity.count() << "ms" << endl;
}


