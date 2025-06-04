#pragma once

#include "Context.hpp"

template<typename ContextType>
class ContextWrapper : public Context
{
private:
	ContextType context;

public:
	ContextWrapper(const ContextType& context);

	int32_t operator()(int32_t x) const override;

	Context* clone() const override;
};

template<typename ContextType>
ContextWrapper<ContextType>::ContextWrapper(const ContextType& context) : context(context) {}

template<typename ContextType>
int32_t ContextWrapper<ContextType>::operator()(int32_t x) const
{
	return this->context(x);
}

template<typename ContextType>
Context* ContextWrapper<ContextType>::clone() const
{
	return new ContextWrapper<ContextType>(*this);
}