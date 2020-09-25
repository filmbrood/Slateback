#pragma once

#include <vector>

#include "Command.h"

// Acts as a container class for a vector of command pointers.
class CommandList
{
public:
	// Deconstructor for deleting m_Commands vector
	~CommandList();

	void PushNewCommand(Command* command);
	void InitAllCommands();

	void OnUpdate(const char* argv);

private:
	std::vector<Command*> m_Commands;
};

// Declare new command classes here. Must define the input string with SetInput() when defining the OnInit() method, and must define the OnUpdate() method.

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

class SerializerTest : public Command
{
public:
	void OnInit();
	void OnUpdate();
};

class DeserializerTest : public Command
{
public:
	void OnInit();
	void OnUpdate();
};