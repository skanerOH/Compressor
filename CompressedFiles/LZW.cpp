#include "LZW.h"

std::map<std::string, unsigned short int> LZW::GetInitDic()
{
	std::map<std::string, unsigned short int> res;
	for (char i = CHAR_MIN; i != CHAR_MAX; ++i)
	{
		res[std::string(1, i)] = res.size();
	}
	return res;
}


std::string LZW::GetStrByCode(const std::map<std::string, unsigned short int>& dict, unsigned short int code)
{
	for (auto &i : dict)
	{
		if (i.second == code)
			return i.first;
	}
	return "";
}

void LZW::encode(const std::shared_ptr<std::vector<char>>& inpVect, const std::string& path)
{
	std::map<std::string, unsigned short int> dict = GetInitDic();
	std::ofstream out;
	out.open(path, std::ios::binary);
	if (out.is_open()) {
		std::string curr;
		std::string priv;
		for (unsigned int i = 0; i < inpVect->size(); ++i)
		{
			curr = std::string(1, inpVect->at(i));
			if (dict.count(priv + curr))
			{
				priv += curr;
			}
			else
			{
				out.write((char*)&dict[priv], sizeof(unsigned short int));
				if (dict.size() < USHRT_MAX - 1)
					dict[priv + curr] = dict.size() + 1;
				priv = curr;
			}
		}
		out.write((char*)&dict[priv], sizeof(unsigned short int));
		out.close();
	}
	else {
		//error
	}
}

std::shared_ptr<std::vector<char>> LZW::decode(const std::string& path)
{
	std::ifstream fin;
	fin.open(path, std::ios::binary);
	std::shared_ptr<std::vector<char>> outVect = std::shared_ptr<std::vector<char>>(new std::vector<char>);
	if (fin.is_open())
	{
		std::map<std::string, unsigned short int> dict = GetInitDic();

		unsigned short int currCode;
		unsigned short int privCode;
		std::string currStr;
		std::string privStr;
		std::string S;

		fin.read((char*)&privCode, sizeof(unsigned short int));
		privStr = GetStrByCode(dict, privCode);
		for (char k : privStr)
			outVect->push_back(k);
		char C = privStr[0];
		while (!fin.eof())
		{
			fin.read((char*)&currCode, sizeof(unsigned short int));
			privStr = GetStrByCode(dict, privCode);
			currStr = GetStrByCode(dict, currCode);

			if (dict.count(currStr))
			{
				S = currStr;
			}
			else
			{
				S = privStr;
				S = S + std::string(1, C);
			}

			for (char k : S)
				outVect->push_back(k);
			C = S[0];
			if (dict.size() < USHRT_MAX - 1)
				dict[privStr + std::string(1, C)] = dict.size() + 1;
			privCode = currCode;
		}
		for (char k : S)
			outVect->pop_back();
		fin.close();
		return outVect;
	}
	else {
		//error
	}
}