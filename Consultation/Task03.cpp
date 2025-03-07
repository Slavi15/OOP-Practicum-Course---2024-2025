#include <iostream>

constexpr size_t SIZE = 7;

int findOddElement(const int* arr, size_t size)
{
	if (!arr) return 0;

	int XOR = 0;
	for (size_t i = 0; i < size; i++)
	{
		XOR ^= arr[i];
	}
	return XOR;
}

int main()
{
	int arr[SIZE]{ 5, 3, 4, 0, 5, 4, 3 };

	std::cout << findOddElement(arr, SIZE) << std::endl;

	return 0;
}