#include <iostream>
#include <random>
#include <sstream>
#include <iomanip>
#include <string>
#include "Guid.h"

std::string GenerateGUID() 
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint32_t> dis32(0, 0xFFFFFFFF);
    std::uniform_int_distribution<uint16_t> dis16(0, 0xFFFF);
    
    std::stringstream ss;
    ss << std::hex << std::setfill('0')
       << std::setw(8) << dis32(gen) << "-"
       << std::setw(4) << dis16(gen) << "-"
       << std::setw(4) << dis16(gen) << "-"
       << std::setw(4) << dis16(gen) << "-"
       << std::setw(12) << dis32(gen) << dis16(gen);

    return ss.str();
}