#include <iostream>
#include <fstream>
#include <filesystem>
#include "file.h"
 

FileWork::FileWork(std::string path) {
	m_path = path;
}

bool FileWork::NameForbidden(void) const {
	try {
		bool isNameNormal = false;
		isNameNormal = std::filesystem::is_regular_file(m_path);
	}
	catch (std::exception&) {
		std::cout << "Недопустимое имя файла!" << std::endl;
		return true;
	}
	return false;
}

std::string FileWork::RewriteName(void) {
	m_path = GetInput<std::string>();
	while (NameForbidden()) {
		m_path = GetInput<std::string>();
	}
	return m_path;
}

bool FileWork::FileExist(void) const {
	std::ifstream checkFile;
	checkFile.open(m_path);
	if (checkFile.is_open()) {
		checkFile.close();
		return true;
	}
	else {
		return false;
	}
}

bool FileWork::SaveFileNormal(void) const {
	bool fileCreated = false;
	if (NameForbidden()) {
		return false;
	}
	if (FileExist()) {
		return true;
	}
	while (!fileCreated) {
		std::ofstream tryCreate;
		tryCreate.open(m_path);
		tryCreate << "check";
		tryCreate.close();
		std::ifstream tryOpen;
		tryOpen.open(m_path);
		if (tryOpen.is_open()) {
			tryOpen.close();
			remove(m_path.c_str());
			fileCreated = true;
		}
		else {
			tryOpen.close();
			fileCreated = false;
			std::cout << "Ошибка при создании файла. Проверьте имя файла" << std::endl;
			return false;
		}
	}
	return true;
}

bool FileWork::FileReadOnly(void) const {
	std::ofstream outputFile;
	outputFile.open(m_path);
	if (outputFile.is_open()) {
		outputFile.close();
		return false;
	}
	else {
		std::cout << "Файл доступен только для чтения" << std::endl;
		outputFile.close();
		return true;
	}
}

void FileWork::Output(std::string& text, int result) {
	std::ofstream outputFile;
	outputFile.open(m_path);
	outputFile << "Исходный текст:" << std::endl;
	outputFile << text << std::endl;
	outputFile << "Количество символов в самой длинной последовательности цифр:" << std::endl;
	outputFile << result << std::endl;
	outputFile.close();
}

void FileWork::SaveData(std::string& text) {
	std::ofstream dataFile;
	dataFile.open(m_path);
	dataFile << text << std::endl;
	dataFile.close();
}

bool FileWork::Input(std::string& usingText) {
	std::ifstream inputFile;
	std::string text;
	std::string data;
	inputFile.open(m_path);

	if (!inputFile.is_open()) {
		std::cout << "Файл не найден" << std::endl;
		return false;
	}
	while (!inputFile.eof()) {
		getline(inputFile, data);
		if (!data.empty()) {
			data += " ";
		}
		text += data;
	}
	

	if (text == "") {
		std::cout << "Файл пуст" << std::endl;
		inputFile.close();
		return false;
	}
	else {
		usingText = text;
		inputFile.close();
		return true;
	}
}






void WriteInFile(std::string& text) {
	std::string path;
	Menu rewrite = Menu::YES;
	std::cout << "Введите имя файла" << std::endl;
	path = GetInput<std::string>();
	FileWork inputSaveFile(path);
	while (!inputSaveFile.SaveFileNormal()) {
		std::cout << "Введите новое имя файла" << std::endl;
		path = inputSaveFile.RewriteName();
	}
	std::ifstream checkFile;
	checkFile.open(path);
	if (checkFile.is_open()) {
		rewrite = AskRewriteFile(path);
		checkFile.close();
		if (rewrite == Menu::YES) {
			std::string newFilePath = path;
			FileWork newInputSave(newFilePath);
			while (newFilePath == path) {
				std::cout << "Введите новое имя файла:" << std::endl;
				newFilePath = newInputSave.RewriteName();
				while (!newInputSave.SaveFileNormal()) {
					std::cout << "" << std::endl;
					newFilePath = newInputSave.RewriteName();
				}
			}
			FileWork file(newFilePath);
			file.SaveData(text);
		}
		else {
			while (inputSaveFile.FileReadOnly()) {
				std::cout << "Введите новое имя файла" << std::endl;
				path = inputSaveFile.RewriteName();
			}
			FileWork file(path);
			file.SaveData(text);
		}
	}
	else {
		checkFile.close();
		while (inputSaveFile.FileReadOnly()) {
			std::cout << "Введите новое имя файла" << std::endl;
			path = inputSaveFile.RewriteName();
		}
		FileWork file(path);
		file.SaveData(text);
	}
	
}



void ReadFromFile(std::string& text) {
	bool dataReaded = false;
	std::string path;
	std::cout << "Введите имя файла:" << std::endl;
	
	path = GetInput<std::string>();
	FileWork checkFile(path);

	while (checkFile.NameForbidden()) {
		std::cout << "Введите новое имя файла" << std::endl;
		path = checkFile.RewriteName();
	}
	FileWork input(path);
	dataReaded = input.Input(text);
	while (!dataReaded) {
		std::cout << "Введите новое имя файла" << std::endl;
		path = input.RewriteName();
		dataReaded = input.Input(text);
	}
}