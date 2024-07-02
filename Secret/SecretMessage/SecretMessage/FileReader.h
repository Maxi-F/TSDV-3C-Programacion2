#pragma once

#include <string>

using namespace std;

class FileReader {
public:
	FileReader(const char* filename);
	~FileReader();
	void read();
	void showUnencryptedContent();

	string encryptedContent = "";

private:
	const char* filename;
	string unencrypt();

};

