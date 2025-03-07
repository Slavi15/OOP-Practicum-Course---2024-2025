#include <iostream>

int** readMatrix(size_t rows, size_t cols)
{
	int** mtx = new int* [rows] { nullptr };

	for (size_t i = 0; i < rows; i++)
	{
		mtx[i] = new int[cols] { 0 };

		for (size_t j = 0; j < cols; j++)
		{
			int num = 0;
			std::cin >> num;

			mtx[i][j] = num;
		}
	}

	return mtx;
}

void deleteMatrix(const int* const* mtx, size_t rows)
{
	if (!mtx) return;

	for (size_t i = 0; i < rows; i++)
	{
		delete[] mtx[i];
	}

	delete[] mtx;
}

void printMatrix(const int* const* mtx, size_t rows, size_t cols)
{
	if (!mtx) return;

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			std::cout << mtx[i][j] << " ";
		}

		std::cout << std::endl;
	}
}

int main()
{
	size_t rows = 0, cols = 0;
	std::cin >> rows >> cols;

	int** mtx = readMatrix(rows, cols);

	printMatrix(mtx, rows, cols);

	deleteMatrix(mtx, rows);

	return 0;
}
