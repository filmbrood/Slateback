#include "sltcli_pch.h"

void About::OnInit()
{
	SetInput("about");
	SetDesc("Displays program information (version, author)");
}

void About::OnUpdate()
{
	std::cout << "Slateback - Camera Report Generator" << std::endl;
	std::cout << "Version: " << SLATEBACKVERSION << std::endl;
	std::cout << "Author: " << AUTHOR << std::endl;
	std::cout << "Copyright " << COPYRIGHT << ". All rights reserved." << std::endl;
}