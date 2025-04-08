#include <string>
#include "GameMap.h"

using namespace std;

GameMap::GameMap()
{
	Name = "map 0";
	NameMaker = "roga";
	IsNight = 0; 
}

GameMap::GameMap(GameMap& SGameMap)
{
	Name = SGameMap.GetName();
	NameMaker = SGameMap.GetNameMaker();
	IsNight = SGameMap.GetIsNight();
}

GameMap::GameMap(string SName ,string SNameMaker ,bool SIsNight)
{
	if (SName == " " || SName == "")
	{
		Name = "map 0";
	}
	else
	{
		Name = SName;
	}
	if (SNameMaker == " " || SNameMaker == "")
	{
	 	NameMaker = "roga";
	} 
	else
	{
		NameMaker = SNameMaker;
	}
	IsNight = SIsNight;
}

GameMap::~GameMap(){}

void GameMap::SetName(string SName)
{
	if (SName == " " || SName == "")
	{
		Name = "map 0";
	}
	else
	{
		Name = SName;
	}
}
		
void GameMap::SetNameMaker(string SNameMaker)
{
	if (SNameMaker == " " || SNameMaker == "")
	{
	 	NameMaker = "roga";
	} 
	else
	{
		NameMaker = SNameMaker;
	}
}
		
void GameMap::SetIsNight(bool SIsNight)
{
	IsNight = SIsNight;
}

string GameMap::GetName()
{
	return Name;
}
		
string GameMap::GetNameMaker()
{
	return NameMaker;
}

bool GameMap::GetIsNight()
{
	return IsNight;
}

bool GameMap::operator==(GameMap& SGameMap)
{
	if (Name != SGameMap.GetName())
	{
		return 0;
	}
	if (NameMaker != SGameMap.GetNameMaker())
	{
		return 0 ;
	}
	if (IsNight != SGameMap.GetIsNight())
	{
		return 0;
	}
	return 1;
}

bool GameMap::operator!=(GameMap& SGameMap)
{
	if (Name != SGameMap.GetName())
	{
		return 1;
	}
	if (NameMaker != SGameMap.GetNameMaker())
	{
		return 1 ;
	}
	if (IsNight != SGameMap.GetIsNight())
	{
		return 1;
	}
	return 0;
}

void GameMap::operator=(GameMap& SGameMap)
{
	Name = SGameMap.GetName();
	NameMaker = SGameMap.GetNameMaker();
	IsNight = SGameMap.GetIsNight();
}