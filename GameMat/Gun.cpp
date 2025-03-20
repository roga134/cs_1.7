#include <string>
#include "Gun.h"

using namespace std;

int Gun::AllGun = 0;

Gun::Gun()
{
	Ammo = 0;
	Price = 0;
	Id = GenerateGUID();
	GunName = static_cast<Name>(0);
	PowerAmmo = 0;

	AllGun++;
}

Gun::Gun(Gun& SGun)
{
	Ammo = SGun.GetAmmo();
	Price = SGun.GetPrice();
	Id = SGun.GetId();
	GunName = SGun.GunName;
	PowerAmmo = SGun.GetPowerAmmo();

	AllGun++;
}

Gun::Gun(int SAmmo , int SPrice , int SName , int SPowerAmmo)
{
	Ammo = SAmmo;
	Price = SPrice;
	Id = GenerateGUID();
	GunName = static_cast<Name>(SName);
	PowerAmmo = SPowerAmmo;

	AllGun++;
}

Gun::~Gun(){}

void Gun::SetAmmo(int SAmmo)
{
	Ammo = SAmmo;
}

void Gun::SetPrice(int SPrice)
{
	Price = SPrice;
}

void Gun::SetName(int SName)
{
	GunName = static_cast<Name>(SName);
}

void Gun::SetPowerAmmo(int SPowerAmmo)
{
	PowerAmmo = SPowerAmmo;
}

int Gun::GetAmmo() const
{
	return Ammo;
}

int Gun::GetPrice() const
{
	return Price;
}
		
string Gun::GetId() const
{
	return Id;
}

string Gun::GetName() const
{
	switch(GunName)
	{
		case ak47:
			return "AK-47"; 
		default:
			return "Unknown";
	}
}
		
int Gun::GetPowerAmmo() const
{
	return PowerAmmo;
}

int Gun::GetAllGun()
{
	return AllGun;
}

bool Gun::operator==(Gun& SGun)
{
	if (Ammo != SGun.GetAmmo())
	{
		return false;
	}
	if (Price != SGun.GetPrice())
	{
		return false;
	}
	if (GunName != SGun.GunName)
	{
		return false;
	}
	if (PowerAmmo != SGun.GetPowerAmmo())
	{
		return false;
	}
	return true;
}

bool Gun::operator!=(Gun& SGun)
{
	if (Ammo != SGun.GetAmmo())
	{
		return true;
	}
	if (Price != SGun.GetPrice())
	{
		return true;
	}
	if (GunName != SGun.GunName)
	{
		return true;
	}
	if (PowerAmmo != SGun.GetPowerAmmo())
	{
		return true;
	}
	return false;
}

void Gun::operator=(Gun& SGun)
{
	Ammo = SGun.GetAmmo();
	Price = SGun.GetPrice();
	Id = SGun.GetId();
	GunName = SGun.GunName;
	PowerAmmo = SGun.GetPowerAmmo();
}