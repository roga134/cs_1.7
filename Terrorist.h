#ifndef TERRORIST_H
#define TERRORIST_H

#include <string>
#include "Player.h"

class Terrorist : public Player
{
	private:
		bool IsBoombOn;
		bool HaveBoomb;
	public:
		Terrorist();
		Terrorist(const Terrorist& STerrorist);
		Terrorist(bool SIsBoombOn , bool SHaveBoomb , std::string SName , std::string SNameGun , std::string  SIdGun ,int SHealth  , int SArmor , bool SIsAlive , bool SIsAI , int SMoney);
		~Terrorist();

		void SetIsBoombOn(bool SIsBoombOn);
		void SetHaveBoomb(bool SHaveBoomb);

		bool GetIsBoombOn() const;
		bool GetHaveBoomb() const;

		bool operator==(Terrorist& STerrorist);
		bool operator!=(Terrorist& STerrorist);
		void operator=(const Terrorist& STerrorist);
};

#endif