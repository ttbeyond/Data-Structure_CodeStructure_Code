#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Print(int* arr, int size)
{
	if (!arr)
		printf("没有数据可供打印\n");
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
	int child = parent * 2 + 1;//左孩子
	while (child < n)
	{
		//找到大的那个孩子
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		//孩子大于父亲，则交换
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		//大的孩子小于父亲，则跳出
		else
		{
			break;
		}
	}
}
void HeapSort(int* arr, int size)
{
	//排升序，建大堆
	//O(N)
	for (int i = (size - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(arr, size, i);
	}

	//去堆顶数据，放至数组的最后
	int end = size - 1;
	while (end > 0)
	{
		Swap(&arr[end], &arr[0]);
		AdjustDown(arr, end, 0);
		--end;
	}
}

//冒泡排序
//时间复杂度：O(N*N)
void BubbleSort(int* arr,int size)
{
	for (int i = size-1; i >0; --i)//控制数组下标
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

//快速排序
//时间复杂度：O(N*logN)
int GetMidIndex(int* arr, int begin, int end)
{
	int mid = (begin + end) >> 1;//相当于除二

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

//注意：参数要传数组的下标(因为下边是按照下标写的)
//左右指针法
int PartSort1(int*arr, int begin, int end)
{
	int key = arr[end];
	int keyindex = end;
	while (begin < end)
	{
		//begin找大于等于key的数
		while (begin < end && arr[begin] <= key)
			++begin;
		//end找小于等于key的数
		while (begin < end && arr[end] >= key)
			--end;
		//交换
		Swap(&arr[begin], &arr[end]);
	 }
	Swap(&arr[begin], &arr[keyindex]);

	return begin;
}

//挖坑法//理解较左右指针法容易
int PartSort2(int*arr, int begin, int end)
{
	int key = arr[end];

	while (begin < end)
	{
		while (begin < end && arr[begin] <= key)//找大于key的数
			++begin;
		arr[end] = arr[begin];//找到大的，放至右边的坑位中，同时end形成新的坑位

		while (begin < end && arr[end] >= key)//找小于key的数
			--end;
		arr[begin] = arr[end];//找到小的，放至左边的坑位，同时begin形成新的坑位
	}
	arr[begin] = key;//把最后一个坑位填上
	return begin;
}

//前后指针法
int PartSort3(int*arr, int begin, int end)
{
	//三数取中法优化数组有序的情况
	//优化
	int midindex = GetMidIndex(arr, begin, end);
	Swap(&arr[midindex], &arr[end]);


	int key = arr[end];
	int cur = begin;
	int prev = begin - 1;
	while (cur < end)//走到key的位置就结束
	{
		if (arr[cur] < key && ++prev != cur)//找小于key的值，并且让prev向前走
			Swap(&arr[prev], &arr[cur]);
		++cur;
	}
	++prev;//最后prev停留的位置的值(arr[prev])是比key要小的,因此需要++一下
	Swap(&arr[prev], &arr[end]);

	return prev;
}
void QuickSort(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//将数组划分为三段
	int keyindex =PartSort1(arr, begin, end);
	//int keyindex = PartSort2(arr, begin, end);
	//int keyindex = PartSort3(arr, begin, end);

	//重新在走俩边
	QuickSort(arr, begin, keyindex - 1);//前面的一段
	QuickSort(arr, keyindex + 1, end);
}

//归并排序
void _MergeSort(int* arr, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	//划分
	int mid = (begin + end) >> 1;
	//[begin,mid] [mid+1,end]  无序的情况
	_MergeSort(arr, begin, mid, tmp);
	_MergeSort(arr, mid+1, end, tmp);

	//[begin,mid] [mid+1,end]  有序的情况


	//归并俩段有序区间
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

	//将归并到tmp的数据拷贝回原数组
	memcpy(arr + begin, tmp + begin, sizeof(int)*(end - begin + 1));
	//注意：加一是因为下标相减会比预期结果小一
}
void MergeSort(int* arr, int size)
{
	int* tmp = (int*)malloc(sizeof(int)*size);
	_MergeSort(arr, 0, size-1,tmp);
	free(tmp);
}


//直接插入排序
//时间复杂度O(N^2)
//逆序情况最坏(排升序，数组给降序)，复杂度为O(N^2)
//顺序情况下最好(排升序，数组给升序)，复杂度为O(N)
void InsertSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
       //单趟排序
	   //在[0,end]区间插入arr[size] 
	   //有序区间最后一个为要插入的数
	   //在[0，end]的有序区间内插入tmp，使其依旧有序
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

//希尔排序
//平均时间复杂度：O(N^1.3)
//顺序有序的情况时最坏，预排序全部白做，不如直接插入排序
void ShellSort(int* arr, int size)
{
	//gap>1时为预排序，让数组接近有序
	//gap == 1时，为直接插入排序，让数组有序
	int gap = size;
	while (gap > 1)
	{
		//间隔为gap的预排序

		gap = gap / 3 + 1;//+1是保证最后一次一定为1  //3为gap  //控制循环结束的条件
		//注意不能是除2   //原因：当gap==2时，2/2+1=2，此时gap减不下去了
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

//选择排序
//时间复杂度：O(N^2)
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
		//修正arr[begin]与arr[minindex]交换后，arr[begin]与arr[maxindex]相等的情况
		if (begin == maxindex)
			maxindex = minindex;
		Swap(&arr[end], &arr[maxindex]);

		++begin;
		--end;
	}
}

//记数排序
//时间复杂度：O(Max(range,N))
//空间复杂度：O(range)
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
	//统计次数
	for (int i = 0; i < size; ++i)
	{
		countArr[arr[i] - min]++;
	}
	//根据次数进行排序
	int j = 0;
	for (int i = 0; i < range; ++i)
	{
		while (countArr[i]--)
		{
			arr[j++] = i + min;
		}
	}
}