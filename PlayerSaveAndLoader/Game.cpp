#include "pch.h"
#include "Game.h"
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>


Game::Game()
{
	Player phil("phil", 10);
	m_players = new Player[m_playerCount]{ phil};
	Player jerry("jerry", 20);
	Player philbert("philbert", 100);
	Player jerryerbt("jerryerbt", 200);
	AddPlayer(jerry);
	AddPlayer(jerryerbt);
	AddPlayer(philbert);
}


Game::~Game()
{
}



void Game::getCommand()
{
	//Create the input buffer
	char input[50] = "\0";
	int inputint = 0;
	



	while (!gameover) {

		std::cout << "Enter a Name of a existing player to find and edit the score of or a player you wish to create." << std::endl;

		//Clear the input buffer, ready for player input
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());

		std::cin >> input;

		if (strcmp(input, "save") == 0) {
			save();
			return;
		}
		else if (strcmp(input, "exit") == 0) {
			gameover = true;
			return;
		}
		else
		{


			for (int i = 0; i < m_playerCount; i++)
			{
				if (strcmp(input, m_players[i].m_name) == 0) {

					std::cout << "Name: " << m_players[i].m_name << std::endl;
					std::cout << "Score: " << m_players[i].m_score << std::endl;

					std::cout << "Please Choose a new Name For this Profile";
					std::cout << "New Name:";
					std::cin >> input;
					m_players[i].setName(input);
					std::cout << "Please Choose a new Score For this Profile";
					std::cout << "New Score:";
					std::cin >> inputint;
					m_players[i].setScore(inputint);

				}


			}
			std::cout << "Generating New Profile";
			std::cout << "New Name:";
			std::cin >> input;

			std::cout << "Please Choose a new Score For this Profile";
			std::cout << "New Score:";
			std::cin >> inputint;

			Player newplayer(input, inputint);
			AddPlayer(newplayer);

		}				
	}
}

void Game::save()
{
	std::ofstream out;

	//Open the file for output in binary mode, and truncate
	out.open("Playersav.dat",
		std::ofstream::out | std::ofstream::binary | std::ofstream::trunc);
	if (out.is_open()) {

			
		out.write((char*)&m_playerCount, sizeof(int));
		
		//out << m_playerCount;

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

	if (!in.is_open()) {
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
	for (int i = 0; i < m_tempPlayerCount; i++) {

		if (m_tempPlayers[i].load(in) == false) {
			delete[] m_tempPlayers;
			m_tempPlayers = nullptr;
			return false;
		}

	}

	return true;
}

void Game::start()
{
	load();
	save();
	draw();
	while (true)
	{
		draw();
		
		getCommand();
		system("CLS");
	}
}

void Game::draw()
{
	for (int i = 0; i < m_playerCount; i++)
	{
		std::cout << "Name: "<< m_players[i].m_name << std::endl;
		std::cout << "Score: "<<m_players[i].m_score << std::endl;
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

	m_playerCount++;

	m_players = temparr;
}


