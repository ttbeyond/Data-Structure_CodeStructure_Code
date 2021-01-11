#include"List.h"

Node* BuyListNode(LTDateType x)
{
	Node* newnode = (Node*)malloc(sizeof(Node));

	newnode->_next = NULL;
	newnode->_prev = NULL;
	newnode->_data = x;
	return newnode;
}

void ListInit(List* plist)//初始化
{
	assert(plist);
	Node* head = BuyListNode(-1);//创建一个自己循环的的头节点
	head->_next = head;
	head->_prev = head;

	plist->_head = head;
}
void ListDestory(List* plist)//销毁链表
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
void ListPrint(List* plist)//打印链表
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

void ListPushBack(List* plist, LTDateType x)//尾插
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
void ListPopBack(List* plist)//尾删
{
	assert(plist&&plist->_head !=plist->_head ->_next );

	//Node* head = plist->_head;
	//Node* tail_prev = head->_prev->_prev;

	//head->_prev = tail_prev;
	//tail_prev->_next = head;//不足之处：没有释放尾节点的空间

	Node* head = plist->_head;
	Node* tail = head->_prev;
	Node* tail_prev = head->_prev->_prev;

	free(tail);
	tail = NULL;
	head->_prev = tail_prev;
	tail_prev->_next = head;
}
void ListPushFront(List* plist, LTDateType x)//头插
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
void ListPopFrount(List* plist)//头删
{
	assert(plist&&plist->_head != plist->_head->_next);

	Node* head = plist->_head;
	Node* next = head->_next;
	Node* second = head->_next->_next;//除头节点外第二个节点

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
void ListInsert(Node* pos, LTDateType x)//某个位置插入
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
void ListErase(Node* pos)//某个位置删除
{
	assert(pos);

	Node* prev = pos->_prev;
	Node* next = pos->_next;

	prev->_next = next;
	next->_prev = prev;
	free(pos);
}

void ListRemove(List* plist, LTDateType x)//移除节点
{
	assert(plist);

	int size = ListSize(plist);
	Node* ret = ListFind(plist, x);
	if (ret == NULL)
		printf("所输入的节点未在此链表中\n");
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
		printf("链表为空\n");
	else
		printf("链表不为空\n");
}