// machelf.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "ElfParser.h"
#include <fstream>
#include <vector>

using namespace std;
int main()
{
	string buffer;
	string line;
	ifstream ifs(R"(D:\WorkStation\Project\Formal\Other\machelf\liblas.so)",ios::binary);
	if (!ifs.good()) 
	{ 
		cout << "File not found" << endl; 
		return 0; 
	}

	ifs.seekg(0, std::ios_base::end);
	std::streampos fileSize = ifs.tellg();
	buffer.resize(fileSize);
	ifs.seekg(0, std::ios_base::beg);
	ifs.read(const_cast<char*>(buffer.data()), fileSize);
	ifs.close();

	ElfParser elf(buffer.data(), buffer.size());
	bool isValid = elf.checkMagic();
	ElfClass elfClass = elf.elfClass();
	Endian endian = elf.elfEndian();

	
	
	

	getchar();
	return 0;
}
