#include "Lib/MatchShower.h"
#include "Lib/LeagueAlgorithm.h"

namespace MatchShower
{
	void Match(Team& WinTeam, Team& LoseTeam, League& le)
	{
		std::string MatchsTeams = WinTeam.NameOfTeam + " vs " + LoseTeam.NameOfTeam;

		auto m = le.MatchRound[0];
		auto n = le.MatchRound[1];

		std::string MatchsRound = std::to_string(m) + " : " + std::to_string(n);

		MatchsStatus[MatchsTeams] = MatchsRound;
	}

	void AllMatch()
	{
		for (auto x : MatchsStatus)
		{
			std::string AllMatches = x.first + " Ened on : " + x.second;
			printf(AllMatches.c_str());
			printf("\n");
		}
	}
}