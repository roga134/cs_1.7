#include <vector>
#include <string>
#include "Player.h"
class GameManager
{
	private:
		static GameManager* instance;
		std::vector<Player> PlayerCT;
		std::vector<Player> PlayerTR;
		std::string Name;
		bool IsTRWin;
	public:
		GameManager();
		GameManager(GameManager& ) = delete;
		GameManager(std::vector<Player> SPlayerCT , std::vector<Player> SPlayerTR , std::string SName , bool SIsTRWin);

		void SetPlayerTR(std::vector<Player> SPlayerTR);
		void SetPlayerCT(std::vector<Player> SPlayerCT);
		void SetName(std::string SName);
		void SetIsTRWin(bool SIsTRWin);

		const std::vector<Player>& GetPlayerCT();
		static GameManager* getInstance(); 
		const std::vector<Player>& GetPlayerTR();
		std::string GetName();
		bool GetIsTRWin();

		GameManager& operator=(GameManager&) = delete;
};