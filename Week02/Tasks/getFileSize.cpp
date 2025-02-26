#include <iostream>
#include <fstream>

size_t getFileSize(std::ifstream& ifs)
{
	size_t currPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	size_t size = ifs.tellg();
	ifs.seekg(currPos);

	return size;
}

size_t getFileSize(const char* fileName)
{
	if (!fileName) return 0;

	std::ifstream ifs(fileName, std::ios::in);

	if (!ifs.is_open()) return 0;

	return getFileSize(ifs);
}

int main()
{
	std::cout << getFileSize("test.txt") << std::endl;

	return 0;
}