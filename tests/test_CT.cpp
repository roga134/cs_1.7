#include <gtest/gtest.h>
#include "../src/ct.h"

TEST(CTTest, good_input) 
{
    CT ct(0, 1 , "Roga" , "AK_47" , "78f" , 100 , 60 , 1 , 0 , 50);
    EXPECT_EQ(ct.GetName(), "Roga");
    EXPECT_EQ(ct.GetIdGun(), "78f");
    EXPECT_EQ(ct.GetNameGun(), "AK_47");
    EXPECT_EQ(ct.GetHealth(), 100);
    EXPECT_EQ(ct.GetArmor(), 60);
    EXPECT_EQ(ct.GetAlive(), 1);
    EXPECT_EQ(ct.GetIsAI(), 0);
    EXPECT_EQ(ct.GetMoney(), 50);
}

TEST(CTTest, bad_Health) 
{
    EXPECT_THROW({CT ct(1 , 0 , "Roga" , "AK_47" , "78f" , -1 , 10 , 1 , 0 , 50);}, std::invalid_argument);
}

TEST(CTTest, bad_armor) 
{
    EXPECT_THROW({CT ct(1 , 0 , "Roga" , "AK_47" , "78f" , 10 , -1 , 1 , 0 , 50);}, std::invalid_argument);
}

TEST(CTTest, bad_money) 
{
    EXPECT_THROW({CT ct(1 , 0 , "Roga" , "AK_47" , "78f" , 10 , 60 , 1 , 0 , -1);}, std::invalid_argument);
}

TEST(CTTest, sen_input) 
{
    CT ct(0, 0 , " " , " " , " " , 0 , 0 , 0 , 0 , 0);
    EXPECT_EQ(ct.GetName(), " ");
    EXPECT_EQ(ct.GetIdGun(), " ");
    EXPECT_EQ(ct.GetNameGun(), " ");
    EXPECT_EQ(ct.GetHealth(), 0);
    EXPECT_EQ(ct.GetArmor(), 0);
    EXPECT_EQ(ct.GetAlive(), 0);
    EXPECT_EQ(ct.GetIsAI(), 0);
    EXPECT_EQ(ct.GetMoney(), 0);
}

TEST(CTTest, bool_is) 
{
    CT ct(0, 1 , "Roga" , "AK_47" , "78f" , 100 , 60 , 1 , 0 , 50);
    CT ct2(1, 0 , "Roga" , "AK_47" , "78f" , 10 , 6 , 0 , 0 , 0);
    int true_bool = (ct == ct2);
    EXPECT_EQ(true_bool, 0);
}

TEST(CTTest, bool_is_not) 
{
    CT ct(0, 1 , "Roga" , "AK_47" , "78f" , 100 , 60 , 1 , 0 , 50);
    CT ct2(1, 0 , "Roga" , "AK_47" , "78f" , 10 , 6 , 0 , 0 , 0);
    int true_bool = (ct != ct2);
    EXPECT_EQ(true_bool, 1);
}

TEST(CTTest, equal) 
{
    CT ct(0, 1 , "Roga" , "AK_47" , "78f" , 100 , 60 , 1 , 0 , 50);
    CT ct2(1, 0 , "Roga" , "AK_47" , "78f" , 10 , 6 , 0 , 0 , 0);
    ct2 = ct;
    EXPECT_EQ(ct2.GetHealth(), 100);
    EXPECT_EQ(ct2.GetArmor(), 60);
    EXPECT_EQ(ct2.GetAlive(), 1);
    EXPECT_EQ(ct2.GetIsAI(), 0);
    EXPECT_EQ(ct2.GetMoney(), 50);
}

TEST(CTTest, cu_good_input) 
{
    CT ct2(0, 1 , "Roga" , "AK_47" , "78f" , 100 , 60 , 1 , 0 , 50);
    CT ct(ct2);
    EXPECT_EQ(ct.GetName(), "Roga");
    EXPECT_EQ(ct.GetIdGun(), "78f");
    EXPECT_EQ(ct.GetNameGun(), "AK_47");
    EXPECT_EQ(ct.GetHealth(), 100);
    EXPECT_EQ(ct.GetArmor(), 60);
    EXPECT_EQ(ct.GetAlive(), 1);
    EXPECT_EQ(ct.GetIsAI(), 0);
    EXPECT_EQ(ct.GetMoney(), 50);
}

TEST(CTTest, bad_Health_get) 
{
	CT ct(1 , 0 , "Roga" , "AK_47" , "78f" , 100 , 10 , 1 , 0 , 50);
    EXPECT_THROW(ct.SetHealth(-1), std::invalid_argument);
}

TEST(CTTest, bad_armor_get) 
{
	CT ct(1 , 0 , "Roga" , "AK_47" , "78f" , 100 , 10 , 1 , 0 , 50);
    EXPECT_THROW(ct.SetArmor(-1), std::invalid_argument);
}

TEST(CTTest, bad_money_get) 
{
	CT ct(1 , 0 , "Roga" , "AK_47" , "78f" , 100 , 10 , 1 , 0 , 50);
    EXPECT_THROW(ct.SetMoney(-1), std::invalid_argument);
}
/*
[==========] Running 12 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 12 tests from CTTest
[ RUN      ] CTTest.good_input
[       OK ] CTTest.good_input (0 ms)
[ RUN      ] CTTest.bad_Health
[       OK ] CTTest.bad_Health (0 ms)
[ RUN      ] CTTest.bad_armor
[       OK ] CTTest.bad_armor (0 ms)
[ RUN      ] CTTest.bad_money
[       OK ] CTTest.bad_money (0 ms)
[ RUN      ] CTTest.sen_input
[       OK ] CTTest.sen_input (0 ms)
[ RUN      ] CTTest.bool_is
[       OK ] CTTest.bool_is (0 ms)
[ RUN      ] CTTest.bool_is_not
[       OK ] CTTest.bool_is_not (0 ms)
[ RUN      ] CTTest.equal
[       OK ] CTTest.equal (0 ms)
[ RUN      ] CTTest.cu_good_input
[       OK ] CTTest.cu_good_input (0 ms)
[ RUN      ] CTTest.bad_Health_get
[       OK ] CTTest.bad_Health_get (0 ms)
[ RUN      ] CTTest.bad_armor_get
[       OK ] CTTest.bad_armor_get (0 ms)
[ RUN      ] CTTest.bad_money_get
[       OK ] CTTest.bad_money_get (0 ms)
[----------] 12 tests from CTTest (1 ms total)

[----------] Global test environment tear-down
[==========] 12 tests from 1 test suite ran. (1 ms total)
[  PASSED  ] 12 tests.
*/