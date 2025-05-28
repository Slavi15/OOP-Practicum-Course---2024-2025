#include "Conjuction.h"

Conjuction::Conjuction(BooleanExpression* left, BooleanExpression* right) : BinaryOperation(left, right)
{
}

bool Conjuction::eval(const BooleanInterpretation& interpret) const
{
	return left->eval(interpret) && right->eval(interpret);
}

BooleanExpression* Conjuction::clone() const
{
	return new Conjuction(left->clone(), right->clone());
}
