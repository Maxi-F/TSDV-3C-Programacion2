#include "String.h";

String::String(const char* stringToSave) 
{
	this->string = {};
	int i = 0;

	while (*(stringToSave + i) != '\0') {
		this->string.push_back(*(stringToSave + i));
		i++;
	}
	if(!this->string.empty()) this->string.push_back('\0');
}

String::~String() 
{
}

int String::length() {
	return this->string.size();
}

char String::charAt(int index) {
	return this->string.at(index);
}



void String::concatChar(String aString) {
	for (int i = 0; i < aString.length() - 1; i++) {
		this->string.push_back(aString.charAt(i));
	}
}

void String::concatStrings(String aString, String otherString) {
	this->concatChar(aString);
	this->concatChar(otherString);
	this->string.push_back('\0');
}

String String::operator +(String other)
{
	String newString = String("");

	newString.concatStrings(*this, other);

	return newString;
}

String String::operator +(const char* other)
{
	String newString = String("");
	String stringFromConst = String(other);

	newString.concatStrings(*this, stringFromConst);

	return newString;
}

void String::operator +=(String other)
{
	const char* actualValue = this->string.data();
	this->string.clear();
	this->concatStrings(String(actualValue), other);
}

void String::operator +=(const char* other)
{
	const char* actualValue = this->string.data();
	this->string.clear();
	this->concatStrings(String(actualValue), String(other));
}

int String::operator >(String other)
{
	for (int i = 0; i < this->length(); i++) {
		if (this->charAt(i) > other.charAt(i)) return 1;
		else if (this->charAt(i) < other.charAt(i)) return -1;
		i++;
	}
	return 0;
}

int String::operator <(String other)
{
	int compared = *this > other;

	return compared == 1 ? -1 : compared == -1 ? 1 : 0;
}

String String::operator *(int times)
{
	String newString = String("");
	for (int i = 0; i < times; i++) {
		newString.concatChar(*this);
		newString.concatChar(String(" "));
	}
	newString.string.push_back('\0');

	return newString;
}

const char* String::toString()
{
	const char* data = this->string.data();
	return data;
}

std::ostream& operator << (std::ostream& stream, String string)
{
	return stream << string.toString();
}
