

#include <iostream>
#include <chrono>

using namespace std;

void functionThree() {
	cout << ":::: This is function three." << endl;
}

void functionTwo() {
	functionThree();
	cout << ":::: This is function two." << endl;
}

void functionOne() {
	functionTwo();
	cout << ":::: This is function one." << endl;
}








int main()
{
	auto startTime = chrono::high_resolution_clock::now();
	cout << "\n\n";
	functionOne();

	auto endTime = chrono::high_resolution_clock::now();
	chrono::duration<double> timeComlexity = endTime - startTime;
	cout << "\n\n::::::::::::::: Time Complexity :::::::::::::::" << endl;
	cout << "::: Run time:" << timeComlexity.count() << "ms" << endl;
}

