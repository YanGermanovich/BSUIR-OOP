#include "CasinoGame.h"

class PvPGame :
	public CasinoGame
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


