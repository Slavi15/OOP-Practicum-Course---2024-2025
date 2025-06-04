#include <iostream>

#include "Song.h"
#include "Playlist.h"

int main()
{
	Song* s1 = new Song("Song1", Genre::ROCK, 206);
	Song* s2 = new Song("Song2", Genre::POP, 193, s1);

	Playlist p(s2);

	Song* s3 = new Song("Song3", Genre::RAP, 182);

	p += s3;

	Song* s4 = new Song("Song4", Genre::JAZZ, 432);

	p += s4;
	p -= s2;

	Song* found = p["Song3"];
	found->printSong();

	if (p)
	{
		std::cout << "Empty playlist!" << std::endl;
	}
	else
	{
		p();
	}

	return 0;
}