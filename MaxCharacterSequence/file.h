#ifndef FILE_H
#define FILE_H
#include <fstream>
#include <filesystem>
#include "menu.h"

class FileWork {
	std::string m_path;
public:
	FileWork(std::string path);
	bool NameForbidden(void) const;
	std::string RewriteName(void);
	bool FileExist(void) const;
	bool SaveFileNormal(void) const;
	bool FileReadOnly() const;
	void Output(std::string& text, int result);
	void SaveData(std::string& afterText);
	bool Input(std::string& usingText);
};


void WriteInFile(std::string& afterText);

void ReadFromFile(std::string& usingText);

#endif