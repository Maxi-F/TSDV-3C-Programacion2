#include "Vector3.h"
#include <iostream>
#include <string>

template<Arithmetic T>
Vector3<T> Vector3<T>::operator +(Vector3<T> other)
{
    return { x + other.x, y + other.y, z + other.z };
}

template<Arithmetic T>
Vector3<T> Vector3<T>::operator -(Vector3<T> other)
{
	return { x - other.x, y - y, z - other.z };
}


template<Arithmetic T>
void Vector3<T>::operator +=(Vector3<T> other)
{
	x += other.x;
	y += other.y;
	z += other.z;
}

template<Arithmetic T>
void Vector3<T>::operator -=(Vector3<T> other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
}

template<Arithmetic T>
Vector3<T> Vector3<T>::operator *(T scalar)
{
	return { x * scalar, y * scalar, z * scalar };
}

template<Arithmetic T>
Vector3<T> Vector3<T>::operator /(T scalar)
{
	if (scalar == 0) {
		throw("Scalar should not be zero.");
	}

	return { x / scalar, y / scalar, z * scalar };
}

template<Arithmetic T>
void Vector3<T>::operator *=(T scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
}

template<Arithmetic T>
void Vector3<T>::operator /=(T scalar)
{
	if (scalar == 0) {
		throw("Scalar should not be zero.");
	}

	x /= scalar;
	y /= scalar;
	z /= scalar;
}

template<Arithmetic T>
bool Vector3<T>::operator ==(Vector3<T> other)
{
	return x == other.x && y == other.y && z == other.z;
}

template<Arithmetic T>
bool Vector3<T>::operator !=(Vector3<T> other)
{
	return !(this == other);
}

template<Arithmetic T>
T Vector3<T>::operator *(Vector3<T> other)
{
	return x * other.x + y * other.y + z * other.z;
}

template<Arithmetic T>
Vector3<T> Vector3<T>::operator ^(Vector3<T> other)
{
	Vector3 result = {
		y * other.z - z * other.y,
		z * other.x - x * other.z,
		x * other.y - y * other.x
	};
	return result;
}

template<Arithmetic T>
std::string Vector3<T>::toString() {
	std::string xPart = "{ X=";
	std::string yPart = ", Y=";
	std::string zPart = ", Z=";
	std::string end = " }";
	std::string xString = std::to_string(x);
	std::string yString = std::to_string(y);
	std::string zString = std::to_string(z);

	return (xPart + xString + yPart + yString + zPart + zString + end);
}

template <Arithmetic T>
extern void calculate(Vector3<T> aVector, Vector3<T> anotherVector) {
	float scalar = 5.0f;

	std::cout << "Suma de vectores: " << std::endl;

	std::cout << aVector.toString().c_str() << " + " << anotherVector.toString().c_str() << " = " << (aVector + anotherVector).toString().c_str() << std::endl << std::endl;

	std::cout << "Resta de vectores: " << std::endl;
	std::cout << aVector.toString().c_str() << " - " << anotherVector.toString().c_str() << " = " << (aVector - anotherVector).toString().c_str() << std::endl << std::endl;

	std::cout << "Multiplicar por " << scalar << ":" << std::endl;
	std::cout << aVector.toString() << " * " << scalar << " = " << (aVector * scalar).toString().c_str() << std::endl << std::endl;

	std::cout << "Producto punto: " << std::endl;
	std::cout << aVector.toString().c_str() << " . " << anotherVector.toString().c_str() << " = " << aVector * anotherVector << std::endl << std::endl;

	std::cout << "Producto cruz: " << std::endl;
	std::cout << aVector.toString().c_str() << " X " << anotherVector.toString().c_str() << " = " << (aVector ^ anotherVector).toString().c_str() << std::endl << std::endl;
};
