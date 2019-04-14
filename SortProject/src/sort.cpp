#include "sort.h"
#include<stack>
#include<math.h>



/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int * a, int size, int max)
{
	if (size > 1) {
		int *count = new int[max + 1];
		for (int q = 0; q < max + 1; q++) {
			count[q] = 0;
		}
		for (int i = 0; i < size; i++) {
			count[a[i]]++;
		}
		for (int j = 1; j < max + 1; j++) {
			count[j] += count[j - 1];
		}
		int *temp = new int[size];
		for (int k = size-1; k >= 0; k--) {
			count[a[k]]--;
			temp[count[a[k]]] = a[k];
		}
		for (int m = 0; m < size; m++) {
			a[m] = temp[m];
		}
		delete temp;
		temp = nullptr;
		delete count;
		count = nullptr;
	}
}

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int * a, int size)
{
	int *times = new int[size];
	int count[10] = { 0 };
	int cow = 1;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			count[j] = 0;
		}
		for (int j = 0; j < size; j++) {
			int temp = a[j] / cow % 10;
			count[temp]++;
		}
		for (int j = 1; j < 10; j++) {
			count[j] += count[j - 1];
		}
		for (int j = size - 1; j >= 0; j--) {
			int temp = (a[j] / cow) % 10;
			times[--count[temp]] = a[j];
		}
		cow *= 10;
		for (int i = 0; i < size; i++) {
			a[i] = times[i];
		}
	}
	delete times;
	times = nullptr;
}

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int * a, int size)
{
	int *p0 = a;
	int *p2 = a+size-1;
	int *p1 = a;
	int temp;
	while (p1 != p2) {
		if (*p1 == 0) {
			temp = *p1;
			*p1 = *p0;
			*p0 = temp;
			p0++;
			if (*p1 == 2) {
				temp = *p1;
				*p1 = *p2;
				*p2 = temp;
				p2--;
			}
		}
		if (*p1 == 2) {
			temp = *p1;
			*p1 = *p2;
			*p2 = temp;
			p2--;
			if (*p1 == 0) {
				temp = *p1;
				*p1 = *p0;
				*p0 = temp;
				p0++;
			}
		}
		p1++;
	}
	if (*p1 == 0) {
		temp = *p1;
		*p1 = *p0;
		*p0 = temp;
		p0++;
	}
	if (*p1 == 2) {
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
		p2--;
	}
}


