#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"
void test_InsertSort()
{
	int a[] = {1, 0,3,5,4,4,2,9,7,8,6 };
	int n = sizeof(a) / sizeof(int);
	InsertSort(a, n);
	PrintArray(a, n);
}
void test_BubbleSort()
{
	int a[] = { 1, 0,3,5,4,4,2,9,7,8,6 };
	int n = sizeof(a) / sizeof(int);
	BubbleSort(a, n);
	PrintArray(a, n);

}
void test_ShellSort()
{
	int a[] = { 1, 0,3,5,4,4,2,9,7,8,6 };
	int n = sizeof(a) / sizeof(int);
	ShellSort(a, n);
	PrintArray(a, n);

}
void test_SelectSort()
{
	int a[] = { 1, 0,3,5,4,4,2,9,7,8,6 };
	int n = sizeof(a) / sizeof(int);
	SelectSort(a, n);
	PrintArray(a, n);

}
void test_HeapSort()
{
	int a[] = { 1, 0,3,5,4,4,2,9,7,8,6 };
	int n = sizeof(a) / sizeof(int);
	HeapSort(a, n);
	PrintArray(a, n);

}
void test_QuickSort()
{
	int a[] = { 6,1,2,5,7,9,3,4,1,5,10,8,-1 };
	int n = sizeof(a) / sizeof(int);
	QuickSort(a, 0,n-1);
	PrintArray(a, n);

}
void test_MergeSort()
{
	int a[] = { 1, 0,3,5,4,4,2,9,7,8,6 };
	int n = sizeof(a) / sizeof(int);
	MergeSort(a, n);
	PrintArray(a, n);

}
int main()
{
	//test_InsertSort();
	//test_BubbleSort();
	//test_ShellSort();
	//test_SelectSort();
	//test_HeapSort();
	//test_QuickSort();
	//test_MeregeSort();
	TestOP();
	return 0;
}