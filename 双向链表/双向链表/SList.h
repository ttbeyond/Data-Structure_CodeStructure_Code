#include"List.h"

ListNode* BuyListNode(LTDateType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_next = NULL;
	node->_prev = NULL;
	node->_data = x;

	return node;
}
void ListInit(List* plist)//��ʼ��
{
	assert(plist);
	ListNode* head = BuyListNode(-1);
	head->_next = head;
	head->_prev = head;

	plist->_head = head;
}
void ListDestory(List* plist)//��������
{
	assert(plist);
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(plist->_head);//�ͷ�ͷ�ڵ�
	plist->_head = NULL;//��ͷ�ڵ�ָ���
}
void ListPrint(List* plist);//��ӡ����

void ListPushBack(List* plist, LTDateType x);//β��
void ListPopBack(List* plist)//βɾ
{
	assert(plist&&plist->_head->_next != plist->_head);//�пղ��ұ�֤����ͷ�ڵ������ٺ���һ���ڵ�
	ListNode* head = plist->_head;
	ListNode* tail = head->_prev;
	ListNode* tailprev = tail->_prev;

	free(tail);
	tailprev->_next = head;//����β�ڵ��next(��һ��)ָ��ͷ�ڵ�
	head->_prev = tailprev;//��ͷ�ڵ��ǰһ����prev��ָ����β�ڵ�

}
void ListPushFront(List* plist, LTDateType x)//ͷ��
{
	assert(plist);

	ListNode* head = plist->_head;
	ListNode* next = head->_next;//������ĵڶ����ڵ�
	ListNode* newnode = BuyListNode(x);

	//���ͷ�岢������ѭ��
	head->_next = newnode;
	newnode->_prev = head;
	newnode->_next = next;
	next->_prev = newnode;
}
void ListPopFrount(List* plist)//ͷɾ
{
	assert(plist&&plist->_head->_next != plist->_head);//�пղ��ұ�֤������һ���ڵ�

	ListNode* head = plist->_head;
	ListNode* next = head->_next;
	ListNode* nextnext = next->_next;//�ɱ�ĵ������ڵ�(��ѭ������ ֻ�������ڵ�ʱ �������ڵ��Ϊ��һ���ڵ�)

	free(next);
	head->_next = nextnext;
	nextnext->_prev = head;
}
ListNode* ListFind(List* plist, LTDateType x)//��ֵΪx�Ľڵ�
{
	assert(plist);
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}
void ListInsert(ListNode* pos, LTDateType x)//ĳ��λ�ò���
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* newnode = BuyListNode(x);

	prev->_next = newnode;
	newnode->_prev = prev;

	newnode->_next = pos;
	pos->_prev = newnode;
}
void ListErase(ListNode* pos)//ĳ��λ��ɾ��
{
	assert(pos);

	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;

	prev->_next = next;
	next->_prev = prev;
	free(pos);
}


void ListRemove(List* plist, LTDateType x)//�Ƴ��ڵ�
{
	assert(plist);
	ListNode* node = ListFind(plist, x);
	if (node)
	{
		ListErase(node);
	}
}
int ListSize(List* plist)
{
	assert(plist);
	int size = 0;

	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		++size;
		cur = cur->_next;
	}
	return size;
}
int ListEmpty(List* plist)
{
	assert(plist);
	//return Listsize(plist) == 0 ? 0 : -1;//�շ���0���ǿշ���-1��
	return plist->_head->_next == plist->_head ? 0 : -1;
}