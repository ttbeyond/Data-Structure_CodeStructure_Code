#include"seqlist.h"

void test()
{
	SeqList ps;
	SeqListInit(&ps);
	SeqListPushBack(&ps, 1);
	SeqListPushBack(&ps, 2);
	SeqListPushBack(&ps, 3);
	SeqListPushBack(&ps, 4);
	SeqListPushFront(&ps, 0);
	SeqListPopBack(&ps);
	SeqListPopFront(&ps);
	
	SeqListInsert(&ps, 0, 20);
	SeqListErase(&ps, 2);

	SeqListBubbleSort(&ps);//排序
	for (int i = 0; i < SeqListSize(&ps); ++i)
	{
		printf("%d ", SeqListAt(&ps, i));
	}
	printf("\n");


	SeqListPushBack(&ps, 2);
	SeqListPushBack(&ps, 2);
	SeqListPushBack(&ps, 2);
	for (int i = 0; i < SeqListSize(&ps); ++i)
	{
		printf("%d ", SeqListAt(&ps, i));
	}
	printf("\n");

	SeqListRemove(&ps, 2);//删除第一个二
	for (int i = 0; i < SeqListSize(&ps); ++i)
	{
		printf("%d ", SeqListAt(&ps, i));
	}
	printf("\n");

	SeqListRemoveAll(&ps, 2);//删除所有的2
	for (int i = 0; i < SeqListSize(&ps); ++i)
	{
		printf("%d ", SeqListAt(&ps, i));
	}
	printf("\n");

	printf("%d \n", SeqListBinaryFind(&ps, 20));//二分查找 找到返回位置 找不到打印：找不到
	//SeqListDestory(&ps);

}
int main()
{
	test();
	system("pause");
	return 0;
}