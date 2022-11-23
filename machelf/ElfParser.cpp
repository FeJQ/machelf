#include "ElfParser.h"
#include "elf.h"

ElfParser::ElfParser(const char * elfBuffer, unsigned long long size)
{
	m_elf = string(elfBuffer, size);
}

bool ElfParser::checkMagic()
{
	const char MAGIC[] = {0x7F,'E','L','F'};
	return *(unsigned long*)m_elf.data() == *(unsigned long*)MAGIC;
}

ElfClass ElfParser::elfClass()
{
	return static_cast<ElfClass>(*(m_elf.data() + 4));
}

Endian ElfParser::elfEndian()
{
	return static_cast<Endian>(*(m_elf.data() + 5));
}

ElfType ElfParser::elfType()
{
	ElfClass cls = elfClass();
	if (cls == ElfClass::kElf32)
	{
		elf32_hdr *header32 = (elf32_hdr*)m_elf.data();
		return static_cast<ElfType>(header32->e_type);
	}
	else if (cls == ElfClass::kElf64)
	{
		elf64_hdr* header64 = (elf64_hdr*)m_elf.data();
		return static_cast<ElfType>(header64->e_type);
	}
	return ElfType::kNone;
}
