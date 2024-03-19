#include "Character.h"
#include <iostream>

Character::Character() {};
Character::~Character() {};

void Character::setActive(bool isActive) {
	isSpawnableActive = isActive;
}

void Character::setPosition(int x, int y) {
	coords.X = x;
	coords.Y = y;
}

void Character::draw() {
	HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(outputHandle, coords);
	SetConsoleTextAttribute(outputHandle, static_cast<WORD>(color));

	std::cout << " O";
	COORD armsCoords;
	armsCoords.X = coords.X;
	armsCoords.Y = coords.Y + 1;
	SetConsoleCursorPosition(outputHandle, armsCoords);
	std::cout << "/|\\";

	COORD legsCoords;
	legsCoords.X = coords.X;
	legsCoords.Y = coords.Y + 2;
	SetConsoleCursorPosition(outputHandle, legsCoords);
	std::cout << "/ \\";
}

void Character::setColor(int newColor) {
	color = newColor;
}
