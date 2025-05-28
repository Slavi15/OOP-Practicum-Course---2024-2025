#include "Negation.h"

Negation::Negation(BooleanExpression* expr) : UnaryOperation(expr)
{
}

bool Negation::eval(const BooleanInterpretation& interpret) const
{
	return !expr->eval(interpret);
}

BooleanExpression* Negation::clone() const
{
	return new Negation(expr);
}
