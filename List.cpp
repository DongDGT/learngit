#include<iostream>
#include<stdexcept>
#include "List.h"
using namespace std;


/*
 * ��ʼ������
 */
List::List()
{
	head = nullptr;
	tail = nullptr;
}

/*
 * ��������
 */
List::~List()
{
	Number *p = head;
	while (p != nullptr) {
		p = head->next;
		delete head;
		head = p;
	}
	tail = nullptr;
}

/*
 * ���������е�һ��Ԫ�ص�����
 */
List::Data & List::front()
{
	if (head = nullptr) {
		throw runtime_error("��ָ��");
	}
	return head->data;
}

/*
 * �������������һ��Ԫ�ص�����
 */
List::Data & List::back()
{
	if (head = nullptr) {
		throw runtime_error("��ָ��");
	}
	return tail->data;
}

/*
 * �������һ��Ԫ��ǰ���Ԫ��e
 */
bool List::push_front(Data & e)
{
	Number *p = new Number;
	if (p != nullptr) {
		p->prior = nullptr;
		p->data = e;
		if (head == nullptr) {
			p->next = nullptr;
			head = tail = p;
		}
		else {
			p->next = head;
			head->prior = p;
			head = p;
		}
		return true;
	}
	return false;
}

/*
 * ɾ�������һ��Ԫ��
 */
bool List::pop_front()
{
	if (head != nullptr) {
		Number *p = head->next;
		delete head;
		if (p != nullptr) {
			head = p;
			p->prior = nullptr;
		}
		else {
			head = tail = nullptr;
		}
		return true;
	}
	return false;
}

/*
 * ���������һ��Ԫ�غ����Ԫ��e
 */
bool List::push_back(Data & e)
{
	Number *p = new Number;
	if (p != nullptr) {
		p->next = nullptr;
		p->data = e;
		if (head == nullptr) {
			p->prior = nullptr;
			head = tail = p;
		}
		else {
			p->prior = tail;
			tail->next = p;
			tail = p;
		}
		return true;
	}
	return false;
}

/*
 * ɾ���������һ��Ԫ��
 */
bool List::pop_back()
{
	if (head != nullptr) {
		Number *p=tail;
		tail = tail->prior;
		delete p;
		p = nullptr;
		if (tail != nullptr) {
			tail->next = nullptr;
		}
		else {
			head = nullptr;
		}
		return true;
	}
	return false;
}

/*
 * ������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
 */
bool List::insert(unsigned int index, Data & e)
{
	Number *p = new Number;
	if (p != nullptr) {
		p->data = e;
		p->next = nullptr;
		p->prior = nullptr;
		Number *pcount = head;
		unsigned int count = 0;
		do {
			if (count == index) {
				if (head == nullptr) {
					head = tail = p;
					p->prior = p->next = nullptr;
				}
				else {
					p->prior = pcount->prior;
					pcount->prior = p;
					p->next = pcount;
					if (p->prior != nullptr) {
						p->prior->next = p;
					}
					if (pcount == head) {
						head = p;
					}
				}
				return true;
			}
			pcount = pcount->next;
			count++;
		} while (pcount != nullptr);
	}
	return false;
}

/*
 * ɾ������λ��Ԫ��
 */
bool List::erase(unsigned int index)
{
	if (index == 0) {
		return true;
	}
	else if(index == 1) {
		if (head == nullptr) {
			return false;
		}
		else {
			Number *p1 = head->next;
			if (head == tail) {
				tail = nullptr;
			}
			delete head;
			head = p1;
			return true;
		}
	}
	else {
		Number *p2 = head;
		unsigned int count = 1;
		while (p2 != nullptr) {
			if (count == index) {
				if (p2 == tail) {
					tail = p2->prior;
				}
				else {
					p2->next->prior = p2->prior;
				}
				p2->prior->next = p2->next;
				delete p2;
				p2 = nullptr;
				return true;
			}
		}

	}
	return false;
}

/*
 * �������
 */
bool List::clear()
{
	if (head != nullptr) {
		Number *p = head;
		while (p != nullptr) {
			p = head->next;
			delete head;
			head = p;
		}
		tail = nullptr;
		return true;
	}
	return false;
}

/*
 * ����Ԫ���Ƿ����
 */
bool List::contain(Data & e)
{
	Number *p = head;
	while (p != nullptr) {
		if (p->data == e) {
			return true;
		}
		p = p->next;
	}
	return false;
}

/*
 * ����������Ԫ�ص�����
 */
unsigned int List::size()
{
	unsigned int count = 0;
	Number *p = head;
	while (p != nullptr) {
		p = p->next;
		count++;
	}
	return count;
}

/*
 * ��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
 */
bool List::traverse(void(*visit)(Data &e))
{
	Number *p = head;
	if (p != nullptr) {
		while (p != nullptr) {
			(*visit)(p->data);
			p = p->next;
		}
		return true;
	}
	return false;
}

/*
*��ӡ��������
*/
void List::print(Data &e)
{
	std::cout << e << " " ;
}



