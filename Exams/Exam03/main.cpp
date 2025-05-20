#include "Tournament.h"

int main()
{
	Tournament collection;

	collection.addPlayer(MoveType::PAPER);
	collection.addPlayer(MoveType::ROCK);
	collection.addPlayer(MoveType::PAPER);

	collection.duelPlayers();

	return 0;
}