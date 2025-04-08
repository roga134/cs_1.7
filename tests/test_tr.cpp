#include <gtest/gtest.h>
#include "../src/Terrorist.h"

TEST(TRTest, good_input) // for testing constructor  
{
    Terrorist terrorist(0, 1 , "Roga" , "AK_47" , "78f" , 100 , 60 , 1 , 0 , 50);
    EXPECT_EQ(terrorist.GetName(), "Roga");
    EXPECT_EQ(terrorist.GetIdGun(), "78f");
    EXPECT_EQ(terrorist.GetNameGun(), "AK_47");
    EXPECT_EQ(terrorist.GetHealth(), 100);
    EXPECT_EQ(terrorist.GetArmor(), 60);
    EXPECT_EQ(terrorist.GetAlive(), 1);
    EXPECT_EQ(terrorist.GetIsAI(), 0);
    EXPECT_EQ(terrorist.GetMoney(), 50);
}

TEST(TRTest, bad_Health) // for negetive input for health  
{
    EXPECT_THROW({Terrorist terrorist(1 , 0 , "Roga" , "AK_47" , "78f" , -1 , 10 , 1 , 0 , 50);}, std::invalid_argument);
}

TEST(TRTest, bad_armor) // for negetive input for armor 
{
    EXPECT_THROW({Terrorist terrorist(1 , 0 , "Roga" , "AK_47" , "78f" , 10 , -1 , 1 , 0 , 50);}, std::invalid_argument);
}

TEST(TRTest, bad_money) // for negetive input for money
{
    EXPECT_THROW({Terrorist terrorist(1 , 0 , "Roga" , "AK_47" , "78f" , 10 , 60 , 1 , 0 , -1);}, std::invalid_argument);
}

TEST(TRTest, sen_input) // for bad constructor
{
    Terrorist terrorist(0, 0 , " " , " " , " " , 0 , 0 , 0 , 0 , 0);
    EXPECT_EQ(terrorist.GetName(), " ");
    EXPECT_EQ(terrorist.GetIdGun(), " ");
    EXPECT_EQ(terrorist.GetNameGun(), " ");
    EXPECT_EQ(terrorist.GetHealth(), 0);
    EXPECT_EQ(terrorist.GetArmor(), 0);
    EXPECT_EQ(terrorist.GetAlive(), 0);
    EXPECT_EQ(terrorist.GetIsAI(), 0);
    EXPECT_EQ(terrorist.GetMoney(), 0);
}

TEST(TRTest, bool_is) // for booling of equaling two object
{
    Terrorist terrorist(0, 1 , "Roga" , "AK_47" , "78f" , 100 , 60 , 1 , 0 , 50);
    Terrorist terrorist2(1, 0 , "Roga" , "AK_47" , "78f" , 10 , 6 , 0 , 0 , 0);
    int true_bool = (terrorist == terrorist2);
    EXPECT_EQ(true_bool, 0);
}

TEST(TRTest, bool_is_not) // for not booling of equaling two object
{
    Terrorist terrorist(0, 1 , "Roga" , "AK_47" , "78f" , 100 , 60 , 1 , 0 , 50);
    Terrorist terrorist2(1, 0 , "Roga" , "AK_47" , "78f" , 10 , 6 , 0 , 0 , 0);
    int true_bool = (terrorist != terrorist2);
    EXPECT_EQ(true_bool, 1);
}

TEST(TRTest, equal) // for equal two object
{
    Terrorist terroristt(0, 1 , "Roga" , "AK_47" , "78f" , 100 , 60 , 1 , 0 , 50);
    Terrorist terrorist2(1, 0 , "Roga" , "AK_47" , "78f" , 10 , 6 , 0 , 0 , 0);
    terrorist2 = terroristt;
    EXPECT_EQ(terrorist2.GetHealth(), 100);
    EXPECT_EQ(terrorist2.GetArmor(), 60);
    EXPECT_EQ(terrorist2.GetAlive(), 1);
    EXPECT_EQ(terrorist2.GetIsAI(), 0);
    EXPECT_EQ(terrorist2.GetMoney(), 50);
}

TEST(TRTest, cu_good_input) // for copy object
{
    Terrorist terrorist2(0, 1 , "Roga" , "AK_47" , "78f" , 100 , 60 , 1 , 0 , 50);
    Terrorist terrorist(terrorist2);
    EXPECT_EQ(terrorist.GetName(), "Roga");
    EXPECT_EQ(terrorist.GetIdGun(), "78f");
    EXPECT_EQ(terrorist.GetNameGun(), "AK_47");
    EXPECT_EQ(terrorist.GetHealth(), 100);
    EXPECT_EQ(terrorist.GetArmor(), 60);
    EXPECT_EQ(terrorist.GetAlive(), 1);
    EXPECT_EQ(terrorist.GetIsAI(), 0);
    EXPECT_EQ(terrorist.GetMoney(), 50);
}

TEST(TRTest, bad_Health_get) // for negetive setting input for health
{
	Terrorist terrorist(1 , 0 , "Roga" , "AK_47" , "78f" , 100 , 10 , 1 , 0 , 50);
    EXPECT_THROW(terrorist.SetHealth(-1), std::invalid_argument);
}

TEST(TRTest, bad_armor_get) // for negetive setting input for armor
{
	Terrorist terrorist(1 , 0 , "Roga" , "AK_47" , "78f" , 100 , 10 , 1 , 0 , 50);
    EXPECT_THROW(terrorist.SetArmor(-1), std::invalid_argument);
}

TEST(TRTest, bad_money_get) // for negetive setting input for money
{
	Terrorist terrorist(1 , 0 , "Roga" , "AK_47" , "78f" , 100 , 10 , 1 , 0 , 50);
    EXPECT_THROW(terrorist.SetMoney(-1), std::invalid_argument);
}

/*
Running main() from ./googletest/src/gtest_main.cc
[==========] Running 12 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 12 tests from TRTest
[ RUN      ] TRTest.good_input
[       OK ] TRTest.good_input (0 ms)
[ RUN      ] TRTest.bad_Health
[       OK ] TRTest.bad_Health (0 ms)
[ RUN      ] TRTest.bad_armor
[       OK ] TRTest.bad_armor (0 ms)
[ RUN      ] TRTest.bad_money
[       OK ] TRTest.bad_money (0 ms)
[ RUN      ] TRTest.sen_input
[       OK ] TRTest.sen_input (0 ms)
[ RUN      ] TRTest.bool_is
[       OK ] TRTest.bool_is (0 ms)
[ RUN      ] TRTest.bool_is_not
[       OK ] TRTest.bool_is_not (0 ms)
[ RUN      ] TRTest.equal
[       OK ] TRTest.equal (0 ms)
[ RUN      ] TRTest.cu_good_input
[       OK ] TRTest.cu_good_input (0 ms)
[ RUN      ] TRTest.bad_Health_get
[       OK ] TRTest.bad_Health_get (0 ms)
[ RUN      ] TRTest.bad_armor_get
[       OK ] TRTest.bad_armor_get (0 ms)
[ RUN      ] TRTest.bad_money_get
[       OK ] TRTest.bad_money_get (0 ms)
[----------] 12 tests from TRTest (1 ms total)

[----------] Global test environment tear-down
[==========] 12 tests from 1 test suite ran. (1 ms total)
[  PASSED  ] 12 tests.
*/