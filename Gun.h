#ifndef GUN_H
#define GUN_H
#include <string>

class Gun
{
	private:
		int Ammo;
		int Price;
		int Id;
		enum Name
		{
			ak47 = 0
		}GunName;
		int PowerAmmo;
		static int AllGun;
	public:	
		Gun();
		Gun(Gun& SGun);
		Gun(int SAmmo , int SPrice , int SId , int SName , int SPowerAmmo);
		~Gun();

		void SetAmmo(int SAmmo);
		void SetPrice(int SPrice);
		void SetId(int SId);
		void SetName(int SName);
		void SetPowerAmmo(int SPowerAmmo);

		int GetAmmo() const;
		int GetPrice() const;
		int GetId() const;
		std::string GetName() const;
		int GetPowerAmmo() const;
		int GetAllGun();

		bool operator==(Gun& SGun);
		bool operator!=(Gun& SGun);
		void operator=(Gun& SGun);
};
#endif