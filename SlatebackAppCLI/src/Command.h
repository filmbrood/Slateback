#pragma once
#include <string>

class Command
{
public:
	virtual void OnInit() = 0;
	virtual void OnUpdate() = 0;
	
	virtual std::string GetInput();
	virtual void SetInput(std::string input);

	virtual std::string GetDesc();
	virtual void SetDesc(std::string desc);

private:
	std::string m_Input;
	std::string m_Desc;
};