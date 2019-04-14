#include"sort.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<fstream>

template<typename T>
void print(T a, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << a[i] << ' ';
	}
}

void insertSortmenu(int *a, int *b, int *c, int *k, std::ofstream&outfile, std::ifstream&inFile) {
	srand(time(0));
	std::cout << "选择测试方式" << std::endl
		<< "1.大量数据检测" << std::endl
		<< "2.输入数据检测" << std::endl
		<< "3.从文件textin.txt中读取数据检测" << std::endl;
	char input = 0;
	int user_input[10] = { 0 };
	clock_t startTime, endTime,alltime=0;
	std::cin >> input;
	switch (input) {
	case'1':
		startTime = clock();
		insertSort(a, 10000);
		endTime = clock();
		std::cout << "1w数据量：" << endTime - startTime << "ms" << std::endl;
		startTime = clock();
		insertSort(b, 50000);
		endTime = clock();
		std::cout << "5w数据量：" << endTime - startTime << "ms" << std::endl;
		startTime = clock();
		insertSort(c, 200000);
		endTime = clock();
		std::cout << "20w数据量：" << endTime - startTime << "ms" << std::endl;
		for (int i = 0; i < 100000; i++) {
			startTime = clock();
			insertSort(k, 100);
			endTime = clock();
			alltime += endTime - startTime;
			for (int j = 0; j < 100; j++) {
				k[j] = rand();
			}
		}
		std::cout << "100*100k数据量：" << alltime << "ms" << std::endl;
		break;
	case'2':
		std::cin.clear();
		std::cin.ignore();
		std::cout << "输入10个整数进行排序" << std::endl;
		outfile << "插入排序：" << std::endl;
		outfile << "输入的数据为：";
		for (int m = 0; m < 10; m++) {
			std::cin >> user_input[m];
			outfile << user_input[m] << " ";
		}
		insertSort(user_input, 10);
		std::cout << "排序结果如下：" << std::endl;
		outfile << std::endl << "排序结果如下:";
		for (int i = 0; i < 10; i++) {
			outfile << user_input[i] << " ";
		}
		outfile << std::endl;
		print(user_input, 10);
		break;
	case'3':
		outfile << "插入排序：" << std::endl;
		outfile << "输入的数据为：";
		std::cout << "文件数据为：" << std::endl;
		for (int i = 0; i < 10; i++) {
			if (inFile.eof()) {
				user_input[i] = 0;
			}
			else {
				inFile >> user_input[i];
			}
			std::cout << user_input[i] << ' ';
			outfile << user_input[i] << ' ';
		}
		inFile.seekg(0);
		insertSort(user_input, 10);
		std::cout << "排序结果如下：" << std::endl;
		outfile << std::endl << "排序结果如下:";
		for (int i = 0; i < 10; i++) {
			outfile << user_input[i] << " ";
		}
		outfile << std::endl;
		print(user_input, 10);
	}
	std::cin.clear();
	std::cin.ignore();
}

