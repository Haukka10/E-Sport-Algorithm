#pragma once
#include <string>
#include <vector>
#include "Lib/Players.h"

struct Team
{
public:
	Team(std::string TeamName);
	Team();
	std::string NameOfTeam = "No Name";

	void SetPlayers(std::string name, bool IsRankSet);
	
	int32_t Rank = 0;
	uint64_t money = 1000;
	uint8_t TeamSize = 9;

	std::vector<std::string> PlayersNames;
private:
	std::vector<Player> m_Players;
	int RankingPlayers();
	int StatsPlayer();
};