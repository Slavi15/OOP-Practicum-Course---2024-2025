#pragma once

#include "Function.hpp"
#include "../Pair/Pair.hpp"

class FunctionCriteria : public Function
{
public:
	template <typename ContextType>
	FunctionCriteria(const ContextType& context);

	Pair<bool, int32_t> operator()(int32_t x) const override;

	Function* clone() const override;
};

template <typename ContextType>
FunctionCriteria::FunctionCriteria(const ContextType& context) : Function(context) {}

Pair<bool, int32_t> FunctionCriteria::operator()(int32_t x) const
{
	return Function::operator()(x);
}

Function* FunctionCriteria::clone() const
{
	return new FunctionCriteria(*this);
}