void MergeSortmenu(int *a, int *b, int *c, int *k, std::ofstream&outfile, std::ifstream&inFile) {
	srand(time(0));
	std::cout << "选择测试方式" << std::endl
		<< "1.大量数据检测" << std::endl
		<< "2.输入数据检测" << std::endl
		<< "3.从文件textin.txt中读取数据检测" << std::endl;
	char input = 0;
	int user_input[10] = { 0 };
	int *a1 = new int[10000];
	int *b2 = new int[50000];
	int *c3 = new int[200000];
	int *k4 = new int[100];
	int *user_input5 = new int[10];
	clock_t startTime, endTime, alltime = 0;
	std::cin >> input;
	switch (input) {
	case'1':
		startTime = clock();
		MergeSort(a, 0,9999,a1);
		endTime = clock();
		std::cout << "1w数据量：" << endTime - startTime << "ms" << std::endl;
		startTime = clock();
		MergeSort(b, 0,49999,b2);
		endTime = clock();
		std::cout << "5w数据量：" << endTime - startTime << "ms" << std::endl;
		startTime = clock();
		MergeSort(c, 0,199999,c3);
		endTime = clock();
		std::cout << "20w数据量：" << endTime - startTime << "ms" << std::endl;
		for (int i = 0; i < 100000; i++) {
			startTime = clock();
			MergeSort(k, 0,99,k4);
			endTime = clock();
			alltime += endTime - startTime;
			for (int j = 0; j < 100; j++) {
				k[j] = rand();
			}
		}
		std::cout << "100*100k数据量：" << alltime << "ms" << std::endl;
		break;
	case'2':
		std::cin.clear();
		std::cin.ignore();
		outfile << "并归排序：" << std::endl;
		outfile << "输入的数据为：";
		std::cout << "输入10个整数进行排序" << std::endl;
		for (int m = 0; m < 10; m++) {
			std::cin >> user_input[m];
			outfile << user_input[m] << " ";
		}
		MergeSort(user_input,0, 9,user_input5);
		std::cout << "排序结果如下：" << std::endl;
		outfile << std::endl << "排序结果如下:";
		for (int i = 0; i < 10; i++) {
			outfile << user_input[i] << " ";
		}
		outfile << std::endl;
		print(user_input, 10);
		break;
	case'3':
		outfile << "归并排序：" << std::endl;
		outfile << "输入的数据为：";
		std::cout << "文件数据为：" << std::endl;
		for (int i = 0; i < 10; i++) {
			if (inFile.eof()) {
				user_input[i] = 0;
			}
			else {
				inFile >> user_input[i];
			}
			std::cout << user_input[i] << ' ';
			outfile << user_input[i] << ' ';
		}
		inFile.seekg(0);
		MergeSort(user_input, 0, 9, user_input5);
		std::cout << "排序结果如下：" << std::endl;
		outfile << std::endl << "排序结果如下:";
		for (int i = 0; i < 10; i++) {
			outfile << user_input[i] << " ";
		}
		outfile << std::endl;
		print(user_input, 10);
	}
	delete[]a1;
	delete[]b2;
	delete[]c3;
	delete[]k4;
	delete[]user_input5;
	user_input5=a1 = b2 = c3 = k4 = nullptr;
	std::cin.clear();
	std::cin.ignore();
}

void QuickSort_Recursionmenu(int *a, int *b, int *c, int *k, std::ofstream&outfile, std::ifstream&inFile) {
	srand(time(0));
	std::cout << "选择测试方式" << std::endl
		<< "1.大量数据检测" << std::endl
		<< "2.输入数据检测" << std::endl
		<< "3.从文件textin.txt中读取数据检测" << std::endl;
	char input = 0;
	int user_input[10] = { 0 };
	clock_t startTime, endTime, alltime = 0;
	std::cin >> input;
	switch (input) {
	case'1':
		startTime = clock();
		QuickSort_Recursion(a, 0,9999);
		endTime = clock();
		std::cout << "1w数据量：" << endTime - startTime << "ms" << std::endl;
		startTime = clock();
		QuickSort_Recursion(b, 0,49999);
		endTime = clock();
		std::cout << "5w数据量：" << endTime - startTime << "ms" << std::endl;
		startTime = clock();
		QuickSort_Recursion(c,0, 199999);
		endTime = clock();
		std::cout << "20w数据量：" << endTime - startTime << "ms" << std::endl;
		for (int i = 0; i < 100000; i++) {
			startTime = clock();
			QuickSort_Recursion(k, 0,99);
			endTime = clock();
			alltime += endTime - startTime;
			for (int j = 0; j < 100; j++) {
				k[j] = rand();
			}
		}
		std::cout << "100*100k数据量：" << alltime << "ms" << std::endl;
		break;
	case'2':
		std::cin.clear();
		std::cin.ignore();
		outfile << "快速排序（递归版）：" << std::endl;
		outfile << "输入的数据为：";
		std::cout << "输入10个整数进行排序" << std::endl;
		for (int m = 0; m < 10; m++) {
			std::cin >> user_input[m];
			outfile << user_input[m] << " ";
		}
		QuickSort_Recursion(user_input,0, 9);
		std::cout << "排序结果如下：" << std::endl;
		outfile << std::endl << "排序结果如下:";
		for (int i = 0; i < 10; i++) {
			outfile << user_input[i] << " ";
		}
		outfile << std::endl;
		print(user_input, 10);
		break;
	case'3':
		outfile << "快速排序（递归版）：" << std::endl;
		outfile << "输入的数据为：";
		std::cout << "文件数据为：" << std::endl;
		for (int i = 0; i < 10; i++) {
			if (inFile.eof()) {
				user_input[i] = 0;
			}
			else {
				inFile >> user_input[i];
			}
			std::cout << user_input[i] << ' ';
			outfile << user_input[i] << ' ';
		}
		inFile.seekg(0);
		QuickSort_Recursion(user_input, 0, 9);
		std::cout << "排序结果如下：" << std::endl;
		outfile << std::endl << "排序结果如下:";
		for (int i = 0; i < 10; i++) {
			outfile << user_input[i] << " ";
		}
		outfile << std::endl;
		print(user_input, 10);
	}
	std::cin.clear();
	std::cin.ignore();
}

