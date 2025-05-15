#include <iostream>
#include <fstream>

#include "ShapesCollection.h"

int main()
{
	uint32_t arr[10] = { 100, 210, 14, 10, 1, 1004, 50 };

	std::ofstream ofs("input.bin", std::ios::out);

	ofs.write(reinterpret_cast<const char*>(arr), sizeof(uint32_t) * 10);

	ofs.close();

	return 0;
}