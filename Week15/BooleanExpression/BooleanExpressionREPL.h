#pragma once

#include <string>

#include "BooleanInterpretation.h"
#include "ExpressionFactory.h"

class BooleanExpressionREPL
{
private:
	BooleanExpression* expr;
	BooleanInterpretation variables;

	void copyFrom(const BooleanExpressionREPL& other);
	void moveFrom(BooleanExpressionREPL&& other) noexcept;
	void free() noexcept;

public:
	BooleanExpressionREPL(const std::string& text);

	BooleanExpressionREPL(const BooleanExpressionREPL& other);
	BooleanExpressionREPL& operator=(const BooleanExpressionREPL& other);

	BooleanExpressionREPL(BooleanExpressionREPL&& other) noexcept;
	BooleanExpressionREPL& operator=(BooleanExpressionREPL&& other) noexcept;

	bool evaluate(const BooleanInterpretation& bi) const;

	~BooleanExpressionREPL() noexcept;
};
