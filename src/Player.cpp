#include <string>
#include <iostream>
#include "Player.h"

using namespace std;


Player::Player()
{
	head = nullptr;
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
    if (SPlayer.GetHealth() < 0) 
    {
        throw std::invalid_argument("Health cannot be negative");
    }
    if (SPlayer.GetArmor() < 0) 
    {
        throw std::invalid_argument("Armor cannot be negative");
    }
    if (SPlayer.GetMoney() < 0) 
    {
        throw std::invalid_argument("Money cannot be negative");
    }

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

Player::Player(std::string SName , std::string SNameGun , string  SIdGun , int SHealth  , int SArmor , bool SIsAlive , bool SIsAI , int SMoney)
{
    if (SHealth < 0) 
    {
        throw std::invalid_argument("Health cannot be negative");
    }
    if (SArmor < 0) 
    {
        throw std::invalid_argument("Armor cannot be negative");
    }
    if (SMoney < 0) 
    {
        throw std::invalid_argument("Money cannot be negative");
    }

	head = nullptr;
	Id = GenerateGUID();
	Name = SName;
	IdGun = SIdGun;
	NameGun = SNameGun;
	Health = SHealth ;
	Armor = SArmor ;
	IsAlive = SIsAlive ;
	IsAI = SIsAI ;
	Money = SMoney ;
}

Player::~Player()
{}

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
	if (SHealth < 0) 
	{
        throw std::invalid_argument("Health cannot be negative");
    }
	Health = SHealth;
}

void Player::SetArmor(int SArmor)
{
	if (SArmor < 0) 
	{
        throw std::invalid_argument("Armor cannot be negative");
    }
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
	if (SMoney < 0) 
	{
        throw std::invalid_argument("Money cannot be negative");
    }
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

void Player::insert(string SId)
{
	GunIdStruct* newNode = new GunIdStruct{SId, nullptr, nullptr};
    if (!head) 
    {
        head = newNode;
        head->next = head;
        head->prev = head;
    } 
    else 
    {
        GunIdStruct* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }
}

void Player::display()
{
	int YourChoose;

    GunIdStruct* temp = head;

    if (temp == nullptr)
    {
    	cout << "the list is empty " << endl;
    	return ;
    }

    cout << "enter 1 to show next and 2 for show prev and 3 for exit : " << endl;

    while(YourChoose != 3)
    {
    	cout << temp->id << " ";
    	cin >> YourChoose;
    	if (YourChoose == 1 )
    	{
    		temp = temp->next;
    	}
    	if (YourChoose == 2)
    	{
    		temp = temp->prev;
    	}
    	if (YourChoose != 1 && YourChoose != 2 && YourChoose != 3)
    	{
    		system("clear");

    		cout << "its not correct please try again:" << endl;
    	}
    }
    cout << endl;
}

std::shared_ptr<Gun> Player::GetGun(std::string id) 
{
    GunIdStruct* current = head;
    while (current != nullptr) 
    {
        if (current->id == id) 
        {
            return gunDatabase[id];  
        }
        current = current->next;
    }
    return nullptr;  
}