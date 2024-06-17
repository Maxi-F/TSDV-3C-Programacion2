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

	for (int i = 0; i < fileReaders.size(); i++) {
		delete fileReaders[i];
	}
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
