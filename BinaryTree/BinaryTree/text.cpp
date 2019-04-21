#include"BinaryTree.h"
#include<string>
#include<iostream>

bool print(int &e) {
	std::cout << e;
	return true;
}

int main() {
	BinaryTree<int> w;
	w.InOrderTraverse(print);
	return 0;
}