all: battle.out

battle.out: obj/battle.o obj/State.o obj/Unit.o obj/Soldier.o
	g++ obj/*.o -o battle.out

obj/battle.o: battle.cpp
	g++ -c -std=c++11 battle.cpp -o obj/battle.o

obj/State.o: state/State.cpp
	g++ -c -std=c++11 state/State.cpp -o obj/State.o

obj/Unit.o: unit/Unit.cpp
	g++ -c -std=c++11 unit/Unit.cpp -o obj/Unit.o

obj/Soldier.o: unit/Soldier.cpp
	g++ -c -std=c++11 unit/Soldier.cpp -o obj/Soldier.o

clean:
	rm -f obj/*.o
