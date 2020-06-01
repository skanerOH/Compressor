#include "Huffman.h"

HuffLeaf::HuffLeaf(char value_t, HuffLeaf* parent_t, int freq_t)
{
	value = value_t;
	parent = parent_t;
	freq = freq_t;
	isLeaf = true;
	right = nullptr;
	left = nullptr;
}

HuffLeaf::HuffLeaf(HuffLeaf* right_t, HuffLeaf* left_t) {
	right = right_t;
	left = left_t;
	freq = right_t->freq + left_t->freq;
	value = '\0';
	isLeaf = false;
	parent = nullptr;
}

HuffLeaf::~HuffLeaf()
{
	delete left;
	delete right;
}

std::string HuffLeaf::GetCode(char inp)
{
	if (left->isLeaf)
	{
		if (left->value == inp)
			return "1";
	}
	else
	{
		std::string v = left->GetCode(inp);
		if (v[0] != 'n')
			return "1" + v;
	}

	if (right->isLeaf)
	{
		if (right->value == inp)
			return "0";
	}
	else
	{
		std::string v = right->GetCode(inp);
		if (v[0] != 'n')
			return "0" + v;
	}
	return "n";
}

std::map<char, unsigned int> Huffman::GetFreqVect(std::shared_ptr<std::vector<char>> inpVect)
{
	std::map<char, unsigned int> res;
	for (auto c = inpVect->begin(); c < inpVect->end(); ++c)
	{
		auto iter = res.find(*c);
		if (iter == res.end())
		{
			res[*c] = 1;
		}
		else
		{
			if (res[*c] < INT32_MAX) res[*c]++;
		}
	}
	return res;
}

HuffLeaf* Huffman::CreateTree(std::map<char, unsigned int> freqVect)
{
	std::vector<HuffLeaf*> huffVect;
	for (auto f = freqVect.begin(); f != freqVect.end(); ++f)
	{
		huffVect.push_back(new HuffLeaf(f->first, nullptr, f->second));
	}

	while (huffVect.size() > 1)
	{
		std::sort(huffVect.begin(), huffVect.end(), [](const HuffLeaf* lhs, const HuffLeaf* rhs) {
			return lhs->freq > rhs->freq; });
		HuffLeaf* rightLeaf = huffVect.back();
		huffVect.pop_back();
		HuffLeaf* leftLeaf = huffVect.back();
		huffVect.pop_back();
		HuffLeaf* fuzed = new HuffLeaf(rightLeaf, leftLeaf);
		rightLeaf->parent = fuzed;
		leftLeaf->parent = fuzed;
		huffVect.push_back(fuzed);
	}

	return huffVect.at(0);
}

char Huffman::pack_byte(bool bits[8]) {
	char res(0);
	for (unsigned i(8); i--;)
	{
		res <<= 1;
		res |= char(bits[i]);
	}
	return res;
}

void Huffman::encode(const std::shared_ptr<std::vector<char>>& inpVect, const std::string& path) {
	std::ofstream out;
	out.open(path, std::ios::binary);
	if (out.is_open()) {

		unsigned int symbCount = inpVect->size();
		out.write((char*)&symbCount, sizeof(unsigned int));

		std::map<char, unsigned int> freqVect = GetFreqVect(inpVect);
		int freqSize = freqVect.size();

		out.write((char*)&freqSize, sizeof(int));
		for (auto f = freqVect.begin(); f != freqVect.end(); ++f)
		{
			out.write((char*)&f->first, sizeof(char));
			out.write((char*)&f->second, sizeof(int));
		}

		std::shared_ptr<HuffLeaf> TreeRoot = std::shared_ptr<HuffLeaf>(CreateTree(freqVect));
		std::map<char, std::string> encMap;

		std::vector<bool> codedBools;
		std::string codeS;
		for (int i = 0; i < inpVect->size(); ++i)
		{
			if (!encMap.count(inpVect->at(i)))
				encMap[inpVect->at(i)] = TreeRoot->GetCode(inpVect->at(i));
			codeS = encMap[inpVect->at(i)];
			for (int j = 0; j < codeS.size(); ++j)
				codedBools.push_back(codeS[j] == '1');
			if (codedBools.size() >= 8)
			{
				char s(0);
				bool bits[8];
				for (int i = 0; i < 8; ++i) {
					bits[i] = codedBools.front();
					codedBools.erase(codedBools.begin());
				}
				s = pack_byte(bits);
				out.write((char*)&s, sizeof(char));
			}
		}
		if (codedBools.size() > 0)
		{
			while (codedBools.size() < 8)
				codedBools.push_back(false);
			char s(0);
			bool bits[8];
			for (int i = 0; i < 8; ++i) {
				bits[i] = codedBools.front();
				codedBools.erase(codedBools.begin());
			}
			s = pack_byte(bits);
			out.write((char*)&s, sizeof(char));
		}
		out.close();
	}
	else
	{
		//error
		return;
	}
}

std::shared_ptr<std::vector<char> > Huffman::decode(const std::string & path) {
	std::ifstream fin;
	fin.open(path, std::ios::binary);
	if (fin.is_open())
	{
		unsigned int symbCount;
		fin.read((char*)&symbCount, sizeof(unsigned int));
		int freqVectSize;
		std::map<char, unsigned int> freqVect;
		fin.read((char*)&freqVectSize, sizeof(int));
		unsigned int freq;
		char val;
		for (unsigned int i = 0; i < freqVectSize; ++i)
		{
			fin.read((char*)&val, sizeof(char));
			fin.read((char*)&freq, sizeof(int));
			freqVect[val] = freq;
		}

		std::shared_ptr<HuffLeaf> TreeRoot = std::shared_ptr<HuffLeaf>(CreateTree(freqVect));
		HuffLeaf* currLeaf = TreeRoot.get();

		std::shared_ptr<std::vector<char>> outVect = std::shared_ptr<std::vector<char>>(new std::vector<char>);
		std::deque<bool> boolsToDecode;

		while (!fin.eof())
		{
			char s;
			fin.read((char*)&s, sizeof(char));

			for (int i = 0; i < 8; ++i)
				boolsToDecode.push_back(s & (1 << i));

			while (boolsToDecode.size() > 0)
			{
				if (currLeaf->isLeaf) {
					outVect->push_back(currLeaf->value);
					currLeaf = TreeRoot.get();
				}
				if (boolsToDecode.front())
					currLeaf = currLeaf->left;
				else
					currLeaf = currLeaf->right;
				boolsToDecode.pop_front();
			}
			if (currLeaf->isLeaf) {
				outVect->push_back(currLeaf->value);
				currLeaf = TreeRoot.get();
			}
		}

		while (outVect->size() > symbCount)
			outVect->pop_back();

		fin.close();
		return outVect;
	}
	else
	{
		fin.close();
		//error
	}
}