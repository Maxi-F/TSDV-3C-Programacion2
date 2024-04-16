#pragma once
#include <concepts>
#include <string>

template<typename T>
concept Arithmetic = (std::is_integral_v<T> || std::is_floating_point_v<T>) && !std::same_as<T, bool> && !std::same_as<T, char>;

template<Arithmetic T>
struct Vector3 {
	T x;
	T y;
	T z;

	Vector3<T> operator +(Vector3<T> other);
	Vector3<T> operator -(Vector3<T> other);
	void operator +=(Vector3<T> other);
	void operator -=(Vector3<T> other);

	Vector3 operator *(T scalar);
	Vector3 operator /(T scalar);
	void operator *=(T scalar);
	void operator /=(T scalar);
	
	bool operator ==(Vector3<T> other);
	bool operator !=(Vector3<T> other);

	T operator *(Vector3<T> other);
	Vector3<T> operator ^(Vector3<T> other);

	std::string toString();
};

template <Arithmetic T>
extern void calculate(Vector3<T> aVector, Vector3<T> anotherVector);

#include "Vector3.tpp";
