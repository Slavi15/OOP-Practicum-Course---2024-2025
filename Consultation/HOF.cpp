#include <iostream>

using Predicate = bool (*)(int);
using MapFunction = int (*)(int);

int* readArray(size_t N)
{
	int* arr = new int[N];

	for (size_t i = 0; i < N; i++)
	{
		std::cin >> arr[i];
	}

	return arr;
}

void printArray(const int* arr, size_t N)
{
	if (!arr) return;

	for (size_t i = 0; i < N; i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}

void freeArray(int* arr)
{
	if (!arr) return;
	delete[] arr;
	arr = nullptr;
}

void map(int* arr, size_t size, MapFunction mapFunction)
{
	if (!arr || !mapFunction) return;

	for (size_t i = 0; i < size; i++)
	{
		arr[i] = mapFunction(arr[i]);
	}
}

void filter(int*& arr, size_t& N, Predicate predicate)
{
	if (!arr || !predicate) return;

	size_t len = 0;

	for (size_t i = 0; i < N; i++)
	{
		if (predicate(arr[i]))
		{
			len++;
		}
	}

	int* toReturn = new int[len];
	size_t idx = 0;

	for (size_t i = 0; i < N; i++)
	{
		if (predicate(arr[i]))
		{
			toReturn[idx++] = arr[i];
		}
	}

	N = len;

	delete[] arr;
	arr = toReturn;
}

bool any(const int* arr, size_t size, Predicate predicate)
{
	if (!arr || !predicate) return false;

	for (size_t i = 0; i < size; i++)
	{
		if (predicate(arr[i]))
		{
			return true;
		}
	}

	return false;
}

bool all(const int* arr, size_t size, Predicate predicate)
{
	if (!arr || !predicate) return false;

	for (size_t i = 0; i < size; i++)
	{
		if (!predicate(arr[i]))
		{
			return false;
		}
	}

	return true;
}

bool none(const int* arr, size_t size, Predicate predicate)
{
	if (!arr || !predicate) return false;

	for (size_t i = 0; i < size; i++)
	{
		if (predicate(arr[i]))
		{
			return false;
		}
	}

	return true;
}

const int* find_if(const int* arr, size_t size, Predicate predicate)
{
	if (!arr || !predicate) return nullptr;

	for (size_t i = 0; i < size; i++)
	{
		if (predicate(arr[i]))
		{
			return &arr[i];
		}
	}

	return nullptr;
}

bool isEven(int n)
{
	return n % 2 == 0;
}

bool isOdd(int n)
{
	return n % 2 == 0;
}

int square(int x)
{
	return x * x;
}

int main()
{
	size_t N = 0;
	std::cin >> N;

	int* arr = readArray(N);

	std::cout << any(arr, N, isEven) << std::endl;

	map(arr, N, square);

	printArray(arr, N);

	filter(arr, N, isEven);

	printArray(arr, N);

	return 0;
}
