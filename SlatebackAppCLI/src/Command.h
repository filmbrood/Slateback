#pragma once
#include <string>

class Command
{
public:
	virtual void OnInit() = 0;
	virtual void OnUpdate() = 0;
	
	virtual std::string GetInput();
	virtual void SetInput(std::string input);

private:
	std::string m_Input;
};