

#include <iostream>
#include <chrono>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
	string key;
	int value;
	Node* next;

	Node(string key, int value) {
		this->key = key;
		this->value = value;
		next = nullptr;
	}
};

class HashTable {
public:
	static const int SIZE = 7;
	Node* dataMap[SIZE];

	void printTable() {
		for (size_t i = 0; i < SIZE; i++)
		{
			cout << i << ": " << endl;
			if (dataMap[i]) {
				Node* temp = dataMap[i];
				while (temp != nullptr)
				{
					cout << "  {" << temp->key << ", " << temp->value << "}" << endl;
					temp = temp->next;
				}
			}
		}
	}

	int hash(string key) {
		int hash = 0;
		for (size_t i = 0; i < key.length(); i++)
		{
			int asciiValue = int(key[i]);
			hash = (hash + asciiValue * 23) % SIZE;
		}
		return hash;
	}

	void setNode(string key, int value) {
		int index = hash(key);
		Node* newNode = new Node(key, value);
		if (dataMap[index] == nullptr) {
			dataMap[index] = newNode;
		}
		else
		{
			Node* temp = dataMap[index];
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}

	int getValue(string key) {
		int index = hash(key);
		Node* temp = dataMap[index];
		while (temp != nullptr)
		{
			if (temp->key == key) {
				return temp->value;
			}
			temp = temp->next;
		}
		return INT_MIN;
	}

	vector<string> allKeys() {
		vector<string> allKeys;
		for (size_t i = 0; i < SIZE; i++)
		{
			Node* temp = dataMap[i];
			while (temp != nullptr)
			{
				allKeys.push_back(temp->key);
				temp = temp->next;
			}
		}
		return allKeys;
	}


};








int main()
{
	auto startTime = chrono::high_resolution_clock::now();
	HashTable* hashT = new HashTable();
	hashT->setNode("nail", 50);
	hashT->setNode("bolt", 40);
	hashT->setNode("read", 50);
	hashT->setNode("read", 80);
	hashT->setNode("read", 90);
	hashT->setNode("nail", 0);



	cout << "\n\n::::::::::::::: PRINTING HASH TABLE :::::::::::::::\n" << endl;
	hashT->printTable();

	cout << "::: Contains: " << hashT->getValue("bolt") << endl;
	cout << "::: Contains: " << (hashT->getValue("Gold") == INT_MIN ? "Not found" : "Found") << endl;

	vector<string> keys = hashT->allKeys();
	cout << "\n";
	for (string& key : keys) { cout << "key: " << key << endl; }
	


	auto endTime = chrono::high_resolution_clock::now();
	chrono::duration<double> timeComplexity = endTime - startTime;
	cout << "\n\n:::::::::::: TIME COMPLEXITY ::::::::::::" << endl;
	cout << "::: Run time: " << timeComplexity.count() << "ms" << endl;
	system("pause > 0");
}


