#pragma once

#include "Lib/LeagueAlgorithm.h"
#include "Lib/Teams.h"

namespace MatchShower
{
	void Match(Team& WinTeam, Team& LoseTeam, League& le);
	void AllMatch();

	static std::map<std::string, std::string> MatchsStatus;
}