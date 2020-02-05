#include "pch.h"
#include "Player.h"
#include <iostream>

Player::Player()
{
	strcpy_s(m_name, "nameless hero");
	m_score = 10;
}

Player::Player(const char name[30], int score) :m_score{score}
{	
	strcpy_s(m_name, name);
	setScore(score); 
}



Player::~Player()
{
}

Player::Player(char * Name, int score)
{
	strcpy_s(m_name, Name);
	setScore(score);
}
//set name
void Player::setName(const char name[30])
{
	strcpy_s(m_name, name);
}
//set score
void Player::setScore(const int score)
{
	m_score = score;
}



void Player::save(std::ofstream & out)
{
	if (!out.is_open())
		return;
	//write player name
	out.write(m_name, 30);
	//write player score
	out.write((char*)&m_score, sizeof(int));

}
bool Player::load(std::ifstream& in)
{
	//check if file is still open
	if (!in.is_open())return false;	

	//Load name
	in.read(m_name, 30);

	if (in.rdstate()) return false;
	//Load Score
	in.read((char*)&m_score, sizeof(int));

	if (in.rdstate()) return false;


	return true;
}


