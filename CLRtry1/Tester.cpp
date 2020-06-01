#include "Tester.h"

std::string Tester::GetTesting(std::string inpPath, char method, bool useBWT)
{
	clock_t encodingTime;
	clock_t decodingTime;
	//std::string outPath = ("../Compressed/testingFileOut");
	std::string outPath = ("../CompressedFiles/testingFileOut");
	std::shared_ptr<std::vector<char>> inpData = FileAccessor::GetSymbVectPtr(inpPath);
	std::shared_ptr<std::vector<char>> outData;
	std::shared_ptr<std::vector<char>> BWTData;
	std::string result;

	switch (method)
	{
	case 'R':
	{
		encodingTime = clock();
		if (useBWT)
		{
			BWTData = BWT::encode(inpData);
		}
		else
			BWTData = inpData;
		RLE::encode(BWTData, outPath);
		encodingTime = clock() - encodingTime;
		decodingTime = clock();
		if (useBWT)
		{
			outData = BWT::decode(RLE::decode(outPath));
		}
		else
		{
			outData = RLE::decode(outPath);
		}
		decodingTime = clock() - decodingTime;
		result = "RLE method";
		break;
	}
	case 'H':
	{
		encodingTime = clock();
		if (useBWT)
		{
			BWTData = BWT::encode(inpData);
		}
		else
			BWTData = inpData;
		Huffman::encode(BWTData, outPath);
		encodingTime = clock() - encodingTime;
		decodingTime = clock();
		if (useBWT)
		{
			outData = BWT::decode(Huffman::decode(outPath));
		}
		else
		{
			outData = Huffman::decode(outPath);
		}
		decodingTime = clock() - decodingTime;
		result = "Huffman method";
		break;
	}
	case 'L':
	{
		encodingTime = clock();
		if (useBWT)
		{
			BWTData = BWT::encode(inpData);
		}
		else
			BWTData = inpData;
		LZW::encode(BWTData, outPath);
		encodingTime = clock() - encodingTime;
		decodingTime = clock();
		if (useBWT)
		{
			outData = BWT::decode(LZW::decode(outPath));
		}
		else
		{
			outData = LZW::decode(outPath);
		}
		decodingTime = clock() - decodingTime;
		result = "LZW method";
		break;
	}
	default:
		return "method not found!";
	}

	if (useBWT)
		result += " + BWT";
	result += "\n";
	double compressionValue = (static_cast<double>(FileAccessor::GetFileSize(outPath)) / static_cast<double>(FileAccessor::GetFileSize(inpPath)))*100.0;
	result += " compression time = " + std::to_string(static_cast<double>(encodingTime) / (CLOCKS_PER_SEC / 1000.0)) + "\n";
	result += " decompression time = " + std::to_string(static_cast<double>(decodingTime) / (CLOCKS_PER_SEC / 1000.0)) + "\n";
	result += " input file size = " + std::to_string(FileAccessor::GetFileSize(inpPath))  + "\n";
	result += " output file size = " + std::to_string(FileAccessor::GetFileSize(outPath)) + "\n";
	result += " compression ratio = " + std::to_string(compressionValue) + "%" + "\n";
	return result;
}