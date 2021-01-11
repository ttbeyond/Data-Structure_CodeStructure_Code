#include"List.h"

ListNode* BuyListNode(LTDateType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_next = NULL;
	node->_prev = NULL;
	node->_data = x;

	return node;
}
void ListInit(List* plist)//初始化
{
	assert(plist);
	ListNode* head = BuyListNode(-1);
	head->_next = head;
	head->_prev = head;

	plist->_head = head;
}
void ListDestory(List* plist)//销毁链表
{
	assert(plist);
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(plist->_head);//释放头节点
	plist->_head = NULL;//让头节点指向空
}


void ListPushBack(List* plist, LTDateType x)//尾插
{
	assert(plist);

	ListNode* new = BuyListNode(x);
	ListNode* cur = plist->_head;
	ListNode* tail = cur->_prev;

	tail->_next = new;
	new->_prev = tail;

	new->_next = cur;
	cur->_prev = new;
}


void ListPopBack(List* plist)//尾删
{
	assert(plist&&plist->_head->_next != plist->_head);//判空并且保证除了头节点外至少含有一个节点
	ListNode* head = plist->_head;
	ListNode* tail = head->_prev;
	ListNode* tailprev = tail->_prev;//尾删前倒数第二个节点

	free(tail);
	tailprev->_next = head;//让新尾节点的next(后一个)指向头节点
	head->_prev = tailprev;//让头节点的前一个（prev）指向新尾节点

}
void ListPushFront(List* plist, LTDateType x)//头插
{
	assert(plist);

	ListNode* head = plist->_head;
	ListNode* next = head->_next;//旧链表的第二个节点
	ListNode* newnode = BuyListNode(x);

	//完成头插并且连接循环
	head->_next = newnode;
	newnode->_prev = head;
	newnode->_next = next;
	next->_prev = newnode;
}
void ListPopFrount(List* plist)//头删
{
	assert(plist&&plist->_head->_next != plist->_head);//判空并且保证至少有一个节点

	ListNode* head = plist->_head;
	ListNode* next = head->_next;
	ListNode* nextnext = next->_next;//旧表的第三个节点(可循环计数：当只有俩个节点时 第三个节点就为第一个节点)

	free(next);
	head->_next = nextnext;
	nextnext->_prev = head;
}
ListNode* ListFind(List* plist, LTDateType x)//找值为x的节点
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
void ListInsert(ListNode* pos, LTDateType x)//pos位置前插入
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* newnode = BuyListNode(x);

	prev->_next = newnode;
	newnode->_prev = prev;

	newnode->_next = pos;
	pos->_prev = newnode;
}
void ListErase(ListNode* pos)//删除pos位置处节点
{
	assert(pos);

	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;

	prev->_next = next;
	next->_prev = prev;
	free(pos);
}


void ListRemove(List* plist, LTDateType x)//移除节点值为x的节点
{
	assert(plist);
	ListNode* node = ListFind(plist, x);
	if (node)
	{
		ListErase(node);
	}
	else
		printf("您所输入的数不存在于链表当中\n");
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
void ListEmpty(List* plist)//判断列表是否为空
{
	assert(plist);
	//return Listsize(plist) == 0 ? 0 : -1;//空返回0，非空返回-1；
	//return plist->_head->_next == plist->_head ? 0 : -1;
	if (plist->_head->_next == plist->_head)
		printf("链表为空\n");
	else
		printf("链表不为空\n");//打印这种方式可直观观察链表是否为空  若想以次函数为判断条件 则需采用上述俩种方法之一即可
}


void ListPrint(List* plist)//打印链表
{
	assert(plist);

	ListNode* ret = plist->_head->_next ;
	int size = ListSize(plist);

	while (size--)
	{
		printf("%d ", ret->_data );
		ret = ret->_next;
	}
	printf("\n");

}