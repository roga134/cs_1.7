#include <vector>
#include <string>
#include "GameManager.h"

using namespace std;
	
GameManager* GameManager::instance = nullptr;

GameManager& GameManager::getInstance()
{
    if (instance == nullptr)
    { 
        instance = new GameManager();
    }
    return *instance;
}

GameManager::GameManager()
{
	PlayerCT = {};
	PlayerTR = {};
	IsTRWin = 0 ;
	Name = "map 0";
}

GameManager::GameManager(std::vector<CT> SPlayerCT , std::vector<Terrorist> SPlayerTR , std::string SName , bool SIsTRWin)
{
	PlayerCT = SPlayerCT;
    PlayerTR = SPlayerTR;
	IsTRWin = SIsTRWin ;
	Name = SName;
}

void GameManager::SetPlayerTR(std::vector<Terrorist> SPlayerTR)
{
	PlayerTR = SPlayerTR;
}

void GameManager::SetPlayerCT(std::vector<CT> SPlayerCT)
{
	PlayerCT = SPlayerCT;
}

void GameManager::SetName(std::string SName)
{
	Name = SName;
}
		
void GameManager::SetIsTRWin(bool SIsTRWin)
{
	IsTRWin = SIsTRWin;
}

const std::vector<CT>& GameManager::GetPlayerCT()
{
	return PlayerCT;
}

const std::vector<Terrorist>& GameManager::GetPlayerTR()
{
	return PlayerTR;
}

std::string GameManager::GetName()
{
	return Name;
}
		
bool GameManager::GetIsTRWin()
{
	return IsTRWin;
}