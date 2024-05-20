// ESportAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Lib/Teams.h"
#include "Lib/ShowResults.h"
#include "Lib/MatchShower.h"
#include "Lib/LeagueAlgorithm.h"
#include "Lib/ImpoertForFiles.h"
#include "Lib/NewTeamsAlgorithm.h"

int main()
{
	auto a = GetFiles();

	if (a.empty() == false)
	{
		{
			League l("TT", a);
			l.RunLeague();
			l.GlobalRanking();

			SaveTeams(l.AllTeams);

			ShowResults::GetTeams(l);
			ShowResults::ShowRainking(l);

			printf("\n");
			printf("-------------------------------------------- \n");

			MatchShower::AllMatch();

			std::cin.get();
		}
	}
	else
	{
		printf("You don't have generated a file for Teams (Name is AllTeams.txt) or is empty. \n Please fill a files TeamsName.txt, then restart program \n");
		printf("Remember. The number of names in the files is equal to the number of teams (5 names = 5 teams)");
		SaveTeams(GeneratorNewTeams());
		return 1;
	}
}