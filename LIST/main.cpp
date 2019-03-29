#include"main.h"

void print(ForwardList::Data &e) {
	std::cout << e << " ";
}

void doubledata(ForwardList::Data & e)
{
	e = e * 2;
}

void flistadd(ForwardList &Flist) {
	std::cout << "选择添加方式" << std::endl
		<< "1:在链表第一个元素前一个添加元素" << std::endl
		<< "2:在链表最后一个元素后添加一个元素" << std::endl
		<< "3:在链表任意位置插入元素" << std::endl;
	unsigned int input = 0;
	do {
		std::cin >> input;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "输入错误，请重新输入" << std::endl;
		}
		else break;
	} while (1);
	ForwardList::Data data;
	unsigned int count = 0;
	switch (input) {
	case 1:std::cout << "输入插入元素: ";
		do {
			std::cin >> data;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
				std::cout << "输入错误，请重新输入" << std::endl;
			}
			else break;
		} while (1);
		if (Flist.push_front(data)) {
			std::cout << "输入成功" << std::endl;
		}
		else {
			std::cout << "输入失败" << std::endl;
		}break;
	case 2:std::cout << "输入插入元素: ";
		do {
			std::cin >> data;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
				std::cout << "输入错误，请重新输入" << std::endl;
			}
			else break;
		} while (1);
		if (Flist.push_back(data)) {
			std::cout << "输入成功" << std::endl;
		}
		else {
			std::cout << "输入失败" << std::endl;
		}break;
	case 3:std::cout << "输入插入位置: ";
		do {
			std::cin >> count;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
				std::cout << "输入错误，请重新输入" << std::endl;
			}
			else break;
		} while (1);
		std::cout << "输入插入元素: ";
		do {
			std::cin >> data;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
				std::cout << "输入错误，请重新输入" << std::endl;
			}
			else break;
		} while (1);
		if (Flist.insert(count, data)) {
			std::cout << "插入成功" << std::endl;
		}
		else {
			std::cout << "插入失败" << std::endl;
		}break;
	default: std::cout << "输入有误" << std::endl;
	}
	system("pause");
}

void flistdelete(ForwardList &Flist) {
	std::wcout << "选择删除方式" << std::endl
		<< "1:删除链表第一个元素" << std::endl
		<< "2:删除链表最后一个元素" << std::endl
		<< "3:删除任意位置元素" << std::endl
		<< "4:清空链表" << std::endl;
	unsigned int input = 0;
	do {
		std::cin >> input;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "输入错误，请重新输入" << std::endl;
		}
		else break;
	} while (1);
	unsigned int count = 0;
	switch (input) {
	case 1:
		if (Flist.pop_front()) {
			std::cout << "删除成功" << std::endl;
		}
		else {
			std::cout << "空指针" << std::endl;
		}break;
	case 2:
		if (Flist.pop_back()) {
			std::cout << "删除成功" << std::endl;
		}
		else {
			std::cout << "空指针" << std::endl;
		}break;
	case 3:
		
		std::cout << "输入删除位置: ";
		do {
			std::cin >> count;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
				std::cout << "输入错误，请重新输入" << std::endl;
			}
			else break;
		} while (1);
		if (Flist.erase(count)) {
			std::cout << "删除成功" << std::endl;
		}
		else {
			std::cout << "删除失败" << std::endl;
		}break;
	case 4:
		if (Flist.clear()) {
			std::cout << "清空成功" << std::endl;
		}
		else {
			std::cout << "空链表" << std::endl;
		}break;
	default:std::cout << "输入有误" << std::endl;
	}
	system("pause");
}

void printflist(ForwardList &Flist) {
	std::cout << "选择打印方式" << std::endl
		<< "1:输出第一个元素" << std::endl
		<< "2:输出最后一个元素" << std::endl
		<< "3:打印全部数据" << std::endl;
	unsigned int input = 0;
	do {
		std::cin >> input;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "输入错误，请重新输入" << std::endl;
		}
		else break;
	} while (1);
	switch (input) {
	case 1:
		if (Flist.size() == 0) {
			std::cout << "空指针" << std::endl;
		}
		else {
			std::cout << "第一个元素为: " << Flist.front() << std::endl;
		}break;
	case 2:
		if (Flist.size() == 0) {
			std::cout << "空指针" << std::endl;
		}
		else {
			std::cout << "最后一个元素为: " << Flist.back() << std::endl;
		}break;
	case 3:
		if (Flist.traverse(print)) {
			std::cout << std::endl << "打印成功" << std::endl;
		}
		else {
			std::cout << "打印失败" << std::endl;
		}break;
	default:std::cout << "输入有误" << std::endl;
	}
	system("pause");
}

