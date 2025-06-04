#pragma once

#include "../Functions/Function.hpp"

#include "../FileReaders/FileReader.hpp"
#include "../FileReaders/FileData.hpp"

#include "../FileReaders/ZeroReader.hpp"
#include "../FileReaders/FirstReader.hpp"
#include "../FileReaders/SecondReader.hpp"
#include "../FileReaders/ThirdReader.hpp"
#include "../FileReaders/FourthReader.hpp"

Function* generateFunction(const String& filePath)
{
	std::ifstream ifs(filePath.c_str(), std::ios::in | std::ios::binary);

	if (!ifs.is_open())
	{
		throw std::runtime_error("Function Factory: File could not be opened!");
	}

	FileData fileData(ifs);

	if (fileData.getN() > 32)
	{
		throw std::out_of_range("Function Factory: Invalid value of N!");
	}

	FileReader* reader = nullptr;

	switch (fileData.getT())
	{
	case 0:
		reader = new ZeroReader(filePath);
		break;
	case 1:
		reader = new FirstReader(filePath);
		break;
	case 2:
		reader = new SecondReader(filePath);
		break;
	case 3:
		reader = new ThirdReader(filePath);
		break;
	case 4:
		reader = new FourthReader(filePath);
		break;
	default:
		return nullptr;
	}

	try
	{
		Function* toReturn = reader->read(ifs, fileData.getN());
		delete reader;
		return toReturn;
	}
	catch (const std::invalid_argument& exc)
	{
		std::cout << "Error: " << exc.what() << std::endl;
		delete reader;
		return nullptr;
	}
	catch (const std::out_of_range& exc)
	{
		std::cout << "Error: " << exc.what() << std::endl;
		delete reader;
		return nullptr;
	}
	catch (const std::logic_error& exc)
	{
		std::cout << "Error: " << exc.what() << std::endl;
		delete reader;
		return nullptr;
	}
	catch (const std::runtime_error& exc)
	{
		std::cout << "Error: " << exc.what() << std::endl;
		delete reader;
		return nullptr;
	}
	catch (const std::exception& exc)
	{
		std::cout << "Error: " << exc.what() << std::endl;
		delete reader;
		return nullptr;
	}
	catch (...)
	{
		delete reader;
		return nullptr;
	}
}