void QuickSortmenu(int *a, int *b, int *c, int *k, std::ofstream&outfile, std::ifstream&inFile) {
	srand(time(0));
	std::cout << "选择测试方式" << std::endl
		<< "1.大量数据检测" << std::endl
		<< "2.输入数据检测" << std::endl
		<< "3.从文件textin.txt中读取数据检测" << std::endl;
	char input = 0;
	int user_input[10] = { 0 };
	clock_t startTime, endTime, alltime = 0;
	std::cin >> input;
	switch (input) {
	case'1':
		startTime = clock();
		QuickSort(a, 10000);
		endTime = clock();
		std::cout << "1w数据量：" << endTime - startTime << "ms" << std::endl;
		startTime = clock();
		QuickSort(b, 50000);
		endTime = clock();
		std::cout << "5w数据量：" << endTime - startTime << "ms" << std::endl;
		startTime = clock();
		QuickSort(c, 200000);
		endTime = clock();
		std::cout << "20w数据量：" << endTime - startTime << "ms" << std::endl;
		for (int i = 0; i < 100000; i++) {
			startTime = clock();
			QuickSort(k, 100);
			endTime = clock();
			alltime += endTime - startTime;
			for (int j = 0; j < 100; j++) {
				k[j] = rand();
			}
		}
		std::cout << "100*100k数据量：" << alltime << "ms" << std::endl;
		break;
	case'2':
		std::cin.clear();
		std::cin.ignore();
		outfile << "快速排序（非递归版）：" << std::endl;
		outfile << "输入的数据为：";
		std::cout << "输入10个整数进行排序" << std::endl;
		for (int m = 0; m < 10; m++) {
			std::cin >> user_input[m];
			outfile << user_input[m] << " ";
		}
		QuickSort(user_input, 10);
		std::cout << "排序结果如下：" << std::endl;
		outfile << std::endl << "排序结果如下:";
		for (int i = 0; i < 10; i++) {
			outfile << user_input[i] << " ";
		}
		outfile << std::endl;
		print(user_input, 10);
		break;
	case'3':
		outfile << "快速排序（非递归版）：" << std::endl;
		outfile << "输入的数据为：";
		std::cout << "文件数据为：" << std::endl;
		for (int i = 0; i < 10; i++) {
			if (inFile.eof()) {
				user_input[i] = 0;
			}
			else {
				inFile >> user_input[i];
			}
			std::cout << user_input[i] << ' ';
			outfile << user_input[i] << ' ';
		}
		inFile.seekg(0);
		QuickSort(user_input, 10);
		std::cout << "排序结果如下：" << std::endl;
		outfile << std::endl << "排序结果如下:";
		for (int i = 0; i < 10; i++) {
			outfile << user_input[i] << " ";
		}
		outfile << std::endl;
		print(user_input, 10);
	}
	std::cin.clear();
	std::cin.ignore();
}

