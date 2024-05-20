#pragma once
#include <string>
#include <filesystem>

#include "Lib/Teams.h"
#include "Lib/Skills.h"
#include "Lib/Players.h"

std::vector<Team> GeneratorNewTeams();
std::vector<std::string> LoadNameTeams();