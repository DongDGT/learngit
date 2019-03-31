#ifndef __FORWRDLIST__
#define __FORWRDLIST__

template<typename T>
class ListStack
{
private:
	struct Number {
		T data;
		struct Number *next;
	};
protected:
	Number *head;

public:

	/*
	 * ��ʼ����ջ
	 */
	ListStack();

	/*
	*������ջ
	*/
	~ListStack();

	/*
	 * �ж��Ƿ�Ϊ��
	 */
	bool empty();

	/*
	 * �õ�ջ��Ԫ��
	 */
	bool front(T &e);

	/*
	 * ѹջ
	 */
	bool push_front(T e);

	/*
	 * ��ջ
	 */
	bool pop_front();

	/*
	 * �����ջ
	 */
	bool clear();

	/*
	 * ������ջ��Ԫ�ص�����
	 */
	unsigned int size();


};

/*
 * ��ʼ����ջ
 */
template<typename T>
ListStack<T>::ListStack()
{
	head = nullptr;
}

/*
*������ջ
*/
template<typename T>
ListStack<T>::~ListStack()
{
	Number *p = head;
	while (p != nullptr) {
		p = head->next;
		delete head;
		head = p;
	}
}

/*
 * �ж��Ƿ�Ϊ��
 */
template<typename T>
bool ListStack<T>::empty() {
	if (head == nullptr)
		return true;
	return false;
}

/*
 * �õ�ջ��Ԫ��
 */
template<typename T>
bool ListStack<T>::front(T &e)
{
	if (head == nullptr)
		return false;
	else {
		e = head->data;
		return true;
	}
}

/*
 * ѹջ
 */
template<typename T>
bool ListStack<T>::push_front(T  e)
{
	Number *p = new Number;
	if (p != nullptr) {
		p->data = e;
		p->next = head;
		head = p;
		return true;
	}
	return false;
}

/*
 * ��ջ
 */
template<typename T>
bool ListStack<T>::pop_front()
{
	Number *p = head;
	if (p != nullptr) {
		head = head->next;
		delete p;
		p = nullptr;
		return true;
	}
	return false;
}


/*
 * �����ջ
 */
template<typename T>
bool ListStack<T>::clear()
{
	Number *p = head;
	if (p != nullptr) {
		while (p != nullptr) {
			p = head->next;
			delete head;
			head = p;
		}
		return true;
	}
	return false;
}

/*
 * ������ջ��Ԫ�ص�����
 */
template<typename T>
unsigned int ListStack<T>::size()
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

#endif