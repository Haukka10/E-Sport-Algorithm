#include "Lib/Players.h"
#include "Lib/Skills.h"

Player::Player(std::string Name)
{
	NameOfPlayer = Name;
}

void Player::SetRank(int Aim, int Mov, int KoG, int TeamWork, int Lider)
{
	Skill sk(Aim, Mov, KoG, TeamWork, Lider);
	Rank = sk.SkillRank;
}
