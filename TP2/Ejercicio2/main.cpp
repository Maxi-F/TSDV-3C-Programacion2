#include "Vector3.h"
#include <iostream>

 void main() {
	Vector3 ints = { 1, 2, 3 };
	Vector3 other = { 4, 5, 6 };
	Vector3 sum = ints + other;

	std::cout << sum.x << sum.y << sum.z << std::endl;
}