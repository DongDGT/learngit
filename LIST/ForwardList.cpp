#include<iostream>
#include<stdexcept>
#include "ForwardList.h"
using namespace std;

/*
 * ��ʼ������
 */
ForwardList::ForwardList()
{
	head = nullptr;
	tail = nullptr;
}

/*
*��������
*/
ForwardList::~ForwardList()
{
	Number *p=head;
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
ForwardList::Data& ForwardList::front()
{
	if (head == nullptr) {
		throw runtime_error("��ָ��");
	}
	return head->data;
}

/*
 * �������������һ��Ԫ�ص�����
 */
ForwardList::Data& ForwardList::back()
{
	if (head == nullptr) {
		throw runtime_error("��ָ��");
	}
	return tail->data;
}

/*
 * �������һ��Ԫ��ǰ���Ԫ��e
 */
bool ForwardList::push_front(Data & e)
{
	Number *p = new Number;
	if (p != nullptr) {
		p->data = e;
		p->next = head;
		head = p;
		if (tail == nullptr) {
			tail = head;
		}
		return true;
	}
	return false;
}

/*
 * ���������һ��Ԫ�غ����Ԫ��e
 */
bool ForwardList::push_back(Data & e)
{
	Number *p = new Number;
	if (p != nullptr) {
		p->data = e;
		if (tail != nullptr) {
			tail->next = p;
		}
		else {
			tail = head = p;
		}
		p->next = nullptr;
		tail = p;
		return true;
	}
	return false;
}

/*
 * ɾ�������һ��Ԫ��
 */
bool ForwardList::pop_front()
{
	Number *p = head;
	if (p != nullptr) {
		head = head->next;
		delete p;
		p = nullptr;
		if (head == nullptr) {
			tail = nullptr;
		}
		return true;
	}
	return false;
}

/*
 * ɾ���������һ��Ԫ��
 */
bool ForwardList::pop_back()
{
	Number *p = head;
	if (p != nullptr) {
		if (p == tail) {
			delete p;
			p = tail = head = nullptr;
			return true;
		}
		while (p->next != tail) {
			p = p->next;
		}
		delete tail;
		tail = p;
		p->next = nullptr;
		return true;
	}
	return false;
}
/*
 * ������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
 */
bool ForwardList::insert(unsigned int index, Data & e)
{
	Number *p = head;
	if (index == 0) {
		Number *p1 = new Number;
		p1->data = e;
		p1->next = head;
		head = p1;
		if (tail == nullptr) {
			tail = head;
		}
		return true;
	}
	unsigned int count = 0;
	while (p->next != nullptr) {
		count++;
		if (count == index) {
			Number *p1 = new Number;
			p1->data = e;
			p1->next = p->next;
			p->next = p1;
			return true;
		}
		p = p->next;

	}
	return false;
}

/*
 * ɾ������λ��Ԫ��
 */
bool ForwardList::erase(unsigned int index)
{
	struct Number *p1 = head, *p2 = head;
	if (index == 0) {
		return true;
	}
	else if(index==1){
		if (head == nullptr) {
			return false;
		}
		else if (head==tail) {
			delete head;
			head = p1 = p2= tail = nullptr;
		}
		else {
			head = head->next;
			delete p1;
			p1 = p2 = nullptr;
		}
		return true;
	}
	else {
		unsigned int count = 2;
		if (p2 != nullptr) {
			p2 = p2->next;
		}
		while (p2!= nullptr) {
			if (count == index) {
				if (p2 == tail) {
					tail = p1;
				}
				p1->next = p2->next;
				delete p2;
				p2 = nullptr;
				return true;
			}
			p2 = p2->next;
			p1 = p1->next;
			count++;
		}

	}
	return false;
}

/*
 * �������
 */
bool ForwardList::clear()
{
	Number *p=head;
	if (p != nullptr) {
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
bool ForwardList::contain(Data & e)
{
	Number *p = head;
	if (p != nullptr) {
		while (p != nullptr) {
			if (p->data == e) {
				return true;
			}
			p = p->next;
		}
	}
	return false;
}

/*
 * ����������Ԫ�ص�����
 */
unsigned int ForwardList::size()
{
	Number *p = head;
	unsigned int count = 0;
	if (p != nullptr) {
		while (p != nullptr) {
			count++;
			p = p->next;
		}
	}
	return count;
}


/*
 * ��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
 */
bool ForwardList::traverse(void(*visit)(Data &e))
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
 * ��ת����1234��ת����4321
 */
 bool ForwardList::reverse()
 {
	 Number *p1, *p2, *p3;
	 p1 = p2 = p3 = head;
	 if (p1 != nullptr) {
		 if (p1->next == nullptr)
			 return true;
		 else {
			 p2 = p1->next;
			 if (p2->next == nullptr) {
				 p2->next = p1;
				 p1->next = nullptr;
				 head = p2;
				 tail = p1;
				 return true;
			 }
			 else {
				 tail = p1;
				 p1->next = nullptr;
				 p3 = p2->next;
				 while (p3 != nullptr) {
					 p2->next = p1;
					 p1 = p2;
					 p2 = p3;
					 p3 = p3->next;
				 }
				 p2->next = p1;
				 head = p2;
				 return true;
			 }
		 }
	 }
	 return false;
 }

 /*
 * �ݹ鷴ת����1234��ת����4321
 */
 void ForwardList::reversal(Number *p) {
	 if (p->next->next != nullptr)
		 reversal(p->next);
	 p->next->next = p;
 }
 bool ForwardList::recursivereverse()
 {
	 if (head->next!= nullptr) {
		 reversal(head);
		 head = tail;
		 Number *p=head;
		 while (p->next != nullptr) {
			 p = p->next;
		 }
		 tail = p;
		 return true;
	 }
	 return false;
 }

 /*
  * �����л�
  */
 bool ForwardList::isLoop()
 {
	 Number *p1, *p2;
	 p1 = p2 = head;
	 if (p1 != nullptr) {
		 do {
			 p1 = p1->next;
			 if (p2 == nullptr || p1 == nullptr) {
				 return false;
			 }
			 p2 = p2->next;
			 if (p1 == nullptr || p2 == nullptr) {
				 return false;
			 }
			 p2 = p2->next;
		 } while (p1 != p2);
		return true;
	 }
	 return false;
 }

 /*
  * ż�ڵ㷴ת��1234��ת����2143
  */
 bool ForwardList::reverseEven()
 {
	 Number *p = head;
	 Data temp=0;
	 if (p != nullptr) {
		 while (p != nullptr&&p->next != nullptr) {
			 temp = p->data;
			 p->data = p->next->data;
			 p->next->data = temp;
			 p = p->next->next;
		 }
		 return true;
	 }
	 return false;
 }

 /*
  * �����м�ڵ�
  */
 ForwardList::Data & ForwardList::middleElem()
 {
	 Number *p1, *p2;
	 p1 = p2 = head;
	 while (p2!=tail) {
		 p1 = p1->next;
		 p2 = p2->next;
		 if (p1 == tail ) {
			 return p1->data;
		 }
		 p2 = p2->next;
	 }
	 return p1->data; 
}

 /*
 *��ӡ��������
 */
 void ForwardList::print(Data &e)
 {
	 std::cout << e << " " ;
 }
	 
 

 