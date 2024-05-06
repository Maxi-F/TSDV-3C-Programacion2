#pragma once
#include <string>

const int NAME_BUFFER_SIZE = 128;

class Drawing
{
private:
	char name[NAME_BUFFER_SIZE];
	std::string drawing;
	int width = 0;
	int height = 0;

	void drawPadding();
	void drawLine();

public:
	Drawing(const char* fileName);
	~Drawing();
	void draw();
};
