#include "Roll.h"

void Roll::SetID(std::string id)
{
	m_ID = id;
}

void Roll::SetShotCount(unsigned int n)
{
	m_ShotCount = n;
}

std::string Roll::GetID()
{
	return m_ID;
}

unsigned int Roll::GetShotCount()
{
	return m_ShotCount;
}

void Roll::PushNewShot(Shot* shot)
{
	m_ShotCount++;
	m_Shots.push_back(shot);

	m_Shots[m_ShotCount - 1]->ShotSetup();
}

Shot* Roll::GetShot(unsigned int index)
{
	return m_Shots[index];
}