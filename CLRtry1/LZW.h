#pragma once

#ifndef KURSACH_LZW_H
#define KURSACH_LZW_H

#include <string>
#include <memory>
#include <vector>
#include <map>
#include <climits>
#include <fstream>
#include <iostream>


class LZW
{
private:
	static std::map<std::string, unsigned short int> GetInitDic();

	static std::string GetStrByCode(const std::map<std::string, unsigned short int>& dict, unsigned short int code);
public:
	static void encode(const std::shared_ptr<std::vector<char>>& inpVect, const std::string& path);

	static std::shared_ptr<std::vector<char>> decode(const std::string& path);
};

#endif //KURSACH_LZW_H