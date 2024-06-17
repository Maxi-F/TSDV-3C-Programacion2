#include <iostream>
#include <fstream>
#include "Drawing.h"

using namespace std;

const int ASCII_LINE_BUFFER_SIZE = 1024;
const int WIDTH_PADDING = 4;
const int HEIGHT_PADDING = 4;

Drawing::Drawing(const char* fileName)
{
	ifstream inputStream = ifstream();
	inputStream.open(fileName);

	if (inputStream.is_open()) {
		inputStream.getline(this->name, NAME_BUFFER_SIZE);
		while (!inputStream.eof()) {
			char aux[ASCII_LINE_BUFFER_SIZE];

			inputStream.getline(aux, ASCII_LINE_BUFFER_SIZE);


			if (strlen(aux) > width) {
				this->width = strlen(aux);
			}

			this->height++;
			this->drawing += aux;
			this->drawing += '\n';
		}

		inputStream.close();
	}
	else {
		throw exception("Error opening file");
	}
}

Drawing::~Drawing()
{
}

void Drawing::draw()
{
	drawLine();

	drawPadding();

	string aux;
	for (int i = 0; i < drawing.size(); i++) {
		if (drawing[i] != '\n') {
			aux += drawing[i];
		}
		else {
			cout << "||";

			for (int j = 0; j < WIDTH_PADDING; j++) {
				cout << " ";
			}
			cout << aux;

			for (int j = 0; j < width + WIDTH_PADDING - aux.size(); j++) {
				cout << " ";
			}

			cout << "||" << endl;
			aux = "";
		}
	}
	
	drawPadding();

	cout << "||";
	cout << " Name: " << name;

	for (int i = 0; i < width + WIDTH_PADDING * 2 - strlen(" Name: ") - strlen(name); i++) {
		cout << " ";
	}

	cout << "||" << endl;

	drawLine();
}

void Drawing::drawLine() {
	cout << "||";

	for (int i = 0; i < width + WIDTH_PADDING * 2; i++) {
		cout << "=";
	}

	cout << "||";
	cout << endl;
}

void Drawing::drawPadding() {
	for (int i = 0; i < HEIGHT_PADDING; i++) {
		cout << "||";

		for (int j = 0; j < width + WIDTH_PADDING * 2; j++) {
			cout << " ";
		}

		cout << "||" << endl;
	}
}
