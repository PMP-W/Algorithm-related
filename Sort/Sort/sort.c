#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"
#include"stack.h"
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
//直接插入排序
//时间复杂度
//最坏：O(n2)  逆序
//最好：O(n)   顺序或接近有序
void InsertSort(int* a, int n)
{
	//[0,end]   end+1
	for (int i = 0; i < n - 1; i++)
	{
		int end=i;
		int tmp = a[end + 1];//保存即将要排序的元素
		while (end >= 0)
		{
			if (tmp < a[end])//升序
			{
				a[end + 1] = a[end];
				end--;
			}
			else
				break;
		}
		a[end + 1] = tmp;
	}
}
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//时间复杂度
//最坏：O(n2)
//最好：O(n)
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n; j++)
	{
		int flag = 0;
		for (int i = 0; i < n - j-1; i++)//for(int i=1;i<n-j-1;i++)   swap(&a[i-1,&a[i])
		{
			if (a[i] > a[i+1])//i+1<n-j
			{
				swap(&a[i], &a[i+1]);
				flag = 1;
			}

		}
		if (flag == 0)
			break;
	}
}

//希尔排序
//1.预排序（接近有序）gap>1
//2.直接插入排序   gap==1

//时间复杂度
//平均O(N^1.3)
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//每次减小gap的值，但是要保证最后一次gap==1
		//for (int j = 0; j < gap; j++)
		//{
		//	for (int i = j; i < n - gap; i += gap)
		//	{
		//		int end = i;
		//		int tmp = a[end + gap];//保存即将要排序的元素
		//		while (end >= 0)
		//		{
		//			if (tmp < a[end])//升序
		//			{
		//				a[end + gap] = a[end];
		//				end -= gap;
		//			}
		//			else
		//				break;
		//		}
		//		a[end + gap] = tmp;
		//	}
		//}
		for (int i = 0; i < n - gap; i++)//多组并排（优化前是一个组一个组地排，即每次i+=gap,且外面还需要套一层循环）
		{
			int end = i;
			int tmp = a[end + gap];//保存即将要排序的元素
			while (end >= 0)
			{
				if (tmp < a[end])//升序
				{
					a[end + gap] = a[end];//向后挪动
					end-=gap;
				}
				else
					break;
			}
			a[end + gap] = tmp;
		}
	}
}
//直接选择排序
//时间复杂度：O（N^2）
//最好情况:O(N^2)
void SelectSort(int* a, int n)
{
	//每轮选出区间内最大的元素和最小的元素的下标
	//然后将这两个元素分别和区间最右边和最左边的元素交换
	int begin = 0;
	int end = n - 1;
	while (begin <= end)
	{
		int mini = begin;
		int maxi = begin;
		for (int i = begin + 1; i <= end; i++)//保存的是下标
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		swap(&a[mini], &a[begin]);
		if (maxi == begin)//可能第一次换的时候最大的数在最左边，这样交换之后，
			              //最大的数的位置就发生了变化，第二次交换，最大的数就不能换到最后面
		{
			maxi = mini;
		}
		swap(&a[maxi], &a[end]);
		begin++;
		end--;
	}
}


