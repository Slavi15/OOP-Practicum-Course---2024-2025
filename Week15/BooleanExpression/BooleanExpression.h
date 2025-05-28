#pragma once

#include "BooleanInterpretation.h"

class BooleanExpression
{
public:
	BooleanExpression();

	BooleanExpression(const BooleanExpression&) = delete;
	BooleanExpression& operator=(const BooleanExpression&) = delete;

	virtual void populate(BooleanInterpretation& interpret) = 0;
	virtual bool eval(const BooleanInterpretation& interpret) const = 0;

	virtual BooleanExpression* clone() const = 0;

	virtual ~BooleanExpression() noexcept;
};
