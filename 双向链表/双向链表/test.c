#include"List.h"

int main()
{
	List pd;
	 ListInit(&pd);//��ʼ������
	ListPrint(&pd);

	ListPushFront(&pd, 5);//ͷ��5
	ListPushFront(&pd, 4);
	ListPushFront(&pd, 3);
	ListPushFront(&pd, 2);
	ListPushFront(&pd, 1);
	printf("������Ϊ��%d\n", ListSize(&pd));
	ListPrint(&pd);

	ListPushBack(&pd, 6);//β��6
	ListPrint(&pd);
	ListPopBack(&pd);//βɾ6
	ListPrint(&pd);
	ListPopFrount(&pd);//ͷɾ1
	ListPrint(&pd);

	printf("%d\n",ListFind(&pd, 3) );//��3��λ��
	ListInsert(ListFind(&pd, 3), 0);//��3ǰ�����0
	ListPrint(&pd);
	ListErase(ListFind(&pd, 0));//��λ��ɾ��
	ListPrint(&pd);
	ListRemove(&pd, 2);//ɾ��ֵΪ2�Ľڵ�
	ListPrint(&pd);
	ListRemove(&pd, 6);
	
	ListDestory(&pd);//��������



	system("pause");
	return 0;
}