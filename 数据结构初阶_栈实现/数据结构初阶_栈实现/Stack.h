#pragma once

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>


typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top; // 栈顶
	int _capacity; // 容量
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);

void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);

STDataType StackTop(Stack* ps);//取栈顶元素，但不删除
int StackEmpty(Stack* ps);//非空返回1，空返回0
int StackSize(Stack* ps);