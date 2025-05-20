#include "Paper.h"

int Paper::play(const GameMove* obj) const
{
	return obj->playWith(this);
}

int Paper::playWith(const Rock* obj) const
{
	return -1;
}

int Paper::playWith(const Scissors* obj) const
{
	return 1;
}

int Paper::playWith(const Paper* obj) const
{
	return 0;
}

GameMove* Paper::clone() const
{
	return new Paper(*this);
}

void Paper::print() const
{
	std::cout << "Paper";
}