void operateflist(ForwardList &Flist) {
	ForwardList::Data data;
	while (1) {
		system("cls");
		std::cout << "输入相应操作前的字符执行相应操作" << std::endl
			<< "a:添加元素" << std::endl
			<< "k:删除元素" << std::endl
			<< "s:查找元素是否存在" << std::endl
			<< "l:显示链表中元素的数量" << std::endl
			<< "d:使每个元素翻倍" << std::endl
			<< "p:打印链表数据" << std::endl
			<< "f:反转链表" << std::endl
			<< "o:判断是否成环" << std::endl
			<< "u:偶节点反转" << std::endl
			<< "m:打印中间节点数据" << std::endl
			<< "e:退出程序" << std::endl;
		char input = 0;
		std::cout << "请输入操作：";
		std::cin >> input;
		switch (input) {
		case 'a':flistadd(Flist); break;
		case 'k':flistdelete(Flist); break;
		case 's':std::cout << "输入查找元素: ";
			do {
				std::cin >> data;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore();
					std::cout << "输入错误，请重新输入" << std::endl;
				}
				else break;
			} while (1);
			if (Flist.contain(data)) {
				std::cout << data << "在链表中" << std::endl;
			}
			else {
				std::cout << data << "不在链表中" << std::endl;
			}break;
		case 'l':std::cout << "链表中元素数量为: " << Flist.size() << std::endl; break;
		case 'd':
			if (Flist.traverse(doubledata)) {
				std::cout << "操作成功" << std::endl;
			}
			else {
				std::cout << "操作失败" << std::endl;
			}break;
		case 'p':
			printflist(Flist); break;
		case 'f':
			if (Flist.reverse()) {
				std::cout << "翻转成功" << std::endl;
			}
			else {
				std::cout << "翻转失败" << std::endl;
			}break;
		case 'o':
			if (Flist.isLoop()) {
				std::cout << "链表成环" << std::endl;
			}
			else {
				std::cout << "链表不成环" << std::endl;
			}break;
		case 'u':
			if (Flist.reverseEven()) {
				std::cout << "操作成功" << std::endl;
			}
			else {
				std::cout << "操作失败" << std::endl;
			}break;
		case 'm':
			if (Flist.size() == 0) {
				std::cout << "空指针" << std::endl;
			}
			else {
				std::cout << "中间节点数据为: " << Flist.middleElem() << std::endl;
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
	std::cout << "选择添加方式" << std::endl
		<< "1:在链表第一个元素前一个添加元素" << std::endl
		<< "2:在链表最后一个元素后添加一个元素" << std::endl
		<< "3:在链表任意位置插入元素" << std::endl;
	unsigned int input = 0;
	do {
		std::cin >> input;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "输入错误，请重新输入" << std::endl;
		}
		else break;
	} while (1);
	ForwardList::Data data;
	unsigned int count = 0;
	switch (input) {
	case 1:std::cout << "输入插入元素: ";
		do {
			std::cin >> data;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
				std::cout << "输入错误，请重新输入" << std::endl;
			}
			else break;
		} while (1);
		if (Dlist.push_front(data)) {
			std::cout << "输入成功" << std::endl;
		}
		else {
			std::cout << "输入失败" << std::endl;
		}break;
	case 2:std::cout << "输入插入元素: ";
		do {
			std::cin >> data;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
				std::cout << "输入错误，请重新输入" << std::endl;
			}
			else break;
		} while (1);
		if (Dlist.push_back(data)) {
			std::cout << "输入成功" << std::endl;
		}
		else {
			std::cout << "输入失败" << std::endl;
		}break;
	case 3:std::cout << "输入插入位置: ";
		do {
			std::cin >> count;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
				std::cout << "输入错误，请重新输入" << std::endl;
			}
			else break;
		} while (1);
		std::cout << "输入插入元素: ";
		do {
			std::cin >> data;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
				std::cout << "输入错误，请重新输入" << std::endl;
			}
			else break;
		} while (1);
		if (Dlist.insert(count, data)) {
			std::cout << "插入成功" << std::endl;
		}
		else {
			std::cout << "插入失败" << std::endl;
		}break;
	}
	system("pause");
}

