// Lab6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <regex> 
#include <Windows.h>

using namespace std;

#pragma region Headers

class CasinoGame
{
public:
	CasinoGame(string name, bool isStickmanNeeded);
	virtual string ToString() = 0;
	virtual void NewGame();
	string Name;
	bool isStickmanNeeded = false;
	~CasinoGame();
};

class VirtualGame :
	public virtual CasinoGame
{
public:
	VirtualGame(string name, bool isStickmanNeeded, string url, string price);
	string ToString();
	void CloseSite();
	string Url = "No Url";
	string PriceForOneGame = "1 coin";
	~VirtualGame();
};

class PvPGame :
	public virtual CasinoGame
{
public:
	PvPGame(string name, int minPlayerCount);
	PvPGame(string name, int minPlayerCount, string stickmanName);
	string ToString();
	void StartBetting();
	int MinPlayerCount;
	string StickmanName = "No stickman";
	~PvPGame();
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
	string ToString();
	~Pokerstar();
};

#pragma endregion

#pragma region Implementations

#pragma region Casino
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
	cout << "Game " + this->Name + " started \n";
}

CasinoGame::~CasinoGame()
{
}
#pragma endregion

#pragma region PvP
PvPGame::PvPGame(string name, int minPlayerCount) : CasinoGame(name, false)
{
	this->MinPlayerCount = minPlayerCount;
}

PvPGame::PvPGame(string name, int minPlayerCount, string stickmanName) : CasinoGame(name, true)
{
	this->MinPlayerCount = minPlayerCount;
	this->StickmanName = stickmanName;
}

string PvPGame::ToString()
{
	string baseName = CasinoGame::ToString();

	return baseName + "Min player count: " + to_string(this->MinPlayerCount) + "\n" + "Stickname: " + this->StickmanName + "\n";}

void PvPGame::StartBetting()
{
}


PvPGame::~PvPGame()
{
}
#pragma endregion

#pragma region Virtual
VirtualGame::VirtualGame(string name, bool isStickmanNeeded, string url, string price) : CasinoGame(name, isStickmanNeeded)
{
	this->Url = url;
	this->PriceForOneGame = price;
}

string VirtualGame::ToString()
{
	string baseName = CasinoGame::ToString();

	return baseName + "Url: " + this->Url + "\n" + "Cost of one game is: " + this->PriceForOneGame + "\n";
}

void VirtualGame::CloseSite()
{
	cout << "Site is closed";
}


VirtualGame::~VirtualGame()
{
}
#pragma endregion

#pragma region PokerStar
Pokerstar::Pokerstar(string name, int minPlayerCount, string url, string price, string login, string password, string stickmanName) : VirtualGame(name, true, url, price), PvPGame(name, minPlayerCount, stickmanName), CasinoGame(name, true)
{
	this->Login = login;
	this->Password = password;
}

Pokerstar::Pokerstar(string name, int minPlayerCount, string url, string price, string login, string password) : VirtualGame(name, false, url, price), PvPGame(name, minPlayerCount), CasinoGame(name, false)
{
	this->Login = login;
	this->Password = password;
}

void Pokerstar::GetMoneyToCard()
{
	cout << "Money is on your cards \n";
}

string Pokerstar::ToString() {
	string baseName = PvPGame::ToString();

	return baseName + "Url: " + this->Url + "\n" + "Cost of one game is: " + this->PriceForOneGame + "\n" + "Login: " + this->Login + "\n";
}

Pokerstar::~Pokerstar()
{
}
#pragma endregion

#pragma endregion

void printError(string msg) {
	cout << endl << "Error. Incorect values." << endl;
	cout << msg;
}

int getIntValue(string msg) {
	string value;
	int intValue;
	bool isValidValue = true;
	regex pattern("[[:digit:]]+");

	cout << msg;

	do {
		getline(cin, value, '\n');

		while (!regex_match(value, pattern) || value.empty() || value == "0") {
			printError(msg);
			getline(cin, value, '\n');
		}

		try {
			intValue = stoi(value);
			isValidValue = true;
		}
		catch (out_of_range) {
			isValidValue = false;
			cout << "Max value - 2147483647" << endl;
			printError(msg);
		}

	} while (!isValidValue);

	return intValue;
}

string getStringValue(string msg) {
	string value;
	cout << msg;

	do
	{
		getline(cin, value, '\n');

		while (value[0] == ' ') {
			value.erase(0, 1);
		}

		if (value.empty()) {
			printError(msg);
		}

	} while (value.empty());

	return value;
}

int main()
{
	string msg = "";
	

	cout << "Enter data for pokerstar:" << endl;

	string name;
	string url;
	string price;
	string login;
	string password;
	string stickman;
	int tempInt;

	name = getStringValue("Name: ");

	tempInt = getIntValue("Min player count: ");

	url = getStringValue("Url: ");

	price = getStringValue("Price: ");

	login = getStringValue("Login: ");

	password = getStringValue("Password: ");

	stickman = getStringValue("Stickman: ");
	
	Pokerstar* pokerStar = new Pokerstar(name, tempInt, url, price, login, password, stickman);

	cout << endl;

	pokerStar->GetMoneyToCard();

	cout << endl;

	cout << pokerStar->ToString();

	cout << endl;

	PvPGame* pvp = new PvPGame("Game 2", 1);

	pvp->StartBetting();
	cout << pvp->ToString();

	cout << endl;

	VirtualGame* virtualGame = new VirtualGame("Game v", false, "1.com", "2 $");

	virtualGame->NewGame();

	cout << virtualGame->ToString();

	delete pokerStar;
	delete pvp;
	delete virtualGame;

	system("pause");
	return 0;
}

