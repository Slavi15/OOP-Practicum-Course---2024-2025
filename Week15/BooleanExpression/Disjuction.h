#pragma once

#include "BinaryOperation.h"

class Disjuction : public BinaryOperation
{
public:
	Disjuction(BooleanExpression* left, BooleanExpression* right);

	bool eval(const BooleanInterpretation& interpret) const override;

	BooleanExpression* clone() const override;
};
