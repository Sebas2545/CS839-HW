#include <iostream>

struct Date {
	int month;
	int day;
	int year;
};

struct Time {
	int hour;
	int minute;
};

struct Event {
	char desc[80];
	Date date;
	Time time;
};


int readEvents(Event *[], const int size);
void displayAll(Event *&array[], int size) const;
void display(Event* &arr[], int index) const;
void sortDesc(Event *arr[], int size);
void sortDate(Event *arr[], int size);
void swapPtrs(Event *&, Event *&);
int searchDesc(Event *[], int size, char []) const;
void searchDate(Event* [], int size, int month) const;
void binSearch(Event* arr[], int month, int size) const;

int main() {
	int SIZE = 50;

	Event *events[SIZE];

	readEvents(events, SIZE);
	displayAll(events, SIZE);

	sortDesc(events, SIZE);
	displayAll(events, SIZE);

	char str[80];
	std::cout << "Enter a search string: " << std::flush;
	std::cin >> str[80];
	display(events, searchDesc(events, SIZE, str));

	sortDate(events, SIZE);
	displayAll(events, SIZE);

	int month;
	std::cout << "Enter a month to display: " << std::flush;
	std::cin >> month;
	binSearch(events, month, SIZE);

	return 0;
}

int readEvents(Event *events[], const int size) {
	char ans;
	std::cout << "Create an event [Y/N]: " << std::flush;
	std::cin >> ans;
	std::cin.ignore(100, '\n');

	int i = 0;
	while(ans == 'y' || ans == 'Y') {
		events[i] = new Event;
		std::cout << "Enter Description: " << std::flush;
		std::cin.getline(events[i]->desc, 80);

		char dummy; // to eat slash chars
		std::cout << "Enter Date: " << std::flush;
		std::cin >> events[i]->date.month >> dummy >> events[i]->date.day >> dummy >> events[i]->date.year;
		std::cout << "Enter Time: " << std::flush;
		std::cin >> events[i]->time.hour >> dummy >> events[i]->time.minute;

		std::cout << "Create an event [Y/N]: " << std::flush;
		std::cin >> ans;
		std::cin.ignore(100, '\n');
	}

	return i + 1; // returns the number of items entered
}

void displayAll(Event *&arr[], int size) const {
	std::cout << "Events Entered: " << std::endl;
	for(int i = 0; i < size; i++)
		display(arr, i);
}

void display(Event* &arr[], int index) const {
	std::cout << arr[index]->desc << std::endl;
	std::cout << "Date: " << arr[index]->date.month << '/' << arr[index]->date.day << '/' << arr[index]->date.year << std::endl;
	std::cout << "Time: " << arr[index]->time.hour << ':' << arr[index]->time.minute << std::endl;
}

void sortDesc(Event *arr[], int size) {
	bool flag = true;
	int d = size;

	while(flag || d > 1) {
		flag = false;
		d = (d + 1) / 2;

		for(int i = 0; i < (size - d); i++) {
			if(arr[i + d]->desc > arr[i]->desc) {
				swapPtrs(arr[i + d], arr[i]);
				flag = true;
			}
		}
	}
}

void sortDate(Event *arr[], int size) {
	bool flag = true;
	int d = size;

	while(flag || d > 1) {
		flag = false;
		d = (d + 1) / 2;

		for(int i = 0; i < (size - d); i++) {
			if(arr[i + d]->date.year < arr[i]->desc) {
				swapPtrs(arr[i + d], arr[i]);
				flag = true;
			}
			else if(arr[i + d]->date.month < arr[i]->date.month) {
				swapPtrs(arr[i + d], arr[i]);
				flag = true;
			}
			else if(arr[i + d]->date.day < arr[i]->date.day) {
				swapPtrs(arr[i + d], arr[i]);
				flag = true;
			}
		}
	}
}

void swapPtrs(Event *&ptr1, Event *&ptr2) {
	Event *temp;

	temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
}

int searchDesc(Event *arr[], int size, char str[]) const {
	int i = 0;
	while(!strstr(arr[i]->desc, str)) // while str is not in desc, keeping going
		i++;

	return i;
}

void searchDate(Event *arr[], int size, int month) const{
	for(int i = 0; i < size; i++)
		if(arr[i]->date.month == month)
			display(arr, i);
}

void binSearch(Event* arr[], int month, int size) const {
	int mid;
	int low = 0;
	int high = size - 1;
	int index;

		while (low <= high)
		{
			mid = (low + high) / 2;
			if (arr[mid]->date.month >= month)
				high = mid -1;
			else if (arr[mid]->date.month < month)
				low = mid + 1;
			else
				index = mid + 1;
		}
	if(arr[mid]->date.month == month)
		while(arr[mid]->date.month == month) {
			display(arr, mid);
			mid++;
		}
	else if(arr[index]->date.month == month)
		while(arr[index]->date.month == month) {
			display(arr, index);
			index++;
		}
	else
		std::cout << "Date not found." << std::endl;
}
