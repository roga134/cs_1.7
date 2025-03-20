#include <string>
#include "Player.h"

using namespace std;

struct Player::GunIdStruct
{
	GunIdStruct * next;
	GunIdStruct * prev;
};

Player::Player()
{
	Id = GenerateGUID();
	Name = "mmad";
	IdGun = GenerateGUID();
	NameGun = "mmad gun";
	Health = 0 ;
	Armor = 0 ;
	IsAlive = 0 ;
	IsAI = 0 ;
	Money = 0 ;
}

Player::Player(const Player& SPlayer)
{
	Id = SPlayer.GetId();
	Name = SPlayer.GetName();
	IdGun = SPlayer.GetIdGun();
	NameGun = SPlayer.GetNameGun();
	Health = SPlayer.GetHealth() ;
	Armor = SPlayer.GetArmor() ;
	IsAlive = SPlayer.GetAlive() ;
	IsAI = SPlayer.GetIsAI() ;
	Money = SPlayer.GetMoney() ;
}

Player::Player(std::string SName , std::string SNameGun , int SHealth  , int SArmor , bool SIsAlive , bool SIsAI , int SMoney)
{
	Id = GenerateGUID();
	Name = SName;
	IdGun = GenerateGUID();
	NameGun = SNameGun;
	Health = SHealth ;
	Armor = SArmor ;
	IsAlive = SIsAlive ;
	IsAI = SIsAI ;
	Money = SMoney ;
}

Player::~Player(){}

void Player::SetName(std::string SName)
{
	Name = SName;
}

void Player::SetNameGun(std::string SNameGun)
{
	NameGun = SNameGun;
}

void Player::SetHealth(int SHealth)
{
	Health = SHealth;
}

void Player::SetArmor(int SArmor)
{
	Armor = SArmor;
}

void Player::SetIsAlive(bool SIsAlive)
{
	IsAlive = SIsAlive;
}
		
void Player::SetIsAI(bool SIsAI)
{
	IsAI = SIsAI;
}
		
void Player::SetMoney(int SMoney)
{
	Money = SMoney;
}

std::string Player::GetId() const
{
	return Id;
}

std::string Player::GetName() const
{
	return Name;
}
		
std::string Player::GetIdGun() const
{
	return IdGun;
}
		
std::string Player::GetNameGun() const
{
	return NameGun;
}
		
int Player::GetHealth() const
{
	return Health;
}
		
int Player::GetArmor() const
{
	return Armor;
}
		
bool Player::GetAlive() const
{
	return IsAlive;
}

bool Player::GetIsAI() const
{
	return IsAI;
}
		
int Player::GetMoney() const
{
	return Money;
}

bool Player::operator==(Player& SPlayer)
{
	if (Name != SPlayer.GetName())
	{
		return 0 ;
	}
	if (NameGun != SPlayer.GetNameGun())
	{
		return 0 ;
	}
	if (Health != SPlayer.GetHealth())
	{
		return 0 ;
	}
	if (Armor != SPlayer.GetArmor())
	{
		return 0 ;
	}
	if (IsAlive != SPlayer.GetAlive())
	{
		return 0;
	}
	if (IsAI != SPlayer.GetIsAI())
	{
		return 0;
	}
	if (Money != SPlayer.GetMoney())
	{
		return 0;
	}
	return 1;
}

bool Player::operator!=(Player& SPlayer)
{
	if (Name != SPlayer.GetName())
	{
		return 1 ;
	}
	if (NameGun != SPlayer.GetNameGun())
	{
		return 1 ;
	}
	if (Health != SPlayer.GetHealth())
	{
		return 1 ;
	}
	if (Armor != SPlayer.GetArmor())
	{
		return 1 ;
	}
	if (IsAlive != SPlayer.GetAlive())
	{
		return 1;
	}
	if (IsAI != SPlayer.GetIsAI())
	{
		return 1;
	}
	if (Money != SPlayer.GetMoney())
	{
		return 1;
	}
	return 0;
}
		
Player& Player::operator=(const Player& SPlayer) 
{
	if (this != &SPlayer) 
    {
        Id = SPlayer.GetId();
        Name = SPlayer.GetName();
        IdGun = SPlayer.GetIdGun();
        NameGun = SPlayer.GetNameGun();
        Health = SPlayer.GetHealth();
        Armor = SPlayer.GetArmor();
        IsAlive = SPlayer.GetAlive();
        IsAI = SPlayer.GetIsAI();
        Money = SPlayer.GetMoney();
    }
    return *this;
}