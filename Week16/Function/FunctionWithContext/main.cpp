#include <iostream>

#include "UserInterface/UserInterface.hpp"

// For testing purposes!
//int m(int k)
//{
//	return k;
//}

int main()
{
	try
	{
		UserInterface input("minFunc.dat");
		input.run();
	}
	catch (const std::invalid_argument& exc)
	{
		std::cout << "Error: " << exc.what() << std::endl;
	}
	catch (const std::out_of_range& exc)
	{
		std::cout << "Error: " << exc.what() << std::endl;
	}
	catch (const std::logic_error& exc)
	{
		std::cout << "Error: " << exc.what() << std::endl;
	}
	catch (const std::runtime_error& exc)
	{
		std::cout << "Error: " << exc.what() << std::endl;
	}
	catch (const std::exception& exc)
	{
		std::cout << "Error: " << exc.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Error!" << std::endl;
	}

	// For testing purposes!

	/*
	int32_t x = 50;
	FunctionCriteria f = [x](int32_t a) {
		std::cout << x << std::endl;
		return a;
		};
	std::cout << f(5) << std::endl;

	int32_t arr[3] = { 1,2,3 };
	int32_t size = 3;
	FunctionCriteria g = [arr, size](int32_t x) {
		for (size_t i = 0; i < 3; i++)
		{
			std::cout << arr[i] << std::endl;
		}
		return x;
		};
	std::cout << g(10) << std::endl;

	g.isDefined(2);

	FunctionCriteria t = &m;

	int32_t arr2[3] = { 1,2,3 };
	int32_t size2 = 3;
	FunctionCriteria h = [arr2, size2](int32_t x) {
		for (size_t i = 0; i < 3; i++)
		{
			std::cout << arr2[i] << std::endl;
		}
		return x;
		};
	std::cout << h(100);

	FunctionDataManagement container;

	container.addFunction(f);
	container.addFunction(g);
	container.addFunction(h);

	int32_t arr3[3] = { 1,2,3 };
	int32_t size3 = 3;

	MaxFunction max(container);
	*/

	// For testing purposes!

	return 0;
}