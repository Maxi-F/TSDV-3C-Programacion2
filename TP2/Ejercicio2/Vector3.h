#pragma once
#include <concepts>

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

	Vector3 operator *(Vector3<T> other);
	Vector3 operator /(Vector3<T> other);
	void operator *=(Vector3<T> other);
	void operator /=(Vector3<T> other);
	
	bool operator ==(Vector3<T> other);
	bool operator !=(Vector3<T> other);

	T operator *(Vector3<T> other);
	Vector3<T> operator ^(Vector3<T> other);
};

#include "Vector3.tpp";
