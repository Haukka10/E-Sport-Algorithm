#include "Lib/LeagueAlgorithm.h"
#include "Lib/MatchShower.h"
#include "Lib/Teams.h"

#include <map>
#include <string>
#include <vector>
#include <algorithm>
League* Temp;

League::League(std::string Name, std::vector<Team> Allteams)
{
	NameOfLeague = &Name;

	AllTeams = Allteams;

	m_ParticipantPos = AllTeams.size();

	for (int i = 0; i < AllTeams.size(); i++)
		m_RemaingTeams.push_back(&AllTeams[i]);

	halfTeams = (int)std::floor(m_RemaingTeams.size() * 0.70F);
	Temp = this;
}

void League::WhoWin()
{
	WinTeam->money += SelectTier;
	WinTeam->Rank += AddRank;
}

Team* comp = nullptr;
Team* compTow = nullptr;

void League::RunLeague()
{
	bool isHlafTeams = false;
	while (m_RemaingTeams.size() != 1)
	{
		srand(m_RemaingTeams.size());
		if (m_RemaingTeams.size() - 1 < Notpar || m_RemaingTeams.size() - 1 < par)
		{
			Notpar = 1;
			par = 2;
		}

		if (m_RemaingTeams.size() == 2)
		{
			Notpar = 1;
			par = 0;
			comp = m_RemaingTeams[par];
			compTow = m_RemaingTeams[Notpar];

			BestOfThree(*comp, *compTow);

			continue;
		}
		else
		{
			comp = m_RemaingTeams[par];
			compTow = m_RemaingTeams[Notpar];
		}

		if (halfTeams >= m_RemaingTeams.size())
			isHlafTeams = true;

		if (isHlafTeams = true)
		{
			BestOfThree(*comp,*compTow);
		}
		else
		{
			OneMatche(*comp, *compTow);
		}

		Notpar += 2;
		par += 2;
	}

	WinTeam = m_RemaingTeams[0];
	WhoWin();
}

unsigned short MapsWinOne = 0;
unsigned short MapsWinTwo = 0;

void League::OneMatche(Team& m_TeamOne, Team& m_TeamTwo)
{
	MapsWinOne = 0;
	MapsWinTwo = 0;

	int pointsOne = m_TeamOne.Rank;
	int pointsTwo = m_TeamTwo.Rank;

	while (pointsOne >= 0 && pointsTwo >= 0)
	{
		int RoundOne = rand() % 10 + 2;
		int RoundTwo = rand() % 10 + 2;

		if (RoundOne > RoundTwo)
		{
			MatchRound[0]++;
			pointsTwo -= RoundOne;
		}
		else
		{
			MatchRound[1]++;
			pointsOne -= RoundTwo;
		}

		m_totalRound++;
	}
	MatchShower::Match(m_TeamOne, m_TeamTwo, *Temp);

	MatchRound[0] = 0;
	MatchRound[1] = 0;

	if (pointsOne >= 0)
		MapsWinTwo++;
	else
		MapsWinOne++;

	DeleteTeamInBOOne();
}

void League::BestOfThree(Team& m_TeamOne, Team& m_TeamTwo)
{
	MapsWinOne = 0;
	MapsWinTwo = 0;

	int pointsOne = m_TeamOne.Rank;
	int pointsTwo = m_TeamTwo.Rank;

	while (MapsWinOne < 2 && MapsWinTwo < 2)
	{
		while (pointsOne >= 0 && pointsTwo >= 0)
		{
			int RoundOne = rand() % 10 + 2;
			int RoundTwo = rand() % 10 + 2;

			if (RoundOne > RoundTwo)
			{
				MatchRound[0]++;
				pointsTwo -= RoundOne;
			}
			else
			{
				MatchRound[1]++;
				pointsOne -= RoundTwo;
			}

			m_totalRound++;
		}

		if (pointsOne <= 0)
		{
			pointsOne = m_TeamOne.Rank;
			pointsTwo = m_TeamTwo.Rank;
			MapsWinTwo++;
		}
		else
		{
			pointsOne = m_TeamOne.Rank;
			pointsTwo = m_TeamTwo.Rank;
			MapsWinOne++;
		}
	}
	MatchShower::Match(m_TeamOne,m_TeamTwo,*Temp);

	MatchRound[0] = 0;
	MatchRound[1] = 0;

	DeleteTeamInBOThree();
}

std::map<uint32_t, std::string> League::GlobalRanking()
{
	CheckForDups();
	for (auto x : AllTeams)
	{
		auto& Name = x.NameOfTeam;
		auto& Rank = x.Rank;

		PosGlobalRanking[Rank] = Name;
	}

	return PosGlobalRanking;
}

void League::DeleteTeamInBOThree()
{
	if (MapsWinOne == 2)
	{
		MapsWinOne = 0;

		m_RemaingTeams[par]->Rank -= m_MuisPoints;
		m_MuisPoints++;

		if (m_RemaingTeams[par]->Rank <= 0)
			m_RemaingTeams[par]->Rank = 100;

		m_RemaingTeams[par] = m_RemaingTeams[m_RemaingTeams.size() - 1];
		m_RemaingTeams.pop_back();

		m_ParticipantPos--;

	}
	else
	{
		MapsWinTwo = 0;

		m_RemaingTeams[Notpar]->Rank -= m_MuisPoints;

		if (m_RemaingTeams[Notpar]->Rank <= 0)
			m_RemaingTeams[Notpar]->Rank = 100;

		m_MuisPoints++;

		m_RemaingTeams[Notpar] = m_RemaingTeams[m_RemaingTeams.size() - 1];
		m_RemaingTeams.pop_back();

		m_ParticipantPos--;
	}
}

void League::CheckForDups()
{
	bool AmmonutDups = false;
	for (size_t i = 0; i < AllTeams.size(); i++)
	{
		for (size_t j = 1; j < AllTeams.size(); j++)
		{
			uint16_t v = AllTeams[i].Rank;

			if (v == AllTeams[j].Rank)
				AmmonutDups = true;

			if (AmmonutDups = true)
			{
				AllTeams[j].Rank += m_MuisPoints;
				AmmonutDups = false;
			}
		}
		AmmonutDups = false;
	}
}

void League::DeleteTeamInBOOne()
{
	if (MapsWinOne == 1)
	{
		MapsWinOne = 0;

		m_RemaingTeams[par]->Rank -= m_MuisPoints;
		m_MuisPoints++;

		if (m_RemaingTeams[par]->Rank <= 0)
			m_RemaingTeams[par]->Rank = 100;

		m_RemaingTeams[par] = m_RemaingTeams[m_RemaingTeams.size() - 1];
		m_RemaingTeams.pop_back();
		
		m_ParticipantPos--;

	}
	else
	{
		MapsWinTwo = 0;

		m_RemaingTeams[Notpar]->Rank -= m_MuisPoints;
		m_MuisPoints++;

		if (m_RemaingTeams[Notpar]->Rank <= 0)
			m_RemaingTeams[Notpar]->Rank = 100;

		m_RemaingTeams[Notpar] = m_RemaingTeams[m_RemaingTeams.size() - 1];
		m_RemaingTeams.pop_back();

		m_ParticipantPos--;
	}
}