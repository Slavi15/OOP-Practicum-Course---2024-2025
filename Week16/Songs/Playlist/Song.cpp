#include "Song.h"

Song::Song() = default;

Song::Song(const char* name, Genre genre, size_t seconds)
{
	setName(name);
	setGenre(genre);
	setSeconds(seconds);
}

Song::Song(const char* name, Genre genre, size_t seconds, Song* next) : next(next)
{
	setName(name);
	setGenre(genre);
	setSeconds(seconds);
}

Song::Song(const Song& other)
{
	copyFrom(other);
}

Song& Song::operator=(const Song& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Song::Song(Song&& other) noexcept
{
	moveFrom(std::move(other));
}

Song& Song::operator=(Song&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

const char* Song::getName() const
{
	return this->name;
}

const char* Song::getGenreString() const
{
	switch (genre)
	{
	case Genre::ROCK: return "ROCK";
	case Genre::POP: return "POP";
	case Genre::EDM: return "EDM";
	case Genre::RAP: return "RAP";
	case Genre::JAZZ: return "JAZZ";
	}

	return nullptr;
}

Genre Song::getGenre() const
{
	return this->genre;
}

size_t Song::getSeconds() const
{
	return this->seconds;
}

void Song::setName(const char* name)
{
	if (!name) return;

	delete[] this->name;
	this->name = new char[strlen(name) + 1] {};
	strcpy(this->name, name);
}

void Song::setGenre(Genre genre)
{
	this->genre = genre;
}

void Song::setSeconds(size_t seconds)
{
	if (seconds > MAX_SECONDS_LENGTH) return;

	this->seconds = seconds;
}

Song* Song::getNextSong() const
{
	return this->next;
}

void Song::setNextSong(Song* nextSong)
{
	this->next = nextSong;
}

void Song::printSong() const
{
	std::cout << "Song: " << getName() << " - " << getGenreString() << " - " << getSeconds() << std::endl;
}

Song::~Song() noexcept
{
	free();
}

void Song::copyFrom(const Song& other)
{
	this->name = new char[strlen(other.name) + 1] {};
	strcpy(this->name, other.name);

	this->next = other.next;

	this->genre = other.genre;
	this->seconds = other.seconds;
}

void Song::moveFrom(Song&& other) noexcept
{
	this->name = other.name;
	this->genre = other.genre;
	this->seconds = other.seconds;
	this->next = other.next;

	other.name = nullptr;
	other.next = nullptr;
	other.seconds = 0;
	other.genre = Genre::NONE;
}

void Song::free()
{
	delete[] this->name;
	delete this->next;

	this->name = nullptr;
	this->next = nullptr;
	this->seconds = 0;
	this->genre = Genre::NONE;
}
