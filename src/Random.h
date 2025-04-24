#ifndef RANDOM_H
#define RANDOM_H

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <unordered_map>
#include <memory>
#include <fstream>
#include <sstream>

#include "Gun.h"
#include "Player.h"
#include "Terrorist.h"
#include "ct.h"
#include "GameMap.h"
#include "LogIU.h"
#include "MainMenu.h"

class Random
{
private:
    std::shared_ptr<Gun> Gun1;
    std::string NameGun;
    std::string IdGun;
    int price ;
    std::string Name[20] = {
    "Ali", "Reza", "Sara", "Omid", "Nina", "John", "Lara", "Arash", "Mina", "David",
    "Sina", "Maya", "Nima", "Sahar", "Amir", "Yas", "Zahra", "Hossein", "Leila", "Bob"};

public:
    Random(int& MyMoney);
    
    std::string GetName() const;
    std::string GetGunName() const;
    std::string GetGunId() const;
};

#endif