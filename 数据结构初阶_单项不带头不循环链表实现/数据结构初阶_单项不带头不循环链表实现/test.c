#include"SListNode.h"

void test()
{
	SList p1;
	SListInit(&p1);
	SListPushFront(&p1, 4);
	SListPushFront(&p1, 3);
	SListPushFront(&p1, 2);
	SListPushFront(&p1, 1);
	SListPushFront(&p1, 0);
	SListPrint(&p1);

	
	Node* ret = SListFind(&p1, 0);
	SListInsertAfter(ret, 5);
	SListPrint(&p1);
	Node* ret1 = SListFind(&p1, 0);
	SListEraseAfter(ret1);
	SListPrint(&p1);

	SListRemove(&p1, 4);
	SListPrint(&p1);



	SListPushBank(&p1, 4);
	SListPrint(&p1);
	SListPopBank(&p1);
	SListPrint(&p1);

	int size = Listsize(&p1);
	printf("%d\n", size);
	ListEmpty(&p1);

	//SListDestory(&p1);
	//ListEmpty(&p1);

}

int main()
{
	test();
	system("pause");
	return 0;
}