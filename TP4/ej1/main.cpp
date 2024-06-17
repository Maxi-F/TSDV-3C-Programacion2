#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

void readIntsFromFile(vector<int>& ints, string filename);
void showObtainedNumbers(vector<int>& ints, string title);
void saveInFile(vector<int>& ints, string filename);
void showBeforeResponseNumbers();

void main() {
	vector<int> intsFromFiles;

	cout << "Reading files..." << endl;

	readIntsFromFile(intsFromFiles, "assets/numbers_1.dat");
	readIntsFromFile(intsFromFiles, "assets/numbers_2.dat");

	showObtainedNumbers(intsFromFiles, "Obtained numbers");

	try {
		showBeforeResponseNumbers();
	}
	catch (exception e) {
		cout << "No response numbers found" << endl << endl;
	}

	sort(intsFromFiles.begin(), intsFromFiles.end(), [](int a, int b) { return a > b; });
	vector<int>::iterator newUniqueEnd = unique(intsFromFiles.begin(), intsFromFiles.end());
	intsFromFiles.erase(newUniqueEnd, intsFromFiles.end());

	showObtainedNumbers(intsFromFiles, "Sorted and unique numbers");

	saveInFile(intsFromFiles, "assets/numbers_response.dat");

	return;
}

void showBeforeResponseNumbers() {
	vector<int> savedResponseNumbers;

	readIntsFromFile(savedResponseNumbers, "assets/numbers_response.dat");
	showObtainedNumbers(savedResponseNumbers, "Before response numbers");
}

void saveInFile(vector<int>& ints, string filename) {
	ofstream file;

	file.open(filename);

	if (file.is_open()) {
		int numbersQuantity = ints.size();
		file.write((char*)&numbersQuantity, sizeof(int));

		for (int i = 0; i < numbersQuantity; i++) {
			file.write((char*)&ints[i], sizeof(int));
		}

		file.close();
	}
	else {
		throw exception("Error opening file to write");
	}
}	

void showObtainedNumbers(vector<int>& ints, string title) {
	cout << title.c_str() << ": (";

	// iterate using iterator
	for (vector<int>::iterator it = ints.begin(); it != ints.end(); it++) {
		cout << *it;
		if (it != ints.end() - 1) {
			cout << ", ";
		}
	}
	cout << ")" << endl << endl;
}

void readIntsFromFile(vector<int>& ints, string filename) {
	cout << "Reading file: " << filename << endl;

	ifstream file;
	int previousSize = ints.size();

	file.open(filename);

	if (file.is_open()) {
		int numbersQuantity;
		file.read((char*)&numbersQuantity, sizeof(int));

		ints.resize(previousSize + numbersQuantity);

		for (int i = 0; i < numbersQuantity; i++) {
			file.read((char*)&ints[previousSize + i], sizeof(int));
		}

		file.close();
	}
	else {
		throw exception("Error opening file to read");
	}

	cout << "File readed: " << ints.size() << " numbers" << endl;
}
