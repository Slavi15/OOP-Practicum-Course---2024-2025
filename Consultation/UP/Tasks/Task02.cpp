#include <iostream>

constexpr size_t DAYS_OF_WEEK = 7;

enum class WeekDay : uint8_t
{
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY
};

const char* getWeekDay(WeekDay weekDay)
{
	switch (weekDay)
	{
	case WeekDay::MONDAY: return "Monday";
	case WeekDay::TUESDAY: return "Tuesday";
	case WeekDay::WEDNESDAY: return "Wednesday";
	case WeekDay::THURSDAY: return "Thursday";
	case WeekDay::FRIDAY: return "Friday";
	case WeekDay::SATURDAY: return "Saturday";
	case WeekDay::SUNDAY: return "Sunday";
	}
}

void setBit(uint8_t& weekDays, size_t k)
{
	uint8_t mask = 1 << k;
	weekDays |= mask;
}

bool checkBit(uint8_t weekDays, int k)
{
	uint8_t mask = 1 << k;
	return (weekDays & mask) == mask;
}

void fillData(uint8_t& weekDays, size_t N)
{
	for (size_t i = 0; i < N; i++)
	{
		size_t day;
		std::cin >> day;

		if (day < 0 || day > DAYS_OF_WEEK) continue;

		setBit(weekDays, day - 1);
	}
}

void printWeek(uint8_t weekDays)
{
	for (size_t i = 0; i < DAYS_OF_WEEK; i++)
	{
		if (checkBit(weekDays, i))
		{
			std::cout << getWeekDay((WeekDay)i) << " ";
		}
	}
}

int main()
{
	size_t N = 0;
	std::cin >> N;

	uint8_t weekDays = 0;

	fillData(weekDays, N);

	printWeek(weekDays);

	return 0;
}