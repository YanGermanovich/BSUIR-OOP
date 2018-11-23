#include "CasinoGame.h"

class VirtualGame :
	public CasinoGame
{
public:
	VirtualGame(string name, bool isStickmanNeeded, string url, string price);
	string ToString();
	void CloseSite();
	string Url = "No Url";
	string PriceForOneGame = "1 coin";
	~VirtualGame();
};

