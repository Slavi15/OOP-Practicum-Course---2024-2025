#pragma once

#include <iostream>
#include <fstream>

template <typename T, typename D>
class Pair
{
private:
	T lhs;
	D rhs;

public:
	Pair() = default;
	Pair(const T& lhs, const D& rhs);

	const T& getLhs() const;
	const D& getRhs() const;

	void setLhs(const T& lhs);
	void setRhs(const D& rhs);

	template <typename T1, typename D1>
	friend std::ostream& operator<<(std::ostream& os, const Pair<T1, D1>& pair);
};

template <typename T, typename D>
Pair<T, D>::Pair(const T& lhs, const D& rhs)
{
	setLhs(lhs);
	setRhs(rhs);
}

template <typename T, typename D>
const T& Pair<T, D>::getLhs() const
{
	return this->lhs;
}

template <typename T, typename D>
const D& Pair<T, D>::getRhs() const
{
	return this->rhs;
}

template <typename T, typename D>
void Pair<T, D>::setLhs(const T& lhs)
{
	this->lhs = lhs;
}

template <typename T, typename D>
void Pair<T, D>::setRhs(const D& rhs)
{
	this->rhs = rhs;
}

template <typename T1, typename D1>
std::ostream& operator<<(std::ostream& os, const Pair<T1, D1>& pair)
{
	return os << "< " << pair.getLhs() << ", " << pair.getRhs() << " >" << std::endl;
}