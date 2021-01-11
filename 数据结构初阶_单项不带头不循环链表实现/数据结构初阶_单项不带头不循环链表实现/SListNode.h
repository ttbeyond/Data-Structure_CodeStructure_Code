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
// ��pos�ĺ�����в��� 
void SListInsertAfter(Node* pos, SLTDataType x);
// ɾ��pos�ĺ�ߵĵ�һ���ڵ� 
void SListEraseAfter(Node* pos);
//�Ƴ�ֵΪx�Ľڵ�
void SListRemove(SList* plist, SLTDataType x);


int Listsize(SList* plist);//������
void ListEmpty(SList* plist);//�����п�
void SListPrint(SList* plist);
