#include "Character.h"
#include <iostream>

Character::Character() {};
Character::~Character() {};

void Character::setActive(bool isActive) {
	isSpawnableActive = isActive;
}

void Character::setCreatedOrder(int createdQuantity) {
	createdOrder = createdQuantity;
}

int Character::getCreatedOrder() {
	return createdOrder;
}

void Character::setPosition(int x, int y) {
	coords.X = x;
	coords.Y = y;
}

void Character::draw() {
	if (!isSpawnableActive) return;

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

int Character::getColor() {
	return color;
}

bool Character::isActive() {
	return isSpawnableActive;
}

bool Character::isInPosition(int x, int y) {
	int CHARACTER_MARGIN = 2;

	bool isInXPosition = coords.X - CHARACTER_MARGIN <= x && coords.X + CHARACTER_MARGIN >= x;
	bool isInYPosition = coords.Y - CHARACTER_MARGIN <= y && coords.Y + CHARACTER_MARGIN >= y;

	return isInXPosition && isInYPosition;
}
