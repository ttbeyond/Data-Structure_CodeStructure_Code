#include"SListNode.h"

void SListInit(SList* plist)
{
	assert(plist);
	plist->_head=NULL;
}
void SListDestory(SList* plist)
{
	assert(plist);
	
	Node* p1 = plist->_head;
	while (p1)
	{
		Node* ret = p1;
		free(ret);
		p1 = p1->_next;
	}
	free(plist->_head);
	plist->_head = NULL;
}

Node* BuySListNode(SLTDataType x)//����һ��ֵΪx���½ڵ�
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->_data = x;
	newnode->_next = NULL;

	return newnode;
}
void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);

	Node* new = BuySListNode(x);
	Node* ret = plist->_head;//����ԭ����ͷ�ĵ�ַ
	plist->_head = new;//��ͷ�ڵ��Ϊ�µ�ͷ�ڵ�
	new->_next = ret;//���µ�ͷ�ڵ�ָ��ԭ����ͷ�ڵ�
}
void SListPopFront(SList* plist)
{
	assert(plist);

	//plist->_head = plist->_head->_next;//����֮��û���ͷ��ڴ�
	Node* ret = plist->_head;
	plist->_head = ret->_next;
	free(ret);
}
void SListPushBank(SList* plist, SLTDataType x)
{
	assert(plist);

	Node* ret = plist->_head;
	while (ret->_next)//�ҵ����һ���ڵ��λ��
	{
		ret = ret->_next;
	}
	Node* new = BuySListNode(x);
	ret->_next = new;
}
void SListPopBank(SList* plist)
{
	assert(plist);
    
	Node* ret = plist->_head;
	if (ret->_next == NULL)//����ֻ��һ���ڵ�����
		SListPopFront(ret);
	//�ҵ������ڶ����ڵ�
	while (ret->_next->_next  != NULL)
	{
		ret = ret->_next;
	}
	free(ret->_next);
	ret->_next = NULL;
}


Node* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);

	Node* ret = plist->_head;
	while (ret->_next != NULL)
	{
		if (ret->_data == x)
          return ret;
		ret = ret->_next;
	}
	printf("�������޴�Ԫ��\n");
}
// ��pos�ĺ�����в��� 
void SListInsertAfter(Node* pos, SLTDataType x)
{
	assert(pos);

	Node* new = BuySListNode(x);
	new->_next = pos->_next;//���½ڵ�ָ��pos����һ��λ��
	pos->_next = new;//��posָ���½ڵ�
}
// ɾ��pos�ĺ�ߵĵ�һ���ڵ� 
void SListEraseAfter(Node* pos)
{
	assert(pos);
	Node* ret1 = pos->_next;
	Node* ret2 = pos->_next->_next;
	if (pos->_next == NULL)
		return ;

	pos->_next = ret2;
	free(ret1);
	ret1 = NULL;
	//Node* ret = pos->_next->_next ;
	//pos->_next = ret;//û���ͷſռ�
}
//�Ƴ�ֵΪx�Ľڵ�
void SListRemove(SList* plist, SLTDataType x)
{
	assert(plist);

	Node* flag = plist->_head ;

	if (flag->_data == x)
		SListPopFront(flag);
	while (flag->_next != NULL&&flag->_next ->_data !=x)//�������յ�������ҵ�x�ڵ��ǰһ��λ��
	{
		flag = flag->_next;
	}
	if (flag->_next == NULL)
		printf("�������޴�Ԫ��\n");
	else
		SListEraseAfter(flag);
}

int Listsize(SList* plist)//������
{
	if (plist == NULL)
		return 0;
	
    int count = 0;
	Node* ret = plist->_head;
	
	while (ret != NULL)
	{
		count += 1;
		ret = ret->_next;
	}
	return count;
}
void ListEmpty(SList* plist)//�����п�
{
	if (plist->_head  == NULL)
		printf("����Ϊ��\n");
	else
		printf("����Ϊ��\n");
}
void SListPrint(SList* plist)
{
	assert(plist);
	Node* ret = plist->_head;
	for (int i = 0; i < Listsize(plist); i++)
	{
		printf("%d ", ret->_data);
		ret = ret->_next;
	}
	printf("\n");
}