#pragma once

#include "FileReader.hpp"

#define MAX_FILENAME_LENGTH 1024

Function* generateFunction(const String& filePath);

class FourthReader : public FileReader
{
public:
	FourthReader(const String& filePath);

	Function* read(std::ifstream& ifs, uint16_t N) const override;
};

FourthReader::FourthReader(const String& filePath) : FileReader(filePath) {}

Function* FourthReader::read(std::ifstream& ifs, uint16_t N) const
{
	FunctionContainer functionContainer(N);

	char fileName[MAX_FILENAME_LENGTH + 1];

	for (size_t i = 0; i < N; i++)
	{
		ifs.getline(fileName, MAX_FILENAME_LENGTH + 1, '\0');

		Function* function = generateFunction(fileName);

		if (!function)
		{
			throw std::runtime_error("Failed to generate function from file!");
		}

		functionContainer.addFunction(function);
		delete function;
	}

	MinFunction* toReturn = new MinFunction(functionContainer);
	return toReturn ? toReturn->clone() : nullptr;
}