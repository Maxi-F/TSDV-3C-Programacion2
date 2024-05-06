#include <string>

const int MAX_NAME_LENGTH = 50;

const int MAX_EXCEPTION_MESSAGE_LENGTH = 100;

class PlayerException : std::exception {
	private:
		char message[MAX_EXCEPTION_MESSAGE_LENGTH];

	public:
		PlayerException(const char* message);
		char* what();
};

class Player {
public:
	char name[MAX_NAME_LENGTH];
	int age;
	int mana;
	int life;
	int attack;
	
	Player(const char* name, int age, int mana, int life, int attack);
	Player(const char* fileName);
	
	~Player();

	void savePlayer(const char* fileName);
};
