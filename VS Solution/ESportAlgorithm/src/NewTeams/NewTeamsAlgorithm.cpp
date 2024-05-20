#include "Lib/NewTeamsAlgorithm.h"

#include <filesystem>
#include <fstream> 
std::vector<Team> GeneratorNewTeams()
{
	auto NameTeams = LoadNameTeams();
	std::vector<Team> NewTeams;

	for (size_t i = 0; i < NameTeams.size(); i++)
	{
		Team ConTeam(NameTeams[i]);

		for (size_t i = 0; i < ConTeam.TeamSize; i++)
		{
			std::string Name = "RadomPlayersName: " + std::to_string(i);
			ConTeam.SetPlayers(Name, false);
		}

		NewTeams.push_back(ConTeam);
	}
	return NewTeams;
}

std::vector<std::string> LoadNameTeams()
{
	std::filesystem::current_path("C:/");
	std::filesystem::current_path("Teams/");
	std::filesystem::current_path();


	std::fstream bufforFiles("TeamsName.txt");
	
	if(!bufforFiles.is_open())
		std::ofstream("TeamsName.txt");

	std::vector<std::string> Names;
	std::string BufforChar;

	while (std::getline(bufforFiles,BufforChar))
	{
		std::string a = BufforChar;

		Names.push_back(a);
	}

	return Names;
}