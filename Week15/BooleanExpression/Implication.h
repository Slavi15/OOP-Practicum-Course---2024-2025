#pragma once

#include "BinaryOperation.h"

class Implication : public BinaryOperation
{
public:
	Implication(BooleanExpression* left, BooleanExpression* right);

	bool eval(const BooleanInterpretation& interpret) const override;

	BooleanExpression* clone() const override;
};
