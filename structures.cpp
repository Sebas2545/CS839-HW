#include <string>
#include <iostream>

struct Class {
	std::string name;
	int units;
	char grade;
};

struct Student {
	int ID;
	std::string name;
	int num; // number of classes taken
	double gpa;
	Class classes[20];
};

int get_info(Student[], int SIZE);
void display(const Student[], int size); // displays entire array of student info
void display(const Student[], int size, int index); // displays a particular student's info
void get_gpa(Student &);
void sort_id(Student[], int size); // all sort in ascending order
void sort_name(Student[], int size);
void sort_gpa(Student[], int size);
int search_id(Student[], int id, int size);
int search_name(Student[], std::string, int size);
int binSearch(const Student[], int value, int low, int high); // binary search (recursive)
int binSearch(const Student[], std::string value, int low, int high); // binary search (recursive)

int main() {
	const int SIZE = 100;

	Student students[SIZE];
	int realSize = get_info(students, SIZE); // fills array and returns the number students entered

	display(students, realSize); // displays in order entered

	sort_id(students, realSize);
	display(students, realSize);


	int id;
	std::cout << "Please enter the ID of the student you would like the information of: " << std::flush;
	std::cin >> id;

	int index = search_id(students, id, realSize);
	if(index == -1) // displays student info with given id
		std::cout << "Student not found" << std::endl;
	else
		display(students, index);

	sort_name(students, realSize);
	display(students, realSize);

	std::string name;
	std::cout << "Please enter the name of the student you would like the information of: " << std::flush;
	std::cin >> name;

	index = search_name(students, name, realSize);
	if(index == -1) // displays student info with given id
		std::cout << "Student not found" << std::endl;
	else
		display(students, index);

	sort_gpa(students, realSize);
	display(students, realSize);


	return 0;
}

int get_info(Student students[], int size) {
	int i = 0;

	std::cout << "Please enter the students ID (-99 to exit): " << std::flush;
	std::cin >> students[i].ID;
	std::cin.ignore(100, '\n');

	while(students[i].ID != -99 && i < size) {
		std::cout << "Please enter the students name: " << std::flush;
		std::getline(std::cin, students[i].name);

		std::cout << "Please enter the number of classes " << students[i].name << " is taking: " << std::flush;
		std::cin >> students[i].num;
		std::cin.ignore(100, '\n');

		for(int j = 0; j < students[i].num; j++) {
			std::cout << "Please enter the name of class " << j + 1 << ": " << std::flush;
			std::getline(std::cin,students[i].classes[j].name);

			std::cout << "Please enter the number of units for " << students[i].classes[j].name << ": " << std::flush;
			std::cin >> students[i].classes[j].units;

			std::cout << "Please enter the grade received in " << students[i].classes[j].name << ": " << std::flush;
			std::cin >> students[i].classes[j].grade;
			std::cin.ignore(100, '\n');
		}
		get_gpa(students[i]);
		i++;

		std::cout << "Please enter the students ID (-99 to exit): " << std::flush;
		std::cin >> students[i].ID;
		std::cin.ignore(100, '\n');
	}
	return i; //true size of the array
}

void display(const Student students[], int size) {
	std::cout << "List of students entered: " << std::endl;
	for(int i = 0; i < size; i++)
		display(students, size, i); // displays individual student
}

void display(const Student students[], int size, int idx) {
	if(idx < size) {
		std::cout << "Student: " << students[idx].ID << ' ' << students[idx].name << std::endl;

		for(int i = 0; i < students[idx].num; i++) {
			std::cout << students[idx].classes[i].name << ", " << students[idx].classes[i].units << " units, Grade " << students[idx].classes[i].grade << std::endl;
		}
		std::cout << "GPA: " << students[idx].gpa << std::endl;
	}
}

void get_gpa(Student &student) {
	double totalPoints = 0.0;
	double totalUnits = 0.0;

	for(int i = 0; i < student.num; i++) { // get total points based off of grade
		switch(student.classes[i].grade) { // because grade is stored as a char
		case 'a':
			totalPoints += 4 * student.classes[i].units;
			break;
		case 'A':
			totalPoints += 4 * student.classes[i].units;
			break;
		case 'b':
			totalPoints += 3 * student.classes[i].units;
			break;
		case 'B':
			totalPoints += 3 * student.classes[i].units;
			break;
		case 'c':
			totalPoints += 2 * student.classes[i].units;
			break;
		case 'C':
			totalPoints += 2 * student.classes[i].units;
			break;
		case 'd':
			totalPoints += 1 * student.classes[i].units;
			break;
		case 'D':
			totalPoints += 1 * student.classes[i].units;
			break;
		case 'f':
			totalPoints += 0 * student.classes[i].units;
			break;
		case 'F':
			totalPoints += 0 * student.classes[i].units;
			break;
		}
		totalUnits += student.classes[i].units;
	}

	student.gpa = (totalPoints / totalUnits);
}

void sort_id(Student students[], int size) {
	int temp, numLength;
	bool flag = true;
	int d = numLength = size;

	while(flag || (d > 1)) {
		flag = false;
		d = (d + 1) / 2;
		for(int i = 0; i < (numLength - d); i++) {
			if(students[i + d].ID < students[i].ID) {
				temp = students[i + d].ID;
				students[i + d].ID = students[i].ID;
				students[i].ID = temp;
				flag = true;
			}
		}
	}
}

void sort_name(Student students[], int size) {
	int numLength;
	std::string temp;
	bool flag = true;
	int d = numLength = size;

	while(flag || (d > 1)) {
		flag = false;
		d = (d + 1) / 2;
		for(int i = 0; i < (numLength - d); i++) {
			if(students[i + d].name < students[i].name) {
				temp = students[i + d].name;
				students[i + d].name = students[i].name;
				students[i].name = temp;
				flag = true;
			}
		}
	}
}

void sort_gpa(Student students[], int size) {
	int temp, numLength;
	bool flag = true;
	int d = numLength = size;

	while(flag || (d > 1)) {
		flag = false;
		d = (d + 1) / 2;
		for(int i = 0; i < (numLength - d); i++) {
			if(students[i + d].gpa < students[i].gpa) {
				temp = students[i + d].gpa;
				students[i + d].gpa = students[i].gpa;
				students[i].gpa = temp;
				flag = true;
			}
		}
	}
}

int search_id(Student students[], int id, int size) {
	sort_id(students, size); //sorts to allow binary search
	return binSearch(students, id, 0, size);
}

int search_name(Student students[], std::string name, int size) {
	sort_name(students, size);
	return binSearch(students, name, 0, size);
}

int binSearch(const Student students[], int value, int low, int high) {
	if(low <= high) {
		int mid = (low + high) / 2;

		if(value == students[mid].ID)
			return mid;
		else if(students[mid].ID > value)
			return binSearch(students, value, low, mid - 1);
		else
			return binSearch(students, value, mid + 1, high);
	}
	return -1;
}

int binSearch(const Student students[], std::string value, int low, int high) {
	if(low <= high) {
		int mid = (low + high) / 2;

		if(value == students[mid].name)
			return mid;
		else if(students[mid].name > value)
			return binSearch(students, value, low, mid - 1);
		else
			return binSearch(students, value, mid + 1, high);
	}
	return -1;
}
