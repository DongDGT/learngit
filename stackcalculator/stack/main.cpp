#include"main.h"

int main() {
	while (1) {
		if (!calculator()) {
			std::cout << "����e�˳�,���������������ַ���������" << std::endl;
		}
		else {
			std::cout << "������ʽ�������������������ַ����¼��㣬��������e�˳�" << std::endl;
		}
		char continuee;
		std::cin >> continuee;
		if (continuee=='e') {
			break;
		}
	}
	return 0;
}