#include <gtest/gtest.h>
#include "../src/Terrorist.h"

TEST(TRTest, good_input) 
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
/*
TEST(TRTest, bad_Health) 
{
    EXPECT_THROW({Terrorist terrorist(1 , 0 , "Roga" , "AK_47" , "78f" , -1 , 10 , 1 , 0 , 50);}, std::invalid_argument);
}

TEST(TRTest, bad_armor) 
{
    EXPECT_THROW({Terrorist terrorist(1 , 0 , "Roga" , "AK_47" , "78f" , 10 , -1 , 1 , 0 , 50);}, std::invalid_argument);
}

TEST(TRTest, bad_money) 
{
    EXPECT_THROW({Terrorist terrorist(1 , 0 , "Roga" , "AK_47" , "78f" , 10 , 60 , 1 , 0 , -1);}, std::invalid_argument);
}

TEST(TRTest, sen_input) 
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

TEST(TRTest, bool_is) 
{
    Terrorist terrorist(0, 1 , "Roga" , "AK_47" , "78f" , 100 , 60 , 1 , 0 , 50);
    Terrorist terrorist2(1, 0 , "Roga" , "AK_47" , "78f" , 10 , 6 , 0 , 0 , 0);
    int true_bool = (terrorist == terrorist2);
    EXPECT_EQ(true_bool, 0);
}

TEST(TRTest, bool_is_not) 
{
    Terrorist terrorist(0, 1 , "Roga" , "AK_47" , "78f" , 100 , 60 , 1 , 0 , 50);
    Terrorist terrorist2(1, 0 , "Roga" , "AK_47" , "78f" , 10 , 6 , 0 , 0 , 0);
    int true_bool = (terrorist != terrorist2);
    EXPECT_EQ(true_bool, 1);
}

TEST(TRTest, equal) 
{
    Terrorist terroristt(0, 1 , "Roga" , "AK_47" , "78f" , 100 , 60 , 1 , 0 , 50);
    Terrorist terrorist2(1, 0 , "Roga" , "AK_47" , "78f" , 10 , 6 , 0 , 0 , 0);
    terrorist2 = terrorist;
    EXPECT_EQ(terrorist2.GetHealth(), 100);
    EXPECT_EQ(terrorist2.GetArmor(), 60);
    EXPECT_EQ(terrorist2.GetAlive(), 1);
    EXPECT_EQ(terrorist2.GetIsAI(), 0);
    EXPECT_EQ(terrorist2.GetMoney(), 50);
}

TEST(TRTest, cu_good_input) 
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

TEST(TRTest, bad_Health_get) 
{
	Terrorist terrorist(1 , 0 , "Roga" , "AK_47" , "78f" , 100 , 10 , 1 , 0 , 50);
    EXPECT_THROW(terrorist.SetHealth(-1), std::invalid_argument);
}

TEST(TRTest, bad_armor_get) 
{
	Terrorist terrorist(1 , 0 , "Roga" , "AK_47" , "78f" , 100 , 10 , 1 , 0 , 50);
    EXPECT_THROW(terrorist.SetArmor(-1), std::invalid_argument);
}

TEST(TRTest, bad_money_get) 
{
	Terrorist terrorist(1 , 0 , "Roga" , "AK_47" , "78f" , 100 , 10 , 1 , 0 , 50);
    EXPECT_THROW(terrorist.SetMoney(-1), std::invalid_argument);
}*/