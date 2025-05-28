#pragma once

class BooleanInterpretation
{
private:
	static constexpr size_t ALPHABET_SIZE = 26;

private:
	bool values[26] = { false };

public:
	void set(char ch, bool condition);

	bool operator()(char ch) const;
};
