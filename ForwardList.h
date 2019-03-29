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
	 * ��ʼ������
	 */
	ForwardList();

	/*
	*��������
	*/
	~ForwardList();

	/*
	 * ���������е�һ��Ԫ�ص�����
	 */
	Data&  front();

	/*
	 * �������������һ��Ԫ�ص�����
	 */
	Data&  back();

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
	 * ��ת����1234��ת����4321
	 */
	bool reverse();
	
	/*
	 * �ݹ鷴ת����1234��ת����4321
	 */
	bool recursivereverse();
	
	/*
	 * �����л�
	 */
	bool isLoop();

	/*
	 * ż�ڵ㷴ת��1234��ת����2143
	 */
	bool reverseEven();

	/*
	 * �����м�ڵ�
	 */
	Data& middleElem();

	/*
	*��ӡ��������
	*/
	void print(Data &e);

};

#endif