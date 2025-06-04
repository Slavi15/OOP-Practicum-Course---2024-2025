#pragma once

#include "FileReader.hpp"

#define ARRAY_MAX_LENGTH 32

class FirstReader : public FileReader
{
public:
	FirstReader(const String& filePath);

	Function* read(std::ifstream& ifs, uint16_t N) const override;
};

FirstReader::FirstReader(const String& filePath) : FileReader(filePath) {}

Function* FirstReader::read(std::ifstream& ifs, uint16_t N) const
{
	int32_t values[ARRAY_MAX_LENGTH]{ 0 };

	ifs.read(reinterpret_cast<char*>(values), N * sizeof(int32_t));

	FunctionCriteria toReturn = [values, N](int32_t x)
		{
			for (size_t i = 0; i < N; i++)
			{
				if (values[i] == x)
				{
					throw std::invalid_argument("Undefined point!");
				}
			}

			return x;
		};

	return toReturn.clone();
}