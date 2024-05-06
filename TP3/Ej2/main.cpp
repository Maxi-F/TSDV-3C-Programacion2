#include "Player.h"
#include <iostream>
#include <conio.h>

using namespace std;

void main() {
	cout << "Ingresa 1 si queres crear un nuevo jugador, o 2 si queres cargar uno existente: ";

	char option;
	do {
		cin.get(option);
	} while(option != '1' && option != '2');

	if (option == '1') {
		cout << "Ingresa el nombre del jugador: ";
		string name;
		cin >> name;

		cout << "Ingresa la edad del jugador: ";
		int age;
		cin >> age;

		cout << "Ingresa la cantidad de maná del jugador: ";
		int mana;
		cin >> mana;

		cout << "Ingresa la cantidad de vida del jugador: ";
		int life;
		cin >> life;

		cout << "Ingresa la cantidad de ataque del jugador: ";
		int attack;
		cin >> attack;
		cout << endl;

		Player player(name.c_str(), age, mana, life, attack);

		cout << "Ingresa el nombre del archivo: ";
		string fileName;
		cin >> fileName;
		fileName += ".dat";

		try {
			player.savePlayer(fileName.c_str());
		}
		catch (PlayerException e) {
			cout << e.what() << endl;
		}

	}
	else {
		cout << "Ingresa el nombre del archivo: ";
		string fileName;
		cin >> fileName;

		try {
			Player player = Player(fileName.c_str());

			cout << "Nombre: " << player.name << endl;
			cout << "Edad: " << player.age << endl;
			cout << "Mana: " << player.mana << endl;
			cout << "Vida: " << player.life << endl;
			cout << "Ataque: " << player.attack << endl;
		}
		catch (PlayerException e) {
			cout << e.what() << endl;
		}
	}
}