#pragma once

#include <string_view>

#include "BooleanExpression.h"

#include "Variable.h"
#include "Negation.h"
#include "Conjuction.h"
#include "Disjuction.h"
#include "Implication.h"

class ExpressionFactory
{
private:
	static constexpr char OPENING_BRACKET = '(';
	static constexpr char CLOSING_BRACKET = ')';

public:
	static BooleanExpression* expressionFactory(std::string_view text);
};
