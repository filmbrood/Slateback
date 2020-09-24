#include "Roll.h"

Roll::~Roll()
{
	for (unsigned int i = 0; i < m_Shots.size(); i++)
		delete m_Shots[i];
}

void Roll::SetID(std::string id)
{
	m_ID = id;
}

std::string Roll::GetID()
{
	return m_ID;
}

size_t Roll::GetShotCount()
{
	return m_Shots.size();
}

void Roll::PushNewShot(Shot* shot)
{
	m_Shots.push_back(shot);
}

Shot* Roll::GetShot(unsigned int index)
{
	return m_Shots[index];
}