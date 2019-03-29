#include"main.h"

void print(ForwardList::Data &e) {
	std::cout << e << " ";
}

void doubledata(ForwardList::Data & e)
{
	e = e * 2;
}

void flistadd(ForwardList &Flist) {
	std::cout << "ѡ����ӷ�ʽ" << std::endl
		<< "1:�������һ��Ԫ��ǰһ�����Ԫ��" << std::endl
		<< "2:���������һ��Ԫ�غ����һ��Ԫ��" << std::endl
		<< "3:����������λ�ò���Ԫ��" << std::endl;
	unsigned int input = 0;
	do {
		std::cin >> input;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "�����������������" << std::endl;
		}
		else break;
	} while (1);
	ForwardList::Data data;
	unsigned int count = 0;
	switch (input) {
	case 1:std::cout << "�������Ԫ��: ";
		do {
			std::cin >> data;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
				std::cout << "�����������������" << std::endl;
			}
			else break;
		} while (1);
		if (Flist.push_front(data)) {
			std::cout << "����ɹ�" << std::endl;
		}
		else {
			std::cout << "����ʧ��" << std::endl;
		}break;
	case 2:std::cout << "�������Ԫ��: ";
		do {
			std::cin >> data;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
				std::cout << "�����������������" << std::endl;
			}
			else break;
		} while (1);
		if (Flist.push_back(data)) {
			std::cout << "����ɹ�" << std::endl;
		}
		else {
			std::cout << "����ʧ��" << std::endl;
		}break;
	case 3:std::cout << "�������λ��: ";
		do {
			std::cin >> count;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
				std::cout << "�����������������" << std::endl;
			}
			else break;
		} while (1);
		std::cout << "�������Ԫ��: ";
		do {
			std::cin >> data;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
				std::cout << "�����������������" << std::endl;
			}
			else break;
		} while (1);
		if (Flist.insert(count, data)) {
			std::cout << "����ɹ�" << std::endl;
		}
		else {
			std::cout << "����ʧ��" << std::endl;
		}break;
	default: std::cout << "��������" << std::endl;
	}
	system("pause");
}

void flistdelete(ForwardList &Flist) {
	std::wcout << "ѡ��ɾ����ʽ" << std::endl
		<< "1:ɾ�������һ��Ԫ��" << std::endl
		<< "2:ɾ���������һ��Ԫ��" << std::endl
		<< "3:ɾ������λ��Ԫ��" << std::endl
		<< "4:�������" << std::endl;
	unsigned int input = 0;
	do {
		std::cin >> input;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "�����������������" << std::endl;
		}
		else break;
	} while (1);
	unsigned int count = 0;
	switch (input) {
	case 1:
		if (Flist.pop_front()) {
			std::cout << "ɾ���ɹ�" << std::endl;
		}
		else {
			std::cout << "��ָ��" << std::endl;
		}break;
	case 2:
		if (Flist.pop_back()) {
			std::cout << "ɾ���ɹ�" << std::endl;
		}
		else {
			std::cout << "��ָ��" << std::endl;
		}break;
	case 3:
		
		std::cout << "����ɾ��λ��: ";
		do {
			std::cin >> count;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
				std::cout << "�����������������" << std::endl;
			}
			else break;
		} while (1);
		if (Flist.erase(count)) {
			std::cout << "ɾ���ɹ�" << std::endl;
		}
		else {
			std::cout << "ɾ��ʧ��" << std::endl;
		}break;
	case 4:
		if (Flist.clear()) {
			std::cout << "��ճɹ�" << std::endl;
		}
		else {
			std::cout << "������" << std::endl;
		}break;
	default:std::cout << "��������" << std::endl;
	}
	system("pause");
}

void printflist(ForwardList &Flist) {
	std::cout << "ѡ���ӡ��ʽ" << std::endl
		<< "1:�����һ��Ԫ��" << std::endl
		<< "2:������һ��Ԫ��" << std::endl
		<< "3:��ӡȫ������" << std::endl;
	unsigned int input = 0;
	do {
		std::cin >> input;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "�����������������" << std::endl;
		}
		else break;
	} while (1);
	switch (input) {
	case 1:
		if (Flist.size() == 0) {
			std::cout << "��ָ��" << std::endl;
		}
		else {
			std::cout << "��һ��Ԫ��Ϊ: " << Flist.front() << std::endl;
		}break;
	case 2:
		if (Flist.size() == 0) {
			std::cout << "��ָ��" << std::endl;
		}
		else {
			std::cout << "���һ��Ԫ��Ϊ: " << Flist.back() << std::endl;
		}break;
	case 3:
		if (Flist.traverse(print)) {
			std::cout << std::endl << "��ӡ�ɹ�" << std::endl;
		}
		else {
			std::cout << "��ӡʧ��" << std::endl;
		}break;
	default:std::cout << "��������" << std::endl;
	}
	system("pause");
}

