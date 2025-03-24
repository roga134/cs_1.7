#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <unordered_map>
#include <memory>
#include "Guid.h"
#include "Gun.h"

struct GunIdStruct
{
	std::string id;
	GunIdStruct * next;
	GunIdStruct * prev;
};

class Player
{
	protected:
		std::string Id;
		std::string Name;
		std::string IdGun;
		std::string NameGun;
		int Health;
		int Armor;
		bool IsAlive;
		bool IsAI;
		GunIdStruct* head;
		int Money;
	public:
		Player();
		Player(const Player& SPlayer);
		Player(std::string SName , std::string SNameGun , std::string  SIdGun , int SHealth  , int SArmor , bool SIsAlive , bool SIsAI , int SMoney);
		~Player();

		void SetName(std::string SName);
		void SetNameGun(std::string SNameGun);
		void SetHealth(int SHealth);
		void SetArmor(int SArmor);
		void SetIsAlive(bool SIsAlive);
		void SetIsAI(bool SIsAI);
		void SetMoney(int SMoney);

		std::string GetId() const;
		std::string GetName() const;
		std::string GetIdGun() const;
		std::string GetNameGun() const;
		int GetHealth() const;
		int GetArmor() const;
		bool GetAlive() const;
		bool GetIsAI() const;
		int GetMoney() const;
		GunIdStruct* GetHead() { return head; }

		bool operator==(Player& SPlayer);
		bool operator!=(Player& SPlayer);
		Player& operator=(const Player& SPlayer); 

		void insert(std::string SId);
		void display();
		std::shared_ptr<Gun> GetGun(std::string gunId);
};
#endif