void CountSortmenu(int *a, int *b, int *c, int *k, std::ofstream&outfile, std::ifstream&inFile) {
	srand(time(0));
	std::cout << "选择测试方式" << std::endl
		<< "1.大量数据检测" << std::endl
		<< "2.输入数据检测" << std::endl
		<< "3.从文件textin.txt中读取数据检测" << std::endl;
	char input = 0;
	int user_input[10] = { 0 };
	int max = 0;
	clock_t startTime, endTime, alltime = 0;
	std::cin >> input;
	switch (input) {
	case'1':
		max = a[0];
		for (int i = 1; i < 10000; i++) {
			if (a[i] > max) {
				max = a[i];
			}
		}
		startTime = clock();
		CountSort(a, 10000,max);
		endTime = clock();
		std::cout << "1w数据量：" << endTime - startTime << "ms" << std::endl;
		max = b[0];
		for (int i = 1; i < 50000; i++) {
			if (b[i] > max) {
				max = b[i];
			}
		}
		startTime = clock();
		CountSort(b, 50000, max);
		endTime = clock();
		std::cout << "5w数据量：" << endTime - startTime << "ms" << std::endl;
		max = c[0];
		for (int i = 1; i < 200000; i++) {
			if (c[i] > max) {
				max = c[i];
			}
		}
		startTime = clock();
		CountSort(c, 200000,max);
		endTime = clock();
		std::cout << "20w数据量：" << endTime - startTime << "ms" << std::endl;
		for (int i = 0; i < 100000; i++) {
			max = k[0];
			for (int i = 1; i < 100; i++) {
				if (k[i] > max) {
					max = k[i];
				}
			}
			startTime = clock();
			CountSort(k, 100, max);
			endTime = clock();
			alltime += endTime - startTime;
			for (int j = 0; j < 100; j++) {
				k[j] = rand();
			}
		}
		std::cout << "100*100k数据量：" << alltime << "ms" << std::endl;
		break;
	case'2':
		std::cin.clear();
		std::cin.ignore();
		outfile << "计数排序：" << std::endl;
		outfile << "输入的数据为：";
		std::cout << "输入10个整数进行排序" << std::endl;
		for (int m = 0; m < 10; m++) {
			std::cin >> user_input[m];
			if (m == 0) {
				max = user_input[0];
			}
			else {
				if (user_input[m] > max) {
					max = user_input[m];
				}
			}
			outfile << user_input[m] << " ";
		}
		CountSort(user_input, 10, max);
		std::cout << "排序结果如下：" << std::endl;
		outfile << std::endl << "排序结果如下:";
		for (int i = 0; i < 10; i++) {
			outfile << user_input[i] << " ";
		}
		outfile << std::endl;
		print(user_input, 10);
		break;
	case'3':
		outfile << "计数排序：" << std::endl;
		outfile << "输入的数据为：";
		std::cout << "文件数据为：" << std::endl;
		for (int i = 0; i < 10; i++) {
			if (inFile.eof()) {
				user_input[i] = 0;
			}
			else {
				inFile >> user_input[i];
			}
			std::cout << user_input[i] << ' ';
			if (i == 0) {
				max = user_input[0];
			}
			else {
				if (user_input[i] > max) {
					max = user_input[i];
				}
			}
			outfile << user_input[i] << ' ';
		}
		inFile.seekg(0);
		CountSort(user_input, 10, max);
		std::cout << "排序结果如下：" << std::endl;
		outfile << std::endl << "排序结果如下:";
		for (int i = 0; i < 10; i++) {
			outfile << user_input[i] << " ";
		}
		outfile << std::endl;
		print(user_input, 10);
	}
	std::cin.clear();
	std::cin.ignore();
}

