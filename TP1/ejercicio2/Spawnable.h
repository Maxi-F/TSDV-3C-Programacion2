#pragma once

class Spawnable {
	public:
		virtual bool isActive() = 0;
		virtual int getCreatedOrder() = 0;
		virtual int getColor() = 0;

		virtual void setColor(int color) = 0;
		virtual void setCreatedOrder(int order) = 0;
		virtual void setPosition(int x, int y) = 0;
		virtual void setActive(bool isActive) = 0;

		virtual bool isInPosition(int x, int y) = 0;
};
