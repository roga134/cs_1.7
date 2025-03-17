#include <string>

class GameMap
{
	private:
		std::string Name;
		std::string NameMaker;
		bool IsNight;
	public:
		GameMap();
		GameMap(GameMap& SGameMap);
		GameMap(std::string SName ,std::string SNameMaker ,bool SIsNight);
		~GameMap();

		void SetName(std::string SName);
		void SetNameMaker(std::string SNameMaker);
		void SetIsNight(bool SIsNight);

		std::string GetName();
		std::string GetNameMaker();
		bool GetIsNight();

		bool operator==(GameMap& SGameMap);
		bool operator!=(GameMap& SGameMap);
		void operator=(GameMap& SGameMap);
};