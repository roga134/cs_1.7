#include <gtest/gtest.h>
#include "../src/Gun.h"

TEST(GunTest, Ammo) // for testing get for ammo 
{
    Gun gun(50, 10 , 2 , 1);
    EXPECT_EQ(gun.GetAmmo(), 50);
}

TEST(GunTest, Price) // for testing get for price
{
    Gun gun(50, 10 , 2 , 1);
    EXPECT_EQ(gun.GetPrice(), 10);
}

TEST(GunTest, name) // for testing get for name
{
    Gun gun(50, 10 , 2 , 1);
    gun.SetName(0);
    EXPECT_EQ(gun.GetName(), "AK-47");
}

TEST(GunTest, PowerAmmo) // for testing get for power ammo
{
    Gun gun(50, 10 , 2 , 1);
    EXPECT_EQ(gun.GetPowerAmmo(), 1);
}

TEST(GunTest, number_of_gun) // for testing get for number of guns
{
    Gun gun;
    EXPECT_EQ(gun.GetAllGun(), 5);
}

TEST(GunTest, bool_is) // for testing on bool of equal two object 
{
    Gun gun(50, 10 , 2 , 1);
    Gun gun2(51, 11 , 3 , 4);
    int it_true = (gun == gun2);
    EXPECT_EQ(it_true, 0);
}

TEST(GunTest, bool_is_not) // for testing on bool of not equal two object 
{
    Gun gun(50, 10 , 2 , 1);
    Gun gun2(51, 11 , 3 , 4);
    int it_true = (gun != gun2);
    EXPECT_EQ(it_true, 1);
}

TEST(GunTest, is) // for testing equal two object 
{
    Gun gun(50, 10 , 2 , 1);
    Gun gun2(51, 11 , 3 , 4);
    gun = gun2;
    EXPECT_EQ(gun.GetAmmo(), 51);
    EXPECT_EQ(gun.GetPrice(), 11);
    EXPECT_EQ(gun.GetName(), "knife");
    EXPECT_EQ(gun.GetPowerAmmo(), 4);
}

TEST(GunTest, bad_name) // for testing get for name in bad input with negetive
{
    Gun gun(50, 10 , 2 , 1);
    gun.SetName(-1);
    EXPECT_EQ(gun.GetName(), "Unknown");
}

TEST(GunTest, NegativeAmmo) // for testing get for ammo in bad input with negetive
{
    EXPECT_THROW({Gun gun(-10, 100, 1, 50);}, std::invalid_argument);  
}

TEST(GunTest, NegativePrice) // for testing get for price in bad input with negetive
{
    EXPECT_THROW({Gun gun(10, -100, 1, 50);}, std::invalid_argument);
}

TEST(GunTest, NegativePowerAmmo) // for testing get for power ammo in bad input with negetive
{
    EXPECT_THROW({Gun gun(10, 100, 1, -50);}, std::invalid_argument);
}

/*
[==========] Running 12 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 12 tests from GunTest
[ RUN      ] GunTest.Ammo
[       OK ] GunTest.Ammo (0 ms)
[ RUN      ] GunTest.Price
[       OK ] GunTest.Price (0 ms)
[ RUN      ] GunTest.name
[       OK ] GunTest.name (0 ms)
[ RUN      ] GunTest.PowerAmmo
[       OK ] GunTest.PowerAmmo (0 ms)
[ RUN      ] GunTest.number_of_gun
[       OK ] GunTest.number_of_gun (0 ms)
[ RUN      ] GunTest.bool_is
[       OK ] GunTest.bool_is (0 ms)
[ RUN      ] GunTest.bool_is_not
[       OK ] GunTest.bool_is_not (0 ms)
[ RUN      ] GunTest.is
[       OK ] GunTest.is (0 ms)
[ RUN      ] GunTest.bad_name
[       OK ] GunTest.bad_name (0 ms)
[ RUN      ] GunTest.NegativeAmmo
[       OK ] GunTest.NegativeAmmo (2 ms)
[ RUN      ] GunTest.NegativePrice
[       OK ] GunTest.NegativePrice (0 ms)
[ RUN      ] GunTest.NegativePowerAmmo
[       OK ] GunTest.NegativePowerAmmo (0 ms)
[----------] 12 tests from GunTest (3 ms total)

[----------] Global test environment tear-down
[==========] 12 tests from 1 test suite ran. (3 ms total)
[  PASSED  ] 12 tests.
*/