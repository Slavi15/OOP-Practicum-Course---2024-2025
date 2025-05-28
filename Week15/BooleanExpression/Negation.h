#pragma once

#include "UnaryOperation.h"

class Negation : public UnaryOperation
{
public:
	Negation(BooleanExpression* expr);

	bool eval(const BooleanInterpretation& interpret) const override;

	BooleanExpression* clone() const override;
};
