#pragma once
#pragma warning (disable : 4996)

#include <iostream>

#define MAX_SECONDS_LENGTH 600

enum class Genre { NONE, ROCK, POP, EDM, RAP, JAZZ };

class Song
{
private:
	char* name = nullptr;
	Genre genre = Genre::NONE;
	size_t seconds = 0;

	Song* next = nullptr;

	void copyFrom(const Song& other);
	void moveFrom(Song&& other) noexcept;
	void free();

public:
	Song();
	Song(const char* name, Genre genre, size_t seconds);
	Song(const char* name, Genre genre, size_t seconds, Song* next);

	Song(const Song& other);
	Song& operator=(const Song& other);

	Song(Song&& other) noexcept;
	Song& operator=(Song&& other) noexcept;

	const char* getName() const;
	const char* getGenreString() const;
	Genre getGenre() const;
	size_t getSeconds() const;

	void setName(const char* name);
	void setGenre(Genre genre);
	void setSeconds(size_t seconds);

	Song* getNextSong() const;

	void setNextSong(Song* nextSong);

	void printSong() const;

	~Song() noexcept;
};