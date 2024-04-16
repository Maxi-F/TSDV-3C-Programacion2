#include "Vector3.h"
#include <iostream>
#include <string>

using namespace std;

char getTypeOption();
void useIntVectors();
void useFloatVectors();

 void main() {
	 char option = getTypeOption();

	 switch (option) {
		case '1':
			useIntVectors();
			break;
		case '2':
			useFloatVectors();
			break;
	 }
}

 char getTypeOption() {
	 cout << "Ingresá el tipo de vectores que se quiere manejar: " << endl;
	 cout << "1. Enteros" << endl;
	 cout << "2. Reales" << endl;

	 char option;
	 do {
		 cout << "opcion: ";
		 option = getchar();
	 } while (option != '1' && option != '2');

	 return option;
}

 void useIntVectors() {
	 Vector3<int> aVector, anotherVector;

	 cout << "Ingrese los valores del primer vector: " << endl;
	 cout << "X: ";
	 cin >> aVector.x;
	 cout << "Y: ";
	 cin >> aVector.y;
	 cout << "Z: ";
	 cin >> aVector.z;

	 cout << "Ingrese los valores del segundo vector: " << endl;
	 cout << "X: ";
	 cin >> anotherVector.x;
	 cout << "Y: ";
	 cin >> anotherVector.y;
	 cout << "Z: ";
	 cin >> anotherVector.z;

	 calculate(aVector, anotherVector);
}

void useFloatVectors() {
	Vector3<float> aVector, anotherVector;

	cout << "Ingrese los valores del primer vector: " << endl;
	cout << "X: ";
	cin >> aVector.x;
	cout << "Y: ";
	cin >> aVector.y;
	cout << "Z: ";
	cin >> aVector.z;


	cout << "Ingrese los valores del segundo vector: " << endl;
	cout << "X: ";
	cin >> anotherVector.x;
	cout << "Y: ";
	cin >> anotherVector.y;
	cout << "Z: ";
	cin >> anotherVector.z;

	calculate(aVector, anotherVector);
}