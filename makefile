GPP=g++
EXEC=FileTester
OBJS=Card.o Test.o Barfight.o BattleCard.o Dragon.o Gremlin.o Mana.o Merchant.o Treasure.o Well.o Witch.o Player.o Healer.o Ninja.o Warrior.o Mtmchkin.o utilities.o 
DEBUG_FLAG= -g# can add -g
COMP_FLAG=--std=c++11 -Wall -Werror -pedantic-errors $(DEBUG_FLAG)

$(EXEC) : $(OBJS)
	$(GPP) $(COMP_FLAG) $(OBJS) -o $@
Card.o : Cards/Card.h Players/Player.h 
	$(GPP) -c $(COMP_FLAG) Cards/Card.cpp -o $@
Test.o : Players/*.h  Mtmchkin.h Cards/*.h Exception.h
	$(GPP) -c $(COMP_FLAG) test.cpp -o $@
Barfight.o : Cards/Barfight.h Cards/Card.h Players/Player.h utilities.h
	$(GPP) -c $(COMP_FLAG) Cards/Barfight.cpp -o $@
BattleCard.o : Cards/BattleCard.h Cards/Card.h Players/Player.h utilities.h
	$(GPP) -c $(COMP_FLAG) Cards/BattleCard.cpp -o $@ 
Dragon.o : Cards/Dragon.h Cards/Card.h Players/Player.h utilities.h Cards/BattleCard.h
	$(GPP) -c $(COMP_FLAG) Cards/Dragon.cpp -o $@
Gremlin.o : Cards/Gremlin.h Cards/Card.h Players/Player.h utilities.h Cards/BattleCard.h
	$(GPP) -c $(COMP_FLAG) Cards/Gremlin.cpp -o $@
Witch.o : Cards/Witch.h Cards/Card.h Players/Player.h utilities.h Cards/BattleCard.h
	$(GPP) -c $(COMP_FLAG) Cards/Witch.cpp -o $@
Mana.o : Cards/Mana.h Cards/Card.h Players/Player.h utilities.h
	$(GPP) -c $(COMP_FLAG) Cards/Mana.cpp -o $@
Merchant.o : Cards/Merchant.h Cards/Card.h Players/Player.h utilities.h
	$(GPP) -c $(COMP_FLAG) Cards/Merchant.cpp -o $@
Treasure.o : Cards/Treasure.h Cards/Card.h Players/Player.h utilities.h
	$(GPP) -c $(COMP_FLAG) Cards/Treasure.cpp -o $@
Well.o : Cards/Well.h Cards/Card.h Players/Player.h utilities.h
	$(GPP) -c $(COMP_FLAG) Cards/Well.cpp -o $@
Player.o : Players/Player.h utilities.h
	$(GPP) -c $(COMP_FLAG) Players/Player.cpp -o $@
Ninja.o : Players/Ninja.h Players/Player.h
	$(GPP) -c $(COMP_FLAG) Players/Ninja.cpp -o $@
Healer.o : Players/Healer.h Players/Player.h
	$(GPP) -c $(COMP_FLAG) Players/Healer.cpp -o $@
Warrior.o : Players/Warrior.h Players/Player.h
	$(GPP) -c $(COMP_FLAG) Players/Warrior.cpp -o $@
Mtmchkin.o : Players/*.h Cards/*.h utilities.h
	$(GPP) -c $(COMP_FLAG) Mtmchkin.cpp -o $@
utilities.o : utilities.h Players/Player.h
	$(GPP) -c $(COMP_FLAG) utilities.cpp -o $@
.PHONY: clean
clean:
	rm -f $(OBJS) $(EXEC)
