#include "Roll.h"

void Roll::SetID(std::string id)
{
	m_ID = id;
}

std::string Roll::GetID()
{
	return m_ID;
}

unsigned int Roll::GetShotCount()
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