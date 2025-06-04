#pragma once

#include "../Context/ContextWrapper.hpp"
#include "../Pair/Pair.hpp"

class Function
{
private:
	Context* contextFunction = nullptr;

	void copyFrom(const Function& other);
	void moveFrom(Function&& other) noexcept;
	void free();

public:
	Function();

	template<typename ContextType>
	Function(const ContextType& contextFunction);

	Function(const Function& other);
	Function& operator=(const Function& other);

	Function(Function&& other) noexcept;
	Function& operator=(Function&& other) noexcept;

	virtual Pair<bool, int32_t> operator()(int32_t x) const;
	bool isDefined(int32_t x) const;

	virtual Function* clone() const = 0;

	virtual ~Function() noexcept;
};

Function::Function() = default;

template<typename ContextType>
Function::Function(const ContextType& contextFunction) : contextFunction(new ContextWrapper<ContextType>(contextFunction)) {}

Function::Function(const Function& other)
{
	copyFrom(other);
}

Function& Function::operator=(const Function& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Function::Function(Function&& other) noexcept
{
	moveFrom(std::move(other));
}

Function& Function::operator=(Function&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Pair<bool, int32_t> Function::operator()(int32_t x) const
{
	return Pair<bool, int32_t>(true, this->contextFunction->operator()(x));
}

bool Function::isDefined(int32_t x) const
{
	if (this->operator()(x).getLhs())
	{
		return true;
	}

	return false;
}

Function::~Function() noexcept
{
	free();
}

void Function::copyFrom(const Function& other)
{
	this->contextFunction = other.contextFunction->clone();
}

void Function::moveFrom(Function&& other) noexcept
{
	this->contextFunction = other.contextFunction;
	other.contextFunction = nullptr;
}

void Function::free()
{
	delete this->contextFunction;
	this->contextFunction = nullptr;
}