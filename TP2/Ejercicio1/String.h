#pragma once
#include <vector>
#include <iostream>

class String {
	public:
		std::vector<char> string;

		String(const char* string);
		~String();

		int length();
		char charAt(int index);

		String operator +(String other);
		String operator +(const char* other);
		void operator +=(String other);
		void operator +=(const char* other);
		int operator >(String other);
		int operator <(String other);
		String operator *(int times);
		
		friend std::ostream& operator << (std::ostream& stream, String string);

	private:
		const char* toString();
		void concatChar(String aString);
		void concatStrings(String aString, String otherString);
};
