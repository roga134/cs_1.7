#include "Random.h"
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

Random::Random(int& MyMoney)
{

	Gun1 = std::make_shared<Gun>((rand() % 5) + 2, 100, rand() % 4, (rand() % 10) + 1);
    RegisterGun(Gun1);
    gunDatabase[Gun1->GetId()] = Gun1;

    NameGun = Gun1->GetName();
    IdGun = Gun1->GetId();
    if (Gun1->GetName() == "AK-47" || Gun1->GetName() == "M4")
    {
    	price = 200;
    }
    else if (Gun1->GetName() == "MWP")
    {
    	price = 300;
    }
    else if (Gun1->GetName() == "knife")
    {
    	price = 0;
    }

    if (price > MyMoney)
    {
    	Gun1->SetAmmo(0);
    	Gun1->SetPowerAmmo(0);
    	Gun1->SetName(3);
    }
    else 
    {
    	MyMoney -= price;
    }
}

std::string Random::GetName() const
{
	return Name[rand() % 10];
}

std::string Random::GetGunName() const
{
	return NameGun;
}
		
std::string Random::GetGunId() const
{
	return IdGun;
}