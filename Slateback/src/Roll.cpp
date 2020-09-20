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

std::string Roll::PrintShotDetailsToString()
{
	std::string output;

	output += "[Roll " + GetID() + "]" + "\n";
	output += "Shot #: " + std::to_string(m_ShotCount) + "\n\n";

	for (unsigned int i = 0; i < m_ShotCount; i++)
	{
		output += "[Shot]\n";
		std::string details[9] =
		{
			"Scene: " + m_Shots[i]->GetScene() + "\n",
			"Take: " + m_Shots[i]->GetTake() + "\n",
			"FPS: " + m_Shots[i]->GetFPS() + "\n",
			"Lens: " + m_Shots[i]->GetLens() + "\n",
			"f/Stop: " + m_Shots[i]->GetFStop() + "\n",
			"ISO: " + m_Shots[i]->GetISO() + "\n",
			"Color Temp: " + m_Shots[i]->GetColorTemp() + "\n",
			"Filter: " + m_Shots[i]->GetColorTemp() + "\n\n"
		};

		for (unsigned int j = 0; j < 9; j++)
			output += details[j];
	}

	return output;
}
