#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


typedef char BtDatatyepf;

typedef struct BtNode
{
	BtDatatyepf data;//储存结点数据
	struct BtNode *Left;
	struct BtNode *Right;

}Node;

Node* BTcreat(BtDatatyepf *arr, int size,int* count);//创建出二叉树
Node* BuyNode(BtDatatyepf val);//创建一个节点
void Btdestroy(Node * Bt);//销毁
void PreBtree(Node* Bt);//前序遍历
void MidBtree(Node* Bt);//中序遍历
void AfterBtree(Node* Bt);//后序遍历
int HightBtree(Node *Bt);//求树的高度
int SizeBtree(Node *Bt);//求总节点的个数
int BalaceBt(Node * Bt);//检测是否为平衡树
int Leafsize(Node *Bt);//获取叶子节点的个数
int KsizeBt(Node *Bt, int k);//求第K层结点个数
Node * FindvalBt(Node *Bt, BtDatatyepf val);//找值为val的结点，返回它的地址
Node* ParentfindBt(Node * Bt, BtDatatyepf val);//找一个结点的双亲
