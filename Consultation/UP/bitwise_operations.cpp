#include <iostream>

size_t powerTwo(size_t n)
{
	return (n <= 31) ? (1 << n) : 0;
}

bool checkBit(size_t num, size_t pos)
{
	size_t mask = 1 << pos;
	return (num & mask) == mask;
}

size_t setBit(size_t num, size_t pos)
{
	size_t mask = 1 << pos;
	return num |= mask;
}

size_t clearBit(size_t num, size_t pos)
{
	size_t mask = ~(1 << pos);
	return num &= mask;
}

size_t toggleBit(size_t num, size_t pos)
{
	size_t mask = 1 << pos;
	return num ^= mask;
}

int main()
{
	return 0;
}