#include "slatebackpch.h"

#include "Roll.h"

// Roll methods. See Roll.h for more info.

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

void Roll::PushNewShot()
{
	if (m_Shots.size() > 0)
		m_ActiveShotIndex++;

	Shot shot;
	m_Shots.push_back(shot);
}

Shot& Roll::GetShot(unsigned int index)
{
	return m_Shots[index];
}

void Roll::SetActiveShotIndex(unsigned int index)
{
	m_ActiveShotIndex = index;
}

unsigned int Roll::GetActiveShotIndex()
{
	return m_ActiveShotIndex;
}
