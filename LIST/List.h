#ifndef __LIST__
#define __LIST__
#include "ForwardList.h"

class List : public ForwardList
{
public:
	typedef int Data;
protected:
	struct Number {
		Data data;
		struct Number *prior;
		struct Number *next;
	};
	Number *head;
	Number *tail;
public:
	/*
	 * ��ʼ������
	 */
	List();

	/*
	 * ��������
	 */
	~List();

	/*
	 * ���������е�һ��Ԫ�ص�����
	 */
	Data& front();

	/*
	 * �������������һ��Ԫ�ص�����
	 */
	Data& back();

	/*
	 * �������һ��Ԫ��ǰ���Ԫ��e
	 */
	bool push_front(Data& e);

	/*
	 * ɾ�������һ��Ԫ��
	 */
	bool pop_front();

	/*
	 * ���������һ��Ԫ�غ����Ԫ��e
	 */
	bool push_back(Data& e);

	/*
	 * ɾ���������һ��Ԫ��
	 */
	bool pop_back();

	/*
	 * ������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
	 */
	bool insert(unsigned int index, Data& e);

	/*
	 * ɾ������λ��Ԫ��
	 */
	bool erase(unsigned int index);

	/*
	 * �������
	 */
	bool clear();

	/*
	 * ����Ԫ���Ƿ����
	 */
	bool contain(Data& e);

	/*
	 * ����������Ԫ�ص�����
	 */
	unsigned int size();

	/*
	 * ��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
	 */
	bool traverse(void(*visit)(Data& e));

	/*
	*��ӡ��������
	*/
	void print(Data &e);
};

#endif