#include "stdafx.h"
#include "Pokerstar.h"
#include <iostream>

Pokerstar::Pokerstar(string name, int minPlayerCount, string url, string price, string login, string password, string stickmanName) : VirtualGame(name, true, url, price), PvPGame(name, minPlayerCount, stickmanName)
{
	this->Login = login;
	this->Password = password;
}

Pokerstar::Pokerstar(string name, int minPlayerCount, string url, string price, string login, string password) : VirtualGame(name, false, url, price), PvPGame(name, minPlayerCount)
{
	this->Login = login;
	this->Password = password;
}

void Pokerstar::GetMoneyToCard()
{
	cout << "Money is on your cards \n";
}

Pokerstar::~Pokerstar()
{
}
