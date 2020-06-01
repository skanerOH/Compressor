#pragma once

#ifndef KURSACH_HUFFMAN_H
#define KURSACH_HUFFMAN_H

#include <vector>
#include <map>
#include <algorithm>
#include <memory>
#include <iostream>
#include <fstream>
#include <deque>


class HuffLeaf {
public:
	char value;
	HuffLeaf* left;
	HuffLeaf* right;
	HuffLeaf* parent;
	bool isLeaf;
	unsigned long int freq;
public:
	HuffLeaf(char value_t, HuffLeaf* parent_t, int freq_t);

	HuffLeaf(HuffLeaf* right_t, HuffLeaf* left_t);

	~HuffLeaf();

	std::string GetCode(char inp);
};

class Huffman {
private:
	static std::map<char, unsigned int> GetFreqVect(std::shared_ptr<std::vector<char>> inpVect);

	static char pack_byte(bool bits[8]);

	static HuffLeaf* CreateTree(std::map<char, unsigned int> freqVect);

public:

	static void encode(const std::shared_ptr<std::vector<char>>& inpVect, const std::string& path);

	static std::shared_ptr<std::vector<char>> decode(const std::string& path);
};


#endif //KURSACH_HUFFMAN_H