void RadixCountSortmenu(int *a, int *b, int *c, int *k, std::ofstream&outfile, std::ifstream&inFile) {
	srand(time(0));
	std::cout << "选择测试方式" << std::endl
		<< "1.大量数据检测" << std::endl
		<< "2.输入数据检测" << std::endl
		<< "3.从文件textin.txt中读取数据检测" << std::endl;
	char input = 0;
	int user_input[10] = { 0 };
	clock_t startTime, endTime, alltime = 0;
	std::cin >> input;
	switch (input) {
	case'1':
		startTime = clock();
		RadixCountSort(a, 10000);
		endTime = clock();
		std::cout << "1w数据量：" << endTime - startTime << "ms" << std::endl;
		startTime = clock();
		RadixCountSort(b, 50000);
		endTime = clock();
		std::cout << "5w数据量：" << endTime - startTime << "ms" << std::endl;
		startTime = clock();
		RadixCountSort(c, 200000);
		endTime = clock();
		std::cout << "20w数据量：" << endTime - startTime << "ms" << std::endl;
		for (int i = 0; i < 100000; i++) {
			startTime = clock();
			RadixCountSort(k, 100);
			endTime = clock();
			alltime += endTime - startTime;
			for (int j = 0; j < 100; j++) {
				k[j] = rand();
			}
		}
		std::cout << "100*100k数据量：" << alltime << "ms" << std::endl;
		break;
	case'2':
		std::cin.clear();
		std::cin.ignore();
		outfile << "基数计数排序：" << std::endl;
		outfile << "输入的数据为：";
		std::cout << "输入10个整数进行排序" << std::endl;
		for (int m = 0; m < 10; m++) {
			std::cin >> user_input[m];
			outfile << user_input[m] << " ";
		}
		RadixCountSort(user_input, 10);
		std::cout << "排序结果如下：" << std::endl;
		outfile << std::endl << "排序结果如下:";
		for (int i = 0; i < 10; i++) {
			outfile << user_input[i] << " ";
		}
		outfile << std::endl;
		print(user_input, 10);
		break;
	case'3':
		outfile << "基数计数排序：" << std::endl;
		outfile << "输入的数据为：";
		std::cout << "文件数据为：" << std::endl;
		for (int i = 0; i < 10; i++) {
			if (inFile.eof()) {
				user_input[i] = 0;
			}
			else {
				inFile >> user_input[i];
			}
			std::cout << user_input[i] << ' ';
			outfile << user_input[i] << ' ';
		}
		inFile.seekg(0);
		RadixCountSort(user_input, 10);
		std::cout << "排序结果如下：" << std::endl;
		outfile << std::endl << "排序结果如下:";
		for (int i = 0; i < 10; i++) {
			outfile << user_input[i] << " ";
		}
		outfile << std::endl;
		print(user_input, 10);
	}
	std::cin.clear();
	std::cin.ignore();
}

void ColorSortmenu(int *a, int *b, int *c, int *k, std::ofstream&outfile, std::ifstream&inFile) {
	srand(time(0));
	std::cout << "选择测试方式" << std::endl
		<< "1.大量数据检测" << std::endl
		<< "2.输入数据检测" << std::endl
		<< "3.从文件textin.txt中读取数据检测" << std::endl;
	char input = 0;
	int user_input[10] = { 0 };
	clock_t startTime, endTime, alltime = 0;
	std::cin >> input;
	switch (input) {
	case'1':
		startTime = clock();
		ColorSort(a, 100000);
		endTime = clock();
		std::cout << "1w数据量：" << endTime - startTime << "ms" << std::endl;
		startTime = clock();
		ColorSort(b, 50000);
		endTime = clock();
		std::cout << "5w数据量：" << endTime - startTime << "ms" << std::endl;
		startTime = clock();
		ColorSort(c, 200000);
		endTime = clock();
		std::cout << "20w数据量：" << endTime - startTime << "ms" << std::endl;
		for (int i = 0; i < 100000; i++) {
			startTime = clock();
			ColorSort(k, 100);
			endTime = clock();
			alltime += endTime - startTime;
			for (int j = 0; j < 100; j++) {
				k[j] = rand();
			}
		}
		std::cout << "100*100k数据量：" << alltime << "ms" << std::endl;
		break;
	case'2':
		std::cin.clear();
		std::cin.ignore();
		outfile << "颜色排序：" << std::endl;
		outfile << "输入的数据为：";
		std::cout << "输入10个整数进行排序" << std::endl;
		for (int m = 0; m < 10; m++) {
			std::cin >> user_input[m];
			outfile << user_input[m] << " ";
		}
		ColorSort(user_input, 10);
		std::cout << "排序结果如下：" << std::endl;
		outfile << std::endl << "排序结果如下:";
		for (int i = 0; i < 10; i++) {
			outfile << user_input[i] << " ";
		}
		outfile << std::endl;
		print(user_input, 10);
		break;
	case'3':
		outfile << "基数计数排序：" << std::endl;
		outfile << "输入的数据为：";
		std::cout << "文件数据为：" << std::endl;
		for (int i = 0; i < 10; i++) {
			if (inFile.eof()) {
				user_input[i] = 0;
			}
			else {
				inFile >> user_input[i];
			}
			std::cout << user_input[i] << ' ';
			outfile << user_input[i] << ' ';
		}
		inFile.seekg(0);
		ColorSort(user_input, 10);
		std::cout << "排序结果如下：" << std::endl;
		outfile << std::endl << "排序结果如下:";
		for (int i = 0; i < 10; i++) {
			outfile << user_input[i] << " ";
		}
		outfile << std::endl;
		print(user_input, 10);
	}
	std::cin.clear();
	std::cin.ignore();
}

