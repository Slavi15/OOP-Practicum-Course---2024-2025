#include "Implication.h"

Implication::Implication(BooleanExpression* left, BooleanExpression* right) : BinaryOperation(left, right)
{
}

bool Implication::eval(const BooleanInterpretation& interpret) const
{
	return !left->eval(interpret) || right->eval(interpret);
}

BooleanExpression* Implication::clone() const
{
	return new Implication(left->clone(), right->clone());
}
