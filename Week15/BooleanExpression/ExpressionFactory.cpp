#include "ExpressionFactory.h"

BooleanExpression* ExpressionFactory::expressionFactory(std::string_view text)
{
    text = text.substr(1, text.size() - 2);

    if (text.size() == 1) return new Variable(text[0]);

    size_t count = 0;

    for (size_t i = 0; i < text.size(); i++)
    {
        if (text[i] == OPENING_BRACKET)
        {
            count++;
        }
        else if (text[i] == CLOSING_BRACKET)
        {
            count--;
        }
        else if (count == 0)
        {
            switch (text[i])
            {
            case '!': return new Negation(expressionFactory(text.substr(i + 1, text.size() - i - 1)));
            case '&': return new Conjuction(expressionFactory(text.substr(0, i)), expressionFactory(text.substr(i + 1, text.size() - i - 1)));
            case '|': return new Disjuction(expressionFactory(text.substr(0, i)), expressionFactory(text.substr(i + 1, text.size() - i - 1)));
            case '>': return new Implication(expressionFactory(text.substr(0, i)), expressionFactory(text.substr(i + 1, text.size() - i - 1)));
            }
        }
    }

    return nullptr;
}
