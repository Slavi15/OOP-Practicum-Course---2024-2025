#pragma warning (disable: 4996)

#include <iostream>
#include <fstream>

namespace Constants
{
	constexpr size_t NAME_MAX_SIZE = 128;
	constexpr size_t STUDENTS_MAX_SIZE = 100;
	constexpr char DELIMITER = ' ';
}

namespace StudentNS
{
	using namespace Constants;

	enum class Subject : uint8_t
	{
		NONE,
		SI,
		IS,
		PM,
		INF
	};

	struct Student
	{
		char name[NAME_MAX_SIZE + 1]{ '\0' };
		Subject subject = Subject::NONE;
		size_t age = 0;
		size_t FN = 0;
	};

	Student readStudent(std::ifstream& ifs)
	{
		Student toReturn;

		ifs.ignore();
		ifs.getline(toReturn.name, NAME_MAX_SIZE, DELIMITER);

		int type;
		ifs >> type;
		toReturn.subject = (Subject)type;

		ifs >> toReturn.age >> toReturn.FN;

		return toReturn;
	}

	Student readStudent(const char* fileName)
	{
		if (!fileName) return {};

		std::ifstream ifs(fileName, std::ios::in);

		if (!ifs.is_open()) return {};

		return readStudent(ifs);
	}

	void writeStudent(std::ofstream& ofs, const Student& obj)
	{
		ofs << obj.name << " " << (int)obj.subject << " " << obj.age << " " << obj.FN << std::endl;
	}

	void writeStudent(const char* fileName, const Student& obj)
	{
		if (!fileName) return;

		std::ofstream ofs(fileName, std::ios::out);

		if (!ofs.is_open()) return;

		return writeStudent(ofs, obj);
	}

	void printStudent(const Student& obj)
	{
		std::cout << obj.name << " " << (int)obj.subject << " " << obj.age << " " << obj.FN << std::endl;
	}
}

namespace UniversityNS
{
	using namespace StudentNS;

	struct University
	{
		Student students[STUDENTS_MAX_SIZE];
		size_t size = 0;
	};

	University readUniversity(std::ifstream& ifs)
	{
		University toReturn;

		ifs >> toReturn.size;

		for (size_t i = 0; i < toReturn.size; i++)
		{
			toReturn.students[i] = readStudent(ifs);
		}

		return toReturn;
	}

	University readUniversity(const char* fileName)
	{
		if (!fileName) return {};

		std::ifstream ifs(fileName, std::ios::in);

		if (!ifs.is_open()) return {};

		return readUniversity(ifs);
	}

	void writeUniversity(std::ofstream& ofs, const University& obj)
	{
		ofs << obj.size << std::endl;

		for (size_t i = 0; i < obj.size; i++)
		{
			writeStudent(ofs, obj.students[i]);
		}
	}

	void writeUniversity(const char* fileName, const University& obj)
	{
		if (!fileName) return;

		std::ofstream ofs(fileName, std::ios::out);

		if (!ofs.is_open()) return;

		return writeUniversity(ofs, obj);
	}

	void printUniversity(const University& obj)
	{
		std::cout << obj.size << std::endl;

		for (size_t i = 0; i < obj.size; i++)
		{
			printStudent(obj.students[i]);
		}
	}
}

int main()
{
	using namespace UniversityNS;

	University university;

	university.size = 3;
	university.students[0] = { "Slavi", Subject::SI, 21, 12345 };
	university.students[1] = { "Martin", Subject::SI, 22, 56789 };
	university.students[2] = { "Ivan", Subject::INF, 30, 13579 };

	writeUniversity("university.txt", university);

	printUniversity(university);

	University uni = readUniversity("university.txt");

	printUniversity(uni);

	return 0;
}
