#include "pch.h"
#include "Game.h"
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>


Game::Game()
{

	//add base players to game
	Player phil("phil", 10);
	m_players = new Player[m_playerCount]{phil};
	Player jerry("jerry", 20);
	Player billybob("billybob", 100);
	Player mike("mike", 200);
	Player albert("albert", 200);
	
	AddPlayer(jerry);
	AddPlayer(billybob);
	AddPlayer(mike);
	AddPlayer(albert);
}


Game::~Game()
{
}



void Game::getCommand()
{
	//Create the input buffer
	char input[50] = "\0";
	int inputint = 0;
	

		//display diffrent avaliable commands
		std::cout << "Enter a Command"<< std::endl;
		std::cout << "Search,";
		
		std::cout << "Exit" << std::endl;
		//Clear the input buffer, ready for player input
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());

		std::cin >> input;

		//save the current game state

		//exit game
		 if (strcmp(input, "exit") == 0) {
			gameover = true;
			return;
		}
		//enter player search menu
		else if (strcmp(input,"search")== 0)
		{
			search();
		}	
		else
		{
			std::cout << "Invalid input" << std::endl;
			system("pause");
		}
}

void Game::search()
{
	
	char input[50] = "\0";
	int inputint = 0;
	int index = 0;

	
	std::cout << "Enter a Name of a existing player to find and edit the score of or a player you wish to create." << std::endl;

	//Clear the input buffer, ready for player input
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());

		std::cin >> input;
		//search current players for name
		index = BinarySearch(input);
		//check if name exist
		if (index != -1) {
			//display the player
			std::cout << "Name: " << m_players[index].m_name << std::endl;
			std::cout << "Score: " << m_players[index].m_score << std::endl;
			//ask player if they would like to edit player
			std::cout << "Would you like to alter this Profile Yes/No" << std::endl;
			std::cin.clear();
			std::cin >> input;
			if (strcmp(input, "Yes") == 0)
			{
				//change players name
				std::cout << "Please Choose a new Name For this Profile " << std::endl;
				std::cout << "New Name:" << std::endl;
				std::cin.clear();
				std::cin >> input;
				m_players[index].setName(input);
				//get a new score for this profile
				std::cout << "Please Choose a new Score For this Profile";
				std::cout << "New Score:";
				std::cin.clear();
				std::cin >> inputint;
				m_players[index].setScore(inputint);
				return;
			}
			//return if no or anything else
			else if (strcmp(input, "No") == 0)
			{
				return;
			}
			else
			{
				system("CLS");
				std::cout << "Invalid Input" <<std::endl;
			}
		}
		
		//generate new player
		else
		{
			//display new name entered periviously
			std::cout << "Generating New Profile" << std::endl;
			std::cout << "New Name: " << input << std::endl;
			//std::cin >> input;
			//get new score for this profile
			std::cout << "Please Choose a new Score For this Profile" << std::endl;
			std::cout << "New Score: ";
			std::cin.clear();
			std::cin >> inputint;
			//generate new player and add to player list
			Player newplayer(input, inputint);
			AddPlayer(newplayer);
		}	
}

void Game::save()
{
	std::ofstream out;

	//Open the file for output in binary mode, and truncate
	out.open("Playersav.dat",
		std::ofstream::out | std::ofstream::binary | std::ofstream::trunc);
	if (out.is_open()) {

			//save amount of players
		out.write((char*)&m_playerCount, sizeof(int));
		

		//save the amount of players equal to player count
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
	//close file being wrote to
	out.flush();
	out.close();

	std::cout << "Progress has been saved" << std::endl;
	system("pause");
	system("CLS");
}

bool Game::load()
{
	std::ifstream in;

	//Open the file for input
	in.open("Playersav.dat", std::ifstream::in | std::ifstream::binary);
	//failed to open document
	if (!in.is_open()) {
		std::cout << "failure to load";
		system("pause"); 
		return false;
	}

	//Clear the temporary list
	if (m_tempPlayers != nullptr)
		delete[] m_tempPlayers;

	//Load the players
	in.read((char*)&m_tempPlayerCount, sizeof(int));
	if (in.rdstate() || m_tempPlayerCount < 0)
		return false;
	//Read the players
	m_tempPlayers = new Player[m_tempPlayerCount];
	for (int i = 0; i < m_tempPlayerCount; i++) {

		if (m_tempPlayers[i].load(in) == false) {
			delete[] m_tempPlayers;
			m_tempPlayers = nullptr;
			return false;
			std::cout << "failure to load";
			system("pause");
			system("CLS");
		}

	}

	m_playerCount = m_tempPlayerCount;
	m_players = m_tempPlayers;
	
	//displays if load was successfuk
	std::cout << "Load Successful press any key to continue" <<std::endl;
	system("pause");
	system("CLS");
	return true;
}
	//search list for player
int Game::BinarySearch(char* key)
{
	
	int max = m_playerCount -1;
	int min = 0;
	 

 	while (max != min)
	{
		//set middle and check
		int middle = (min + max) / 2;
		if (strcmp(m_players[middle].m_name, key) == 0)
		{
			return middle;
		}
		//lower max if lower
		if (strcmp(m_players[middle].m_name, key) > 0)
		{
			max = middle -1;
			
		}
		//lift min if higher
		else if (strcmp(m_players[middle].m_name, key) < 0)
		{
			min = middle + 1;
		}
		//set middle again and check again
		middle = (min + max) / 2;
		if (strcmp(m_players[middle].m_name, key) == 0)
		{
			return middle;
		}
	
		
	}
	return -1;
}

void Game::start()
{
	//load previous game state
	load();
	while (!gameover)
	{
		//sort list
		bubbleSort();
		//draw list
		draw();		
		//get player command
		getCommand();
		//clear 
		system("CLS");
	}
	save();
	
}
//draw player list
void Game::draw()
{
	//draw the list of players
	for (int i = 0; i < m_playerCount; i++)
	{
		std::cout << "Name: "<< m_players[i].m_name << std::endl;
		std::cout << "Score: "<<m_players[i].m_score << std::endl;
	}
	
}
//add player to the player list
void Game::AddPlayer(Player x)
{
	//temporary array to hold players
	Player* temparr = new Player[m_playerCount + 1];
	//copy players over to temp
  	 for (int i = 0; i < m_playerCount; i++)
	 {
		temparr[i] = m_players[i];
	 }
	 //set last player in temp to added player
	temparr[m_playerCount] = x;
	//incrament player count
	m_playerCount++;
	//set players to temp
	m_players = temparr;
}
//sort the players alphabetically
void Game::bubbleSort()
{
	bool done = false;

	while(!done)
	{
		//set check to true
		done = true;
		//go through player list seeing if any players are out of order and if they are swap them
		for (int i = 0; i < m_playerCount -1; i++)
		{
			//compare two players
			if (strcmp(m_players[i].m_name, m_players[i + 1].m_name) > 0)				
			{    
				//swap to players if they need to be swapped
				Swap(m_players, i, i + 1);
				//if any swaps occure then set to false and iterate again
				done = false;
			
			}

		}

	}
}
//swap to players position in the array
void Game::Swap(Player* players, int n, int k)

{   
	//set the two players to each other
	Player temp;

	temp = players[n];
	

	players[n] = players[k];

	players[k] = temp;

}


