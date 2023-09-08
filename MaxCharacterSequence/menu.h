#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <limits>
#include <vector>
#include <string>
#ifdef max
#undef max
#endif

enum class Menu {
	YES = 1,
	NO = 2
};

enum class InputType {
	FILE = 1,
	KEYBOARD = 2
};



template <typename ElementType>
ElementType GetInput(void) {
	ElementType input;
	std::cin >> input;
	while (std::cin.fail()) {
		std::cout << "Введены некорректные данные! Повторите ввод." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> input;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << std::endl;
	return input;
}

void Greeting(void);
bool RightMenuChoice(Menu choice);
bool RightInputChoice(InputType choice);
Menu AskTests(void);
Menu AskRepeat(void);
InputType AskInput(void);
Menu AskSaveInput(void);
Menu AskSaveResult(void);
Menu AskRewriteFile(std::string path);
Menu AskSaveResult(void);
void MainFunction(void);

#endif