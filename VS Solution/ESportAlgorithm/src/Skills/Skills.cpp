#include "Lib/Skills.h"

#include <cmath>
#include <algorithm>

Skill::Skill(int Aim, int Mov, int KoG, int TeamWork, int Lider)
{
	m_Aim = Aim;
	m_Movment = Mov;
	m_KonwofGame = KoG;
	m_TeamWork = TeamWork;
	m_LiderShip = Lider;
	SkillRank = GetSkillRank();
}

int Skill::GetSkillRank()
{
	int sum = (m_Aim + m_Movment + m_KonwofGame + m_TeamWork + m_LiderShip);
	int ArithmeticAve = sum / 5;

	m_buffor = &sum;
	*m_buffor /= 2;
	*m_buffor -= log10(sum);

	*m_buffor += std::sqrt(ArithmeticAve);

	*m_buffor = std::clamp(*m_buffor, 0, 150);
	return *m_buffor;
}
