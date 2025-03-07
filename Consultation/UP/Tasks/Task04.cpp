#include <iostream>

namespace PairNS
{
	struct Pair
	{
		int x;
		int y;
	};

	Pair initPair(int x, int y)
	{
		return Pair{ x, y };
	}

	void printPair(const Pair& obj)
	{
		std::cout << obj.x << " " << obj.y << std::endl;
	}
}

using Predicate = bool (*)(const PairNS::Pair&, const PairNS::Pair&);

namespace RelationNS
{
	using namespace PairNS;

	struct Relation
	{
		Pair* pairs;
		size_t size;
	};

	Relation initRelaion(size_t size)
	{
		Relation toReturn;

		toReturn.size = size;
		toReturn.pairs = new Pair[size];

		return toReturn;
	}

	void sortData(Relation& relation, Predicate predicate)
	{
		if (!predicate) return;

		for (size_t i = 0; i < relation.size; i++)
		{
			size_t idx = i;

			for (size_t j = i + 1; j < relation.size; j++)
			{
				if (predicate(relation.pairs[j], relation.pairs[idx]))
				{
					idx = j;
				}
			}

			if (idx != i)
			{
				std::swap(relation.pairs[i], relation.pairs[idx]);
			}
		}
	}

	void printRelation(const Relation& obj)
	{
		for (size_t i = 0; i < obj.size; i++)
		{
			printPair(obj.pairs[i]);
		}
	}

	void freeRelation(Relation& obj)
	{
		delete[] obj.pairs;
	}
}

int main()
{
	using namespace RelationNS;

	Relation relation = initRelaion(5);

	relation.pairs[0] = initPair(1, 2);
	relation.pairs[1] = initPair(2, 3);
	relation.pairs[2] = initPair(2, 5);
	relation.pairs[3] = initPair(4, 3);
	relation.pairs[4] = initPair(5, 2);

	sortData(relation, [](const Pair& lhs, const Pair& rhs) -> bool {
		return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y <= rhs.y);
		});

	printRelation(relation);

	freeRelation(relation);

	return 0;
}
