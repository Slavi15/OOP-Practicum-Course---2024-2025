#include <iostream>

#include "ShapesCollection.h"

int main()
{
	ShapesCollection collection;

	collection.addFigure(ShapeType::TRIANGLE); // 0 0 3 0 3 4
	collection.addFigure(ShapeType::RECTANGLE); // 0 0 4 4
	collection.addFigure(ShapeType::CIRCLE); // 0 0 2

	std::cout << collection.getAreaByIndex(0) << std::endl;

	std::cout << collection.getIsPointInByIndex(0, 1, 1) << std::endl;
	std::cout << collection.getIsPointInByIndex(0, 2, 1) << std::endl;

	Intersection intersection = collection[0]->intersect(collection[1]);

	if (
		(intersection.lhsShape == ShapeType::TRIANGLE && intersection.rhsShape == ShapeType::RECTANGLE) ||
		(intersection.lhsShape == ShapeType::RECTANGLE && intersection.rhsShape == ShapeType::TRIANGLE))
	{
		std::cout << "Triangle + Rectangle" << std::endl;
	}
	else
	{
		std::cout << "No intersection!" << std::endl;
	}

	return 0;
}