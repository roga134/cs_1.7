#include <iostream>
#include "Gun.h"
#include "Player.h"

using namespace std;

int main()
{
	Player Player1;
	Player Player2;

	Player1.SetName("asd");
	Player1.SetNameGun("sdf");
	Player1.SetHealth(56);
	Player1.SetArmor(23);
	Player1.SetIsAlive(1);
	Player1.SetIsAI(1);
	Player1.SetMoney(12);

	Player2.SetName("asda");
	Player2.SetNameGun("sdfaq");
	Player2.SetHealth(561);
	Player2.SetArmor(232);
	Player2.SetIsAlive(13);
	Player2.SetIsAI(14);
	Player2.SetMoney(125);

	return 0;
}