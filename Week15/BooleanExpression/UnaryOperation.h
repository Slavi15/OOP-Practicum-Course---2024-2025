#pragma once

#include "BooleanExpression.h"

class UnaryOperation : public BooleanExpression
{
protected:
	BooleanExpression* expr;

public:
	UnaryOperation(BooleanExpression* expr);

	void populate(BooleanInterpretation& interpret) override;

	~UnaryOperation() noexcept;
};
