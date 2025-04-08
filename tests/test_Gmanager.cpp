#include <gtest/gtest.h>
#include <vector>
#include "../src/GameManager.h"
#include "../src/ct.h"
#include "../src/Terrorist.h"
#include "../src/GameMap.h"

TEST(GmanagerTest, constructor) // testing constructor
{
	Terrorist Terrorist1(0 , 1 , "mahdy" , "M4" , "sfsd1" ,2000 , 0 , 1 , 0 , 100);
	Terrorist Terrorist2(0 , 0 , "ali" , "AK_47" , "asfre" ,2000 , 50 , 1 , 0 , 100);

	CT CT1(0 , 1 , "roga" , "M4A5" , "asfsdw" ,2000 , 0 , 1 , 0 , 200);
	CT CT2(0 , 1 , "crazy" , "MP5" , "1esaf43" ,2000 , 30 , 1 , 0 , 200);

	std::vector<CT> SPlayerCT;
	SPlayerCT.push_back(CT1);
	SPlayerCT.push_back(CT2);

	std::vector<Terrorist> SPlayerTR;
	SPlayerTR.push_back(Terrorist1);
	SPlayerTR.push_back(Terrorist2);

	GameMap gamemap;
    GameManager& gamemanager = GameManager::getInstance();
    gamemanager.SetName(gamemap.GetName());
    gamemanager.SetIsTRWin(1);
    gamemanager.SetPlayerTR(SPlayerTR);
    gamemanager.SetPlayerCT(SPlayerCT);
    EXPECT_EQ(gamemanager.GetName(), "map 0");
    EXPECT_EQ(gamemanager.GetIsTRWin(), 1);
}

TEST(GmanagerTest, single) // testing is single or not
{
	GameMap gamemap;
    GameManager& gamemanager = GameManager::getInstance();
    gamemanager.SetName(gamemap.GetName());
    gamemanager.SetIsTRWin(1);

    GameManager& gamemanager2 = GameManager::getInstance();
    gamemanager2.SetName("mammd");
    gamemanager2.SetIsTRWin(0);

    EXPECT_EQ(gamemanager2.GetName(), gamemanager.GetName());
    EXPECT_EQ(gamemanager2.GetIsTRWin(), gamemanager.GetIsTRWin());
}

/*
Running main() from ./googletest/src/gtest_main.cc
[==========] Running 2 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 2 tests from GmanagerTest
[ RUN      ] GmanagerTest.constructor
[       OK ] GmanagerTest.constructor (1 ms)
[ RUN      ] GmanagerTest.single
[       OK ] GmanagerTest.single (0 ms)
[----------] 2 tests from GmanagerTest (1 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test suite ran. (1 ms total)
[  PASSED  ] 2 tests.
*/

