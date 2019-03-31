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
	 * 初始化链栈
	 */
	ListStack();

	/*
	*销毁链栈
	*/
	~ListStack();

	/*
	 * 判断是否为空
	 */
	bool empty();

	/*
	 * 得到栈顶元素
	 */
	bool front(T &e);

	/*
	 * 压栈
	 */
	bool push_front(T e);

	/*
	 * 出栈
	 */
	bool pop_front();

	/*
	 * 清空链栈
	 */
	bool clear();

	/*
	 * 返回链栈中元素的数量
	 */
	unsigned int size();


};

/*
 * 初始化链栈
 */
template<typename T>
ListStack<T>::ListStack()
{
	head = nullptr;
}

/*
*销毁链栈
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
 * 判断是否为空
 */
template<typename T>
bool ListStack<T>::empty() {
	if (head == nullptr)
		return true;
	return false;
}

/*
 * 得到栈顶元素
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
 * 压栈
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
 * 出栈
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
 * 清空链栈
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
 * 返回链栈中元素的数量
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