#pragma once
#include <string>
#include <vector>
class Player
{
public:
	Player(std::string Name);

	void SetRank(int Aim, int Mov, int KoG, int TeamWork, int Lider);

	std::string NameOfPlayer;

	short Rank = 0;

};
/*
* Players :
* Name =
* Rank =
* Languages =
* Role =
*/