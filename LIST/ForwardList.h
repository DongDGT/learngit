#ifndef __FORWRDLIST__
#define __FORWRDLIST__


class ForwardList
{
public:
	typedef int Data;
private:
	struct Number {
		Data data;
		struct Number *next;
	};
	void reversal(struct Number *p);
protected:
	Number *head;
	Number *tail;


public:
	
	/*
	 * 初始化链表
	 */
	ForwardList();

	/*
	*销毁链表
	*/
	~ForwardList();

	/*
	 * 返回链表中第一个元素的引用
	 */
	Data&  front();

	/*
	 * 返回链表中最后一个元素的引用
	 */
	Data&  back();

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
	 * 反转链表，1234反转后变成4321
	 */
	bool reverse();
	
	/*
	 * 递归反转链表，1234反转后变成4321
	 */
	bool recursivereverse();
	
	/*
	 * 链表判环
	 */
	bool isLoop();

	/*
	 * 偶节点反转，1234反转后变成2143
	 */
	bool reverseEven();

	/*
	 * 返回中间节点
	 */
	Data& middleElem();

	/*
	*打印链表数据
	*/
	void print(Data &e);

};

#endif