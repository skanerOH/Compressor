#pragma once

#ifndef KURSACH_BWT_H
#define KURSACH_BWT_H

#include <vector>
#include <algorithm>
#include <cstring>
#include <memory>
#include <string>
#include <climits>

class BWT
{
private:
	static const unsigned char MaxBlockSize = UCHAR_MAX-1;

	static std::vector<char> encodeBlock(std::vector<char> inpVect);

	static std::vector<char> decodeBlock(std::vector<char> inpVect);
public:

	static std::shared_ptr<std::vector<char>> encode(const std::shared_ptr<std::vector<char>>& inpVect);

	static std::shared_ptr<std::vector<char>> decode(const std::shared_ptr<std::vector<char>>& inpVect);
};


#endif //KURSACH_BWT_H