

#include <iostream>
#include <chrono>
#include <memory>
#include <vector>
#include <functional>
#include <map>
#include <thread>
#include <vector>
#include <list>
using namespace std;




void insertionSort(int array[], int size) {                   // ---> Here is the main sorting function.
	for (size_t i = 1; i < size; i++)
	{
		int temp = array[i];
		int j = i - 1;

		while (j > -1 && temp < array[j])
		{
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

void bubble(int array[], int size) {
	for (size_t i = size - 1; i > 0; i--)
	{
		for (size_t j = 0; j < i; j++)
		{
			if (array[j] > array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void selectionSort(int array[], int size) {
	for (int i = 0; i < size; i++) {
		int minIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (array[j] < array[minIndex]) {
				minIndex = j;
			}
		}
		if (i != minIndex) {
			int temp = array[i];
			array[i] = array[minIndex];
			array[minIndex] = temp;
		}
	}
}

void insertion(int array[], int size) {
	for (int i = 1; i < size; i++) {
		int temp = array[i];
		int j = i - 1;

		while (j > -1 && temp < array[j]) {
			array[j+1] = array[j];
			array[j] = temp;
			j--;
		}
	}
}

void print(const list<int>& players) {
	cout << "::::::::::::::::::  ALL PLAYERS  <----------- " << endl;
	for (list<int>::const_iterator it = players.begin(); it != players.end(); it++) {
		cout << "::: " << *it << endl;
	}
}

void arrangePlayers(int playerRate, list<int>& playerList) {
	for (list<int>::iterator it = playerList.begin(); it != playerList.end(); it++) {
		if (*it > playerRate) {
			playerList.insert(it, playerRate);
			return;
		}
	}
	playerList.push_back(playerRate);
}

void playerGrade(const list<int>& playerGrade) {
	list<int> players = {
		10,20,32,11,22,23,34,45,56,67,78,4,56,67,2,4,56,
	};
	list<int> pros;
	list<int>beginners;
	for (list<int>::const_iterator it = playerGrade.begin(); it != playerGrade.end(); it++) {
		if (*it <= 35) {
			arrangePlayers(*it, pros);
		}
		else
		{
			arrangePlayers(*it, beginners);
		}
	}
	print(pros);
	cout <<"\n";
	print(beginners);
}


int main()
{
	auto startTime = chrono::high_resolution_clock::now();
	cout << "\n\n";

	list<int> players = {
		10,20,32,11,22,23,34,45,56,67,78,4,56,67,2,4,56,
	};

	playerGrade(players);

	int arrayNumbers[] = { 10, 5, 2, 4, 7, 6, 9, 50, 10 };
	int size = sizeof(arrayNumbers) / sizeof(arrayNumbers[0]);
	insertion(arrayNumbers, size);
	for (auto& values : arrayNumbers) {
		cout << values << " ";
	}

	
	auto endTime = chrono::high_resolution_clock::now();
	chrono::duration<double> timeComplexity = endTime - startTime;
	cout << "\n\n::::::::::::: TIME COMPLEXITY :::::::::::::" << endl;
	cout << "::::: Run time: " << timeComplexity.count() << "ms" << endl;
}


