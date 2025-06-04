#pragma once

#include "FileReader.hpp"

Function* generateFunction(const String& filePath);

#define MAX_FILENAME_LENGTH 1024

class ThirdReader : public FileReader
{
public:
	ThirdReader(const String& filePath);

	Function* read(std::ifstream& ifs, uint16_t N) const override;
};

ThirdReader::ThirdReader(const String& filePath) : FileReader(filePath) {}

Function* ThirdReader::read(std::ifstream& ifs, uint16_t N) const
{
	FunctionContainer functionContainer(N);

	char fileName[MAX_FILENAME_LENGTH + 1];

	for (size_t i = 0; i < N; i++)
	{
		ifs.getline(fileName, MAX_FILENAME_LENGTH + 1, '\0');

		Function* function = generateFunction(fileName);

		if (!function)
		{
			throw std::runtime_error("Function Factory: Failed to generate function from file!");
		}

		functionContainer.addFunction(function);
		delete function;
	}

	MaxFunction* toReturn = new MaxFunction(functionContainer);
	return toReturn ? toReturn->clone() : nullptr;
}