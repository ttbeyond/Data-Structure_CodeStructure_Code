#include"Heap.h"


void Swap(int*p1, int*p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//С�ѣ����µ����㷨
//ǰ�����������ڵ������������ΪС��
void AdjustDown(int* a, int n, int root)//nΪ�����С//rootΪ���ڵ��±�
{
	int parent = root;
	int child = parent * 2 + 1;

	while (child<n)
	{
		//�ҳ�С���Ǹ�����
		if (child + 1<n && a[child + 1] < a[child])//�ж����������ĸ�С
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

//���ϵ����㷨
void AdjustUp(int* a, int child)
{
	int parent = (child - 1) / 2;
	//while (parent>=0)//д���߼�����,��child=0ʱӦ������ѭ��������������ѭ����������һ�Σ�parent=(0-1)/2=0��
	//�ж���ֹ����û�����ã�ѭ������break�������ɺϵ���ȷ��
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
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);//���洢�����ݵ����鿪�ٿռ�

	memcpy(hp->_a, a, sizeof(HPDataType)*n);//�����ݴ������
	hp->_size = n;
	hp->_capacity = n;
	//����
	//�����ߣ�������������ϵ����ҵ�����һ����Ҷ�ӽڵ����ڵ�������ʼ����һֱ���������ѱ�ɽ���
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

//���ڲ�������
void HeapPush(Heap* hp, HPDataType x)
{
	//���ռ��Ƿ��㹻//��������
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

//ɾ���Ѷ�Ԫ��
void HeapPop(Heap* hp)
{
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0);
}

//�Ѷ�Ԫ�ػ�ȡ
HPDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}

//��С
int HeapSize(Heap* hp)
{
	return hp->_size;
}

//�п�
int HeapEmpty(Heap* hp)
{
	return hp->_size == 0 ? 1 : 0;
}

//��ӡ
void HeadPrint(Heap* hp)
{
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}

// ������
void HeapSort(int* a, int n)//���򣬽�С��
{
	//����
	//nΪ�����С�����һ���±�Ϊn-1�����丸�ڵ�Ϊ(n-1-1)/2
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	//����(����)
 int end = n - 1;
	while (end>0)
	{
		Swap(&a[end], &a[0]);
		
		AdjustDown(a,end,0);
		--end;	
	}

}
