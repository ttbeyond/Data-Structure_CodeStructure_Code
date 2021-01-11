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

Node* BuySListNode(SLTDataType x)//创建一个值为x的新节点
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
	Node* ret = plist->_head;//保存原链表头的地址
	plist->_head = new;//将头节点改为新的头节点
	new->_next = ret;//让新的头节点指向原来的头节点
}
void SListPopFront(SList* plist)
{
	assert(plist);

	//plist->_head = plist->_head->_next;//不足之处没有释放内存
	Node* ret = plist->_head;
	plist->_head = ret->_next;
	free(ret);
}
void SListPushBank(SList* plist, SLTDataType x)
{
	assert(plist);

	Node* ret = plist->_head;
	while (ret->_next)//找到最后一个节点的位置
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
	if (ret->_next == NULL)//处理只有一个节点的情况
		SListPopFront(ret);
	//找到倒数第二个节点
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
	printf("链表中无此元素\n");
}
// 在pos的后面进行插入 
void SListInsertAfter(Node* pos, SLTDataType x)
{
	assert(pos);

	Node* new = BuySListNode(x);
	new->_next = pos->_next;//让新节点指向pos的下一个位置
	pos->_next = new;//让pos指向新节点
}
// 删除pos的后边的第一个节点 
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
	//pos->_next = ret;//没有释放空间
}
//移除值为x的节点
void SListRemove(SList* plist, SLTDataType x)
{
	assert(plist);

	Node* flag = plist->_head ;

	if (flag->_data == x)
		SListPopFront(flag);
	while (flag->_next != NULL&&flag->_next ->_data !=x)//在链表不空的情况下找到x节点的前一个位置
	{
		flag = flag->_next;
	}
	if (flag->_next == NULL)
		printf("链表中无此元素\n");
	else
		SListEraseAfter(flag);
}

int Listsize(SList* plist)//链表长度
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
void ListEmpty(SList* plist)//链表判空
{
	if (plist->_head  == NULL)
		printf("链表为空\n");
	else
		printf("链表不为空\n");
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