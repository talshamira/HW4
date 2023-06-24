# The first line states the minimum CMake version to use with this project
# and is requires by CMake.
cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 11)

# Set <PROJNAME> to be your project name. We set CXX (C++) here as the target language.
project(HW4 VERSION 0.1.0 LANGUAGES CXX)

# If you want to see "under the hood" of CMake, uncomment this:
# set(CMAKE_VERBOSE_MAKEFILE ON)

# Define variables containing compiler flags for gcc
set(MTM_FLAGS_DEBUG "-std=c++11 --pedantic-errors -Wall -Werror")
set(MTM_FLAGS_RELEASE "${MTM_FLAGS_DEBUG} -DNDEBUG")

# Set the flags for gcc
set(CMAKE_CPP_FLAGS ${MTM_FLAGS_DEBUG})

include_directories(${PROJECT_SOURCE_DIR})

# Add the names of your source files here
set(CPP_FILES "Mtmchkin.cpp" "utilities.cpp" "test.cpp"
        "Players/Player.cpp" "Players/Healer.cpp" "Players/Ninja.cpp" "Players/Warrior.cpp"
        "Cards/Card.cpp" "Cards/BattleCard.cpp" "Cards/Gremlin.cpp" "Cards/Dragon.cpp" "Cards/Witch.cpp"
        "Cards/Merchant.cpp" "Cards/Treasure.cpp" "Cards/Well.cpp" "Cards/Barfight.cpp" "Cards/Mana.cpp")

add_executable(run ${CPP_FILES})