void dlistdelete(List &Dlist) {
	std::cout << "选择删除方式" << std::endl
		<< "1:删除链表第一个元素" << std::endl
		<< "2:删除链表最后一个元素" << std::endl
		<< "3:删除任意位置元素" << std::endl
		<< "4:清空链表" << std::endl;
	unsigned int input = 0;
	do {
		std::cin >> input;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "输入错误，请重新输入" << std::endl;
		}
		else break;
	} while (1);
	unsigned int count = 0;
	switch (input) {
	case 1:
		if (Dlist.pop_front()) {
			std::cout << "删除成功" << std::endl;
		}
		else {
			std::cout << "空指针" << std::endl;
		}break;
	case 2:
		if (Dlist.pop_back()) {
			std::cout << "删除成功" << std::endl;
		}
		else {
			std::cout << "空指针" << std::endl;
		}break;
	case 3:
		std::cout << "输入删除位置: ";
		do {
			std::cin >> count;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
				std::cout << "输入错误，请重新输入" << std::endl;
			}
			else break;
		} while (1);
		if (Dlist.erase(count)) {
			std::cout << "删除成功" << std::endl;
		}
		else {
			std::cout << "删除失败" << std::endl;
		}break;
	case 4:
		if (Dlist.clear()) {
			std::cout << "清空成功" << std::endl;
		}
		else {
			std::cout << "空链表" << std::endl;
		}break;
	}
	system("pause");
}

void printdlist(List &Dlist) {
	std::cout << "输入打印方式" << std::endl
		<< "1:输出第一个元素" << std::endl
		<< "2:输出最后一个元素" << std::endl
		<< "p:打印全部链表数据" << std::endl;
	unsigned int input = 0;
	do {
		std::cin >> input;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "输入错误，请重新输入" << std::endl;
		}
		else break;
	} while (1);
	switch (input) {
	case 1:
		if (Dlist.size() == 0) {
			std::cout << "空指针" << std::endl;
		}
		else {
			std::cout << "第一个元素为: " << Dlist.front() << std::endl;
		}break;
	case 2:
		if (Dlist.size() == 0) {
			std::cout << "空指针" << std::endl;
		}
		else {
			std::cout << "最后一个元素为:" << Dlist.back() << std::endl;
		}break;
	case 3:
		if (Dlist.traverse(print)){
			std::cout << std::endl << "打印成功" << std::endl;
		}
		else {
			std::cout << "打印失败" << std::endl;
		}break;
	default:std::cout << "输入有误" << std::endl;
	}
	system("pause");
}

void operatedlist(List &Dlist) {
	List::Data data;
	while (1) {
		system("cls");
		std::cout << "输入相应操作前的字符执行相应操作" << std::endl
			<< "a:添加元素" << std::endl
			<< "k:删除元素" << std::endl
			<< "s:查找元素是否存在" << std::endl
			<< "l:显示链表中元素的数量" << std::endl
			<< "d:使每个元素翻倍" << std::endl
			<< "p:打印链表数据" << std::endl
			<< "e:退出程序" << std::endl;
		char input = 0;
		std::cout << "请输入操作：";
		std::cin >> input;
		switch (input) {
		case 'a':dlistadd(Dlist); break;
		case 'k':dlistdelete(Dlist); break;
		case 's':std::cout << "输入查找元素: ";
			do {
				std::cin >> data;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore();
					std::cout << "输入错误，请重新输入" << std::endl;
				}
				else break;
			} while (1);
			if (Dlist.contain(data)) {
				std::cout << data << "在链表中" << std::endl;
			}
			else {
				std::cout << data << "不在链表中" << std::endl;
			}break;
		case 'l':std::cout << "链表中元素数量为: " << Dlist.size() << std::endl; break;
		case 'd':
			if (Dlist.traverse(doubledata)) {
				std::cout << "操作成功" << std::endl;
			}
			else {
				std::cout << "操作失败" << std::endl;
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
	std::cout << "操作单链表输入1，操作双链表输入2,输入e退出程序" << std::endl;
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




