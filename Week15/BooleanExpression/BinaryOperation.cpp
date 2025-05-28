#include "BinaryOperation.h"

BinaryOperation::BinaryOperation(BooleanExpression* left, BooleanExpression* right) : left(left), right(right)
{
}

void BinaryOperation::populate(BooleanInterpretation& interpret)
{
	left->populate(interpret);
	right->populate(interpret);
}

BinaryOperation::~BinaryOperation() noexcept
{
	delete left;
	delete right;
}
