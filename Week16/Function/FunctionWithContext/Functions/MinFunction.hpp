#pragma once

#include "Function.hpp"
#include "../FunctionContainer/FunctionContainer.hpp"

class MinFunction : public Function
{
private:
	FunctionContainer functionContainer;

public:
	MinFunction(const FunctionContainer& functionContainer);

	Pair<bool, int32_t> operator()(int32_t x) const override;
	bool isDefined(int32_t x) const;

	Function* clone() const override;
};

MinFunction::MinFunction(const FunctionContainer& functionContainer) : functionContainer(functionContainer) {}

Pair<bool, int32_t> MinFunction::operator()(int32_t x) const
{
	if (functionContainer.getCount() == 0)
	{
		throw std::logic_error("Function container empty!");
	}

	int32_t result = INT32_MAX;

	if (isDefined(x))
	{
		for (size_t i = 0; i < functionContainer.getCount(); i++)
		{
			if (functionContainer.getFunction(i)->operator()(x).getRhs() < result)
			{
				result = functionContainer.getFunction(i)->operator()(x).getRhs();
			}
		}

		return Pair<bool, int32_t>(true, result);
	}

	return Pair<bool, int32_t>(false, result);
}

bool MinFunction::isDefined(int32_t x) const
{
	for (size_t i = 0; i < functionContainer.getCount(); i++)
	{
		try
		{
			functionContainer.getFunction(i)->isDefined(x);
		}
		catch (const std::invalid_argument& exc) { return false; }
		catch (const std::out_of_range& exc) { return false; }
		catch (const std::runtime_error& exc) { return false; }
		catch (const std::exception& exc) { return false; }
		catch (...) { return false; }
	}

	return true;
}

Function* MinFunction::clone() const
{
	return new MinFunction(functionContainer);
}