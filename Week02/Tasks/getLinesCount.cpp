#include <iostream>
#include <fstream>

constexpr size_t MAX_SIZE = 1024;
constexpr char DELIMITER = '\n';

size_t getLinesCount(std::ifstream& ifs)
{
	char buff[MAX_SIZE + 1]{ '\0' };
	size_t lines = 0;

	while (!ifs.eof())
	{
		ifs.getline(buff, MAX_SIZE + 1, DELIMITER);
		lines++;
	}

	return lines;
}

size_t getLinesCount(const char* fileName)
{
	if (!fileName) return 0;

	std::ifstream ifs(fileName, std::ios::in);

	if (!ifs.is_open()) return 0;

	return getLinesCount(ifs);
}

int main()
{
	std::cout << getLinesCount("text.txt") << std::endl;

	return 0;
}