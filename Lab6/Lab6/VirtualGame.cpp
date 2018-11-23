#include "stdafx.h"
#include "VirtualGame.h"
#include <iostream>

using namespace std;

VirtualGame::VirtualGame(string name, bool isStickmanNeeded, string url, string price) : CasinoGame(name, isStickmanNeeded)
{
	this->Url = url;
	this->PriceForOneGame = price;
}

string VirtualGame::ToString()
{
	string baseName = CasinoGame::ToString();

	return baseName + "Url: " + this->Url + "\n" + "Cost of one game is "  + this->PriceForOneGame + "\n";
}
void VirtualGame::CloseSite()
{
	cout << "Site is closed";
}


VirtualGame::~VirtualGame()
{
}
