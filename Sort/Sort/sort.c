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
//ֱ�Ӳ�������
//ʱ�临�Ӷ�
//���O(n2)  ����
//��ã�O(n)   ˳���ӽ�����
void InsertSort(int* a, int n)
{
	//[0,end]   end+1
	for (int i = 0; i < n - 1; i++)
	{
		int end=i;
		int tmp = a[end + 1];//���漴��Ҫ�����Ԫ��
		while (end >= 0)
		{
			if (tmp < a[end])//����
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
//ʱ�临�Ӷ�
//���O(n2)
//��ã�O(n)
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

//ϣ������
//1.Ԥ���򣨽ӽ�����gap>1
//2.ֱ�Ӳ�������   gap==1

//ʱ�临�Ӷ�
//ƽ��O(N^1.3)
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//ÿ�μ�Сgap��ֵ������Ҫ��֤���һ��gap==1
		//for (int j = 0; j < gap; j++)
		//{
		//	for (int i = j; i < n - gap; i += gap)
		//	{
		//		int end = i;
		//		int tmp = a[end + gap];//���漴��Ҫ�����Ԫ��
		//		while (end >= 0)
		//		{
		//			if (tmp < a[end])//����
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
		for (int i = 0; i < n - gap; i++)//���鲢�ţ��Ż�ǰ��һ����һ������ţ���ÿ��i+=gap,�����滹��Ҫ��һ��ѭ����
		{
			int end = i;
			int tmp = a[end + gap];//���漴��Ҫ�����Ԫ��
			while (end >= 0)
			{
				if (tmp < a[end])//����
				{
					a[end + gap] = a[end];//���Ų��
					end-=gap;
				}
				else
					break;
			}
			a[end + gap] = tmp;
		}
	}
}
//ֱ��ѡ������
//ʱ�临�Ӷȣ�O��N^2��
//������:O(N^2)
void SelectSort(int* a, int n)
{
	//ÿ��ѡ������������Ԫ�غ���С��Ԫ�ص��±�
	//Ȼ��������Ԫ�طֱ���������ұߺ�����ߵ�Ԫ�ؽ���
	int begin = 0;
	int end = n - 1;
	while (begin <= end)
	{
		int mini = begin;
		int maxi = begin;
		for (int i = begin + 1; i <= end; i++)//��������±�
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
		if (maxi == begin)//���ܵ�һ�λ���ʱ��������������ߣ���������֮��
			              //��������λ�þͷ����˱仯���ڶ��ν������������Ͳ��ܻ��������
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
		if (child + 1 < size && a[child + 1] > a[child])//���ֵܽڵ��н�С����һ�����ٽ���  //С�ѣ����ʱ��>��
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
	//�����
	//�������һ��Ԫ�ؿ���һ����ȫ��������Ȼ������Ԫ�ز��룬�����ϵ���
	//���ʣ�ģ��Ѳ���Ĺ��̽���
	/*for (int i = 1; i < n; i++)
	{
		AdjustUp(a, i);
	}*/
	//���µ�������Ч�ʸ���  O(N)
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

//����
int GetMidi(int* a, int begin, int end)
{
	int midi = (begin + end) / 2;
	//ȡ��λ��
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
//�ұ����ߣ�����λ��һ����keyС
int PartSort1(int* a, int begin,int end)
{
	
	/*
����Ҫ���ұ��ߣ����������ߣ�
�������һ��������Ҳ�������
��׼ֵ�ģ��ᵼ��begin == end
�������������ұ߻�û���ߣ�����
�����ֵһ�����ڻ�׼ֵ����󽻻�
�ͻ�����⣬����һ��Ҫ���ұ��ߣ�
��ʹ���һ���Ҳ���С�ڻ�׼ֵ�ģ�
����������������ߴ�ʱ��û�ߣ�
һ���Ȼ�׼ֵС����󽻻��϶�û������
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
//˫ָ�뷨
int PartSort2(int* a, int begin, int end)
{
	int midi = GetMidi(a, begin, end);
	swap(&a[begin], &a[midi]);
	int keyi = begin;
	int prev = begin;
	int cur = begin + 1;
	while (cur <= end)
	{
		if (a[cur] < a[keyi] && ++prev != cur)//������������
		{
			swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	swap(&a[keyi], &a[prev]);
	keyi = prev;
	return prev;
}
//�ڿӷ�
int PartSort3(int* a, int begin, int end)
{
	int midi = GetMidi(a, begin, end);
	swap(&a[begin], &a[midi]);
	int key = a[begin];
	int hole = begin;
	while (begin < end)
	{
		//�ұ���С�����ߵĿ�
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		a[hole] = a[end];
		hole = end;
		//����Ҵ���ұߵĿ�
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
//���O(n^2) ����O(nlogn) ƽ��O(nlogn)
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

//ʱ�临�Ӷ�:O(NlogN)
//�ռ临�Ӷ�:O(N)
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
	//[begin,mid] [begin+1,end]  �鲢
	int begin1 = begin, end1 = mid;
	int begin2 = mid+1, end2 = end;
	int i = begin;
	//�ϲ�������������
	//��һ��������ֹ������ֹͣѭ��
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])//ȡС��β��
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	//ûѭ�����ֱ��β��
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	//������ԭ����
	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}
//����ݹ�
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