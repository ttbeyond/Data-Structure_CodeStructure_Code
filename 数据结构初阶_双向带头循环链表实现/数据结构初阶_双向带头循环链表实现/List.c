#include"List.h"

Node* BuyListNode(LTDateType x)
{
	Node* newnode = (Node*)malloc(sizeof(Node));

	newnode->_next = NULL;
	newnode->_prev = NULL;
	newnode->_data = x;
	return newnode;
}

void ListInit(List* plist)//��ʼ��
{
	assert(plist);
	Node* head = BuyListNode(-1);//����һ���Լ�ѭ���ĵ�ͷ�ڵ�
	head->_next = head;
	head->_prev = head;

	plist->_head = head;
}
void ListDestory(List* plist)//��������
{
	assert(plist);

	Node* cur = plist->_head->_next ;
	while (cur != plist->_head)
	{
		Node* ret = cur;
		cur = cur->_next;
		free(ret);
	}
	free(plist->_head);
	plist->_head = NULL;
}
void ListPrint(List* plist)//��ӡ����
{
	assert(plist);

	int size = ListSize(plist);
	Node* ret = plist->_head->_next ;
	while (size--)
	{
		printf("%d ", ret->_data);
		ret = ret->_next;
	}
	printf("\n");
}

void ListPushBack(List* plist, LTDateType x)//β��
{
	assert(plist);

	Node* newnode = BuyListNode(x);
	Node* cur = plist->_head;
	Node* tail = cur->_prev;

	tail->_next = newnode;
	newnode->_prev = tail;

	cur->_prev = newnode;
	newnode->_next = cur;

}
void ListPopBack(List* plist)//βɾ
{
	assert(plist&&plist->_head !=plist->_head ->_next );

	//Node* head = plist->_head;
	//Node* tail_prev = head->_prev->_prev;

	//head->_prev = tail_prev;
	//tail_prev->_next = head;//����֮����û���ͷ�β�ڵ�Ŀռ�

	Node* head = plist->_head;
	Node* tail = head->_prev;
	Node* tail_prev = head->_prev->_prev;

	free(tail);
	tail = NULL;
	head->_prev = tail_prev;
	tail_prev->_next = head;
}
void ListPushFront(List* plist, LTDateType x)//ͷ��
{
	assert(plist);

	Node* new = BuyListNode(x);
	Node* head = plist->_head;
	Node* old_head_next = head->_next;

	head->_next = new;
	new->_prev = head;

	new->_next = old_head_next;
	old_head_next->_prev = new;
}
void ListPopFrount(List* plist)//ͷɾ
{
	assert(plist&&plist->_head != plist->_head->_next);

	Node* head = plist->_head;
	Node* next = head->_next;
	Node* second = head->_next->_next;//��ͷ�ڵ���ڶ����ڵ�

	free(next);
	head->_next = second;
	second->_prev = head;
}

Node* ListFind(List* plist, LTDateType x)
{
	assert(plist);

	Node* cur = plist->_head->_next ;

	while (cur !=plist->_head )
	{
		if (cur->_data != x)
			cur = cur->_next;
		else
			return cur;
	}
	return NULL;
}
void ListInsert(Node* pos, LTDateType x)//ĳ��λ�ò���
{
	assert(pos);

	Node* new = BuyListNode(x);
	Node* post = pos;
	Node* flag = pos->_next;

	post->_next = new;
	new->_prev = post;

	new->_next = flag;
	flag->_prev = new;
}
void ListErase(Node* pos)//ĳ��λ��ɾ��
{
	assert(pos);

	Node* prev = pos->_prev;
	Node* next = pos->_next;

	prev->_next = next;
	next->_prev = prev;
	free(pos);
}

void ListRemove(List* plist, LTDateType x)//�Ƴ��ڵ�
{
	assert(plist);

	int size = ListSize(plist);
	Node* ret = ListFind(plist, x);
	if (ret == NULL)
		printf("������Ľڵ�δ�ڴ�������\n");
	else
			ListErase(ret);
	
}
int ListSize(List* plist)
{
	assert(plist);

	int count = 0;
	Node* flag = plist->_head->_next ;
	while (flag != plist->_head )
	{
		count += 1;
		flag = flag->_next;
	}
	return count;
}
void ListEmpty(List* plist)
{
	if (plist->_head == plist->_head ->_next )
		printf("����Ϊ��\n");
	else
		printf("����Ϊ��\n");
}