#ifndef MAINMENU_H
#define MAINMENU_H

#include "LogIU.h"
#include "Terrorist.h"
#include "ct.h"
#include "GameMap.h"
#include <string>
#include <vector>

struct InfoSetting  
{
    GameMap Map;
    int NumCT;
    int NumTR;
    int AMoney;
};

void StartGame(LogIU& YourLogIU , InfoSetting& SInfoSetting , std::vector<CT> SPlayerCT , std::vector<Terrorist> SPlayerTR , int your_team);
void Info(LogIU& YourLogIU);
void Setting(InfoSetting* SInfoSetting);

#endif