#include <iostream>;
#include <conio.h>;

#include "Character.h";
#include "Spawner.h";

const int spawner_size = 20;

void main() {
	Spawner<Character, spawner_size>* spawner = new Spawner<Character, spawner_size>();

	bool keepDoingActions = true;

	do {
		char action = _getch();

		switch (action) {
			case 'r':
				spawner->activate(RED);
				break;
			case 'g':
				spawner->activate(GREEN);
				break;
			case 'b':
				spawner->activate(BLUE);
				break;
			case 'd':
				spawner->deactivateRandom();
				break;
			case 'x':
				keepDoingActions = false;
				break;
			default:
				break;
		}

		spawner->draw();
	} while (keepDoingActions);
}