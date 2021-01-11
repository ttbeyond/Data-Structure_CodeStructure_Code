#include"BinaryTree.h"

//创建出二叉树
Node* BTcreat(BtDatatyepf *arr, int size,int* count)
{
	Node* root = NULL;
	while (*count<size&&arr[*count] != '*'&&arr[*count] != '\0')
	{
		root = BuyNode(arr[*count]);
		++(*count);
		root->Left = BTcreat(arr, size, count);
		++(*count);
		root->Right = BTcreat(arr, size, count);
	}
	return root;
}

//创建一个节点
Node* BuyNode(BtDatatyepf val)
{
	Node* ret = NULL;
	ret = (Node*)malloc(sizeof(Node));
	if (ret == NULL)
		return ret;

	ret->data = val;
	ret->Left = ret->Right = NULL;
	return ret;
}

//销毁
void Btdestroy(Node * Bt)
{

}

//前序遍历
void PreBtree(Node* Bt)
{
	//assert(Bt!=NULL);
	if (Bt != NULL)
	{
	   printf("%c ", Bt->data);
	   PreBtree(Bt->Left);
	   PreBtree(Bt->Right);
	}

}

//中序遍历
void MidBtree(Node* Bt)
{
	if (Bt != NULL)
	{
		MidBtree(Bt->Left);
		printf("%c ", Bt->data);
		MidBtree(Bt->Right);
	}
}

//后序遍历
void AfterBtree(Node* Bt)
{
	if (Bt != NULL)
	{
		AfterBtree(Bt->Right);
		AfterBtree(Bt->Left);
		printf("%c ", Bt->data);
	}
}

//求树的高度
int HightBtree(Node *BT)
{
	if (BT == NULL)
		return 0;
	if (BT->Left == NULL&&BT->Right == NULL)
		return 1;
	//根节点加上左右子树中高度大的那个子树
	return 1 + (HightBtree(BT->Left) > HightBtree(BT->Right) ? HightBtree(BT->Left) : HightBtree(BT->Right));
}

//求总节点的个数
int SizeBtree(Node *Bt)
{
	if (Bt == NULL)
		return 0;
	if (Bt->Left == NULL&&Bt->Right == NULL)//保证走到叶子节点
		return 1;
	return 1 + SizeBtree(Bt->Left) + SizeBtree(Bt->Right);
}

//检测是否为平衡树
int BalaceBt(Node * BT)//平衡返回1，否则返回0；
{
	if (BT == NULL)//没有节点
		return 1;
	if (BT->Left == NULL&&BT->Right == NULL)//只有一个节点
		return 1;
	//平衡二叉树的左右子树高度差的绝对值不可超过1，因此用abs()<2判断即可
	if (BalaceBt(BT->Left) && BalaceBt(BT->Right) && abs((BalaceBt(BT->Left) - BalaceBt(BT->Right)) < 2))
		return 1;
	return 0;
}

//获取叶子节点的个数
int Leafsize(Node *Bt)
{
	if (Bt == NULL)
		return 0;
	if (Bt->Left == NULL&&Bt->Right == NULL)//走到叶子节点,并且记数
		return 1;
	return SizeBtree(Bt->Left) + SizeBtree(Bt->Right);//左右叶子节点之和
}

//求第K层结点个数
int KsizeBt(Node *BT, int k)
{
	if (BT == NULL)
		return 0;
	if (( BT->Left == NULL&&BT->Right == NULL )|| k == 1)//走到第k层的情况或k为1的情况
		return 1;
	return KsizeBt(BT->Left, k - 1) + KsizeBt(BT->Right, k - 1);
}

//找值为val的结点，找到 返回它的地址，找不到 返回NULL
Node * FindvalBt(Node *BT, BtDatatyepf val)
{
	if (BT == NULL)
		return NULL;
	if (BT->data == val)
		return BT;

	//普通情况
	if (FindvalBt(BT->Left, val) != NULL)
		return BT->Left;
	return FindvalBt(BT->Right, val);
}

//找一个结点的双亲
Node* ParentfindBt(Node * BT, BtDatatyepf val)
{
	//节点为空或者只有一个节点的情况
	if (BT == NULL||(BT->Left ==NULL&&BT->Right==NULL))
		return NULL;
	//有俩个以上节点的情况
	if ((BT->Left != NULL&& BT->Left->data == val) || (BT->Right != NULL&& BT->Right->data == val))
		return BT;
	ParentfindBt(BT->Left, val);
	ParentfindBt(BT->Right, val);
}
