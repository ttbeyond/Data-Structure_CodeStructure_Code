#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


typedef char BtDatatyepf;

typedef struct BtNode
{
	BtDatatyepf data;//����������
	struct BtNode *Left;
	struct BtNode *Right;

}Node;

Node* BTcreat(BtDatatyepf *arr, int size,int* count);//������������
Node* BuyNode(BtDatatyepf val);//����һ���ڵ�
void Btdestroy(Node * Bt);//����
void PreBtree(Node* Bt);//ǰ�����
void MidBtree(Node* Bt);//�������
void AfterBtree(Node* Bt);//�������
int HightBtree(Node *Bt);//�����ĸ߶�
int SizeBtree(Node *Bt);//���ܽڵ�ĸ���
int BalaceBt(Node * Bt);//����Ƿ�Ϊƽ����
int Leafsize(Node *Bt);//��ȡҶ�ӽڵ�ĸ���
int KsizeBt(Node *Bt, int k);//���K�������
Node * FindvalBt(Node *Bt, BtDatatyepf val);//��ֵΪval�Ľ�㣬�������ĵ�ַ
Node* ParentfindBt(Node * Bt, BtDatatyepf val);//��һ������˫��
