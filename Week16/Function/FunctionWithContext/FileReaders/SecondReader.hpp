#pragma once

#include "FileReader.hpp"

#define ARRAY_MAX_LENGTH 32

class SecondReader : public FileReader
{
public:
	SecondReader(const String& filePath);

	Function* read(std::ifstream& ifs, uint16_t N) const override;
};

SecondReader::SecondReader(const String& filePath) : FileReader(filePath) {}

Function* SecondReader::read(std::ifstream& ifs, uint16_t N) const
{
	int32_t values[ARRAY_MAX_LENGTH]{ 0 };

	ifs.read(reinterpret_cast<char*>(values), N * sizeof(int32_t));

	FunctionCriteria toReturn = [values, N](int32_t x)
		{
			for (size_t i = 0; i < N; i++)
			{
				if (values[i] == x)
				{
					return 1;
				}
			}

			return 0;
		};

	return toReturn.clone();
}