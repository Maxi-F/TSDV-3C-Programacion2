#include "FileReader.h"

void main() {
	FileReader fileReader = FileReader("secret_message.txt");

	fileReader.read();
	fileReader.showUnencryptedContent();
}
