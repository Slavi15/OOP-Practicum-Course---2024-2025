#include "Playlist.h"

Playlist::Playlist() = default;

Playlist::Playlist(Song* song) : song(song) {}

Playlist::Playlist(const Playlist& other)
{
	copyFrom(other);
}

Playlist& Playlist::operator=(const Playlist& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Playlist::Playlist(Playlist&& other) noexcept
{
	moveFrom(std::move(other));
}

Playlist& Playlist::operator=(Playlist&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Song* Playlist::getSong() const
{
	return this->song;
}

void Playlist::setSong(Song* song)
{
	if (!song) return;

	this->song = song;
}

int Playlist::findSong(const Song& song)
{
	int index = 0;

	if (strcmp(this->song->getName(), song.getName()) == 0)
		return index;

	Song* nextSong = this->song;

	while (strcmp(this->song->getName(), song.getName()) != 0 && nextSong != nullptr)
	{
		nextSong = nextSong->getNextSong();
		index++;
	}

	return index ? index : -1;
}

const Song* Playlist::operator[](size_t index) const
{
	Song* nextSong = this->song;
	size_t currentIndex = 0;

	while (currentIndex != index)
	{
		nextSong = nextSong->getNextSong();
		currentIndex++;
	}

	return nextSong;
}

Song* Playlist::operator[](size_t index)
{
	Song* nextSong = this->song;
	size_t currentIndex = 0;

	while (currentIndex != index)
	{
		nextSong = nextSong->getNextSong();
		currentIndex++;
	}

	return nextSong;
}

const Song* Playlist::operator[](const char* name) const
{
	if (!name) return nullptr;

	Song* nextSong = this->song;

	while (strcmp(nextSong->getName(), name) != 0 && nextSong != nullptr)
	{
		nextSong = nextSong->getNextSong();
	}

	return nextSong;
}

Song* Playlist::operator[](const char* name)
{
	if (!name) return nullptr;

	Song* nextSong = this->song;

	while (strcmp(nextSong->getName(), name) != 0 && nextSong != nullptr)
	{
		nextSong = nextSong->getNextSong();
	}

	return nextSong;
}

Playlist& Playlist::operator+=(Song* song)
{
	Song* nextSong = this->song;

	while (nextSong->getNextSong() != nullptr)
	{
		nextSong = nextSong->getNextSong();
	}

	nextSong->setNextSong(song);
	return *this;
}

Playlist& Playlist::operator-=(Song* song)
{
	int foundIndex = findSong(*song);

	if (foundIndex == -1) return *this;

	Song* current = operator[](foundIndex);
	Song* next = current->getNextSong();

	while (next != nullptr)
	{
		if (strcmp(this->song->getName(), current->getName()) == 0)
		{
			this->song = next;
		}
		else
		{
			current = next;
		}
		
		next = next->getNextSong();
	}

	return *this;
}

Playlist::operator bool() const
{
	return this->song == nullptr;
}

void Playlist::operator()() const
{
	Song* nextSong = this->song;

	while (nextSong != nullptr)
	{
		nextSong->printSong();
		nextSong = nextSong->getNextSong();
	}
}

Playlist::~Playlist() noexcept
{
	free();
}

void Playlist::copyFrom(const Playlist& other)
{
	this->song = other.song;
}

void Playlist::moveFrom(Playlist&& other) noexcept
{
	this->song = other.song;
	other.song = nullptr;
}

void Playlist::free()
{
	delete this->song;
	this->song = nullptr;
}
