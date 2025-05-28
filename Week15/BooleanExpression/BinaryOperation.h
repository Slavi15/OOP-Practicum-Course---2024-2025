#pragma once

#include "BooleanExpression.h"

class BinaryOperation : public BooleanExpression
{
protected:
	BooleanExpression* left;
	BooleanExpression* right;

public:
	BinaryOperation(BooleanExpression* left, BooleanExpression* right);

	void populate(BooleanInterpretation& interpret) override;

	~BinaryOperation() noexcept;
};
