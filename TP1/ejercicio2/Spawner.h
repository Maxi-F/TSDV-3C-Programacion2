#pragma once
#include <concepts>
#include "Spawnable.h"
#include "Entity.h"

extern const int GREEN;
extern const int BLUE;
extern const int RED;

template<typename T>
concept IsSpawnableAndDrawable = std::is_base_of_v<Spawnable, T> && std::is_base_of_v<Entity, T>;

template<IsSpawnableAndDrawable T, int Quantity = 10>
class Spawner {
	public: 
		Spawner();
		~Spawner();

		void draw();
		void activate(int color);
		void deactivateRandom();

	private:
		int createdQuantity;
		T* spawnables[Quantity];

		T* getRandomSpawnable();
		T* getSpawnableFromColor(int color);
		int getRandomColor();
		COORD getRandomCoordinatesToSpawn();
};

#include "Spawner.tpp"
