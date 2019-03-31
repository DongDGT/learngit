#ifndef __STACKH__
#define __STACKH__
#include <istream>
template<typename T>
class Stack
{
private:
	T *ptop;
	int top;
	const unsigned int sizes;
public:
	Stack(int x);//初始化栈
	~Stack();//销毁栈
	bool emptystack();//判断栈是否为空
	bool getTopstack(T &e);//得到栈顶元素
	bool clearstack();//清空栈
	bool getstackLen(int &len);//检测栈长度
	bool pushstack(T e);//入栈
	bool popstack(T &e);//出栈
};

template<typename T>
Stack<T>::Stack(int x) :sizes(x)
{
	ptop = new T[x];
	top = -1;
}

template<typename T>
Stack<T>::~Stack()
{
	for (int i = 0; i < top; i++) {
		ptop--;
	}
	top = -1;
	delete[]ptop;
	ptop = nullptr;
}

template<typename T>
bool Stack<T>::emptystack()
{
	if (top == -1)
		return true;
	return false;
}

template<typename T>
bool Stack<T>::getTopstack(T & e)
{
	if (top != -1) {
		e = *ptop;
		return true;
	}
	return false;
}

template<typename T>
bool Stack<T>::clearstack()
{
	if (top != -1) {
		top = -1;
		return true;
	}
	return false;
}

template<typename T>
bool Stack<T>::getstackLen(int & len)
{
	len = top + 1;
	return false;
}

template<typename T>
bool Stack<T>::pushstack(T e)
{
	if (top == sizes - 1) {
		return false;
	}
	else if (top = -1) {
		*ptop = e;
		top++;
		return true;
	}
	else {
		ptop++;
		*ptop = e;
		top++;
		return true;
	}
	return false;
}

template<typename T>
bool Stack<T>::popstack(T & e)
{
	if (top == -1) {
		return false;
	}
	else if (top == 0) {
		top = -1;
	}
	else {
		ptop--;
		top--;
	}
	return false;
}
#endif