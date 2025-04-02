#include "ct.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

CT::CT()
{
	HaveKitDef = 0;
	IsBoombDef = 0;
}
		
CT::CT(const CT& SCT)
{
    if (SCT.GetHealth() < 0) 
	{
        throw std::invalid_argument("Health cannot be negative");
    }
    if (SCT.GetArmor() < 0) 
	{
        throw std::invalid_argument("Armor cannot be negative");
    }
    if (SCT.GetMoney() < 0) 
	{
        throw std::invalid_argument("Money cannot be negative");
    }

	HaveKitDef = SCT.GetHaveKitDef();
	IsBoombDef = SCT.GetIsBoombDef();
	Id = SCT.GetId();
	Name = SCT.GetName();
	IdGun = SCT.GetIdGun();
	NameGun = SCT.GetNameGun();
	Health = SCT.GetHealth() ;
	Armor = SCT.GetArmor() ;
	IsAlive = SCT.GetAlive() ;
	IsAI = SCT.GetIsAI() ;
	Money = SCT.GetMoney() ;

	if (SCT.head) 
	{
       	GunIdStruct* current = SCT.head;
        do 
        {
            insert(current->id);
            current = current->next;
        } while (current != SCT.head);
    }
	
}
		
CT::CT(bool SHaveKitDef, bool SIsBoombDef, std::string SName, std::string SNameGun, std::string SIdGun, int SHealth, int SArmor, bool SIsAlive, bool SIsAI, int SMoney)
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

    HaveKitDef = SHaveKitDef;
    IsBoombDef = SIsBoombDef;
    Id = GenerateGUID();
    Name = SName;
    IdGun = SIdGun;
    NameGun = SNameGun;
    Health = SHealth;
    Armor = SArmor;
    IsAlive = SIsAlive;
    IsAI = SIsAI;
    Money = SMoney;
}


CT::~CT() {}

void CT::SetHaveKitDef(bool SHaveKitDef)
{
	HaveKitDef = SHaveKitDef;
}
		
void CT::SetIsBoombDef(bool SIsBoombDef)
{
	IsBoombDef = SIsBoombDef;
}

bool CT::GetHaveKitDef() const
{
	return HaveKitDef;
}
	
bool CT::GetIsBoombDef() const
{
	return IsBoombDef;
}

bool CT::operator==(CT& SCT)
{
	if (IsBoombDef != SCT.GetIsBoombDef())
	{
		return 0;
	}
	if (HaveKitDef != SCT.GetHaveKitDef())
	{
		return 0;
	}
	return 1;
}

bool CT::operator!=(CT& SCT)
{
	if (IsBoombDef != SCT.GetIsBoombDef())
	{
		return 1;
	}
	if (HaveKitDef != SCT.GetHaveKitDef())
	{
		return 1;
	}
	return 0;
}

void CT::operator=(const CT& SCT)
{
	HaveKitDef = SCT.GetHaveKitDef();
	IsBoombDef = SCT.GetIsBoombDef();
	Id = SCT.GetId();
	Name = SCT.GetName();
	IdGun = SCT.GetIdGun();
	NameGun = SCT.GetNameGun();
	Health = SCT.GetHealth() ;
	Armor = SCT.GetArmor() ;
	IsAlive = SCT.GetAlive() ;
	IsAI = SCT.GetIsAI() ;
	Money = SCT.GetMoney() ;

	if (SCT.head) 
	{
       	GunIdStruct* current = SCT.head;
        do 
        {
            insert(current->id);
            current = current->next;
        } while (current != SCT.head);
    }

}