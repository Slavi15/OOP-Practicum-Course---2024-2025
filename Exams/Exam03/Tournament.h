#pragma once

#include "Container.hpp"
#include "GameMoveFactory.h"

class Tournament
{
private:
	static constexpr size_t WIN = 3;
	static constexpr size_t DRAW = 1;

private:
	Container<GameMove> collection;

public:
	void addPlayer(MoveType type);

	void duelPlayers() const;
};