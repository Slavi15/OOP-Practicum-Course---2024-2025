#include "Variable.h"

Variable::Variable(char ch) : ch(ch)
{
}

void Variable::populate(BooleanInterpretation& interpret)
{
	interpret.set(ch, true);
}

bool Variable::eval(const BooleanInterpretation& interpret) const
{
	return interpret.operator()(ch);
}

BooleanExpression* Variable::clone() const
{
	return new Variable(ch);
}
