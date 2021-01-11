#include"Heap.h"


void Swap(int*p1, int*p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//小堆，向下调整算法
//前提条件：根节点的左右子树都为小堆
void AdjustDown(int* a, int n, int root)//n为数组大小//root为根节点下标
{
	int parent = root;
	int child = parent * 2 + 1;

	while (child<n)
	{
		//找出小的那个孩子
		if (child + 1<n && a[child + 1] < a[child])//判断左右子树哪个小
		{
			++child;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//向上调整算法
void AdjustUp(int* a, int child)
{
	int parent = (child - 1) / 2;
	//while (parent>=0)//写法逻辑不对,在child=0时应该跳出循环，而此条件下循环还会运行一次，parent=(0-1)/2=0；
	//判断终止条件没起作用，循环借助break跳出。巧合的正确。
	while (child>0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
			
		}
		else
			break;
	}
}
Heap* HeapGreate(Heap* hp, HPDataType* a, int n)
{
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);//给存储堆数据的数组开辟空间

	memcpy(hp->_a, a, sizeof(HPDataType)*n);//将数据存入堆中
	hp->_size = n;
	hp->_capacity = n;
	//建堆
	//倒着走，从下面的树向上调，找倒数第一个非叶子节点所在的树，开始调，一直调到根，堆便可建成
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
	return hp;
}
void HeapDestory(Heap* hp)
{
	hp->_size = hp->_capacity = 0;
	free(hp->_a);
	hp->_a = NULL;
	free(hp);
}

//堆内插入数据
void HeapPush(Heap* hp, HPDataType x)
{
	//检查空间是否足够//不够增容
	if (hp->_size == hp->_capacity)
	{
		size_t newcapacity = hp->_capacity*2;
		hp->_a = (HPDataType*)realloc(hp->_a,newcapacity*sizeof(HPDataType));
		hp->_capacity = newcapacity;
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	AdjustUp(hp->_a, hp->_size - 1);
}

//删除堆顶元素
void HeapPop(Heap* hp)
{
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0);
}

//堆顶元素获取
HPDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}

//大小
int HeapSize(Heap* hp)
{
	return hp->_size;
}

//判空
int HeapEmpty(Heap* hp)
{
	return hp->_size == 0 ? 1 : 0;
}

//打印
void HeadPrint(Heap* hp)
{
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}

// 堆排序
void HeapSort(int* a, int n)//降序，建小堆
{
	//建堆
	//n为数组大小，最后一个下标为n-1，而其父节点为(n-1-1)/2
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	//排序(降序)
 int end = n - 1;
	while (end>0)
	{
		Swap(&a[end], &a[0]);
		
		AdjustDown(a,end,0);
		--end;	
	}

}
