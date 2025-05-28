#include <iostream>

#include "BooleanExpressionREPL.h"

int main()
{
	BooleanExpressionREPL repl("((!(p))|((q)&(t)))");

	BooleanInterpretation bi;
	bi.set('p', false);

	std::cout << repl.evaluate(bi) << std::endl;

	return 0;
}