void operateflist(ForwardList &Flist) {
	ForwardList::Data data;
	while (1) {
		system("cls");
		std::cout << "������Ӧ����ǰ���ַ�ִ����Ӧ����" << std::endl
			<< "a:���Ԫ��" << std::endl
			<< "k:ɾ��Ԫ��" << std::endl
			<< "s:����Ԫ���Ƿ����" << std::endl
			<< "l:��ʾ������Ԫ�ص�����" << std::endl
			<< "d:ʹÿ��Ԫ�ط���" << std::endl
			<< "p:��ӡ��������" << std::endl
			<< "f:��ת����" << std::endl
			<< "o:�ж��Ƿ�ɻ�" << std::endl
			<< "u:ż�ڵ㷴ת" << std::endl
			<< "m:��ӡ�м�ڵ�����" << std::endl
			<< "e:�˳�����" << std::endl;
		char input = 0;
		std::cout << "�����������";
		std::cin >> input;
		switch (input) {
		case 'a':flistadd(Flist); break;
		case 'k':flistdelete(Flist); break;
		case 's':std::cout << "�������Ԫ��: ";
			do {
				std::cin >> data;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore();
					std::cout << "�����������������" << std::endl;
				}
				else break;
			} while (1);
			if (Flist.contain(data)) {
				std::cout << data << "��������" << std::endl;
			}
			else {
				std::cout << data << "����������" << std::endl;
			}break;
		case 'l':std::cout << "������Ԫ������Ϊ: " << Flist.size() << std::endl; break;
		case 'd':
			if (Flist.traverse(doubledata)) {
				std::cout << "�����ɹ�" << std::endl;
			}
			else {
				std::cout << "����ʧ��" << std::endl;
			}break;
		case 'p':
			printflist(Flist); break;
		case 'f':
			if (Flist.reverse()) {
				std::cout << "��ת�ɹ�" << std::endl;
			}
			else {
				std::cout << "��תʧ��" << std::endl;
			}break;
		case 'o':
			if (Flist.isLoop()) {
				std::cout << "����ɻ�" << std::endl;
			}
			else {
				std::cout << "�����ɻ�" << std::endl;
			}break;
		case 'u':
			if (Flist.reverseEven()) {
				std::cout << "�����ɹ�" << std::endl;
			}
			else {
				std::cout << "����ʧ��" << std::endl;
			}break;
		case 'm':
			if (Flist.size() == 0) {
				std::cout << "��ָ��" << std::endl;
			}
			else {
				std::cout << "�м�ڵ�����Ϊ: " << Flist.middleElem() << std::endl;
			}break;
		default:;
		}
		if (input == 'e') {
			break;
		}
		system("pause");
	}
}

void dlistadd(List &Dlist) {
	std::cout << "ѡ����ӷ�ʽ" << std::endl
		<< "1:�������һ��Ԫ��ǰһ�����Ԫ��" << std::endl
		<< "2:���������һ��Ԫ�غ����һ��Ԫ��" << std::endl
		<< "3:����������λ�ò���Ԫ��" << std::endl;
	unsigned int input = 0;
	do {
		std::cin >> input;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "�����������������" << std::endl;
		}
		else break;
	} while (1);
	ForwardList::Data data;
	unsigned int count = 0;
	switch (input) {
	case 1:std::cout << "�������Ԫ��: ";
		do {
			std::cin >> data;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
				std::cout << "�����������������" << std::endl;
			}
			else break;
		} while (1);
		if (Dlist.push_front(data)) {
			std::cout << "����ɹ�" << std::endl;
		}
		else {
			std::cout << "����ʧ��" << std::endl;
		}break;
	case 2:std::cout << "�������Ԫ��: ";
		do {
			std::cin >> data;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
				std::cout << "�����������������" << std::endl;
			}
			else break;
		} while (1);
		if (Dlist.push_back(data)) {
			std::cout << "����ɹ�" << std::endl;
		}
		else {
			std::cout << "����ʧ��" << std::endl;
		}break;
	case 3:std::cout << "�������λ��: ";
		do {
			std::cin >> count;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
				std::cout << "�����������������" << std::endl;
			}
			else break;
		} while (1);
		std::cout << "�������Ԫ��: ";
		do {
			std::cin >> data;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
				std::cout << "�����������������" << std::endl;
			}
			else break;
		} while (1);
		if (Dlist.insert(count, data)) {
			std::cout << "����ɹ�" << std::endl;
		}
		else {
			std::cout << "����ʧ��" << std::endl;
		}break;
	}
	system("pause");
}

