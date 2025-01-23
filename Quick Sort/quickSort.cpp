

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;


void swap(int array[], int index1, int index2) {
	int temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
}

int pivot(int array[], int pivotIndex, int endIndex) {
	int swapIndex = pivotIndex;
	for (size_t i = pivotIndex + 1; i <= endIndex; i++)
	{
		if (array[i] < array[pivotIndex]) {
			swapIndex++;
			swap(array, swapIndex, i);
		}
	}
	swap(array, pivotIndex, swapIndex);
	return swapIndex;
}

void quickSort(int array[], int leftIndex, int rightIndex) {
	if (leftIndex >= rightIndex) return;
	int pivotIndex = pivot(array, leftIndex, rightIndex);
	quickSort(array, leftIndex, pivotIndex);
	quickSort(array, pivotIndex + 1, rightIndex);
}









int main()
{
	auto startTime = chrono::high_resolution_clock::now();

	int array[] = { 4,6,3,7,9,5,3,2,2,6 };
	int size = sizeof(array) / sizeof(array[0]);
	quickSort(array, 0, size - 1);
	for (auto& i : array)
	{
		cout << i << " ";
	}
	

	auto endTime = chrono::high_resolution_clock::now();
	chrono::duration<double> timeComlexity = endTime - startTime;
	cout << "\n\n:::::::::::::: TIME COMPLEXITY ::::::::::::::" << endl;
	cout << "::::: Run Time: " << timeComlexity.count() << "ms" << endl;
}


