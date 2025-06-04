#pragma once

#include "../Functions/Function.hpp"

#include "../FunctionContainer/FunctionContainer.hpp"

#include "../Functions/FunctionCriteria.hpp"
#include "../Functions/MaxFunction.hpp"
#include "../Functions/MinFunction.hpp"

#include "../String/String.h"

class FileReader
{
private:
	static size_t getFileSize(std::ifstream& ifs);

protected:
	String filePath;

public:
	FileReader(const String& filePath);

	virtual Function* read(std::ifstream& ifs, uint16_t N) const = 0;

	virtual ~FileReader() noexcept = default;
};

FileReader::FileReader(const String& filePath) : filePath(filePath) {}

inline size_t FileReader::getFileSize(std::ifstream& ifs)
{
	size_t currentPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);

	size_t size = ifs.tellg();
	ifs.seekg(currentPos);

	return size;
}