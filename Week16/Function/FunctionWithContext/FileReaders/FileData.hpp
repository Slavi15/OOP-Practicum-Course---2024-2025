#pragma once

class FileData
{
private:
	uint16_t N = 0;
	uint16_t T = 0;

public:
	FileData(std::ifstream& ifs);

	uint16_t getN() const;
	uint16_t getT() const;
};

FileData::FileData(std::ifstream& ifs)
{
	ifs.read(reinterpret_cast<char*>(&this->N), sizeof(uint16_t));
	ifs.read(reinterpret_cast<char*>(&this->T), sizeof(uint16_t));
}

uint16_t FileData::getN() const
{
	return this->N;
}

uint16_t FileData::getT() const
{
	return this->T;
}