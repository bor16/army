all: battle.out

battle.out: obj/battle.o obj/case.o obj/State.o obj/Unit.o obj/Soldier.o obj/Rogue.o
	g++ obj/*.o -o battle.out

obj/battle.o: test/battle.cpp
	g++ -c -std=c++11 $< -o $@

obj/case.o: test/case.cpp
	g++ -c -std=c++11 $< -o $@

obj/State.o: state/State.cpp
	g++ -c -std=c++11 $< -o $@

obj/Unit.o: unit/Unit.cpp
	g++ -c -std=c++11 $< -o $@

obj/Soldier.o: unit/Soldier.cpp
	g++ -c -std=c++11 $< -o $@
	
obj/Rogue.o: unit/Rogue.cpp
	g++ -c -std=c++11 $< -o $@

clean:
	rm -fv obj/*.o battle.out
