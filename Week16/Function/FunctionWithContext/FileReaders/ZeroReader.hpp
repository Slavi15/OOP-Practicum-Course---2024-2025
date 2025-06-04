#pragma once

#include "FileReader.hpp"

#define ARRAY_MAX_LENGTH 32

class ZeroReader : public FileReader
{
public:
	ZeroReader(const String& filePath);

	Function* read(std::ifstream& ifs, uint16_t N) const override;
};

ZeroReader::ZeroReader(const String& filePath) : FileReader(filePath) {}

Function* ZeroReader::read(std::ifstream& ifs, uint16_t N) const
{
	int32_t arguments[ARRAY_MAX_LENGTH]{ 0 };
	int32_t results[ARRAY_MAX_LENGTH]{ 0 };

	ifs.read(reinterpret_cast<char*>(arguments), N * sizeof(int32_t));
	ifs.read(reinterpret_cast<char*>(results), N * sizeof(int32_t));

	FunctionCriteria toReturn = [arguments, results, N](int32_t x)
		{
			for (size_t i = 0; i < N; i++)
			{
				if (arguments[i] == x)
				{
					return results[i];
				}
			}

			throw std::invalid_argument("Undefined point!");
		};

	return toReturn.clone();
}