#pragma once

#include "Spawnable.h"
#include "Entity.h"
#include "Windows.h"

class Character : Spawnable, Entity {
	private: 
		bool isSpawnableActive;
		int color;
		int createdOrder;
		COORD coords;

	public:
		Character();
		~Character();

		int getColor() override;
		bool isActive() override;
		int getCreatedOrder() override;

		void setCreatedOrder(int createdOrder) override;
		void setColor(int newColor) override;
		bool isInPosition(int x, int y) override;
		void setActive(bool isActive) override;
		void setPosition(int x, int y) override;
		void draw() override;
};
