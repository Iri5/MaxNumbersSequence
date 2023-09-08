#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <Windows.h>
#include "menu.h"
#include "tests.h"
#include "file.h"
#include "functions.h"


void Greeting() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::cout << "Бовчурова Ирина группа 404" << std::endl;
	std::cout << "Лабораторная 1, вариант 4" << std::endl;
	std::cout << "Задан текст. Подсчитать в нем наибольшее количество цифр,идущих подряд" << std::endl;
}

bool RightMenuChoice(Menu choice) {
	if ((choice == Menu::NO) || (choice == Menu::YES)) {
		return true;
	}
	else {
		std::cout << "Используйте указанные варианты" << std::endl;
		return false;
	}
}

bool RightInputChoice(InputType choice) {
	if ((choice == InputType::KEYBOARD) || (choice == InputType::FILE)) {
		return true;
	}
	else {
		std::cout << "Используйте указанные варианты" << std::endl;
		return false;
	}
}

Menu AskTests(void) {
	std::cout << "Провести тестирование?" << std::endl;
	std::cout << "1 - Да" << std::endl;
	std::cout << "2 - Нет" << std::endl;
	std::cout << "Ваш выбор:" << std::endl;
	Menu decision = static_cast<Menu>(GetInput<int>());
	while (!RightMenuChoice(decision)) {
		decision = static_cast<Menu>(GetInput<int>());
	}
	return decision;
}
Menu AskRepeat(void) {
	std::cout << "Желаете ли выполнить программу повторно?" << std::endl;
	std::cout << "1 - Да" << std::endl;
	std::cout << "2 - Нет" << std::endl;
	std::cout << "Ваш выбор:" << std::endl;
	Menu decision = static_cast<Menu>(GetInput<int>());
	while (!RightMenuChoice(decision)) {
		decision = static_cast<Menu>(GetInput<int>());
	}
	return decision;
}

InputType AskInput(void) {
	std::cout << "Как вы желаете ввести текст?" << std::endl;
	std::cout << "1 - Из файла" << std::endl;
	std::cout << "2 - С клавиатуры" << std::endl;
	std::cout << "Ваш выбор:" << std::endl;
	InputType decision = static_cast<InputType>(GetInput<int>());
	while (!RightInputChoice(decision)) {
		decision = static_cast<InputType>(GetInput<int>());
	}
	return decision;
}

Menu AskSaveInput(void) {
	std::cout << "Сохранить исходные данные в файл?" << std::endl;
	std::cout << "1 - Да" << std::endl;
	std::cout << "2 - Нет" << std::endl;
	std::cout << "Ваш выбор:" << std::endl;
	Menu decision = static_cast<Menu>(GetInput<int>());
	while (!RightMenuChoice(decision)) {
		decision = static_cast<Menu>(GetInput<int>());
	}
	return decision;
}

Menu AskSaveResult(void) {
	std::cout << "Сохранить результат в файл?" << std::endl;
	std::cout << "1 - Да" << std::endl;
	std::cout << "2 - Нет" << std::endl;
	std::cout << "Ваш выбор:" << std::endl;
	Menu decision = static_cast<Menu>(GetInput<int>());
	while (!RightMenuChoice(decision)) {
		decision = static_cast<Menu>(GetInput<int>());
	}
	return decision;
}


Menu AskRewriteFile(std::string path) {
	
	Menu decision = Menu::NO;
	
		std::cout << "Файл с таким именем уже существует" << std::endl;
		std::cout << "1 - Создать новый" << std::endl;
		std::cout << "2 - Перезаписать существующий" << std::endl;
		std::cout << "Ваш выбор:" << std::endl;
		decision = static_cast<Menu>(GetInput<int>());
		while (!RightMenuChoice(decision)) {
			decision = static_cast<Menu>(GetInput<int>());
		}
		return decision;
	
}




void MainFunction(void) {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	auto wantTests = Menu::YES;
	auto wantContinue = Menu::YES;
	auto wantSave = Menu::YES;
	auto wantRewrite = Menu::YES;
	auto inputType = InputType::KEYBOARD;
	std::string text;
	std::string afterText;
	int result = 0;

	do {
		std::string filePath = "nothing";
		wantTests = AskTests();
		if (wantTests == Menu::YES) {
			Tests();
		}

		inputType = AskInput();
		
		if (inputType == InputType::FILE) {
			std::cout << "Ввод текста" << std::endl;
			ReadFromFile(text);
			std::cout << "Исходный текст:" << std::endl;
			std::cout << text << std::endl;
		}
		else {
			std::cout << "Введите текст" << std::endl;
			//text = KeyboardInput();
			getline(std::cin, text);
			//text = (GetInput<std::string>());
		}
		
		result = MaxNumSequense(text);
		std::cout << "Длина максимальной последовательности цифр:" << std::endl;
		std::cout << result << std::endl;
		//тут вычисление

		if (inputType != InputType::FILE) {
			wantSave = AskSaveInput();
			if (wantSave == Menu::YES) {
				std::cout << "Сохранение исходного текста" << std::endl;
				WriteInFile(text);
			}
		}

		wantSave = AskSaveResult();
		if (wantSave == Menu::YES) {
			
			std::cout << "Введите имя файла:" << std::endl;
			filePath = GetInput<std::string>();
			FileWork outputSaveFile(filePath);
			while (!outputSaveFile.SaveFileNormal()) {
				std::cout << "Введите новое имя файла" << std::endl;
				filePath = outputSaveFile.RewriteName();
			}
			wantRewrite = AskRewriteFile(filePath);
			if (wantRewrite == Menu::YES) {
				std::string newFilePath = filePath;
				FileWork newOutputSave(newFilePath);
				while (newFilePath == filePath) {
					std::cout << "Введите новое имя файла" << std::endl;
					newFilePath = newOutputSave.RewriteName();
					while (!newOutputSave.SaveFileNormal()) {
						std::cout << "Введите новое имя файла" << std::endl;
						newFilePath = newOutputSave.RewriteName();
					}
				}
				FileWork file(newFilePath);
				file.Output(text, result);
			}
			else {
				while (outputSaveFile.FileReadOnly()) {
					std::cout << "Введите новое имя файла" << std::endl;
					filePath = outputSaveFile.RewriteName();
				}
				FileWork file(filePath);
				file.Output(text, result);
			}
			
			
		}
		wantContinue = AskRepeat();
	} while (wantContinue == Menu::YES);
}