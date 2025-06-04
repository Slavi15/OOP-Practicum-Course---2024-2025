#pragma once

#include "Song.h"

class Playlist
{
private:
	Song* song = nullptr;

	int findSong(const Song& song);

	void copyFrom(const Playlist& other);
	void moveFrom(Playlist&& other) noexcept;
	void free();

public:
	Playlist();
	Playlist(Song* song);

	Playlist(const Playlist& other);
	Playlist& operator=(const Playlist& other);

	Playlist(Playlist&& other) noexcept;
	Playlist& operator=(Playlist&& other) noexcept;

	Song* getSong() const;

	void setSong(Song* song);

	const Song* operator[](size_t index) const;
	Song* operator[](size_t index);

	const Song* operator[](const char* name) const;
	Song* operator[](const char* name);

	Playlist& operator+=(Song* song);
	Playlist& operator-=(Song* song);

	operator bool() const;
	void operator()() const;

	~Playlist() noexcept;
};