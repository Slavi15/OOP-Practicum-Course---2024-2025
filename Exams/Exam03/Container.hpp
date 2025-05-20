#pragma once

#include <utility>

template <typename T>
class Container
{
private:
	T** data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	explicit Container(size_t size);

	void resize(size_t newCapacity);

	unsigned int getNextPowerOfTwo(unsigned int n) const;
	unsigned int allocateCapacity(unsigned int n) const;

	void copyFrom(const Container<T>& other);
	void moveFrom(Container<T>&& other) noexcept;
	void free();

public:
	Container();

	Container(const Container<T>& other);
	Container<T>& operator=(const Container<T>& other);

	Container(Container<T>&& other) noexcept;
	Container<T>& operator=(Container<T> && other) noexcept;

	size_t getSize() const;
	size_t getCapacity() const;

	void push_back(T* ptr);

	const T* operator[](size_t idx) const;

	~Container() noexcept;
};

template<typename T>
inline Container<T>::Container() : Container(4)
{
}

template<typename T>
inline Container<T>::Container(size_t size) : size(0)
{
	this->capacity = allocateCapacity(size);
	this->data = new T * [this->capacity] { nullptr };
}


template<typename T>
inline Container<T>::Container(const Container<T>& other)
{
	copyFrom(other);
}

template<typename T>
inline Container<T>& Container<T>::operator=(const Container<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
inline Container<T>::Container(Container<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
inline Container<T>& Container<T>::operator=(Container<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
inline size_t Container<T>::getSize() const
{
	return this->size;
}

template<typename T>
inline size_t Container<T>::getCapacity() const
{
	return this->capacity;
}

template<typename T>
inline void Container<T>::push_back(T* ptr)
{
	if (getSize() >= getCapacity())
	{
		resize(getCapacity() * 2);
	}

	this->data[this->size++] = ptr;
}

template<typename T>
inline const T* Container<T>::operator[](size_t idx) const
{
	return this->data[idx];
}

template<typename T>
inline Container<T>::~Container() noexcept
{
	free();
}

template<typename T>
inline unsigned int Container<T>::getNextPowerOfTwo(unsigned int n) const
{
	if (n == 0) return 1;

	while (n & (n - 1))
	{
		n &= (n - 1);
	}

	return n << 1;
}

template<typename T>
inline unsigned int Container<T>::allocateCapacity(unsigned int n) const
{
	return std::max(getNextPowerOfTwo(n + 1), 8u);
}

template<typename T>
inline void Container<T>::resize(size_t newCapacity)
{
	T** newData = new T * [newCapacity];

	for (size_t i = 0; i < getSize(); i++)
	{
		newData[i] = this->data[i];
	}

	delete[] this->data;
	this->data = newData;
	this->capacity = newCapacity;
}

template<typename T>
inline void Container<T>::copyFrom(const Container<T>& other)
{
	this->size = other.size;
	this->capacity = other.capacity;

	this->data = new T * [this->capacity];

	for (size_t i = 0; i < this->capacity; i++)
	{
		this->data[i] = other.data[i]->clone();
	}
}

template<typename T>
inline void Container<T>::moveFrom(Container<T>&& other) noexcept
{
	this->data = other.data;
	this->size = other.size;
	this->capacity = other.capacity;

	other.data = nullptr;
	other.size = other.capacity = 0;
}

template<typename T>
inline void Container<T>::free()
{
	for (size_t i = 0; i < getSize(); i++)
	{
		delete this->data[i];
	}

	delete[] this->data;

	this->data = nullptr;
	this->size = this->capacity = 0;
}
