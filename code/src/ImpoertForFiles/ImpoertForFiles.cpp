#include "Lib/ImpoertForFiles.h"
#include "Lib/ShowResults.h"

#include <string>
#include <vector>
#include <fstream> 
#include <algorithm>
#include <filesystem>

std::vector<Team> BufforAllTeams;

std::vector<Team> GetFiles()
{
	LoadTeam();
	return BufforAllTeams;
}

void SaveTeams(std::vector<Team> Teams)
{
	auto TempDir = SetCurrentPath();

	std::ofstream WritesFiles("AllTeams.txt");
	
	for (auto x : Teams)
	{
		WritesFiles << "TEAM NAME:\n";
		WritesFiles << x.NameOfTeam;
		WritesFiles << "\n";

		WritesFiles << "RANKS:\n";
		WritesFiles << x.Rank;
		WritesFiles << "\n";

		WritesFiles << "Players:\n";

		for (size_t i = 0; i < x.TeamSize; i++)
		{
			WritesFiles << x.PlayersNames[i];
			WritesFiles << "\n";
		}

		WritesFiles << ";";
		WritesFiles << "\n";
	}

	WritesFiles.close();
}

void LoadTeam()
{
	auto TempDir = SetCurrentPath();

	std::fstream bufforFiles("AllTeams.txt");

	std::string FilesContentBuffor;
	std::string FilesContent;

	bool NameTeam = false;
	bool NamePlayer = false;
	bool Rank = false;

	Team t;
	uint16_t index = 0;

	if (!bufforFiles.is_open())
	{
		std::ofstream("AllTeams.txt");
	}

	while (std::getline(bufforFiles, FilesContentBuffor))
	{
		std::string a = FilesContentBuffor;

		if (NameTeam != true || NamePlayer != true)
			std::transform(a.begin(), a.end(), a.begin(), ::toupper);

		if (a == "TEAM NAME:")
		{
			NameTeam = true;
			continue;
		}

		if (NameTeam == true)
		{
			t = Team(a);
			NameTeam = false;
		}

		if (a == "PLAYERS:")
		{
			NamePlayer = true;
			continue;
		}

		if (a == "RANKS:")
		{
			Rank = true;
			continue;
		}

		if (Rank == true)
		{
			auto i = atoi(a.c_str());

			if (i == 0)
			{
				Rank = false;
				continue;
			}

			t.Rank = atoi(a.c_str());
			Rank = false;
		}

		if (NamePlayer == true && t.TeamSize > index)
		{
			t.SetPlayers(a,t.Rank > 0);
			index++;
		}

		if (t.TeamSize == index)
		{
			BufforAllTeams.push_back(t);
			index = 0;
			continue;
		}

		if (a == ";")
		{
			t = Team();
			NamePlayer = false;
			NameTeam = false;
			Rank = false;
			index = 0;
			continue;
		}
	}

	bufforFiles.close();
}

std::filesystem::path SetCurrentPath()
{
	std::filesystem::current_path("C:/");

	if (!std::filesystem::is_directory("Teams/"))
	{
		std::filesystem::create_directory("Teams/");
	}

	std::filesystem::current_path("Teams/");

	return std::filesystem::current_path();
}