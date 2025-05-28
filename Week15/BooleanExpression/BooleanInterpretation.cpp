#include "BooleanInterpretation.h"

void BooleanInterpretation::set(char ch, bool condition)
{
	this->values[ch - 'a'] = condition;
}

bool BooleanInterpretation::operator()(char ch) const
{
	return this->values[ch - 'a'];
}
