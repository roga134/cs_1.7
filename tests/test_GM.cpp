#include <gtest/gtest.h>
#include "../src/GameMap.h"

TEST(GMTest, constructor) // testing defualt constructor
{
    GameMap gamemap;
    EXPECT_EQ(gamemap.GetName(), "map 0");
    EXPECT_EQ(gamemap.GetNameMaker(), "roga");
    EXPECT_EQ(gamemap.GetIsNight(), 0);
}

TEST(GMTest, good_constructor) // testing constructor with good input
{
    GameMap gamemap("Dust 2" , "Mahdy" , 1);
    EXPECT_EQ(gamemap.GetName(), "Dust 2");
    EXPECT_EQ(gamemap.GetNameMaker(), "Mahdy");
    EXPECT_EQ(gamemap.GetIsNight(), 1);
}

TEST(GMTest, cp_constructor) // testing copy two object 
{
    GameMap gamemap2("Dust 2" , "Mahdy" , 1);
    GameMap gamemap(gamemap2);
    EXPECT_EQ(gamemap.GetName(), "Dust 2");
    EXPECT_EQ(gamemap.GetNameMaker(), "Mahdy");
    EXPECT_EQ(gamemap.GetIsNight(), 1);
}

TEST(GMTest, bad_constructor) // testing constructor with bad input
{
    GameMap gamemap(" " , " " , 2);
    EXPECT_EQ(gamemap.GetName(), "map 0");
    EXPECT_EQ(gamemap.GetNameMaker(), "roga");
    EXPECT_EQ(gamemap.GetIsNight(), 1);
}

TEST(GMTest, bad_setter_name) // testing bad input for setter for name
{
    GameMap gamemap("Dust 2" , "Mahdy" , 1);
    gamemap.SetName(" ");
    EXPECT_EQ(gamemap.GetName(), "map 0");
}

TEST(GMTest, bad_setter_mname) // testing bad input for setter for maker name
{
    GameMap gamemap("Dust 2" , "Mahdy" , 1);
    gamemap.SetNameMaker(" ");
    EXPECT_EQ(gamemap.GetNameMaker(), "roga");
}

TEST(GMTest, is_bool) // testing bool of equal two object
{
    GameMap gamemap("Dust 2" , "Mahdy" , 1);
    GameMap gamemap2("Dust 2" , "Mahdy1" , 1);
    int is_true = (gamemap == gamemap2);
    EXPECT_EQ(is_true, 0);
}

TEST(GMTest, is_not_bool) // testing bool of not equal two object
{
    GameMap gamemap("Dust 2" , "Mahdy" , 1);
    GameMap gamemap2("Dust 2" , "Mahdy1" , 1);
    int is_true = (gamemap != gamemap2);
    EXPECT_EQ(is_true, 1);
}

TEST(GMTest, equaling) // testing equal two object
{
    GameMap gamemap(" " , " " , 2);
    GameMap gamemap2("Dust 2" , "Mahdy" , 1);
    gamemap = gamemap2;
    EXPECT_EQ(gamemap.GetName(), "Dust 2");
    EXPECT_EQ(gamemap.GetNameMaker(), "Mahdy");
    EXPECT_EQ(gamemap.GetIsNight(), 1);
}

/*
Running main() from ./googletest/src/gtest_main.cc
[==========] Running 9 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 9 tests from GMTest
[ RUN      ] GMTest.constructor
[       OK ] GMTest.constructor (0 ms)
[ RUN      ] GMTest.good_constructor
[       OK ] GMTest.good_constructor (0 ms)
[ RUN      ] GMTest.cp_constructor
[       OK ] GMTest.cp_constructor (0 ms)
[ RUN      ] GMTest.bad_constructor
[       OK ] GMTest.bad_constructor (0 ms)
[ RUN      ] GMTest.bad_setter_name
[       OK ] GMTest.bad_setter_name (0 ms)
[ RUN      ] GMTest.bad_setter_mname
[       OK ] GMTest.bad_setter_mname (0 ms)
[ RUN      ] GMTest.is_bool
[       OK ] GMTest.is_bool (0 ms)
[ RUN      ] GMTest.is_not_bool
[       OK ] GMTest.is_not_bool (0 ms)
[ RUN      ] GMTest.equaling
[       OK ] GMTest.equaling (0 ms)
[----------] 9 tests from GMTest (0 ms total)

[----------] Global test environment tear-down
[==========] 9 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 9 tests.
*/