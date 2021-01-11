#include"Heap.h"


//建大堆，向下调整算法
//前提条件：根节点的左右子树都为大堆
void AdjustDown2(int* a, int n, int root)//n为数组大小//root为根节点
{
	int parent = root;
	int child = parent * 2 + 1;

	while (child<n)
	{
		//找出大的那个孩子
		if (child + 1<n && a[child + 1] > a[child])//判断左右子树哪个小
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

	printf("堆顶元素为：%d\n", HeapTop(&hp));

	HeapPop(&hp);
	HeadPrint(&hp);

	printf("堆中元素有：%d\n", HeapSize(&hp));
	//升序打印Heap
	for (int i = 0; i < 11; ++i)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	printf("\n");

	//降序打印arr
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