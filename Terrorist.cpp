#include "Terrorist.h"

using namespace std;

Terrorist::Terrorist()
{
	IsBoombOn = 0;
	HaveBoomb = 0;
}	
		
Terrorist::Terrorist(const Terrorist& STerrorist)
{
	IsBoombOn = STerrorist.GetIsBoombOn();
	HaveBoomb = STerrorist.GetHaveBoomb();
	Id = STerrorist.GetId();
	Name = STerrorist.GetName();
	IdGun = STerrorist.GetIdGun();
	NameGun = STerrorist.GetNameGun();
	Health = STerrorist.GetHealth() ;
	Armor = STerrorist.GetArmor() ;
	IsAlive = STerrorist.GetAlive() ;
	IsAI = STerrorist.GetIsAI() ;
	Money = STerrorist.GetMoney() ;

	if (STerrorist.head) 
	{
       	GunIdStruct* current = STerrorist.head;
        do 
        {
            insert(current->id);
            current = current->next;
        } while (current != STerrorist.head);
    }
}
		
Terrorist::Terrorist(bool SIsBoombOn , bool SHaveBoomb , std::string SName , std::string SNameGun , std::string  SIdGun ,int SHealth  , int SArmor , bool SIsAlive , bool SIsAI , int SMoney)
{
	IsBoombOn = SIsBoombOn;
	HaveBoomb = SHaveBoomb;
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

Terrorist::~Terrorist(){}

void Terrorist::SetIsBoombOn(bool SIsBoombOn)
{
	IsBoombOn = SIsBoombOn;
}

void Terrorist::SetHaveBoomb(bool SHaveBoomb)
{
	HaveBoomb = SHaveBoomb;
}

bool Terrorist::GetIsBoombOn() const 
{
	return IsBoombOn;
}

bool Terrorist::GetHaveBoomb() const
{
	return HaveBoomb ;
}

bool Terrorist::operator==(Terrorist& STerrorist)
{
	if (IsBoombOn != STerrorist.GetIsBoombOn())
	{
		return 0;
	}
	if (HaveBoomb != STerrorist.GetHaveBoomb())
	{
		return 0;
	}
	return 1;
}

bool Terrorist::operator!=(Terrorist& STerrorist)
{
	if (IsBoombOn != STerrorist.GetIsBoombOn())
	{
		return 1;
	}
	if (HaveBoomb != STerrorist.GetHaveBoomb())
	{
		return 1;
	}
	return 0;
}
	
void Terrorist::operator=(const Terrorist& STerrorist)
{
	IsBoombOn = STerrorist.GetIsBoombOn();
	HaveBoomb = STerrorist.GetHaveBoomb();
}