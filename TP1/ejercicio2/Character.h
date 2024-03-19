#pragma once

#include "Spawnable.h"
#include "Entity.h"
#include "Windows.h"

class Character : Spawnable, Entity {
	private: 
		bool isSpawnableActive;
		int color;
		COORD coords;

	public:
		Character();
		~Character();

		void setColor(int newColor);
		void setActive(bool isActive) override;
		void setPosition(int x, int y) override;
		void draw() override;
};
