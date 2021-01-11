#pragma once

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>


typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top; // ջ��
	int _capacity; // ����
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);

void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);

STDataType StackTop(Stack* ps);//ȡջ��Ԫ�أ�����ɾ��
int StackEmpty(Stack* ps);//�ǿշ���1���շ���0
int StackSize(Stack* ps);