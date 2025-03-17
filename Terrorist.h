#ifndef TERRORIST_H
#define TERRORIST_H

#include <string>

class Terrorist 
{
	private:
		bool IsBoombOn;
		bool HaveBoomb;
	public:
		Terrorist();
		Terrorist(Terrorist& STerrorist);
		Terrorist(bool SIsBoombOn , bool SHaveBoomb);
		~Terrorist();

		void SetIsBoombOn(bool SIsBoombOn);
		void SetHaveBoomb(bool SHaveBoomb);

		bool GetIsBoombOn();
		bool GetHaveBoomb();

		bool operator==(Terrorist& STerrorist);
		bool operator!=(Terrorist& STerrorist);
		void operator=(Terrorist& STerrorist);
};

#endif