#pragma once
#include "Lib/Teams.h"

#include <vector>
#include <filesystem>

std::filesystem::path SetCurrentPath();

std::vector<Team> GetFiles();
void SaveTeams(std::vector<Team> Teams);
void LoadTeam();