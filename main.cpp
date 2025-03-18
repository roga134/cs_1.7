#include <iostream>
#include <vector>
#include "Gun.h"
#include "Player.h"
#include "Terrorist.h"
#include "ct.h"
#include "GameMap.h"
#include "GameManager.h"

using namespace std;

int main()
{	
	Player Player1;

	Player1.SetName("asdas");

	vector<Player> v;
	v.push_back(Player1);

	GameManager* GameManager1 = GameManager::getInstance();
	GameManager* GameManager2 = GameManager::getInstance();

	GameManager1->SetPlayerCT(v);

	cout << (GameManager2->GetPlayerCT())[0].GetName() << endl;

	return 0;
}