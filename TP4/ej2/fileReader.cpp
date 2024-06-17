#include "fileReader.h"
#include <fstream>
#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

FileReader::FileReader(const char* filename) {
	this->filename = filename;
}

FileReader::~FileReader() {
}

void FileReader::read() {
	ifstream file;

	file.open(filename);

	if (file.is_open()) {
		char c;

		while (file.get(c)) {
			content += c;

			if (charactersQuantities[c]) {
				charactersQuantities[c]++;
			}
			else {
				charactersQuantities[c] = 1;
			}
		}
	}
	else {
		throw new exception("There was an error opening the file");
	}

	file.close();
}

void FileReader::showContent() {
	cout << content << endl << endl;

	cout << "Characters quantities:" << endl;
	cout << "Vowels: " << getVowelsQuantities() << endl;
	cout << "Consonants: " << getConsonantsQuantities() << endl;
	cout << "Words: " << getWordsQuantities() << endl;
	cout << "Characters: " << getCharactersQuantities() << endl;
	cout << "Puntuaction marks: " << getPuntuactionMarksQuantities() << endl;
	cout << endl;
}

int FileReader::getVowelsQuantities() {
	const int VOWELS_QUANTITY = 10;
	char vowels[] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

	int vowelsQuantities = 0;
	
	for (int i = 0; i < VOWELS_QUANTITY; i++) {
		vowelsQuantities += getQuantityOf(vowels[i]);
	}

	return vowelsQuantities;
}

int FileReader::getConsonantsQuantities() {
	const int CONSONANTS_QUANTITY = 42;
	char consonants[] = { 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z',
			'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z' };

	int consonantsQuantities = 0;

	for (int i = 0; i < CONSONANTS_QUANTITY; i++) {
		consonantsQuantities += getQuantityOf(consonants[i]);
	}

	return consonantsQuantities;
}

int FileReader::getWordsQuantities() {
	const int SEPARATORS_QUANTITY = 5;
	char words[] = { ' ', '\n', '\t', '\r', '\0' };

	int wordsQuantities = 0;

	for (int i = 0; i < SEPARATORS_QUANTITY; i++) {
		wordsQuantities += getQuantityOf(words[i]);
	}

	// sum 1 for last word
	return wordsQuantities + 1;
}

int FileReader::getCharactersQuantities() {
	const int CHARACTERS_QUANTITY = 256;

	int charactersQuantities = 0;

	for (int i = 0; i < CHARACTERS_QUANTITY; i++) {
		charactersQuantities += getQuantityOf(i);
	}

	return charactersQuantities - getQuantityOf('\n');
}

int FileReader::getPuntuactionMarksQuantities() {
	const int PUNTUATION_MARKS_QUANTITY = 32;
	char puntuactionMarks[] = { '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', ':', ';', '<', '=', '>', '?', '@', '[', '\\', ']', '^', '_', '`', '{', '|', '}', '~' };

	int puntuactionMarksQuantities = 0;

	for (int i = 0; i < PUNTUATION_MARKS_QUANTITY; i++) {
		puntuactionMarksQuantities += getQuantityOf(puntuactionMarks[i]);
	}

	return puntuactionMarksQuantities;
}

int FileReader::getQuantityOf(char character) {
	return charactersQuantities[character] ? charactersQuantities[character] : 0;
}
