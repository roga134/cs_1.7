#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Guid.h"

class Player
{
	private:
		std::string Id;
		std::string Name;
		std::string IdGun;
		std::string NameGun;
		int Health;
		int Armor;
		bool IsAlive;
		bool IsAI;
		struct GunIdStruct;
		int Money;
	public:
		Player();
		Player(Player& SPlayer);
		Player(std::string SName , std::string SNameGun , int SHealth  , int SArmor , bool SIsAlive , bool SIsAI , int SMoney);
		~Player();

		void SetName(std::string SName);
		void SetNameGun(std::string SNameGun);
		void SetHealth(int SHealth);
		void SetArmor(int SArmor);
		void SetIsAlive(bool SIsAlive);
		void SetIsAI(bool SIsAI);
		void SetMoney(int SMoney);

		std::string GetId();
		std::string GetName();
		std::string GetIdGun();
		std::string GetNameGun();
		int GetHealth();
		int GetArmor();
		bool GetAlive();
		bool GetIsAI();
		int GetMoney();

		bool operator==(Player& SPlayer);
		bool operator!=(Player& SPlayer);
		void operator=(Player& SPlayer);
};
#endif