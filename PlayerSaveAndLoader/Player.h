#pragma once
#include <fstream>

class Player
{
public:
	Player();
	Player(const char name[30], int score);
	~Player();
	Player(char* Name, int score);
	void setName(const char name[30]);
	void setScore(const int score);
	char* Name;
	int Score;
	
	char m_name[30];
	int score;

	void save(std::ofstream& out);
	bool load(std::ifstream& in);


};

