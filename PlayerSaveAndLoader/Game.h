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
	

	void getCommand();
	void save();
	bool load();

	bool gameover = false;

	int m_playerCount =1;
	


	int m_tempPlayerCount =1;
	Player* m_tempPlayers;

	

};

