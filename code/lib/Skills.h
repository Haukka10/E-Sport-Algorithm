#pragma once
struct Skill
{
public:
	Skill(int Aim, int Mov, int KoG, int TeamWork, int Lider);

	int SkillRank = 0;

private:
	int GetSkillRank();

	int m_Aim = 0;

	int m_Movment = 0;

	int m_KonwofGame = 0;

	int m_TeamWork = 0;

	int m_LiderShip = 0;

	int* m_buffor = 0;
};
/*
*Skill:
*Aim
* Movemnet
* KonwofGame
* TeamWork
* LiderShip
*/