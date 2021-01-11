#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

typedef int LTDateType;

typedef struct ListNode
{
	LTDateType _data;
	struct ListNode* _next;//��һ���ڵ�
	struct ListNode* _prev;//��һ���ڵ�
}Node;

typedef struct List
{
	Node* _head;
}List;

Node* BuyListNode(LTDateType x);

void ListInit(List* plist);//��ʼ��
void ListDestory(List* plist);//��������
void ListPrint(List* plist);//��ӡ����

void ListPushBack(List* plist, LTDateType x);//β��
void ListPopBack(List* plist);//βɾ
void ListPushFront(List* plist, LTDateType x);//ͷ��
void ListPopFrount(List* plist);//ͷɾ

Node* ListFind(List* plist, LTDateType x);
void ListInsert(Node* pos, LTDateType x);//ĳ��λ�ò���
void ListErase(Node* pos);//ĳ��λ��ɾ��

void ListRemove(List* plist, LTDateType x);//�Ƴ��ڵ�
int ListSize(List* plist);
void ListEmpty(List* plist);