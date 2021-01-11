#define _CRT_SECURE_NO_WARNINGS 1
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
}ListNode;

typedef struct List
{
	ListNode* _head;
}List;

ListNode* BuyListNode(LTDateType x);

void ListInit(List* plist);//��ʼ��
void ListDestory(List* plist);//��������
void ListPrint(List* plist);//��ӡ����

void ListPushBack(List* plist, LTDateType x);//β��
void ListPopBack(List* plist);//βɾ
void ListPushFront(List* plist, LTDateType x);//ͷ��
void ListPopFrount(List* plist);//ͷɾ

ListNode* ListFind(List* plist,LTDateType x);
void ListInsert(ListNode* pos, LTDateType x);//ĳ��λ�ò���
void ListErase(ListNode* pos);//ĳ��λ��ɾ��

void ListRemove(List* plist, LTDateType x);//�Ƴ��ڵ�
int ListSize(List* plist);
void ListEmpty(List* plist);