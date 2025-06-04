#pragma once

#include <cstring>

#include "../Functions/Function.hpp"
#include "../FunctionFactory/FunctionFactory.hpp"

class UserInterface
{
private:
	char* fileName = nullptr;

	void copyFrom(const UserInterface& other);
	void moveFrom(UserInterface&& other) noexcept;
	void free();

	void generateFunctionRangeValues(Function* function) const;
	void generateFunctionValuesSequentially(Function* function) const;

public:
	UserInterface(const char* fileName);

	UserInterface(const UserInterface& other);
	UserInterface& operator=(const UserInterface& other);

	UserInterface(UserInterface&& other) noexcept;
	UserInterface& operator=(UserInterface&& other) noexcept;

	const char* getFileName() const;

	void run() const;

	~UserInterface() noexcept;
};

UserInterface::UserInterface(const char* fileName)
{
	if (!fileName)
	{
		throw std::runtime_error("UserInterface: NULLPTR!");
	}

	this->fileName = new char[strlen(fileName) + 1];
	strcpy(this->fileName, fileName);
}

void UserInterface::run() const
{
	Function* function = generateFunction(fileName);

	if (!function)
	{
		throw std::runtime_error("UserInterface: NULLPTR!");
	}

	std::cout << "Welcome to Function Modifier Interface!" << std::endl;
	std::cout << "Commands: " << std::endl;
	std::cout << "1 - Generate all the results in the range [ A ... B ]" << std::endl;
	std::cout << "2 - Press 'Y' / 'N' to sequentially generate all function results in [ A ... INT32_MAX ]" << std::endl;

	size_t N = 0;

	while (std::cin >> N)
	{
		if (N == 1)
		{
			return generateFunctionRangeValues(function);
		}
		else if (N == 2)
		{
			return generateFunctionValuesSequentially(function);
		}
		else
		{
			delete function;
			function = nullptr;
			return;
		}
	}
}

void UserInterface::generateFunctionRangeValues(Function* function) const
{
	if (!function)
	{
		throw std::runtime_error("UserInterface: NULLPTR!");
	}

	int32_t A = 0;
	int32_t B = 0;

	std::cout << "Enter A: "; std::cin >> A;
	std::cout << "Enter B: "; std::cin >> B;

	for (int32_t x = A; x <= B; x++)
	{
		try
		{
			if (function->isDefined(x))
			{
				std::cout << "F(" << x << ") = " << function->operator()(x);

				if (x == INT32_MAX)
				{
					delete function;
					return;
				}
			}

			if (x == INT32_MAX)
			{
				delete function;
				return;
			}
		}
		catch (const std::invalid_argument& exc) { continue; }
		catch (const std::out_of_range& exc) { continue; }
		catch (const std::runtime_error& exc) { continue; }
		catch (const std::exception& exc) { continue; }
		catch (...) { continue; }
	}

	delete function;
	function = nullptr;
}

void UserInterface::generateFunctionValuesSequentially(Function* function) const
{
	if (!function)
	{
		throw std::runtime_error("UserInterface: NULLPTR!");
	}

	int32_t start = 0;
	std::cout << "Enter starting point: "; std::cin >> start;

	char command;

	std::cout << "Press 'Y' or 'y' to generate next Function Result / 'N' to terminate: "; std::cin >> command;

	while (command == 'Y' || command == 'y')
	{
		try
		{
			if (function->operator()(start).getLhs())
			{
				std::cout << "F(" << start << ") = " << function->operator()(start) << std::endl;
			}
			else
			{
				bool found = false;

				for (int32_t x = start; x <= INT32_MAX; x++)
				{
					if (function->operator()(x).getLhs())
					{
						start = x;
						std::cout << "F(" << start << ") = " << function->operator()(start) << std::endl;
						found = true;
						break;
					}

					if (x == INT32_MAX)
					{
						break;
					}
				}

				if (!found || start == INT32_MAX)
				{
					delete function;
					return;
				}
			}
		}
		catch (const std::out_of_range& exc) { break; }
		catch (const std::runtime_error& exc) { break; }
		catch (const std::exception& exc) { break; }
		catch (...) { break; }

		start++;
		std::cout << "Press 'Y' or 'y' to generate next Function Result / 'N' to terminate: "; std::cin >> command;
	};

	delete function;
	function = nullptr;
}

UserInterface::UserInterface(const UserInterface& other)
{
	copyFrom(other);
}

UserInterface& UserInterface::operator=(const UserInterface& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

UserInterface::UserInterface(UserInterface&& other) noexcept
{
	moveFrom(std::move(other));
}

UserInterface& UserInterface::operator=(UserInterface&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

const char* UserInterface::getFileName() const
{
	return this->fileName;
}

UserInterface::~UserInterface() noexcept
{
	free();
}

void UserInterface::copyFrom(const UserInterface& other)
{
	this->fileName = new char[strlen(other.fileName) + 1];
	strcpy(this->fileName, other.fileName);
}

void UserInterface::moveFrom(UserInterface&& other) noexcept
{
	this->fileName = other.fileName;
	other.fileName = nullptr;
}

void UserInterface::free()
{
	delete[] this->fileName;
	this->fileName = nullptr;
}
