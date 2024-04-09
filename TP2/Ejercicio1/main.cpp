#include "String.h"

void main() {
	String testString = String("un test");
	String otherString = String(" otro test");

	String sumTwoStrings = testString + otherString;
	String sumConstString = testString + " constant";
	String testSumEqualString = String("mas igual");
	testSumEqualString += otherString;
	testSumEqualString += " y constante";
	
	String largerString = "xyz";
	String lesserString = "abc";
	int isLargerMoreThanLesser = largerString > lesserString;
	int isLargerLessThanLesser = largerString < lesserString;

	String hi = "hola";
	String multipliedHi = hi * 3;

	std::cout << "sumTwoStrings: " << sumTwoStrings << std::endl;
	std::cout << "sumConstString: " << sumConstString << std::endl;
	std::cout << "testSumEqualString: " << testSumEqualString << std::endl;
	std::cout << "isMore: " << isLargerMoreThanLesser << std::endl;
	std::cout << "isLess: " << isLargerLessThanLesser << std::endl;
	std::cout << "multiplied: " << multipliedHi << std::endl;
}