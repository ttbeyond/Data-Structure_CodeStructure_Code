#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Print(int* arr, int size)
{
	if (!arr)
		printf("û�����ݿɹ���ӡ\n");
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void Swap(int* p, int* q)
{
	int ret = *p;
  	*p = *q;
	*q = ret;
}

void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;//����
	while (child < n)
	{
		//�ҵ�����Ǹ�����
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		//���Ӵ��ڸ��ף��򽻻�
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		//��ĺ���С�ڸ��ף�������
		else
		{
			break;
		}
	}
}
void HeapSort(int* arr, int size)
{
	//�����򣬽����
	//O(N)
	for (int i = (size - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(arr, size, i);
	}

	//ȥ�Ѷ����ݣ�������������
	int end = size - 1;
	while (end > 0)
	{
		Swap(&arr[end], &arr[0]);
		AdjustDown(arr, end, 0);
		--end;
	}
}

//ð������
//ʱ�临�Ӷȣ�O(N*N)
void BubbleSort(int* arr,int size)
{
	for (int i = size-1; i >0; --i)//���������±�
	{
		int flag = 0;
		for (int j = 0; j < i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
               Swap(&arr[j], &arr[j + 1]);
			   flag = 1;
			}				
		}
		if (flag == 0)
		{
			break;
		}
	}
}

//��������
//ʱ�临�Ӷȣ�O(N*logN)
int GetMidIndex(int* arr, int begin, int end)
{
	int mid = (begin + end) >> 1;//�൱�ڳ���

	if (arr[begin] < arr[mid])
	{
		if (arr[mid] < arr[end])
			return mid;
		else if (arr[begin] < arr[end])
			return end;
		else
			return begin;
	}
	else
	{
		if (arr[mid] < arr[end])
			return mid;
		else if (arr[begin] < arr[end])
			return begin;
		else
			return end;
	}
}

//ע�⣺����Ҫ��������±�(��Ϊ�±��ǰ����±�д��)
//����ָ�뷨
int PartSort1(int*arr, int begin, int end)
{
	int key = arr[end];
	int keyindex = end;
	while (begin < end)
	{
		//begin�Ҵ��ڵ���key����
		while (begin < end && arr[begin] <= key)
			++begin;
		//end��С�ڵ���key����
		while (begin < end && arr[end] >= key)
			--end;
		//����
		Swap(&arr[begin], &arr[end]);
	 }
	Swap(&arr[begin], &arr[keyindex]);

	return begin;
}

//�ڿӷ�//��������ָ�뷨����
int PartSort2(int*arr, int begin, int end)
{
	int key = arr[end];

	while (begin < end)
	{
		while (begin < end && arr[begin] <= key)//�Ҵ���key����
			++begin;
		arr[end] = arr[begin];//�ҵ���ģ������ұߵĿ�λ�У�ͬʱend�γ��µĿ�λ

		while (begin < end && arr[end] >= key)//��С��key����
			--end;
		arr[begin] = arr[end];//�ҵ�С�ģ�������ߵĿ�λ��ͬʱbegin�γ��µĿ�λ
	}
	arr[begin] = key;//�����һ����λ����
	return begin;
}

//ǰ��ָ�뷨
int PartSort3(int*arr, int begin, int end)
{
	//����ȡ�з��Ż�������������
	//�Ż�
	int midindex = GetMidIndex(arr, begin, end);
	Swap(&arr[midindex], &arr[end]);


	int key = arr[end];
	int cur = begin;
	int prev = begin - 1;
	while (cur < end)//�ߵ�key��λ�þͽ���
	{
		if (arr[cur] < key && ++prev != cur)//��С��key��ֵ��������prev��ǰ��
			Swap(&arr[prev], &arr[cur]);
		++cur;
	}
	++prev;//���prevͣ����λ�õ�ֵ(arr[prev])�Ǳ�keyҪС��,�����Ҫ++һ��
	Swap(&arr[prev], &arr[end]);

	return prev;
}
void QuickSort(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//�����黮��Ϊ����
	int keyindex =PartSort1(arr, begin, end);
	//int keyindex = PartSort2(arr, begin, end);
	//int keyindex = PartSort3(arr, begin, end);

	//������������
	QuickSort(arr, begin, keyindex - 1);//ǰ���һ��
	QuickSort(arr, keyindex + 1, end);
}

