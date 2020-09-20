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