void dlistdelete(List &Dlist) {
	std::cout << "ѡ��ɾ����ʽ" << std::endl
		<< "1:ɾ�������һ��Ԫ��" << std::endl
		<< "2:ɾ���������һ��Ԫ��" << std::endl
		<< "3:ɾ������λ��Ԫ��" << std::endl
		<< "4:�������" << std::endl;
	unsigned int input = 0;
	do {
		std::cin >> input;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "�����������������" << std::endl;
		}
		else break;
	} while (1);
	unsigned int count = 0;
	switch (input) {
	case 1:
		if (Dlist.pop_front()) {
			std::cout << "ɾ���ɹ�" << std::endl;
		}
		else {
			std::cout << "��ָ��" << std::endl;
		}break;
	case 2:
		if (Dlist.pop_back()) {
			std::cout << "ɾ���ɹ�" << std::endl;
		}
		else {
			std::cout << "��ָ��" << std::endl;
		}break;
	case 3:
		std::cout << "����ɾ��λ��: ";
		do {
			std::cin >> count;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
				std::cout << "�����������������" << std::endl;
			}
			else break;
		} while (1);
		if (Dlist.erase(count)) {
			std::cout << "ɾ���ɹ�" << std::endl;
		}
		else {
			std::cout << "ɾ��ʧ��" << std::endl;
		}break;
	case 4:
		if (Dlist.clear()) {
			std::cout << "��ճɹ�" << std::endl;
		}
		else {
			std::cout << "������" << std::endl;
		}break;
	}
	system("pause");
}

void printdlist(List &Dlist) {
	std::cout << "�����ӡ��ʽ" << std::endl
		<< "1:�����һ��Ԫ��" << std::endl
		<< "2:������һ��Ԫ��" << std::endl
		<< "p:��ӡȫ����������" << std::endl;
	unsigned int input = 0;
	do {
		std::cin >> input;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "�����������������" << std::endl;
		}
		else break;
	} while (1);
	switch (input) {
	case 1:
		if (Dlist.size() == 0) {
			std::cout << "��ָ��" << std::endl;
		}
		else {
			std::cout << "��һ��Ԫ��Ϊ: " << Dlist.front() << std::endl;
		}break;
	case 2:
		if (Dlist.size() == 0) {
			std::cout << "��ָ��" << std::endl;
		}
		else {
			std::cout << "���һ��Ԫ��Ϊ:" << Dlist.back() << std::endl;
		}break;
	case 3:
		if (Dlist.traverse(print)){
			std::cout << std::endl << "��ӡ�ɹ�" << std::endl;
		}
		else {
			std::cout << "��ӡʧ��" << std::endl;
		}break;
	default:std::cout << "��������" << std::endl;
	}
	system("pause");
}

void operatedlist(List &Dlist) {
	List::Data data;
	while (1) {
		system("cls");
		std::cout << "������Ӧ����ǰ���ַ�ִ����Ӧ����" << std::endl
			<< "a:���Ԫ��" << std::endl
			<< "k:ɾ��Ԫ��" << std::endl
			<< "s:����Ԫ���Ƿ����" << std::endl
			<< "l:��ʾ������Ԫ�ص�����" << std::endl
			<< "d:ʹÿ��Ԫ�ط���" << std::endl
			<< "p:��ӡ��������" << std::endl
			<< "e:�˳�����" << std::endl;
		char input = 0;
		std::cout << "�����������";
		std::cin >> input;
		switch (input) {
		case 'a':dlistadd(Dlist); break;
		case 'k':dlistdelete(Dlist); break;
		case 's':std::cout << "�������Ԫ��: ";
			do {
				std::cin >> data;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore();
					std::cout << "�����������������" << std::endl;
				}
				else break;
			} while (1);
			if (Dlist.contain(data)) {
				std::cout << data << "��������" << std::endl;
			}
			else {
				std::cout << data << "����������" << std::endl;
			}break;
		case 'l':std::cout << "������Ԫ������Ϊ: " << Dlist.size() << std::endl; break;
		case 'd':
			if (Dlist.traverse(doubledata)) {
				std::cout << "�����ɹ�" << std::endl;
			}
			else {
				std::cout << "����ʧ��" << std::endl;
			}break;
		case 'p':
			printdlist(Dlist); break;
		default:;
		}
		if (input == 'e') {
			break;
		}
		system("pause");
	}
}

bool menu(ForwardList &Flist,List &Dlist) {
	system("cls");
	char input = 0;
	std::cout << "��������������1������˫��������2,����e�˳�����" << std::endl;
	std::cin >> input;
	if (input == '1') {
		operateflist(Flist);
		return true;
	}
	else if(input == '2') {
		operatedlist(Dlist);
		return true;
	}
	else if (input == 'e') {
		return false;
	}
	else return true;
}

int main() {
	ForwardList Flist;
	List Dlist;
	while (1) {
		if (!menu(Flist,Dlist)) {
			break;
		}
		system("cls");
	}
	return 0;
	
}




