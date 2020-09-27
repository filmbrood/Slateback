#pragma once

#include <vector>
#include <memory>

#include "Command.h"

// Acts as a container class for a vector of command pointers. Runs as a Singleton.
class CommandList
{
public:
	// Deconstructor for deleting m_Commands vector
	~CommandList();

	void PushNewCommand(Command* command);
	void InitAllCommands();
	void ClearCommandsFromMemory();

	size_t GetCommandCount();
	Command* GetCommand(unsigned int index);

	void OnUpdate(const char* argv);

	static CommandList& Get();

private:
	CommandList() {}

	static CommandList s_Instance;

	std::vector<Command*> m_Commands;
};

// Declare new command classes here. Must define the input string and description with SetInput() and SetDesc() when defining the OnInit() method, and must define the OnUpdate() method.

// "project" argument class
class NewProject : public Command
{
public:
	void OnInit();
	void OnUpdate();
};

// "camera" argument class
class NewCamera : public Command
{
public:
	void OnInit();
	void OnUpdate();
};

// "roll" argument class
class NewRoll : public Command
{
public:
	void OnInit();
	void OnUpdate();
};

// "shot" argument class
class NewShot : public Command
{ 
public:
	void OnInit();
	void OnUpdate();
};

// "status" argument class
class Status : public Command
{
public:
	void OnInit();
	void OnUpdate();
};

// "print" argument class
class Print : public Command
{
public:
	void OnInit();
	void OnUpdate();
};

// "help" argument class
class Help : public Command
{
public:
	void OnInit();
	void OnUpdate();
};

// "changeproject" argument class
class ChangeProject : public Command
{
public:
	void OnInit();
	void OnUpdate();
};

// "changeroll" argument class
class ChangeCamera : public Command
{
public:
	void OnInit();
	void OnUpdate();
};