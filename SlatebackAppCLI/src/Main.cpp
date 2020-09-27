#include "CommandList.h"

#include <iostream>

int main(int argc, char** argv)
{
	CommandList::Get().OnUpdate(argv[1]);
	return 0;
}