//�鲢����
void _MergeSort(int* arr, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	//����
	int mid = (begin + end) >> 1;
	//[begin,mid] [mid+1,end]  ��������
	_MergeSort(arr, begin, mid, tmp);
	_MergeSort(arr, mid+1, end, tmp);

	//[begin,mid] [mid+1,end]  ��������


	//�鲢������������
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int index = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
			tmp[index++] = arr[begin1++];
		else
			tmp[index++] = arr[begin2++];
	}
	if (begin1 <= end1)
	{
		while (begin1 <= end1)
			tmp[index++] = arr[begin1++];
	}
	else
	{
		while (begin2 <= end2)
			tmp[index++] = arr[begin2++];
	}

	//���鲢��tmp�����ݿ�����ԭ����
	memcpy(arr + begin, tmp + begin, sizeof(int)*(end - begin + 1));
	//ע�⣺��һ����Ϊ�±�������Ԥ�ڽ��Сһ
}
void MergeSort(int* arr, int size)
{
	int* tmp = (int*)malloc(sizeof(int)*size);
	_MergeSort(arr, 0, size-1,tmp);
	free(tmp);
}


//ֱ�Ӳ�������
//ʱ�临�Ӷ�O(N^2)
//��������(���������������)�����Ӷ�ΪO(N^2)
//˳����������(���������������)�����Ӷ�ΪO(N)
void InsertSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
       //��������
	   //��[0,end]�������arr[size] 
	   //�����������һ��ΪҪ�������
	   //��[0��end]�����������ڲ���tmp��ʹ����������
	   int end = i;
	   int tmp = arr[end + 1];
	   while (end >= 0)
	    {
		  if (arr[end] > tmp)
		   {
			  arr[end + 1] = arr[end];
				 --end;
		    }
		   else
		  {
			break;
		   }
	      }
	    arr[end + 1] = tmp;
       }
}

//ϣ������
//ƽ��ʱ�临�Ӷȣ�O(N^1.3)
//˳����������ʱ���Ԥ����ȫ������������ֱ�Ӳ�������
void ShellSort(int* arr, int size)
{
	//gap>1ʱΪԤ����������ӽ�����
	//gap == 1ʱ��Ϊֱ�Ӳ�����������������
	int gap = size;
	while (gap > 1)
	{
		//���Ϊgap��Ԥ����

		gap = gap / 3 + 1;//+1�Ǳ�֤���һ��һ��Ϊ1  //3Ϊgap  //����ѭ������������
		//ע�ⲻ���ǳ�2   //ԭ�򣺵�gap==2ʱ��2/2+1=2����ʱgap������ȥ��
	    for (int i = 0; i < size - gap; ++i)
	     {
		   int end = i;
		   int tmp = arr[end + gap];
		    while (end >= 0)
		       {
		  	      if (arr[end] > tmp)
		 	        {
				      arr[end + gap] = arr[end];
				       end -= gap;
			         }
			       else
			         {
			 	        break;
			          }
		        }
		     arr[end + gap] = tmp;

	       }
	}
}

//ѡ������
//ʱ�临�Ӷȣ�O(N^2)
void SelectSort(int* arr, int size)
{
	int begin = 0, end = size - 1;
	//
	while (begin < end)
	{
		int minindex = begin, maxindex = end;
		for (int i = begin; i <= end; ++i)
		{
			if (arr[i]>arr[maxindex])
				maxindex = i;
			if (arr[i] < arr[minindex])
				minindex = i;
		}
		Swap(&arr[begin], &arr[minindex]);
		//����arr[begin]��arr[minindex]������arr[begin]��arr[maxindex]��ȵ����
		if (begin == maxindex)
			maxindex = minindex;
		Swap(&arr[end], &arr[maxindex]);

		++begin;
		--end;
	}
}

//��������
//ʱ�临�Ӷȣ�O(Max(range,N))
//�ռ临�Ӷȣ�O(range)
void CountSort(int* arr, int size)
{
	int max = arr[0], min = arr[0];
	for (int i = 0; i < size; ++i)
	{
		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
	}
	int range = max - min + 1;
	int* countArr = (int*)malloc(sizeof(int)*range);
	memset(countArr, 0,sizeof(int)*range);
	//ͳ�ƴ���
	for (int i = 0; i < size; ++i)
	{
		countArr[arr[i] - min]++;
	}
	//���ݴ�����������
	int j = 0;
	for (int i = 0; i < range; ++i)
	{
		while (countArr[i]--)
		{
			arr[j++] = i + min;
		}
	}
}