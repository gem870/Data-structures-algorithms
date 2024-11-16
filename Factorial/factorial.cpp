

#include <iostream>
#include <chrono>

using namespace std;



int factorial(int number) {
	if (number == 1) return 1;
	return number * factorial(number - 1);
}






int main()
{
	auto startTime = chrono::high_resolution_clock::now();
	cout << "\n\n";
	cout << factorial(10) << endl;


	auto endTime = chrono::high_resolution_clock::now();
	chrono::duration<double> timeComlexity = endTime - startTime;
	cout << "\n\n::::::::::::::: Time Complexity :::::::::::::::" << endl;
	cout << "::: Run time:" << timeComlexity.count() << "ms" << endl;
}

