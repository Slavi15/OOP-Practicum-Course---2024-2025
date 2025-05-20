#pragma once

#include <iostream>

class Rock;
class Paper;
class Scissors;

class GameMove
{
public:
	virtual int play(const GameMove* obj) const = 0;

	virtual int playWith(const Rock* obj) const = 0;
	virtual int playWith(const Scissors* obj) const = 0;
	virtual int playWith(const Paper* obj) const = 0;

	virtual void print() const = 0;

	virtual GameMove* clone() const = 0;

	virtual ~GameMove() noexcept = default;
};
