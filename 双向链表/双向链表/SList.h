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
void ListPrint(List* plist);//打印链表

void ListPushBack(List* plist, LTDateType x);//尾插
void ListPopBack(List* plist)//尾删
{
	assert(plist&&plist->_head->_next != plist->_head);//判空并且保证除了头节点外至少含有一个节点
	ListNode* head = plist->_head;
	ListNode* tail = head->_prev;
	ListNode* tailprev = tail->_prev;

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
	ListNode* nextnext = next->_next;//旧表的第三个节点(可循环计数 只有俩个节点时 第三个节点就为第一个节点)

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
void ListInsert(ListNode* pos, LTDateType x)//某个位置插入
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* newnode = BuyListNode(x);

	prev->_next = newnode;
	newnode->_prev = prev;

	newnode->_next = pos;
	pos->_prev = newnode;
}
void ListErase(ListNode* pos)//某个位置删除
{
	assert(pos);

	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;

	prev->_next = next;
	next->_prev = prev;
	free(pos);
}


void ListRemove(List* plist, LTDateType x)//移除节点
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
	//return Listsize(plist) == 0 ? 0 : -1;//空返回0，非空返回-1；
	return plist->_head->_next == plist->_head ? 0 : -1;
}