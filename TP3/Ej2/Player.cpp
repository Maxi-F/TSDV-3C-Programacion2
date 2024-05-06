#include "Player.h"
#include <fstream>

using namespace std;

char* PlayerException::what() {
		return message;
}

PlayerException::PlayerException(const char* message) {
	int i;
	for (i = 0; i < MAX_EXCEPTION_MESSAGE_LENGTH && message[i] != '\0'; i++) {
		this->message[i] = message[i];
	}
	this->message[i + 1] = '\0';
}

Player::Player(const char* name, int age, int mana, int life, int attack) {
	int i;
	for (i = 0; i < MAX_NAME_LENGTH - 1 || name[i] == '\0'; i++) {
		this->name[i] = name[i];
	}
	this->name[i + 1] = '\0';
	this->age = age;
	this->mana = mana;
	this->life = life;
	this->attack = attack;
}

Player::~Player() {
}

Player::Player(const char* fileName) {
	ifstream file;
	file.open(fileName, ios::in | ios::binary);

	if (file.is_open()) {
		file.read((char*)this, sizeof(Player));
	}
	else {
		throw PlayerException("Error al abrir el archivo");
	}

	file.close();
}

void Player::savePlayer(const char* fileName) {
	ofstream file;
	file.open(fileName, ios::out | ios::binary);

	if (file.is_open()) {
		file.write((char*)this, sizeof(Player));
	}
	else {
		throw PlayerException("Error al abrir el archivo");
	}

	file.close();
}
