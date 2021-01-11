#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}Node;
typedef struct SList
{
	Node* _head;
}SList;
void SListInit(SList* plist);
void SListDestory(SList* plist);

Node* BuySListNode(SLTDataType x);
void SListPushFront(SList* plist, SLTDataType x);
void SListPopFront(SList* plist);
void SListPushBank(SList* plist, SLTDataType x);
void SListPopBank(SList* plist);



Node* SListFind(SList* plist, SLTDataType x);
// 在pos的后面进行插入 
void SListInsertAfter(Node* pos, SLTDataType x);
// 删除pos的后边的第一个节点 
void SListEraseAfter(Node* pos);
//移除值为x的节点
void SListRemove(SList* plist, SLTDataType x);


int Listsize(SList* plist);//链表长度
void ListEmpty(SList* plist);//链表判空
void SListPrint(SList* plist);
