#pragma once

#include "BooleanExpression.h"

class Variable : public BooleanExpression
{
private:
	char ch;

public:
	Variable(char ch);

	void populate(BooleanInterpretation& interpret) override;
	bool eval(const BooleanInterpretation& interpret) const override;

	BooleanExpression* clone() const override;
};
