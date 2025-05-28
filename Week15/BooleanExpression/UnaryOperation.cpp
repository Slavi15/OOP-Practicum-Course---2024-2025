#include "UnaryOperation.h"

UnaryOperation::UnaryOperation(BooleanExpression* expr) : expr(expr)
{
}

void UnaryOperation::populate(BooleanInterpretation& interpret)
{
	expr->populate(interpret);
}

UnaryOperation::~UnaryOperation() noexcept
{
	delete expr;
}
