#include "Lib/LeagueAlgorithm.h"
#include "Lib/ShowResults.h"
#include "Lib/Teams.h"

#include <string>

namespace ShowResults
{
	void GetTeams(League& le)
	{
		std::string WinTeamNname = "Win Teams is " + le.WinTeam->NameOfTeam + " And has ranking " + std::to_string(le.WinTeam->Rank);
		std::printf(WinTeamNname.c_str());
		printf("\n");
	}

	void ShowRainking(League& le)
	{
		printf("\n");
		printf("All Teams: vvv");
		for (const auto& a : le.PosGlobalRanking)
		{
			printf("\n");
			std::string Rp = "Name: " + a.second + " Rainking: " + std::to_string(a.first);
			printf(Rp.c_str());
		}
	}
}