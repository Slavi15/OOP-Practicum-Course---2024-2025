#pragma once

#include "../Functions/Function.hpp"

class FunctionContainer
{
private:
	Function** functions = nullptr;
	size_t count = 0;
	size_t capacity = 0;

	void resize(size_t newCapacity);

	unsigned int getNextPowerOfTwo(unsigned int n) const;
	unsigned int allocateCapacity(unsigned int size) const;

	void copyFrom(const FunctionContainer& other);
	void moveFrom(FunctionContainer&& other) noexcept;
	void free();

public:
	FunctionContainer();
	FunctionContainer(size_t newCount);

	FunctionContainer(const Function* const* functions, size_t count);

	FunctionContainer(const FunctionContainer& other);
	FunctionContainer& operator=(const FunctionContainer& other);

	FunctionContainer(FunctionContainer&& other) noexcept;
	FunctionContainer& operator=(FunctionContainer&& other) noexcept;

	size_t getCount() const;
	size_t getCapacity() const;

	Function* getFunction(size_t index) const;

	void addFunction(const Function& function);
	void addFunction(Function* function);

	const Function* operator[](size_t index) const;
	Function* operator[](size_t index);

	~FunctionContainer() noexcept;
};

FunctionContainer::FunctionContainer() : FunctionContainer(4) {}

FunctionContainer::FunctionContainer(size_t newCount) : count(0)
{
	this->capacity = allocateCapacity(newCount);
	this->functions = new Function * [this->capacity];
}

FunctionContainer::FunctionContainer(const Function* const* functions, size_t count) : count(count)
{
	if (!functions)
	{
		throw std::runtime_error("Function Container: NULLPTR!");
	}

	this->capacity = allocateCapacity(count);

	this->functions = new Function * [this->capacity];
	for (size_t i = 0; i < getCount(); i++)
	{
		this->functions[i] = functions[i]->clone();
	}
}

FunctionContainer::FunctionContainer(const FunctionContainer& other)
{
	copyFrom(other);
}

FunctionContainer& FunctionContainer::operator=(const FunctionContainer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

FunctionContainer::FunctionContainer(FunctionContainer&& other) noexcept
{
	moveFrom(std::move(other));
}

FunctionContainer& FunctionContainer::operator=(FunctionContainer&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

size_t FunctionContainer::getCount() const
{
	return this->count;
}

size_t FunctionContainer::getCapacity() const
{
	return this->capacity;
}

Function* FunctionContainer::getFunction(size_t index) const
{
	if (index >= getCount())
	{
		return nullptr;
	}

	return this->functions[index];
}

void FunctionContainer::addFunction(const Function& function)
{
	if (getCount() >= getCapacity())
	{
		resize(getCapacity() * 2);
	}

	this->functions[this->count++] = function.clone();
}

void FunctionContainer::addFunction(Function* function)
{
	if (!function)
	{
		throw std::runtime_error("Function Container: NULLPTR!");
	}

	if (getCount() >= getCapacity())
	{
		resize(getCapacity() * 2);
	}

	this->functions[this->count++] = function->clone();
}

const Function* FunctionContainer::operator[](size_t index) const
{
	return this->functions[index];
}

Function* FunctionContainer::operator[](size_t index)
{
	return this->functions[index];
}

FunctionContainer::~FunctionContainer() noexcept
{
	free();
}

unsigned int FunctionContainer::getNextPowerOfTwo(unsigned int n) const
{
	if (n == 0) return 1;

	while (n & (n - 1))
	{
		n &= (n - 1);
	}

	return n << 1;
}

unsigned int FunctionContainer::allocateCapacity(unsigned int size) const
{
	return std::max(getNextPowerOfTwo(size + 1), 8u);
}

void FunctionContainer::resize(size_t newCapacity)
{
	Function** newFunctions = new Function * [newCapacity];
	for (size_t i = 0; i < getCount(); i++)
	{
		newFunctions[i] = this->functions[i];
	}

	delete[] this->functions;
	this->functions = newFunctions;
	this->capacity = newCapacity;
}

void FunctionContainer::copyFrom(const FunctionContainer& other)
{
	this->count = other.count;
	this->capacity = other.capacity;

	this->functions = new Function * [this->count];
	for (size_t i = 0; i < this->count; i++)
	{
		this->functions[i] = other.functions[i]->clone();
	}
}

void FunctionContainer::moveFrom(FunctionContainer&& other) noexcept
{
	this->functions = other.functions;
	this->count = other.count;
	this->capacity = other.capacity;

	other.functions = nullptr;
	other.count = other.capacity = 0;
}

void FunctionContainer::free()
{
	for (size_t i = 0; i < this->count; i++)
	{
		delete this->functions[i];
	}

	delete[] this->functions;
	this->functions = nullptr;
	this->count = this->capacity = 0;
}