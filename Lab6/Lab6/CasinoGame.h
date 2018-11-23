#include <string>
#include "stdafx.h"
using namespace std;

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

