#include"main.h"

int main() {
	while (1) {
		if (!calculator()) {
			std::cout << "输入e退出,或输入其他任意字符继续计算" << std::endl;
		}
		else {
			std::cout << "输入表达式有误，请输入其他任意字符重新计算，或者输入e退出" << std::endl;
		}
		char continuee;
		std::cin >> continuee;
		if (continuee=='e') {
			break;
		}
	}
	return 0;
}