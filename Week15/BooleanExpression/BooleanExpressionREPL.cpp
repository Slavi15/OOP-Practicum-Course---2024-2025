#include "BooleanExpressionREPL.h"

BooleanExpressionREPL::BooleanExpressionREPL(const std::string& text)
{
	this->expr = ExpressionFactory::expressionFactory(text);
	this->expr->populate(variables);
}

bool BooleanExpressionREPL::evaluate(const BooleanInterpretation& bi) const
{
	return expr->eval(bi);
}

BooleanExpressionREPL::BooleanExpressionREPL(const BooleanExpressionREPL& other)
{
	copyFrom(other);
}

BooleanExpressionREPL& BooleanExpressionREPL::operator=(const BooleanExpressionREPL& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

BooleanExpressionREPL::BooleanExpressionREPL(BooleanExpressionREPL&& other) noexcept
{
	moveFrom(std::move(other));
}

BooleanExpressionREPL& BooleanExpressionREPL::operator=(BooleanExpressionREPL&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

BooleanExpressionREPL::~BooleanExpressionREPL() noexcept
{
	free();
}

void BooleanExpressionREPL::copyFrom(const BooleanExpressionREPL& other)
{
	this->expr = other.expr->clone();
	this->variables = other.variables;
}

void BooleanExpressionREPL::moveFrom(BooleanExpressionREPL&& other) noexcept
{
	this->expr = other.expr;
	this->variables = std::move(other.variables);

	other.expr = nullptr;
}

void BooleanExpressionREPL::free() noexcept
{
	delete expr;
}
