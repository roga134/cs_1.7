#include "Terrorist.h"

using namespace std;

Terrorist::Terrorist()
{
	IsBoombOn = 0;
	HaveBoomb = 0;
}	
		
Terrorist::Terrorist(Terrorist& STerrorist)
{
	IsBoombOn = STerrorist.GetIsBoombOn();
	HaveBoomb = STerrorist.GetHaveBoomb();
}
		
Terrorist::Terrorist(bool SIsBoombOn , bool SHaveBoomb)
{
	IsBoombOn = SIsBoombOn;
	HaveBoomb = SHaveBoomb;
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

bool Terrorist::GetIsBoombOn()
{
	return IsBoombOn;
}

bool Terrorist::GetHaveBoomb()
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
	
void Terrorist::operator=(Terrorist& STerrorist)
{
	IsBoombOn = STerrorist.GetIsBoombOn();
	HaveBoomb = STerrorist.GetHaveBoomb();
}