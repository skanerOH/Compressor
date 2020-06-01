#pragma once

#ifndef KURSACH_RLE_H
#define KURSACH_RLE_H

#include "FileAccessor.h"

#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <climits>
#include <deque>


class RLE {
public:
	static void encode(const std::shared_ptr<std::vector<char>>& inpVect, const std::string& path);

	static std::shared_ptr<std::vector<char>> decode(const std::string& path);
};

#endif //KURSACH_RLE_H