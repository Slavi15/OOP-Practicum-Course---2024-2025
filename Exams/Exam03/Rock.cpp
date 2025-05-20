#include "Rock.h"

int Rock::play(const GameMove* obj) const
{
	return obj->playWith(this);
}

int Rock::playWith(const Rock* obj) const
{
	return 0;
}

int Rock::playWith(const Scissors* obj) const
{
	return -1;
}

int Rock::playWith(const Paper* obj) const
{
	return 1;
}

GameMove* Rock::clone() const
{
	return new Rock(*this);
}

void Rock::print() const
{
	std::cout << "Rock";
}
