#include <iostream>
#include <string>
#include "functions.h"

bool Test1() {
	int rightAns = 3;
	int curAns = 0;
	std::string text = "123";
	curAns = MaxNumSequense(text);
	if (curAns != rightAns) {
		std::cout << "Ошибка в выполнении первого теста" << std::endl;
		std::cout << "Исходные данные:" << std::endl;
		std::cout << text << std::endl;
		std::cout << "Ожидаемый ответ:" << std::endl;
		std::cout << rightAns << std::endl;
		std::cout << "Полученный ответ:" << std::endl;
		std::cout << curAns << std::endl;
		return false;
	}
	else {
		return true;
	}
}

bool Test2() {
	int rightAns = 0;
	int curAns = 0;
	std::string text = "";
	curAns = MaxNumSequense(text);
	if (curAns != rightAns) {
		std::cout << "Ошибка в выполнении второго теста" << std::endl;
		std::cout << "Исходные данные:" << std::endl;
		std::cout << text << std::endl;
		std::cout << "Ожидаемый ответ:" << std::endl;
		std::cout << rightAns << std::endl;
		std::cout << "Полученный ответ:" << std::endl;
		std::cout << curAns << std::endl;
		return false;
	}
	else {
		return true;
	}
}

bool Test3() {
	int rightAns = 0;
	int curAns = 0;
	std::string text = "abc";
	curAns = MaxNumSequense(text);
	if (curAns != rightAns) {
		std::cout << "Ошибка в выполнении третьего теста" << std::endl;
		std::cout << "Исходные данные:" << std::endl;
		std::cout << text << std::endl;
		std::cout << "Ожидаемый ответ:" << std::endl;
		std::cout << rightAns << std::endl;
		std::cout << "Полученный ответ:" << std::endl;
		std::cout << curAns << std::endl;
		return false;
	}
	else {
		return true;
	}
}

bool Test4() {
	int rightAns = 5;
	int curAns = 0;
	std::string text = "123_12345_123";
	curAns = MaxNumSequense(text);
	if (curAns != rightAns) {
		std::cout << "Ошибка в выполнении четвертого теста" << std::endl;
		std::cout << "Исходные данные:" << std::endl;
		std::cout << text << std::endl;
		std::cout << "Ожидаемый ответ:" << std::endl;
		std::cout << rightAns << std::endl;
		std::cout << "Полученный ответ:" << std::endl;
		std::cout << curAns << std::endl;
		return false;
	}
	else {
		return true;
	}
}

bool Test5() {
	int rightAns = 3;
	int curAns = 0;
	std::string text = "вф4пре45рамр4мвпр456";
	curAns = MaxNumSequense(text);
	if (curAns != rightAns) {
		std::cout << "Ошибка в выполнении пятого теста" << std::endl;
		std::cout << "Исходные данные:" << std::endl;
		std::cout << text << std::endl;
		std::cout << "Ожидаемый ответ:" << std::endl;
		std::cout << rightAns << std::endl;
		std::cout << "Полученный ответ:" << std::endl;
		std::cout << curAns << std::endl;
		return false;
	}
	else {
		return true;
	}
}

void Tests() {
	int trueTests = 0;
	if (Test1()) trueTests++;
	if (Test2()) trueTests++;
	if (Test3()) trueTests++;
	if (Test4()) trueTests++;
	if (Test5()) trueTests++;
	if (trueTests == 5) {
		std::cout << "Тестирование прошло успешно" << std::endl;
	}
}