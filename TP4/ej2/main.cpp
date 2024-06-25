#include "fileReader.h"
#include <time.h>
#include <iostream>
#include <future>
#include <vector>
#include <conio.h>

using namespace std;

const int MAX_FILES = 3;
const int MIN_MILLI_SECONDS = 1000;
const int MAX_MILLI_SECONDS = 8000;

vector<future<void>> readFutures;
mutex readMutex;

void readFile(string fileName, vector<FileReader*> *fileReaders, int delay, int index);
bool allFilesReaded();
int getRandomSecondsToSleep();
void showAverages(vector<FileReader*> fileReaders);

void main() {
	srand(time(NULL));
	
	vector<FileReader*> fileReaders;

	string files[MAX_FILES] = {"assets/text_1.txt", "assets/text_2.txt", "assets/text_3.txt" };
	fileReaders.resize(MAX_FILES);

	for (int i = 0; i < MAX_FILES; i++) {
		fileReaders[i] = nullptr;
		readFutures.push_back(async(launch::async, readFile, files[i], &fileReaders, getRandomSecondsToSleep(), i));
	}

	bool isRunning = true;

	while (isRunning) {
		system("cls");
		
		cout << "Reading files..." << endl << endl;

		if (_kbhit() && _getch() == 27 || allFilesReaded())
			isRunning = false;

		for (int i = 0; i < fileReaders.size(); i++) {
			if (fileReaders[i] != nullptr) {
				cout << "Content of file " << i + 1 << ":" << endl;
				fileReaders[i]->showContent();
			}
		}

		this_thread::sleep_for(chrono::milliseconds(500));
	}

	showAverages(fileReaders);

	for (int i = 0; i < fileReaders.size(); i++) {
		delete fileReaders[i];
	}
}

void showAverages(vector<FileReader*> fileReaders) {
	cout << "Averages:" << endl;

	float vowels = 0;
	float consonants = 0;
	float words = 0;
	float characters = 0;
	float puntuactionMarks = 0;
	float fileReadersSize = static_cast<float>(fileReaders.size());

	for (int i = 0; i < fileReaders.size(); i++) {
		if (fileReaders[i] != nullptr) {
			vowels += fileReaders[i]->getVowelsQuantities();
			consonants += fileReaders[i]->getConsonantsQuantities();
			words += fileReaders[i]->getWordsQuantities();
			characters += fileReaders[i]->getCharactersQuantities();
			puntuactionMarks += fileReaders[i]->getPuntuactionMarksQuantities();
		}
	}

	cout << "Vowels: " << vowels / fileReadersSize << endl;
	cout << "Consonants: " << consonants / fileReadersSize << endl;
	cout << "Words: " << words / fileReadersSize << endl;
	cout << "Characters: " << characters / fileReadersSize << endl;
	cout << "Puntuaction marks: " << puntuactionMarks / fileReadersSize << endl;

	cout << endl;
}

bool allFilesReaded() {
	for (int i = 0; i < MAX_FILES; i++) {
		if (readFutures[i].wait_for(chrono::seconds(0)) != future_status::ready) {
			return false;
		}
	}

	return true;
}

void readFile(string fileName, vector<FileReader*> *fileReaders, int delay, int index) {
	FileReader *fileReader = new FileReader(fileName.c_str());

	this_thread::sleep_for(chrono::milliseconds(delay));
	fileReader->read();

	lock_guard<mutex> lock(readMutex);

	(*fileReaders)[index] = fileReader;
}

int getRandomSecondsToSleep() {
	return rand() % MAX_MILLI_SECONDS + MIN_MILLI_SECONDS;
}
