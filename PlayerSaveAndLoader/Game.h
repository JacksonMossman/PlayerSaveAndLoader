#pragma once
#include "Player.h"

class Game
{
public:
	Game();
	~Game();
	void start();
	void draw();

	void AddPlayer(Player x);


private:
	Player* m_players;
	

	int getCommand();
	void save();
	bool load();

	bool gameover = false;

	int m_playerCount;
	


	int m_tempPlayerCount;
	Player* m_tempPlayers;

};

