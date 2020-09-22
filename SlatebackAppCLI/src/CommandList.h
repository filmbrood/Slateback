#pragma once

#include <vector>

#include "Command.h"

// Acts as a container class for a vector of command pointers.
class CommandList
{
public:
	void PushNewCommand(Command* command);
	void InitAllCommands();

	void OnUpdate(std::string userinput);

private:
	std::vector<Command*> m_Commands;
};

// Declare new command classes here. Must define the input string with SetInput() when defining the OnInit() method, and must define the OnUpdate() method.
class NewProject : public Command
{
public:
	void OnInit();
	void OnUpdate();
};

class NewCamera : public Command
{
public:
	void OnInit();
	void OnUpdate();
};

class NewRoll : public Command
{
public:
	void OnInit();
	void OnUpdate();
};

class NewShot : public Command
{ 
public:
	void OnInit();
	void OnUpdate();
};