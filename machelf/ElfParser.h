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

	// ���magic
	bool checkMagic();

	// ��ȡelf�ļ�����, 32/64bit
	ElfClass elfClass();

	// ��ȡ�������� 
	Endian elfEndian();

	ElfType elfType();

private:
	string m_elf;
};

