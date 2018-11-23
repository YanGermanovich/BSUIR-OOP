#pragma once
#include "VirtualGame.h"


class PvPGame {
public:
	PvPGame(string name, int minPlayerCount);
	PvPGame(string name, int minPlayerCount, string stickmanName);
};


class Pokerstar :
	public VirtualGame,
	public PvPGame
{
public:
	Pokerstar(string name, int minPlayerCount, string url, string price, string login, string password, string stickmanName);
	Pokerstar(string name, int minPlayerCount, string url, string price, string login, string password);
	string Login;
	string Password;
	void GetMoneyToCard();
	~Pokerstar();
};
