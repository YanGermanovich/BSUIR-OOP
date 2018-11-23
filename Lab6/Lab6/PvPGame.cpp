#include "stdafx.h"
#include "PvPGame.h"

PvPGame::PvPGame(string name, int minPlayerCount): CasinoGame(name, false)
{
	this->MinPlayerCount = minPlayerCount;
}

PvPGame::PvPGame(string name, int minPlayerCount, string stickmanName): CasinoGame(name, true)
{
	this->MinPlayerCount = minPlayerCount;
	this->StickmanName = stickmanName;
}

string PvPGame::ToString()
{
	return string();
}

void PvPGame::StartBetting()
{
}


PvPGame::~PvPGame()
{
}
