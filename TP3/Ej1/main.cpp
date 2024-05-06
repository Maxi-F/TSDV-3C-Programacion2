#include "Drawing.h"
#include <fstream>
#include <conio.h>
#include <iostream>

using namespace std;

const int DRAWINGS_LENGTH = 10;

void main() {
	bool shouldClose = false;

	Drawing drawings[DRAWINGS_LENGTH] = {
		Drawing("assets/cat.txt"),
		Drawing("assets/bat.txt"),
		Drawing("assets/elephant.txt"),
		Drawing("assets/spider.txt"),
		Drawing("assets/fish.txt"),
		Drawing("assets/beaver.txt"),
		Drawing("assets/cow.txt"),
		Drawing("assets/dolphin.txt"),
		Drawing("assets/dog.txt"),
		Drawing("assets/frog.txt")
	};

	int index = 0;

	while (!shouldClose) {
		drawings[index].draw();

		int c = _getch();

		if (c == 27) { // escape
			shouldClose = true;
		}

		system("cls");
		index = (index + 1) % DRAWINGS_LENGTH;
	}
}
