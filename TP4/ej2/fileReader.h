#pragma once
#include <map>
#include <string>

using namespace std;

class FileReader {
	public:
		FileReader(const char* filename);
		~FileReader();
		void read();
		void showContent();

		string content = "";

		int getVowelsQuantities();
		int getConsonantsQuantities();
		int getWordsQuantities();
		int getCharactersQuantities();
		int getPuntuactionMarksQuantities();

		int getQuantityOf(char character);

	private:
		const char* filename;
		std::map<char, int> charactersQuantities;
};
