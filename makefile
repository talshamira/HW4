# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g -Itool

# ****************************************************
# Targets needed to bring the executable up to date

mtmchkin: test.o mtmchkin.o Cards/Card.o Cards/Barfight.o Cards/BattleCard.o Cards/Dragon.o Cards/Gremlin.o Cards/Mana.o Cards/Merchant.o Cards/Treasure.o Cards/Well.o Cards/Witch.o Players/Healer.o Players/Ninja.o Players/Player.o Players/Warrior.o utilities.o
    $(CC) $(CFLAGS) -o mtmchkin test.o mtmchkin.o Cards/Card.o Cards/Barfight.o Cards/BattleCard.o Cards/Dragon.o Cards/Gremlin.o Cards/Mana.o Cards/Merchant.o Cards/Treasure.o Cards/Well.o Cards/Witch.o Players/Healer.o Players/Ninja.o Players/Player.o Players/Warrior.o utilities.o

# The main.o target can be written more simply

test.o: main.cpp Point.h Square.h
    $(CC) $(CFLAGS) -c main.cpp

Point.o: Point.h

Square.o: Square.h Point.h