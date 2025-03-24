#ifndef CT_H
#define CT_H

#include "Player.h"

class CT : public Player
{
	private:
		bool HaveKitDef;
		bool IsBoombDef;
	public:
		CT();
		CT(const CT& SCT);
		CT(bool SHaveKitDef , bool SIsBoombDef , std::string SName , std::string SNameGun , std::string  SIdGun ,int SHealth  , int SArmor , bool SIsAlive , bool SIsAI , int SMoney);
		~CT();

		void SetHaveKitDef(bool SHaveKitDef);
		void SetIsBoombDef(bool SIsBoombDef);

		bool GetHaveKitDef() const;
		bool GetIsBoombDef() const;

		bool operator==(CT& SCT);
		bool operator!=(CT& SCT);
		void operator=(const CT& SCT);
};
#endif