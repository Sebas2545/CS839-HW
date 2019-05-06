#include <iostream>
using namespace std;

int maxDivs(int low, int high, int& num, int& divs);
int numDivs(int);

int main() {
	int rngLow, rngHigh, num, divs;

	cout << "Please enter the range." << endl;
	cout << "Lowest Value: " << flush;
	cin >> rngLow;
	cout << "Highest Value: " << flush;
	cin >> rngHigh;

	num = maxDivs(rngLow, rngHigh, num, divs);
	divs = numDivs(num);

	cout << "The number with the highest number of divisors between " << rngLow << " and " << rngHigh << " is: " << num << endl;
	cout << num << " has " << divs << " divisors." << endl;

	system("pause");
	return 0;
}

int maxDivs(int low, int high, int& num, int& divs) { // finds number with highest # of divisors in range
	num = low; // sets initial highest number of divisors to the first number in range
	divs = numDivs(low);

	for(int a = low + 1; a <= high; a++) { // checks all numbers after the first in range
		if(divs < numDivs(a)) { // if a number has a greater number of divisors, it replaces the original number
			divs = numDivs(a);
			num = a;
		}
	}
	return num;
}

int numDivs(int num) { // determines the number of divisors a number has
	int divs = 0;

	for (int b = 2; b < num; b++) { // skips 1 and the number itself as divisors
		if ((num % b == 0)) { // checks if num is divided evenly
			divs++;
		}
	}
	return divs;
}
