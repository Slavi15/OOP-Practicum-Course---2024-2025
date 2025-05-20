#pragma once

#include "GameMove.h"

class Paper : public GameMove
{
public:
	int play(const GameMove* obj) const override;

	int playWith(const Rock* obj) const override;
	int playWith(const Scissors* obj) const override;
	int playWith(const Paper* obj) const override;

	GameMove* clone() const override;

	void print() const override;
};
