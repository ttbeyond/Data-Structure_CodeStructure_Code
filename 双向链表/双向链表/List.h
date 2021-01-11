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
	struct ListNode* _next;//下一个节点
	struct ListNode* _prev;//上一个节点
}ListNode;

typedef struct List
{
	ListNode* _head;
}List;

ListNode* BuyListNode(LTDateType x);

void ListInit(List* plist);//初始化
void ListDestory(List* plist);//销毁链表
void ListPrint(List* plist);//打印链表

void ListPushBack(List* plist, LTDateType x);//尾插
void ListPopBack(List* plist);//尾删
void ListPushFront(List* plist, LTDateType x);//头插
void ListPopFrount(List* plist);//头删

ListNode* ListFind(List* plist,LTDateType x);
void ListInsert(ListNode* pos, LTDateType x);//某个位置插入
void ListErase(ListNode* pos);//某个位置删除

void ListRemove(List* plist, LTDateType x);//移除节点
int ListSize(List* plist);
void ListEmpty(List* plist);