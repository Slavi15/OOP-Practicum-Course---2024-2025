#include <iostream>
#include <fstream>

constexpr size_t MAX_SIZE = 1024;
constexpr char DELIMITER = '\n';

void selfPrinting(std::ifstream& ifs)
{
	char buff[MAX_SIZE + 1]{ '\0' };

	while (!ifs.eof())
	{
		ifs.getline(buff, MAX_SIZE + 1, DELIMITER);
		std::cout << buff << std::endl;
	}
}

void selfPrinting(const char* fileName)
{
	if (!fileName) return;

	std::ifstream ifs(fileName, std::ios::in);

	if (!ifs.is_open()) return;

	return selfPrinting(ifs);
}

int main()
{
	selfPrinting("text.txt");

	return 0;
}