#include "Scissors.h"

int Scissors::play(const GameMove* obj) const
{
	return obj->playWith(this);
}

int Scissors::playWith(const Rock* obj) const
{
	return 1;
}

int Scissors::playWith(const Scissors* obj) const
{
	return 0;
}

int Scissors::playWith(const Paper* obj) const
{
	return -1;
}

GameMove* Scissors::clone() const
{
	return new Scissors(*this);
}

void Scissors::print() const
{
	std::cout << "Scissors";
}
