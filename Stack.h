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
	Stack(int x);//��ʼ��ջ
	~Stack();//����ջ
	bool emptystack();//�ж�ջ�Ƿ�Ϊ��
	bool getTopstack(T &e);//�õ�ջ��Ԫ��
	bool clearstack();//���ջ
	bool getstackLen(int &len);//���ջ����
	bool pushstack(T e);//��ջ
	bool popstack(T &e);//��ջ
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