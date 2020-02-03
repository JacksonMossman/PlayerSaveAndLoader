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

	void bubbleSort();

	void Swap(Player * players, int n, int k);


	


private:


	Player* m_players;
	

	void getCommand();
	void search();
	void save();
	bool load();

	int BinarySearch(char * key);

	
	

	bool gameover = false;

	int m_playerCount =1;
	
	

	int m_tempPlayerCount =1;
	Player* m_tempPlayers;

	

};

