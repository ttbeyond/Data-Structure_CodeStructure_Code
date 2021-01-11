#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include<string.h>

// 顺序表的动态存储 
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* _array; // 指向动态开辟的数组 
	size_t _size; // 有效数据个数 
	size_t _capacity; // 容量空间的大小 
}SeqList;

// 基本增删查改接口 
void SeqListInit(SeqList* ps);
void SeqListDestory(SeqList* ps);

void CheckCapacity(SeqList* ps);
void SeqListPushBack(SeqList* ps, SLDataType x);
void SeqListPopBack(SeqList* ps);
void SeqListPushFront(SeqList* ps, SLDataType x);
void SeqListPopFront(SeqList* ps);

int SeqListFind(SeqList* ps, SLDataType x);
int SeqListSize(SeqList* ps); //有效个数
SLDataType SeqListAt(SeqList* ps, size_t x);//查询post位置处的数据


void SeqListInsert(SeqList* ps, size_t pos, SLDataType x);//pos位置插入值为x的节点
void SeqListErase(SeqList* ps, size_t pos);

void SeqListRemove(SeqList* ps, SLDataType x);  //移除值为x的节点
void SeqListModify(SeqList* ps, size_t pos, SLDataType x);


// 扩展面试题实现 
void SeqListBubbleSort(SeqList* ps);//对顺序表进行冒泡排序
int SeqListBinaryFind(SeqList* ps, SLDataType x);
// 本题要求：时间复杂度：O(N) 空间复杂度 O(1) 
void SeqListRemoveAll(SeqList* ps, SLDataType x);
