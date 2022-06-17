#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//快速排序算法(递归方式)
void quickSort(int* arr, int len);
void qSort(int* arr, int low, int high);
void swap(int* a, int* b);

void quickSort(int* arr, int len)
{
	int begin = 0;
	int end = len - 1;
	qSort(arr, begin, end);
}

void qSort(int* arr, int start, int end)
{
	if (start >= end) return;
	int low = start;
	int high = end;
	int key = arr[low];

	while (low < high) {
		while (low < high && arr[high] <= key) {
			high--;
		}
		swap(&arr[low], &arr[high]);
		while (low < high && arr[low] >= key) {
			low++;
		}
		swap(&arr[low], &arr[high]);
	}

	qSort(arr, start, low - 1);
	qSort(arr, low + 1, end);
}

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	int arr[] = {94, 46, 55, 28, 37,100, 68, 77, 11};
	int arr_len = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, arr_len);

	printf("after sort:\n");
	for (int i = 0; i < arr_len; i++) {
		printf("%4d,", arr[i]);
	}
	return 0;

}