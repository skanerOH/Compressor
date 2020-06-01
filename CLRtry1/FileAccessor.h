#pragma once

#ifndef KURSACH_FILEACCESSOR_H
#define KURSACH_FILEACCESSOR_H

#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <climits>

class FileAccessor
{
public:
	static std::shared_ptr<std::vector<char>> GetSymbVectPtr(const std::string& path);

	static void WriteSymbVectToFile(const std::shared_ptr<std::vector<char>>& inpVect, const std::string& path);

	static long int GetFileSize(const std::string& path);
};

#endif //KURSACH_FILEACCESSOR_H