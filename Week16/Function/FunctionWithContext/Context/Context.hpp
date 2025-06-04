#pragma once

#include <iostream>
#include <cstdint>

class Context
{
public:
	virtual int32_t operator()(int32_t x) const = 0;

	virtual Context* clone() const = 0;

	virtual ~Context() noexcept = default;
};