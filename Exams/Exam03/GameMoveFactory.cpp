#include "GameMoveFactory.h"

GameMove* GameMoveFactory::moveFactory(MoveType moveType)
{
    switch (moveType)
    {
    case MoveType::ROCK: return new Rock();
    case MoveType::PAPER: return new Paper();
    case MoveType::SCISSORS: return new Scissors();
    }

    return nullptr;
}
