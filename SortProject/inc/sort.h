#ifndef __SORTH__
#define __SORTH__
#include<stack>

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ��������
 *  @param       : ����ָ�� a, ���鳤�� n
 */
template<typename T>
void insertSort(T * a, int n)
{
	if (n > 1) {
		for (int i = 1; i < n; i++) {
			if (a[i] < a[i - 1]) {
				int j = i;
				T temp = a[j];
				while (j>0&&temp < a[j-1]) {
					a[j] = a[j-1];
					j--;
				}
				a[j] = temp;
			}
		}
	}
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
template<typename T>
void MergeArray(T * a, int begin, int mid, int end, T * temp)
{
	int i = begin, j = mid;
	T *p1 = a + begin;
	T *p2 = a + mid;
	T *p0 = temp + begin;
	for (; i < mid && j <= end; p0++) {
		if (*p1 < *p2) {
			*p0 = *p1;
			p1++;
			i++;
		}
		else {
			*p0 = *p2;
			p2++;
			j++;
		}
	}
	while (i < mid) {
		*p0 = *p1;
		p1++;
		p0++;
		i++;
	}
	while (j <= end) {
		*p0 = *p2;
		p2++;
		p0++;
		j++;
	}
	p0 = temp + begin;
	p1 = a + begin;
	for (i = 0; i < end - begin + 1; i++, p0++, p1++) {
		*p1 = *p0;
	}


}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
template<typename T>
void MergeSort(T * a, int begin, int end, T *temp)
{
	if (begin < end) {
		MergeSort(a, begin, (end + begin) / 2 , temp);
		MergeSort(a, (end + begin) / 2+1, end, temp);
		MergeArray(a, begin, (end + begin) / 2+1, end, temp);
	}
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
template<typename T>
void QuickSort_Recursion(T * a, int begin, int end)
{
	int i = begin, j = begin;
	T key = *(a + begin);
	T temp;
	T *p1 = a + begin;
	T *p2 = a + begin + 1;
	if (end - begin + 1 >= 8) {
		if (begin < end) {
			while (i < end) {
				if (*p2 < key) {
					p1++;
					j++;
					temp = *p2;
					*p2 = *p1;
					*p1 = temp;
				}
				p2++;
				i++;
			}
			temp = *(a+begin);
			 *(a+begin)= *p1;
			 *p1 = temp;
			QuickSort_Recursion(a, begin, j - 1);
			QuickSort_Recursion(a, j + 1, end);
		}
	}
	else {
		if (end - begin + 1 > 1) {
			for (int m = begin; m < end+1; m++) {
				if (a[m] < a[m - 1]) {
					int n = m;
					temp = a[n];
					while (n > 0 && temp < a[n - 1]) {
						a[n] = a[n - 1];
						n--;
					}
					a[n] = temp;
				}
			}
		}
	}


	/*int low = begin, high = end;
	T key = *a;
	T temp;
	while (low < high) {
		while (low < high&&*(a + high) >= key)
			high--;
		temp = *(a + high);
		*(a + high) = *(a + low);
		*(a + low) = temp;
		while (begin < high&&*(a + low) <= key)
			low++;
		temp = *(a + high);
		*(a + high) = *(a + low);
		*(a + low) = temp;
	}
	if (begin < end) {
		QuickSort_Recursion(a, begin, low-1);
		QuickSort_Recursion(a, low+1, end);
	}*/
}





/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
template<typename T>
int Partition(T * a, int begin, int end)
{
	int low = begin, high = end;
	T key = *(a+begin);
	T temp;
	while (low < high) {
		while (low < high&&*(a + high) >= key)
			high--;
		temp = *(a + high);
		*(a + high) = *(a + low);
		*(a + low) = temp;
		while (low < high&&*(a + low) <= key)
			low++;
		temp = *(a + high);
		*(a + high) = *(a + low);
		*(a + low) = temp;
	}
	return low;
}

/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
template<typename T>
void QuickSort(T * a, int size)
{
	int k = 0, low = 0, high = 0;
	std::stack<int> temp;
	temp.push(0);
	temp.push(size-1);
	while (!temp.empty()) {
		high = temp.top();
		temp.pop();
		low = temp.top();
		temp.pop();
		k = Partition(a, low, high);
		if (low < k) {
			temp.push(low);
			temp.push(k-1);
		}
		if (k < high) {
			temp.push(k+1);
			temp.push(high);
		}
	}
}



/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int * a, int size, int max);


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int *a, int size);


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */

void ColorSort(int *a, int size);


/**
 *  @name        : ����
 *  @description : ��һ�������������ҵ���KС����
 *  @param       : ����ָ��a�����鳤��size
 */
template<typename T>
bool No_k_sort(T *a, int begin, int end, const int k,T *get) {
	static int number = 0;
	int i = begin, j = begin;
	T key = *(a + begin);
	T temp;
	T *p1 = a + begin;
	T *p2 = a + begin + 1;
	if (begin < end) {
		while (i < end) {
			if (*p2 < key) {
				p1++;
				j++;
				temp = *p2;
				*p2 = *p1;
				*p1 = temp;
			}
			p2++;
			i++;
		}
		temp = *(a + begin);
		*(a + begin) = *p1;
		*p1 = temp;
		if (!No_k_sort(a, begin, j - 1, k, get)) {
			number++;
			if (number == k) {
				*get = *(a + begin);
			}
		}
		if (p1 != a + begin) {
			number++;
			if (number == k) {
				*get = *(a + begin);
			}
		}
		if (!No_k_sort(a, j + 1, end, k, get)) {
			number++;
			if (number == k) {
				*get = *(a + end);
			}
		}
	}
	else {
		return false;
	}
	return true;
}



#endif

