#ifndef GUN_H
#define GUN_H
#include <string>
#include "Guid.h"

class Gun
{
	private:
		int Ammo;
		int Price;
		std::string Id;
		enum Name
		{
			ak47 = 0
		}GunName;
		int PowerAmmo;
		static int AllGun;
	public:	
		Gun();
		Gun(Gun& SGun);
		Gun(int SAmmo , int SPrice , int SName , int SPowerAmmo);
		~Gun();

		void SetAmmo(int SAmmo);
		void SetPrice(int SPrice);
		void SetName(int SName);
		void SetPowerAmmo(int SPowerAmmo);

		int GetAmmo() const;
		int GetPrice() const;
		std::string GetId() const;
		std::string GetName() const;
		int GetPowerAmmo() const;
		int GetAllGun();

		bool operator==(Gun& SGun);
		bool operator!=(Gun& SGun);
		void operator=(Gun& SGun);
};
#endif