#pragma once

#include "BinaryOperation.h"

class Conjuction : public BinaryOperation
{
public:
	Conjuction(BooleanExpression* left, BooleanExpression* right);

	bool eval(const BooleanInterpretation& interpret) const override;

	BooleanExpression* clone() const override;
};
