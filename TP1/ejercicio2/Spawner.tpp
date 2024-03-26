#include "Spawner.h"
#include "Character.h"
#include <vector>
#include <exception>
#include <stdexcept>

extern const int GREEN = 10;
extern const int BLUE = 9;
extern const int RED = 12;

static int getRandomNumber(int from, int to) {
	return from + (rand() % to);
}

template<IsSpawnableAndDrawable T, int Quantity>
int Spawner<T, Quantity>::getRandomColor() {
	int number = getRandomNumber(1, 3);

	switch (number) {
		case 1:
			return GREEN;
		case 2:
			return BLUE;
		case 3:
			return RED;
	}
}

template<IsSpawnableAndDrawable T, int Quantity>
T* Spawner<T, Quantity>::getRandomSpawnable() {
	T* spawnedEntities[Quantity];

	int spawnedQuantity = 0;

	for (int i = 0; i < Quantity; i++) {
		if (spawnables[i]->isActive()) {
			spawnedEntities[spawnedQuantity] = spawnables[i];
			spawnedQuantity++;
		};
	}

	if (spawnedQuantity == 0) {
		throw std::logic_error("No Entities spawned");
	}

	int index = spawnedQuantity == 1 ? 0 : getRandomNumber(0, spawnedQuantity - 1);

	return spawnedEntities[index];
}

template<IsSpawnableAndDrawable T, int Quantity>
T* Spawner<T, Quantity>::getSpawnableFromColor(int color) {
	for (int i = 0; i < Quantity; i++) {
		if (!spawnables[i]->isActive()) {
			return spawnables[i];
		}
	}
	
	T* leastOrderSpawnable = nullptr;

	for (int i = 0; i < Quantity; i++) {
		if (leastOrderSpawnable == nullptr || leastOrderSpawnable->getCreatedOrder() > spawnables[i]->getCreatedOrder()) {
			leastOrderSpawnable = spawnables[i];
		}
	}

	return leastOrderSpawnable;
}

template<IsSpawnableAndDrawable T, int Quantity>
COORD Spawner<T, Quantity>::getRandomCoordinatesToSpawn() {
	int HEIGHT = 25;
	int WIDTH = 25;
	int MARGIN = 3;

	int xPosition = getRandomNumber(MARGIN, WIDTH);
	int yPosition = getRandomNumber(MARGIN, HEIGHT);

	for (int i = 0; i < Quantity; i++) {
		if (spawnables[i]->isInPosition(xPosition, yPosition)) {
			return getRandomCoordinatesToSpawn();
		}
	}

	return { static_cast<short>(xPosition), static_cast<short>(yPosition) };
}

template<IsSpawnableAndDrawable T, int Quantity>
Spawner<T, Quantity>::Spawner() {
	createdQuantity = 0;

	for (int i = 0; i < Quantity; i++) {
		spawnables[i] = new Character();

		spawnables[i]->setPosition(0, 0);
		spawnables[i]->setActive(false);
	}
}

template<IsSpawnableAndDrawable T, int Quantity>
Spawner<T, Quantity>::~Spawner() {
	delete[] spawnables;
}

template<IsSpawnableAndDrawable T, int Quantity>
void Spawner<T, Quantity>::draw() {
	system("cls");

	for (int i = 0; i < Quantity; i++) {
		spawnables[i]->draw();
	}
}

template<IsSpawnableAndDrawable T, int Quantity>
void Spawner<T, Quantity>::activate(int color) {
	T* spawnable = getSpawnableFromColor(color);
	spawnable->setActive(true);

	spawnable->setColor(color);

	spawnable->setCreatedOrder(createdQuantity);
	createdQuantity++;

	COORD coords = getRandomCoordinatesToSpawn();
	spawnable->setPosition(coords.X, coords.Y);
}

template<IsSpawnableAndDrawable T, int Quantity>
void Spawner<T, Quantity>::deactivateRandom() {
	try {
		T* spawnable = getRandomSpawnable();
 		spawnable->setActive(false);
	}
	catch (std::logic_error error) {
		return;
	}

	
}
