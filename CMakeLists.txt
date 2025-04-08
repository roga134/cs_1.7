cmake_minimum_required(VERSION 3.10)
project(MyProject)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
find_package(GTest REQUIRED)

add_library(CoreLib src/Gun.cpp src/Guid.cpp src/Player.cpp src/ct.cpp src/Terrorist.cpp src/GameMap.cpp src/GameManager.cpp)

add_executable(test_Gun tests/test_gun.cpp)
add_executable(test_CT tests/test_CT.cpp)
add_executable(test_tr tests/test_tr.cpp)
add_executable(test_GM tests/test_GM.cpp)
add_executable(test_Gmanager tests/test_Gmanager.cpp)

target_link_libraries(test_Gun PRIVATE CoreLib GTest::GTest GTest::Main pthread)
target_link_libraries(test_CT PRIVATE CoreLib GTest::GTest GTest::Main pthread)
target_link_libraries(test_tr PRIVATE CoreLib GTest::GTest GTest::Main pthread)
target_link_libraries(test_GM PRIVATE CoreLib GTest::GTest GTest::Main pthread)
target_link_libraries(test_Gmanager PRIVATE CoreLib GTest::GTest GTest::Main pthread)