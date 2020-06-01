#pragma once

#ifndef KURSACH_COMPRESSOR_H
#define KURSACH_COMPRESSOR_H

#include <string>
#include "BWT.h"
#include "Huffman.h"
#include "LZW.h"
#include "RLE.h"
#include "FileAccessor.h"

class Compressor {
public:
	static int compress(const std::string& inpPath, const std::string& outPath, char method, bool useBWT);

	static int decompress(const std::string& inpPath, const std::string& outPath, char method, bool useBWT);
};

#endif //KURSACH_COMPRESSOR_H