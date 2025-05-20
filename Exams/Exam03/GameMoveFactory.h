#pragma once

#include "GameMove.h"
#include "Paper.h"
#include "Rock.h"
#include "Scissors.h"

enum class MoveType : uint8_t
{
	ROCK,
	PAPER,
	SCISSORS
};

class GameMoveFactory
{
public:
	static GameMove* moveFactory(MoveType moveType);
};
