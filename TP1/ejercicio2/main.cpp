#include <iostream>;
#include "Character.h";

const int GREEN = 10;
const int BLUE = 9;
const int RED = 12;

void main() {
	Character* character = new Character();

	character->setColor(BLUE);
	character->setPosition(10, 10);
	character->draw();

	delete character;
}