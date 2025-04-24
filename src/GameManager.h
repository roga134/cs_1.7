#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <vector>
#include <string>
#include "Player.h"
#include "Terrorist.h"
#include "ct.h"
class GameManager
{
	private:
		static GameManager* instance;
		GameManager(const GameManager& ) = delete;
		GameManager& operator=(const GameManager&) = delete;
		GameManager();
		std::vector<CT> PlayerCT;
		std::vector<Terrorist> PlayerTR;
		std::string Name;
		bool IsTRWin;
	public:
		GameManager(std::vector<CT> SPlayerCT , std::vector<Terrorist> SPlayerTR , std::string SName , bool SIsTRWin);

		void SetPlayerTR(std::vector<Terrorist> SPlayerTR);
		void SetPlayerCT(std::vector<CT> SPlayerCT);
		void SetName(std::string SName);
		void SetIsTRWin(bool SIsTRWin);

		const std::vector<CT>& GetPlayerCT();
		static GameManager& getInstance(); 
		const std::vector<Terrorist>& GetPlayerTR();
		std::string GetName();
		bool GetIsTRWin();

		void ResetGame();
};

#endif