void AdjustDown(int* a, int size, int parent)
{
	assert(a);
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] > a[child])//找兄弟节点中较小的那一个，再交换  //小堆（大堆时是>）
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = child * 2 + 1;
			//child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	//建大堆
	//把数组第一个元素看作一个完全二叉树，然后将其他元素插入，再向上调整
	//本质：模拟堆插入的过程建堆
	/*for (int i = 1; i < n; i++)
	{
		AdjustUp(a, i);
	}*/
	//向下调整建堆效率更高  O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	//O(NlogN)
	while (end > 0)
	{
		swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

//快排
int GetMidi(int* a, int begin, int end)
{
	int midi = (begin + end) / 2;
	//取中位数
	if (a[begin] <= a[midi])
	{
		if (a[midi] <= a[end])
		{
			return midi;
		}
		else 
		{
			if (a[begin] <= a[end])
				return end;
			else
				return begin;
		}
	}
	else   //midi begin
	{
		if (a[begin] >= a[end])
		{
			if (a[midi] >= end)
			{
				return midi;
			}
			else
				return end;
		}
		else
			return begin;
	}
}

//hoare
//右边先走，相遇位置一定比key小
int PartSort1(int* a, int begin,int end)
{
	
	/*
这里要从右边走，如果从左边走，
可能最后一步，如果找不到大于
基准值的，会导致begin == end
即相遇，但是右边还没有走，所以
这里的值一定大于基准值，最后交换
就会出问题，所以一定要从右边走，
即使最后一次找不到小于基准值的，
会和左边相遇，而左边此时还没走，
一定比基准值小，最后交换肯定没有问题
*/
	int midi = GetMidi(a, begin, end);
	swap(&a[midi], &a[begin]);
	int left = begin;
	int right = end;
	int keyi = begin;
	while (left < right)
	{
		while (left<right&&a[right] >= a[keyi])
		{
			right--;
		}
		while (left<right&&a[left] <= a[keyi])
		{
			left++;
		}
		swap(&a[right], &a[left]);

	}
	swap(&a[left], &a[keyi]);
	keyi = left;
	return keyi;

}
//双指针法
int PartSort2(int* a, int begin, int end)
{
	int midi = GetMidi(a, begin, end);
	swap(&a[begin], &a[midi]);
	int keyi = begin;
	int prev = begin;
	int cur = begin + 1;
	while (cur <= end)
	{
		if (a[cur] < a[keyi] && ++prev != cur)//自身交换减少了
		{
			swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	swap(&a[keyi], &a[prev]);
	keyi = prev;
	return prev;
}
//挖坑法
int PartSort3(int* a, int begin, int end)
{
	int midi = GetMidi(a, begin, end);
	swap(&a[begin], &a[midi]);
	int key = a[begin];
	int hole = begin;
	while (begin < end)
	{
		//右边找小，填到左边的坑
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		a[hole] = a[end];
		hole = end;
		//左边找大，填到右边的坑
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		a[hole] = a[begin];
		hole = begin;
	}
	a[hole] = key;
	return hole;
}
//最差O(n^2) 最优O(nlogn) 平均O(nlogn)
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	//int keyi = PartSort1(a, begin, end);
	//int keyi = PartSort2(a, begin, end);
	int keyi = PartSort3(a, begin, end);
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}
void QuickSortNonR(int* a, int begin, int end)
{
	ST s;
	STInit(&s);
	STPush(&s, end);
	STPush(&s, begin);

	while (!STEmpty(&s))
	{
		int left = STTop(&s);
		STPop(&s);
		int right = STTop(&s);
		STPop(&s);

		int keyi = PartSort3(a, left, right);
		// [left, keyi-1] keyi [keyi+1, right]
		if (left < keyi - 1)
		{
			STPush(&s, keyi - 1);
			STPush(&s, left);
		}

		if (keyi + 1 < right)
		{
			STPush(&s, right);
			STPush(&s, keyi + 1);
		}
	}

	STDestroy(&s);
}

//时间复杂度:O(NlogN)
//空间复杂度:O(N)
void _MergeSort(int* a, int begin, int end,int* tmp)
{
	if (begin >= end)
	{
		return;
	}
	int mid = (begin + end) / 2;
	//[begin,mid] [begin+1,end]
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid+1, end, tmp);
	//[begin,mid] [begin+1,end]  归并
	int begin1 = begin, end1 = mid;
	int begin2 = mid+1, end2 = end;
	int i = begin;
	//合并两个有序数组
	//有一个到了终止条件就停止循环
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])//取小的尾插
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	//没循环完的直接尾插
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	//拷贝回原数组
	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}
//后序递归
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc!");
		return;
	}
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand()+i;
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}
	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();
	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();
	int begin3 = clock();
	SelectSort(a3, N);
	int end3 = clock();
	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();
	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();
	int begin6 = clock();
	MergeSort(a6, N);
	int end6 = clock();
	int begin7 = clock();
	BubbleSort(a7, N);
	int end7 = clock();
	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);
	printf("BubbleSort:%d\n", end7 - begin7);
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}