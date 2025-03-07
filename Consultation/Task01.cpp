#include <iostream>

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
}

void freeArray(int* arr)
{
	if (!arr) return;
	delete[] arr;
	arr = nullptr;
}

void insertAt(int*& arr, size_t& len, int index, int elem)
{
	if (index < 0 || index > len) return;

	int* newArray = new int[len + 1];

	size_t newIndex = 0;

	for (size_t i = 0; i < index; i++)
	{
		newArray[newIndex++] = arr[i];
	}

	newArray[newIndex++] = elem;

	for (size_t i = index; i < len; i++)
	{
		newArray[newIndex++] = arr[i];
	}

	len++;

	delete[] arr;
	arr = newArray;
}

void removeAt(int*& arr, size_t& len, int index)
{
	int* newArray = new int[len - 1];

	size_t newIndex = 0;

	for (size_t i = 0; i < len; i++)
	{
		if (i == index) continue;

		newArray[newIndex++] = arr[i];
	}

	len--;

	delete[] arr;
	arr = newArray;
}

int main()
{
	size_t N = 0;
	std::cin >> N;

	int* arr = readArray(N);

	removeAt(arr, N, 1);

	printArray(arr, N);

	freeArray(arr);

	return 0;
}
