#include "stdafx.h"
#include "CasinoGame.h"
#include "iostream"

using namespace std;

CasinoGame::CasinoGame(string name, bool isStickmanNeeded)
{
	this->Name = name;
	this->isStickmanNeeded = isStickmanNeeded;
}

string CasinoGame::ToString()
{
	return "Name: " + this->Name + "\n" + "Stickman is needed:" + (this->isStickmanNeeded ? "true" : "false") + "\n";
}

void CasinoGame::NewGame()
{
	cout << "Game " + this->Name + "started \n";
}

CasinoGame::~CasinoGame()
{
}
