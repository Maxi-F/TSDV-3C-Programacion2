#pragma once
#include <concepts>
#include "Spawnable.h"
#include "Entity.h"

template<typename T>
concept IsSpawnableAndDrawable = std::derived_from<T, Spawnable>&& std::derived_from<T, Entity>;

template<IsSpawnableAndDrawable T>
class Spawner {
	public: 
		Spawnable();
		~Spawnable();


};
