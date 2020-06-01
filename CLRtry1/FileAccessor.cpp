#include "FileAccessor.h"

std::shared_ptr<std::vector<char>> FileAccessor::GetSymbVectPtr(const std::string& path)
{
	std::shared_ptr<std::vector<char>> symbVectorPtr = std::shared_ptr<std::vector<char>>(new std::vector<char>);
	std::ifstream file(path, std::ios::binary);
	if (file.is_open() && !file.fail())
	{
		char t;
		while (!file.eof()) {
			file.read((char*)&t, sizeof(char));
			symbVectorPtr->push_back(t);
		}
	}
	else
	{
		return nullptr;
	}
	file.close();
	symbVectorPtr->pop_back();
	return symbVectorPtr;
};

void FileAccessor::WriteSymbVectToFile(const std::shared_ptr<std::vector<char>>& inpVect, const std::string& path) {
	std::ofstream file;
	file.open(path, std::ios::binary);
	if (file.is_open() && !file.fail())
	{
		unsigned int from = 0;
		char* buff = new char[UCHAR_MAX];
		while (from < inpVect->size())
		{
			if (from + UCHAR_MAX < inpVect->size())
			{
				for (int i = 0; i < UCHAR_MAX; ++i)
				{
					buff[i] = inpVect->at(from + i);
				}
				file.write(buff, sizeof(char)*UCHAR_MAX);
				from += UCHAR_MAX;
			}
			else {
				for (int i = 0; i < inpVect->size() - from; ++i)
				{
					buff[i] = inpVect->at(from + i);
				}
				file.write(buff, sizeof(char)*(inpVect->size() - from));
				from = inpVect->size();
			}
		}
	}
	else {
		//error
	}
	file.close();
}

long FileAccessor::GetFileSize(const std::string & path)
{
	std::ifstream file(path, std::ios::binary);
	file.seekg(0, std::ios::end);
	long int file_size = file.tellg();
	return file_size;
}