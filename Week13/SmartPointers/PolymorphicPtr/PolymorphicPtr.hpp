#pragma once

#include <iostream>

template <typename T>
class PolymorphicPtr
{
private:
	T* ptr;

	void copyFrom(const PolymorphicPtr<T>& other);
	void moveFrom(PolymorphicPtr<T>&& other) noexcept;
	void free();

public:
	PolymorphicPtr();
	PolymorphicPtr(T* ptr);

	PolymorphicPtr(const PolymorphicPtr<T>& other);
	PolymorphicPtr& operator=(const PolymorphicPtr<T>& other);

	PolymorphicPtr(PolymorphicPtr<T>&& other) noexcept;
	PolymorphicPtr& operator=(PolymorphicPtr<T>&& other) noexcept;

	const T* operator->() const;
	T* operator->();

	const T& operator*() const;
	T& operator*();

	const T* get() const;
	T* get();

	~PolymorphicPtr() noexcept;
};

template <typename T>
PolymorphicPtr<T>::PolymorphicPtr() : ptr(nullptr)
{
}

template <typename T>
PolymorphicPtr<T>::PolymorphicPtr(T* ptr) : ptr(ptr) {}

template <typename T>
PolymorphicPtr<T>::PolymorphicPtr(const PolymorphicPtr<T>& other)
{
	copyFrom(other);
}

template <typename T>
PolymorphicPtr<T>& PolymorphicPtr<T>::operator=(const PolymorphicPtr<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template <typename T>
PolymorphicPtr<T>::PolymorphicPtr(PolymorphicPtr<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template <typename T>
PolymorphicPtr<T>& PolymorphicPtr<T>::operator=(PolymorphicPtr<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template <typename T>
const T* PolymorphicPtr<T>::operator->() const
{
	return this->ptr;
}

template <typename T>
T* PolymorphicPtr<T>::operator->()
{
	return this->ptr;
}

template <typename T>
const T& PolymorphicPtr<T>::operator*() const
{
	if (!this->ptr)
		throw std::runtime_error("nullptr!");

	return *this->ptr;
}

template <typename T>
T& PolymorphicPtr<T>::operator*()
{
	if (!this->ptr)
		throw std::runtime_error("nullptr!");

	return *this->ptr;
}

template <typename T>
const T* PolymorphicPtr<T>::get() const
{
	return this->ptr;
}

template <typename T>
T* PolymorphicPtr<T>::get()
{
	return this->ptr;
}

template <typename T>
PolymorphicPtr<T>::~PolymorphicPtr() noexcept
{
	free();
}

template <typename T>
void PolymorphicPtr<T>::copyFrom(const PolymorphicPtr<T>& other)
{
	this->ptr = other.ptr->clone();
}

template <typename T>
void PolymorphicPtr<T>::moveFrom(PolymorphicPtr<T>&& other) noexcept
{
	this->ptr = other.ptr;
	other.ptr = nullptr;
}

template <typename T>
void PolymorphicPtr<T>::free()
{
	delete this->ptr;
	this->ptr = nullptr;
}