void No_k_sortmenu(std::ofstream&outfile, std::ifstream&inFile) {
	std::cout << "1.自行输入数据" << std::endl
		<< "2.从文件textin.txt中读取数据检测" << std::endl;
	outfile << "寻找第几小的数：" << std::endl;
	outfile << "输入的数字为：";
	int temp[10] = { 0 };
	char input = 0;
	std::cin >> input;
	switch (input) {
	case '1':
		std::cout << "输入10个数字创建数组（不足则补0）:" << std::endl;
		for (int i = 0; i < 10; i++) {
			std::cin >> temp[i];
			outfile << temp[i] << " ";
		}
		break;
	case '2':
		std::cout << "文件数据为：" << std::endl;
		for (int i = 0; i < 10; i++) {
			if (inFile.eof()) {
				temp[i] = 0;
			}
			else {
				inFile >> temp[i];
			}
			std::cout << temp[i] << ' ';
			outfile << temp[i] << ' ';
		}
		inFile.seekg(0);
		break;
	}
	std::cout << "输入寻找第几小的数：";
	int k, get;
	std::cin >> k;
	No_k_sort(temp, 0, 9, k, &get);
	std::cout << "第" << k << "小的数:" << get << std::endl;
	outfile << std::endl << "第" << k << "小的数:" << get << std::endl;
	std::cin.clear();
	std::cin.ignore();
}

bool menu(int*a, int *b, int*c, int*k, int*a1, int*b2, int*c3, std::ofstream&outfile, std::ifstream&inFile) {
	system("cls");
	char input = 0;
	std::cout << "选择排序方式" << std::endl;
	std::cout << "1.插入排序" << std::endl
		<< "2.并归排序" << std::endl
		<< "3.快速排序（递归版）" << std::endl
		<< "4.快速排序（非递归版）" << std::endl
		<< "5.计数排序" << std::endl
		<< "6.基数计数排序" << std::endl
		<< "7.颜色排序" << std::endl
		<< "8.寻找第K小的数" << std::endl;
	std::cin >> input;
	switch (input) {
	case '1':insertSortmenu(a, b, c, k, outfile, inFile); break;
	case '2':MergeSortmenu(a, b, c, k, outfile, inFile); break;
	case '3':QuickSort_Recursionmenu(a, b, c, k, outfile, inFile); break;
	case '4':QuickSortmenu(a, b, c, k, outfile, inFile); break;
	case '5':CountSortmenu(a, b, c, k, outfile, inFile); break;
	case '6':RadixCountSortmenu(a, b, c, k, outfile, inFile); break;
	case '7':ColorSortmenu(a1, b2, c3, k, outfile, inFile); break;
	case '8':No_k_sortmenu(outfile, inFile); break;
	case 'e':return true;
	}
	std::cin.clear();
	std::cin.ignore();
	system("pause");
	return false;
}

int main() {
	std::ofstream ontFile;
	ontFile.open("text.txt", std::ios::out);
	std::ifstream inFile;
	inFile.open("textin.txt", std::ios::in);
	srand(time(0));
	int *a = new int[10000];
	for (int j = 0; j < 10000; j++) {
		a[j] = rand();
	}
	int *b = new int[50000];
	for (int j = 0; j < 50000; j++) {
		b[j] = rand();
	}
	int *c = new int[200000];
	for (int j = 0; j < 200000; j++) {
		c[j] = rand();
	}
	int *a1 = new int[10000];
	for (int j = 0; j < 10000; j++) {
		a1[j] = rand()%3;
	}
	int *b2 = new int[50000];
	for (int j = 0; j < 50000; j++) {
		b2[j] = rand()%3;
	}
	int *c3 = new int[200000];
	for (int j = 0; j < 200000; j++) {
		c3[j] = rand()%3;
	}
	int *k = new int[100];
	while (1) {
		if (menu(a, b, c, a1, b2, c3, k, ontFile, inFile))
			break;
	}
	delete []a;
	delete []b;
	delete []c;
	delete[]a1;
	delete[]b2;
	delete[]c3;
	delete []k;
	a = b = c = a1 = b2 = c3 = k = nullptr;
	ontFile.close();
	inFile.close();
	return 0;
}



