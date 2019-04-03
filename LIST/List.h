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
	 * 初始化链表
	 */
	List();

	/*
	 * 销毁链表
	 */
	~List();

	/*
	 * 返回链表中第一个元素的引用
	 */
	Data& front();

	/*
	 * 返回链表中最后一个元素的引用
	 */
	Data& back();

	/*
	 * 在链表第一个元素前添加元素e
	 */
	bool push_front(Data& e);

	/*
	 * 删除链表第一个元素
	 */
	bool pop_front();

	/*
	 * 在链表最后一个元素后添加元素e
	 */
	bool push_back(Data& e);

	/*
	 * 删除链表最后一个元素
	 */
	bool pop_back();

	/*
	 * 在链表的第index + 1个元素前插入元素e
	 */
	bool insert(unsigned int index, Data& e);

	/*
	 * 删除任意位置元素
	 */
	bool erase(unsigned int index);

	/*
	 * 清空链表
	 */
	bool clear();

	/*
	 * 查找元素是否存在
	 */
	bool contain(Data& e);

	/*
	 * 返回链表中元素的数量
	 */
	unsigned int size();

	/*
	 * 遍历链表, 对每个元素调用visit指向的函数
	 */
	bool traverse(void(*visit)(Data& e));

	/*
	*打印链表数据
	*/
	void print(Data &e);
};

#endif