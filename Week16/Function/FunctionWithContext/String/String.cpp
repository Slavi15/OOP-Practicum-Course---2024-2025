#include "String.h"

String::String() : String("") {}

String::String(size_t newSize) : size(0)
{
	this->capacity = allocateCapacity(newSize);
	this->data = new char[this->capacity] { '\0' };
}

String::String(const char* data)
{
	if (!data)
		throw std::runtime_error("NULLPTR!");

	this->size = strlen(data);
	this->capacity = allocateCapacity(this->size);

	this->data = new char[this->capacity];
	strcpy(this->data, data);
}

String::String(const String& other)
{
	copyFrom(other);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

String::String(String&& other) noexcept
{
	moveFrom(std::move(other));
}

String& String::operator=(String&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

size_t String::getSize() const
{
	return this->size;
}

size_t String::getCapacity() const
{
	return this->capacity;
}

const char* String::c_str() const
{
	return this->data;
}

const char& String::operator[](size_t index) const
{
	return this->data[index];
}

char& String::operator[](size_t index)
{
	return this->data[index];
}

String& String::operator+=(const String& other)
{
	if (getSize() + other.getSize() >= getCapacity())
	{
		resize(allocateCapacity(getSize() + other.getSize()));
	}

	strncat(this->data, other.data, other.getSize());

	this->size += other.getSize();

	return *this;
}

String& String::operator+=(char ch)
{
	if (getSize() + 1 >= getCapacity())
	{
		resize(allocateCapacity(getSize() + 1));
	}

	this->data[this->size++] = ch;
	this->data[this->size] = '\0';

	return *this;
}

String String::substr(size_t begin, size_t howMany) const
{
	if (begin + howMany > getSize())
		throw std::out_of_range("Substr: Too many symbols!");

	String toReturn(howMany);
	strncat(toReturn.data, this->data + begin, howMany);
	return toReturn;
}

String operator+(const String& lhs, const String& rhs)
{
	String toReturn(lhs.getSize() + rhs.getSize());
	toReturn += rhs;
	return toReturn;
}

String operator+(const String& lhs, char ch)
{
	String toReturn(lhs.getSize() + 1);
	toReturn += ch;
	return toReturn;
}

bool operator==(const String& lhs, const String& rhs)
{
	return strcmp(lhs.data, rhs.data) == 0;
}

bool operator!=(const String& lhs, const String& rhs)
{
	return strcmp(lhs.data, rhs.data) != 0;
}

bool operator<(const String& lhs, const String& rhs)
{
	return strcmp(lhs.data, rhs.data) < 0;
}

bool operator<=(const String& lhs, const String& rhs)
{
	return strcmp(lhs.data, rhs.data) <= 0;
}

bool operator>(const String& lhs, const String& rhs)
{
	return strcmp(lhs.data, rhs.data) > 0;
}

bool operator>=(const String& lhs, const String& rhs)
{
	return strcmp(lhs.data, rhs.data) >= 0;
}

std::istream& operator>>(std::istream& is, String& ref)
{
	char buff[MAX_TEXT_LENGTH + 1];
	is >> buff;

	size_t buffLength = strlen(buff);

	if (buffLength >= ref.getCapacity())
	{
		ref.resize(ref.allocateCapacity(buffLength));
	}

	strcpy(ref.data, buff);

	ref.size = buffLength;

	return is;
}

std::ostream& operator<<(std::ostream& os, const String& ref)
{
	return os << ref.data;
}

String::~String() noexcept
{
	free();
}

unsigned int String::getNextPowerOfTwo(unsigned int n) const
{
	if (n == 0) return 1;

	while (n & (n - 1))
	{
		n &= (n - 1);
	}

	return n << 1;
}

unsigned int String::allocateCapacity(unsigned int size) const
{
	return std::max(getNextPowerOfTwo(size + 1), 16u);
}

void String::resize(size_t newCapacity)
{
	this->capacity = newCapacity;

	char* newData = new char[this->capacity];
	strcpy(newData, this->data);

	delete[] this->data;

	this->data = newData;
}

void String::copyFrom(const String& other)
{
	this->size = other.size;
	this->capacity = other.capacity;

	this->data = new char[strlen(other.data) + 1];
	strcpy(this->data, other.data);
}

void String::moveFrom(String&& other) noexcept
{
	this->data = other.data;
	this->size = other.size;
	this->capacity = other.capacity;

	other.data = nullptr;
	other.size = other.capacity = 0;
}

void String::free()
{
	delete[] this->data;

	this->data = nullptr;
	this->size = this->capacity = 0;
}