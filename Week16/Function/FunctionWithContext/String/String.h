#pragma once

#pragma warning (disable : 4996)

#include <iostream>
#include <fstream>
#include <cstring>

#define MAX_TEXT_LENGTH 1024

class String
{
private:
	char* data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	explicit String(size_t newSize);

	unsigned int getNextPowerOfTwo(unsigned int n) const;
	unsigned int allocateCapacity(unsigned int size) const;

	void resize(size_t newCapacity);

	void copyFrom(const String& other);
	void moveFrom(String&& other) noexcept;
	void free();

public:
	String();
	String(const char* data);

	String(const String& other);
	String& operator=(const String& other);

	String(String&& other) noexcept;
	String& operator=(String&& other) noexcept;

	size_t getSize() const;
	size_t getCapacity() const;

	const char* c_str() const;

	const char& operator[](size_t index) const;
	char& operator[](size_t index);

	String& operator+=(const String& other);
	String& operator+=(char ch);

	friend String operator+(const String& lhs, const String& rhs);
	friend String operator+(const String& lhs, char ch);

	String substr(size_t begin, size_t howMany) const;

	friend bool operator==(const String& lhs, const String& rhs);
	friend bool operator!=(const String& lhs, const String& rhs);

	friend bool operator<(const String& lhs, const String& rhs);
	friend bool operator<=(const String& lhs, const String& rhs);

	friend bool operator>(const String& lhs, const String& rhs);
	friend bool operator>=(const String& lhs, const String& rhs);

	friend std::istream& operator>>(std::istream& is, String& ref);
	friend std::ostream& operator<<(std::ostream& os, const String& ref);

	~String() noexcept;
};