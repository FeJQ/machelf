#pragma once
#include <string>
using std::string;

enum class ElfClass
{
	kNone,
	kElf32,
	kElf64
};
enum class Endian
{
	kNone,
	kLittleEndian,
	kBigEndian
};

enum class ElfType
{
	kNone,
	kRel,
	kExec,
	kDyn,
	kCore,
	kLoproc,
	kHiproc
};

class ElfParser
{
public:
	ElfParser(const char* elfBuffer,unsigned long long size);

	// 检查magic
	bool checkMagic();

	// 获取elf文件类型, 32/64bit
	ElfClass elfClass();

	// 获取编码类型 
	Endian elfEndian();

	ElfType elfType();

private:
	string m_elf;
};

