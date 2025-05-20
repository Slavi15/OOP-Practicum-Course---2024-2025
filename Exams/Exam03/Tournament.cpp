#include "Tournament.h"

void Tournament::addPlayer(MoveType type)
{
	collection.push_back(GameMoveFactory::moveFactory(type));
}

void Tournament::duelPlayers() const
{
	size_t* points = new size_t[collection.getSize()]{ 0 };

	for (size_t i = 0; i < collection.getSize(); i++)
	{
		for (size_t j = i + 1; j < collection.getSize(); j++)
		{
			int lhsPoints = collection[i]->play(collection[j]);
			int rhsPoints = collection[j]->play(collection[i]);
			
			if (lhsPoints > 0)
			{
				points[i] += WIN;
			}
			else if (lhsPoints == rhsPoints)
			{
				points[i] += DRAW;
				points[j] += DRAW;
			}
			else
			{
				points[j] += WIN;
			}
		}
	}

	for (size_t i = 0; i < collection.getSize(); i++)
	{
		std::cout << "Player " << i << ": ";
		collection[i]->print();
		std::cout << " scored " << points[i] << " points" << std::endl;
	}

	delete[] points;
}
