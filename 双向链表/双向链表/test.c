#include"List.h"

int main()
{
	List pd;
	 ListInit(&pd);//初始化链表
	ListPrint(&pd);

	ListPushFront(&pd, 5);//头插5
	ListPushFront(&pd, 4);
	ListPushFront(&pd, 3);
	ListPushFront(&pd, 2);
	ListPushFront(&pd, 1);
	printf("链表长度为：%d\n", ListSize(&pd));
	ListPrint(&pd);

	ListPushBack(&pd, 6);//尾插6
	ListPrint(&pd);
	ListPopBack(&pd);//尾删6
	ListPrint(&pd);
	ListPopFrount(&pd);//头删1
	ListPrint(&pd);

	printf("%d\n",ListFind(&pd, 3) );//找3的位置
	ListInsert(ListFind(&pd, 3), 0);//在3前面插入0
	ListPrint(&pd);
	ListErase(ListFind(&pd, 0));//按位置删除
	ListPrint(&pd);
	ListRemove(&pd, 2);//删除值为2的节点
	ListPrint(&pd);
	ListRemove(&pd, 6);
	
	ListDestory(&pd);//销毁链表



	system("pause");
	return 0;
}