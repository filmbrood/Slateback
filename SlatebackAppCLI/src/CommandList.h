#pragma once

#include <vector>

#include "Command.h"

// Acts as a container class for a vector of command pointers. Runs as a Singleton, access with CommandList::Get().
class CommandList
{
public:
	void PushNewCommand(Command* command); // Pushes a Command child instance to m_Commands
	void InitAllCommands(); // Runs the OnInit() method in all classes within the m_Commands vector
	void ClearCommandsFromMemory(); // Deletes heap-allocated Command classes within m_Commands vector, then clears the vector
	size_t GetCommandCount(); // Returns size of m_Commands
	Command* GetCommand(unsigned int index); // Returns command from m_Commands at specificed index

	void OnUpdate(const char* argv); // Pushes commands to vector, initializes them, and chooses which one to run based on argv argument
	static CommandList& Get(); // Returns static singleton s_Instance

private:
	CommandList() {}
	static CommandList s_Instance;
	std::vector<Command*> m_Commands;
};

// Declare new command classes here. Must define the input string and description with SetInput() and SetDesc() when defining the OnInit() method, and must define the OnUpdate() method.
// Command methods are defined in their respective .cpp files in src/commands/.

class NewProject : public Command // "project" argument class
{
public:
	void OnInit();
	void OnUpdate();
};

class NewCamera : public Command // "camera" argument class
{
public:
	void OnInit();
	void OnUpdate();
};

class NewRoll : public Command // "roll" argument class
{
public:
	void OnInit();
	void OnUpdate();
};

class NewShot : public Command // "shot" argument class
{ 
public:
	void OnInit();
	void OnUpdate();
};

class Status : public Command // "status" argument class
{
public:
	void OnInit();
	void OnUpdate();
};

class Print : public Command // "print" argument class
{
public:
	void OnInit();
	void OnUpdate();
};

class Help : public Command // "help" argument class
{
public:
	void OnInit();
	void OnUpdate();
};

class ChangeProject : public Command // "changeproject" argument class
{
public:
	void OnInit();
	void OnUpdate();
};

class ChangeCamera : public Command // "changecamera" argument class
{
public:
	void OnInit();
	void OnUpdate();
};

class About : public Command // "about" argument class
{
public:
	void OnInit();
	void OnUpdate();
};