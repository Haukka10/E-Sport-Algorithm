#include "Lib/Teams.h"

#include <string>
#include <math.h>
#include <time.h>

Team::Team(std::string TeamName)
{
	NameOfTeam = TeamName;
	char Letter = NameOfTeam[0];

	auto a = NameOfTeam.find(Letter);

	Letter = toupper(Letter);
	NameOfTeam[a] = Letter;
}

Team::Team()
{
}

int bufforRank = 0;
void Team::SetPlayers(std::string name, bool IsRankSet)
{
	auto p = Player(name);
	PlayersNames.push_back(p.NameOfPlayer);

	if (IsRankSet == false)
	{
		p.SetRank(StatsPlayer(), StatsPlayer(), StatsPlayer(), StatsPlayer(), StatsPlayer());
		m_Players.push_back(p);
		bufforRank = p.Rank;

		if (m_Players.size() == TeamSize)
			Rank = RankingPlayers();
	}
}

int Team::RankingPlayers()
{
	int RankNotPlayer = bufforRank;
	if (TeamSize % 2 == 0)
	{
		int a = abs(RankNotPlayer);

		int b = (int)floor(a);
		b = (b ^ 2);

		if (b < 0)
			b = b * -1;

		auto c = b % 2;
		RankNotPlayer = b + c;
	}
	return RankNotPlayer;
}

int Team::StatsPlayer()
{
	return rand() % 100 + 5;
}
