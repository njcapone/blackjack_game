CXX = g++
CXXFLAGS = -Wall
main: main.cpp Game.o Player.o Dealer.o Hand.o Card.o
	$(CXX) $(CXXFLAGS) main.cpp Game.o Player.o Dealer.o Hand.o Card.o -o run

Game.o: Game.h Game.cpp
	$(CXX) $(CXXFLAGS) -c Game.cpp

Player.o: Player.h Player.cpp
	$(CXX) $(CXXFLAGS) -c Player.cpp

Dealer.o: Dealer.h Dealer.cpp Player.o
	$(CXX) $(CXXFLAGS) -c Dealer.cpp

Hand.o: Hand.h Hand.cpp
	$(CXX) $(CXXFLAGS) -c Hand.cpp

Card.o: Card.h Card.cpp
	$(CXX) $(CXXFLAGS) -c Card.cpp