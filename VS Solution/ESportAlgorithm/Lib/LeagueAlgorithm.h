#pragma once

#include <vector>
#include <map>
#include <unordered_map>

#include "Lib/Teams.h"

struct League
{
public:
	League(std::string Name, std::vector<Team> Allteams);

	Team* WinTeam = nullptr;
	uint16_t MatchRound[2] = {};

	std::string* NameOfLeague;
	std::vector<Team> AllTeams;

	void RunLeague();
	std::map<uint32_t, std::string> GlobalRanking();
	std::map<uint32_t, std::string> PosGlobalRanking;

private:
	
	void WhoWin();
	void OneMatche(Team& m_TeamOne,Team& m_TeamTwo);
	void BestOfThree(Team& m_TeamOne, Team& m_TeamTwo);

	enum Tier
	{
		T1 = 100000,
		T2 = 10000,
		T3 = 1000,
		T4 = 100,
	};

	enum AddRank
	{
		RT1 = 30,
		RT2 = 25,
		RT3 = 20,
		RT4 = 10,
	};


	Tier SelectTier = T1;
	AddRank AddRank = RT1;

	uint8_t m_totalRound = 0;

	uint8_t m_AmmoutToBO3 = 6;
	size_t m_ParticipantPos;

	uint16_t m_MuisPoints = 2;
	
	std::vector<Team*> m_RemaingTeams;
protected:

	int par = 0;
	int Notpar = 1;
	int halfTeams = 0;

	void CheckForDups();
	void DeleteTeamInBOThree();
	void DeleteTeamInBOOne();
};

/*
* Liga :
* Teams =
* bo1 (warking)
* bo3 (-||-)
* How win
* Ranking
*/