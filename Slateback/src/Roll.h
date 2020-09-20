#pragma once
#include <string>

class Roll
{
public:
	void SetID(std::string id);
	void SetShotCount(unsigned int n);

	std::string GetID();
	unsigned int GetShotCount();
private:
	std::string m_ID;
	unsigned int m_ShotCount;
};