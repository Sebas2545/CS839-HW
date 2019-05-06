#include <iostream>
using namespace std;

void displayMenu(); // displays menu of choices
void searchString(char[], char, int&, int&); // searches a string for a specific character
void changeString(char[], char, int); // changes the nth character in a string
void displayStart(char[], int); // displays the first number of characters in a string
void displayEnd(char[], int); // displays the last number of characters in a string
void displayPart(char[], int start, int end); // displays the characters within a range of the string
void nullString(char[]);


int main(){
	const int SIZE = 100;
	int choice;

	do {
		char str[SIZE];
		cout << "Please enter a string: " << endl;
		cin.getline(str, '\n'); // gets entire string, including whitespace

		displayMenu();
		cin >> choice;

		switch(choice) {
			case 1: { // search for a character
				char chr;
				int count;
				int index;
				cout << "Please enter a character: " << flush;
				cin >> chr;
				cin.ignore(100, '\n');
				searchString(str, chr, index, count);
				cout << "There are " << count << ' ' << chr << "'s in \"" << str << "\" with the 1st one at index " << index << '.' << endl;
				break;
			}
			case 2: { // change a character
				char chr;
				int index;
				cout << "Please enter the character you wish to change: " << flush;
				cin >> chr;
				cin.ignore(100, '\n');
				cout << "Please enter the index of the character you want to change: " << flush;
				cin >> index;
				cin.ignore(100, '\n');
				changeString(str, chr, index);
				cout << "The new string is: " << str << endl;
				break;
			}
			case 3: { // display the start of a string
				int index;
				cout << "Please enter how many characters from the beginning of the string you want to display: " << flush;
				cin >> index;
				cin.ignore(100, '\n');
				displayStart(str, index);
				cout << str << endl;
				break;
			}
			case 4: { // display the end of a string
				int index;
				cout << "Please enter how many characters from the end of the string you want to display: " << flush;
				cin >> index;
				cin.ignore(100, '\n');
				displayEnd(str, index);
				cout << str << endl;
				break;
			}
			case 5: { // display a portion of a string
				int start;
				int end;
				cout << "Please enter the start of the index: " << flush;
				cin >> start;
				cin.ignore(100, '\n');
				cout << "Please enter the end of the index: " << flush;
				cin >> end;
				cin.ignore(100, '\n');
				displayPart(str, start, end);
				cout << str << endl;
				break;
			}
			case 6: { // null a string
				nullString(str);
				cout << "The string is now Null." << endl;
				break;
			}
			case 7: // exit
				cout << "Exiting..." << endl;
				break;
		}

		cin.ignore(100, '\n');
	}while(choice != 7);

	return 0;
}

void displayMenu() {
	cout << "Make a selection: " << endl;
	cout << "1. Search for a character in the string " << endl;
	cout << "2. Change a character within the string " << endl;
	cout << "3. Display the first n characters of the string " << endl;
	cout << "4. Display the last n characters of the string " << endl;
	cout << "5. Display all characters that lie between two given indices " << endl;
	cout << "6. Null the string " << endl;
	cout << "7. Exit " << endl;

	return;
}

void searchString(char str[], char chr, int& index, int& count) {
	index = -1;
	count = 0;

	for(int i = 0; i < strlen(str); i++){
		if(str[i] == chr) {
			index = i;
			count++;
		}
	}

	return;
}

void changeString(char str[], char chr, int a) {
	str[a] = chr;

	return;
}

void displayStart(char str[], int end) {
	for(int i = 0; i < end;i++)
		cout << str[i] << flush;

	return;
}

void displayEnd(char str[], int start) {
	for(int i = strlen(str); start < i;start++)
		cout << str[start] << flush;

	return;
}

void displayPart(char str[], int start, int end) {
	for(; start < end;start++)
		cout << str[start] << flush;

	return;
}

void nullString(char str[]) {
	str[0] = '\0';

	return;
}
