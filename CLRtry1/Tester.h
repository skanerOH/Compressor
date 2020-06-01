#pragma once

#ifndef KURSACH_TESTER_H
#define KURSACH_TESTER_H

#include <string>
#include "BWT.h"
#include "Huffman.h"
#include "LZW.h"
#include "RLE.h"
#include "FileAccessor.h"
#include <chrono>


class Tester
{
public:
	static std::string GetTesting(std::string inpPath, char method, bool useBWT);
};

#endif //KURSACH_TESTER_H