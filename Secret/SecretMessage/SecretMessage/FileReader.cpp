#include "FileReader.h"
#include <fstream>
#include <iostream>
#include <map>

static char encoding_table[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
								'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
								'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
								'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
								'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
								'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
								'w', 'x', 'y', 'z', '0', '1', '2', '3',
								'4', '5', '6', '7', '8', '9', '+', '/' };

std::map<char, char> *decoding_table;

FileReader::FileReader(const char* filename) {
	this->filename = filename;

	decoding_table = new std::map<char, char>();

	for (int i = 0; i < 64; i++) {
		decoding_table->insert(std::pair<char, char>(encoding_table[i], i));
	}
}

FileReader::~FileReader() {
}

void FileReader::read() {
	ifstream file;

	file.open(filename);

	if (file.is_open()) {
		char c;

		while (file.get(c)) {
			encryptedContent += c;
		}
	}
	else {
		throw new exception("There was an error opening the file");
	}

	file.close();
}

void FileReader::showUnencryptedContent() {
	std::cout << unencrypt() << std::endl;
};

string FileReader::unencrypt() {
	string decodedData = "";
	for (int i = 0; i < encryptedContent.length();) {
		uint32_t sextet_a = decoding_table->at(encryptedContent[i++]);
		uint32_t sextet_b = decoding_table->at(encryptedContent[i++]);
		uint32_t sextet_c = decoding_table->at(encryptedContent[i++]);
		uint32_t sextet_d = decoding_table->at(encryptedContent[i++]);

		uint32_t pushedA = (sextet_a << 3 * 6);
		uint32_t pushedB = (sextet_b << 2 * 6);
		uint32_t pushedC = (sextet_c << 1 * 6);
		uint32_t pushedD = (sextet_d << 0 * 6);

		// << command shifts the bits so the int has all bits
		uint32_t allBitsOfSextets = (sextet_a << 3 * 6)
			+ (sextet_b << 2 * 6)
			+ (sextet_c << 1 * 6)
			+ (sextet_d << 0 * 6);

		// >> shifts the bits to the last place and 0xFF masks it!
		decodedData.push_back((allBitsOfSextets >> 2 * 8) & 0xFF);
		decodedData.push_back((allBitsOfSextets >> 1 * 8) & 0xFF);
		decodedData.push_back((allBitsOfSextets >> 0 * 8) & 0xFF);
	}

	return decodedData;
}
