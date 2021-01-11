#include"Heap.h"


//����ѣ����µ����㷨
//ǰ�����������ڵ������������Ϊ���
void AdjustDown2(int* a, int n, int root)//nΪ�����С//rootΪ���ڵ�
{
	int parent = root;
	int child = parent * 2 + 1;

	while (child<n)
	{
		//�ҳ�����Ǹ�����
		if (child + 1<n && a[child + 1] > a[child])//�ж����������ĸ�С
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			int tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void test()
{
	int arr[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	Heap hp;
	HeapGreate(&hp, arr, 10);
	HeadPrint(&hp);

	HeapPush(&hp, 14);
	HeadPrint(&hp);

	HeapPush(&hp, 67);
	HeadPrint(&hp);

	printf("�Ѷ�Ԫ��Ϊ��%d\n", HeapTop(&hp));

	HeapPop(&hp);
	HeadPrint(&hp);

	printf("����Ԫ���У�%d\n", HeapSize(&hp));
	//�����ӡHeap
	for (int i = 0; i < 11; ++i)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	printf("\n");

	//�����ӡarr
	HeapSort(arr, 10);
	for (int i = 0; i < sizeof(arr)/sizeof(int); ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

}
int main()
{
	test();

	system("pause");
	return 0;
}