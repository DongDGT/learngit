#include<string>
#include<stack>
#include<queue>
template<typename T>
class BinaryTree {
protected:
	struct BiTNode {
		T data;
		BiTNode *leftson;
		BiTNode *rightson;
	};
	BiTNode *root;
public:
	BinaryTree();
	~BinaryTree();
	bool DestroyBiTree();
	bool PreOrderTraverse(bool(*visit)(T &e));
	bool PreOrderTraverse_recursion(bool(*visit)(T &e), BiTNode *T);
	bool InOrderTraverse(bool(*visit)(T &e));
	bool InOrderTraverse_recursion(bool(*visit)(T &e), BiTNode *T);
	bool PostOrderTraverse(bool(*visit)(T &e));
	bool PostOrderTraverse_recursion(bool(*visit)(T &e), BiTNode *T);
	bool LevelOrderTraverse(bool(*visit)(T &e));
	
};


/*
*构造二叉树
*/
template<typename T>
BinaryTree<T>::BinaryTree()
{
	root = nullptr;
}

/*
*销毁二叉树
*/
template<typename T>
BinaryTree<T>::~BinaryTree()
{
	std::stack<BiTNode*> father;
	BiTNode *p1;
	p1 = root;
	while (p1 != nullptr) {
		father.push(p1);
		p1 = p1->leftson;
	}
	while (!father.empty()) {
		p1 = father.top();
		if (p1->rightson != nullptr) {
			father.push(p1->rightson);
			p1 = p1->rightson;
			while (p1 != nullptr) {
				father.push(p1);
				p1 = p1->leftson;
			}
		}
		else {
			delete p1;
			p1 = nullptr;
			father.pop();
			p1 = father.top();
			if (p1->leftson == nullptr) {
				p1->rightson=nullptr;
			}
			else {
				p1->leftson = nullptr;
			}
		}
	}
	root = nullptr;
}

template<typename T>
bool BinaryTree<T>::DestroyBiTree()
{
	std::stack<BiTNode*> father;
	BiTNode *p1;
	p1 = root;
	while (p1 != nullptr) {
		father.push(p1);
		p1 = p1->leftson;
	}
	while (!father.empty()) {
		p1 = father.top();
		if (p1->rightson != nullptr) {
			father.push(p1->rightson);
			p1 = p1->rightson;
			while (p1 != nullptr) {
				father.push(p1);
				p1 = p1->leftson;
			}
		}
		else {
			delete p1;
			p1 = nullptr;
			father.pop();
			p1 = father.top();
			if (p1->leftson == nullptr) {
				p1->rightson = nullptr;
			}
			else {
				p1->leftson = nullptr;
			}
		}
	}
	root = nullptr;
}


/*
*先序遍历，使用函数（非递归）
*/
template<typename T>
bool BinaryTree<T>::PreOrderTraverse(bool(*visit)(T &e))
{
	std::queue<BiTNode*> father;
	BiTNode *p1;
	bool mode = true;
	p1 = root;
	while (p1 != nullptr) {
		father.push(p1);
		p1 = p1->leftson;
	}
	while (!father.empty()&&mode) {
		p1 = father.front();
		while (p1 != nullptr) {
			father.push(p1);
			p1 = p1->leftson;
		}
		p1 = father.front();
		mode=visit(p1->data);
		if (p1->rightson != nullptr) {
			father.push(p1->rightson);
		}
		father.pop();
	}
	return mode;
}

/*
*先序遍历，使用函数（递归）
*/
template<typename T>
bool BinaryTree<T>::PreOrderTraverse_recursion(bool(*visit)(T &e), BiTNode *t)
{
	static bool mode = true;
	if (mode) {
		if (t->leftson == nullptr&&t->rightson == nullptr) {
			mode = visit(t->data);
		}
		else {
			if (t->leftson != nullptr)
				PreOrderTraverse_recursion(visit, t->leftson);
			if (t->rightson != nullptr)
				PreOrderTraverse_recursion(visit, t->rightson);
			if (!mode)
				return mode;
			mode = visit(t->data);
		}
	}
	return mode;
}

/*
*中序遍历，使用函数（非递归）
*/
template<typename T>
bool BinaryTree<T>::InOrderTraverse(bool(*visit)(T &e))
{
	std::stack<BiTNode*> father;
	BiTNode *p1 = root;
	bool mode = true;
	while (p1 != nullptr) {
		father.push(p1);
		p1 = p1->leftson;
	}
	p1 = father.top();
	while (p1 != nullptr&&mode) {
		mode = visit(p1->data);
		if (p1->rightson != nullptr) {
			p1 = p1->rightson;
			while (p1 != nullptr) {
				father.push(p1);
				p1 = p1->leftson;
			}
		}
		else {
			if (!father.empty()) {
				father.pop();
				p1 = father.top();
			}
			else {
				p1 = nullptr;
			}
		}
	}
	return mode;
}

/*
*中序遍历，使用函数（递归）
*/
template<typename T>
bool BinaryTree<T>::InOrderTraverse_recursion(bool(*visit)(T &e), BiTNode *t)
{
	static bool mode = true;
	if (mode) {
		if (t->leftson == nullptr&&t->rightson == nullptr) {
			mode = visit(t->data);
		}
		else {
			if (t->leftson != nullptr)
				PreOrderTraverse_recursion(visit, t->leftson);
			if (!mode)
				return mode;
			mode = visit(t->data);
			if (t->rightson != nullptr)
				PreOrderTraverse_recursion(visit, t->rightson);
		}
	}
	return mode;
}

/*
*后序遍历，使用函数（非递归）
*/
template<typename T>
bool BinaryTree<T>::PostOrderTraverse(bool(*visit)(T &e))
{
	std::stack<BiTNode*> father;
	BiTNode *p1, *p2;
	bool mode = true;
	p2 = p1 = root;
	while (p1 != nullptr) {
		father.push(p1);
		p1 = p1->leftson;
	}
	while (!father.empty()&&mode) {
		p1 = father.top();
		if (p1->rightson != nullptr&&p2!= p1->rightson) {
			father.push(p1->rightson);
			p1 = p1->rightson;
			while (p1 != nullptr) {
				father.push(p1);
				p1 = p1->leftson;
			}
		}
		else {
			p2 = p1;
			mode=visit(p1->data);
			father.pop();
		}
	}
	return mode;
}

/*
*后序遍历，使用函数（递归）
*/
template<typename T>
inline bool BinaryTree<T>::PostOrderTraverse_recursion(bool(*visit)(T &e), BiTNode *t)
{
	static bool mode = true;
	if (mode) {
		if (t->leftson == nullptr&&t->rightson == nullptr) {
			mode = visit(t->data);
		}
		else {
			if (t->leftson != nullptr)
				PreOrderTraverse_recursion(visit, t->leftson);
			if (!mode)
				return mode;
			mode = visit(t->data);
			if (t->rightson != nullptr)
				PreOrderTraverse_recursion(visit, t->rightson);
		}
	}
	return mode;
}

/*
*层次遍历，使用函数
*/
template<typename T>
bool BinaryTree<T>::LevelOrderTraverse(bool(*visit)(T &e))
{
	std::stack<BiTNode*> father;
	BiTNode *p1 = root;
	bool mode = true;
	father.push(p1);
	while (!father.empty()&&mode) {
		p1 = father.top();
		if (p1->leftson != nullptr) {
			father.push(p1->leftson);
		}
		if (p1->rightson != nullptr) {
			father.push(p1->rightson);
		}
		mode=visit(p1->data);
		father.pop();
	}
	return true;
}



