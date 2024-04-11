all: main.o Game.o Card.o Deck.o Player.o Human.o Meek.o Random.o Dealer.o
	g++ -g main.o Game.o Card.o Deck.o Player.o Human.o Meek.o Random.o Dealer.o

main.o: main.cpp
	g++ -g -c main.cpp

Game.o: Game.h Game.cpp
	g++ -g -c Game.cpp

Deck.o: Deck.h Deck.cpp
	g++ -g -c Deck.cpp

Card.o: Card.h Card.cpp
	g++ -g -c Card.cpp

Player.o: Player.h Player.cpp
	g++ -g -c Player.cpp

Human.o: Human.h Human.cpp
	g++ -g -c Human.cpp

Meek.o: Meek.h Meek.cpp
	g++ -g -c Meek.cpp

Random.o: Random.h Random.cpp
	g++ -g -c Random.cpp

Dealer.o: Dealer.h Dealer.cpp
	g++ -g -c Dealer.cpp

clean:
	rm -f main.o Game.o Card.o Deck.o Player.o Human.o Meek.o Random.o Dealer.o


