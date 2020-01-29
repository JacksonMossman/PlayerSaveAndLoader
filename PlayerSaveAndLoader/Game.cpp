#include "pch.h"
#include "Game.h"
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>


Game::Game()
{
	
	Player phil("phil", 10);
	Player jerry("jerry", 20);
	Player philbert("philbert", 100);
	Player jerryerbt("jerryerbt", 200);
	int m_playerCount = 1;
	AddPlayer(phil);
	AddPlayer(jerry);
	AddPlayer(jerryerbt);
	AddPlayer(philbert);
}


Game::~Game()
{
}



int Game::getCommand()
{
	return 0;
}

void Game::save()
{
	std::ofstream out;

	//Open the file for output in binary mode, and truncate
	out.open("Playersav.dat",
		std::ofstream::out | std::ofstream::binary | std::ofstream::trunc);

	if (out.is_open()) {

			//Save the powerups
			out.write((char*)&m_playerCount, sizeof(int));

		for (int i = 0; i < m_playerCount; i++) 
		{
				m_players[i].save(out);
		}
	}
	
	else 
	{
		//Could not open the file
		std::cout <<"Could not open zorpsave.dat."<< std::endl;
	}

	out.flush();
	out.close();
}

bool Game::load()
{
	std::ifstream in;

	//Open the file for input
	in.open("Playersav.dat", std::ifstream::in | std::ifstream::binary);

	if (!in.is_open())
	{
		return false;
	}

	//Clear the temporary list
	if (m_tempPlayers != nullptr)
		delete[] m_tempPlayers;

	//Load the powerups
	in.read((char*)&m_tempPlayerCount, sizeof(int));
	if (in.rdstate() || m_tempPlayerCount < 0)
		return false;
	//Read the powerups
	m_tempPlayers = new Player[m_tempPlayerCount];
	for (int i = 0; i < m_tempPlayerCount; i++) 
	{
		if (m_tempPlayers[i].load(in) == false) 
		{
			delete[] m_tempPlayers;
			m_tempPlayers = nullptr;
			return false;
		}
	}



	//Add the powerups
	delete[] m_tempPlayers;
	m_players = m_tempPlayers;
	m_playerCount = m_tempPlayerCount;
	m_tempPlayers = nullptr;
	//Place the powerups
	for (int i = 0; i < m_playerCount; i++)
	{		

	}

	return true;
}

void Game::start()
{
 	m_players = new Player[m_playerCount];
	save();

	//while (true)
	//{

	//	draw();
	//}
	//while (!gameover)
	//{
	//	save();
	//	//getCommand();
	//}
}

void Game::draw()
{
	for (int i = 0; i < m_playerCount; i++)
	{
		char* temp = m_players[i].Name;
		std::cout <<"Name: " <<temp << std::endl;
		std::cout <<"Score: "<< m_players[i].score << std::endl;
	}
}

void Game::AddPlayer(Player x)
{

	Player* temparr = new Player[m_playerCount + 1];

	for (int i = 0; i < m_playerCount; i++)
	{
		temparr[i] = m_players[i];
	}
	temparr[m_playerCount] = x;
	

	m_players = temparr;
}


