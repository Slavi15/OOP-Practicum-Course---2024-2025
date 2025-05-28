#include "Disjuction.h"

Disjuction::Disjuction(BooleanExpression* left, BooleanExpression* right) : BinaryOperation(left, right)
{
}

bool Disjuction::eval(const BooleanInterpretation& interpret) const
{
	return left->eval(interpret) || right->eval(interpret);
}

BooleanExpression* Disjuction::clone() const
{
	return new Disjuction(left->clone(), right->clone());
}
