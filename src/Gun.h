#ifndef GUN_H
#define GUN_H

#include <string>
#include <unordered_map>
#include <memory>
#include "Guid.h"

class Gun;

extern std::unordered_map<std::string, std::shared_ptr<Gun>> gunDatabase;  

class Gun
{
	private:
		int Ammo;
		int Price;
		std::string Id;
		enum Name
		{
			ak47 = 0,
			m4 = 1,
			mwp = 2,
			knife = 3
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

		bool operator==(const Gun& SGun);
		bool operator!=(const Gun& SGun);
		void operator=(const Gun& SGun);
};

void RegisterGun(std::shared_ptr<Gun> gun);

#endif