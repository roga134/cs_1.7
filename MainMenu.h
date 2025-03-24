#ifndef MAINMENU_H
#define MAINMENU_H

#include "LogIU.h"
#include "Terrorist.h"
#include "ct.h"
#include <string>
#include <vector>

struct InfoSetting  
{
    std::string MapName;
    int NumCT;
    int NumTR;
    int AMoney;
};

void StartGame(LogIU& YourLogIU , InfoSetting& SInfoSetting , std::vector<CT> SPlayerCT , std::vector<Terrorist> SPlayerTR);
void Info(LogIU& YourLogIU);
void Setting(InfoSetting* SInfoSetting);

#endif