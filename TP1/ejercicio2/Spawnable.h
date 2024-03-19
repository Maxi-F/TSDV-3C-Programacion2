#pragma once

class Spawnable {
	public:
		virtual void setPosition(int x, int y) = 0;
		virtual void setActive(bool isActive) = 0;
};
