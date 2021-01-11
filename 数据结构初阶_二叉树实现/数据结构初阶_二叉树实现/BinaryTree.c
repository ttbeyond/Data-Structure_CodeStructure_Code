#include"BinaryTree.h"

//������������
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

//����һ���ڵ�
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

//����
void Btdestroy(Node * Bt)
{

}

//ǰ�����
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

//�������
void MidBtree(Node* Bt)
{
	if (Bt != NULL)
	{
		MidBtree(Bt->Left);
		printf("%c ", Bt->data);
		MidBtree(Bt->Right);
	}
}

//�������
void AfterBtree(Node* Bt)
{
	if (Bt != NULL)
	{
		AfterBtree(Bt->Right);
		AfterBtree(Bt->Left);
		printf("%c ", Bt->data);
	}
}

//�����ĸ߶�
int HightBtree(Node *BT)
{
	if (BT == NULL)
		return 0;
	if (BT->Left == NULL&&BT->Right == NULL)
		return 1;
	//���ڵ�������������и߶ȴ���Ǹ�����
	return 1 + (HightBtree(BT->Left) > HightBtree(BT->Right) ? HightBtree(BT->Left) : HightBtree(BT->Right));
}

//���ܽڵ�ĸ���
int SizeBtree(Node *Bt)
{
	if (Bt == NULL)
		return 0;
	if (Bt->Left == NULL&&Bt->Right == NULL)//��֤�ߵ�Ҷ�ӽڵ�
		return 1;
	return 1 + SizeBtree(Bt->Left) + SizeBtree(Bt->Right);
}

//����Ƿ�Ϊƽ����
int BalaceBt(Node * BT)//ƽ�ⷵ��1�����򷵻�0��
{
	if (BT == NULL)//û�нڵ�
		return 1;
	if (BT->Left == NULL&&BT->Right == NULL)//ֻ��һ���ڵ�
		return 1;
	//ƽ������������������߶Ȳ�ľ���ֵ���ɳ���1�������abs()<2�жϼ���
	if (BalaceBt(BT->Left) && BalaceBt(BT->Right) && abs((BalaceBt(BT->Left) - BalaceBt(BT->Right)) < 2))
		return 1;
	return 0;
}

//��ȡҶ�ӽڵ�ĸ���
int Leafsize(Node *Bt)
{
	if (Bt == NULL)
		return 0;
	if (Bt->Left == NULL&&Bt->Right == NULL)//�ߵ�Ҷ�ӽڵ�,���Ҽ���
		return 1;
	return SizeBtree(Bt->Left) + SizeBtree(Bt->Right);//����Ҷ�ӽڵ�֮��
}

//���K�������
int KsizeBt(Node *BT, int k)
{
	if (BT == NULL)
		return 0;
	if (( BT->Left == NULL&&BT->Right == NULL )|| k == 1)//�ߵ���k��������kΪ1�����
		return 1;
	return KsizeBt(BT->Left, k - 1) + KsizeBt(BT->Right, k - 1);
}

//��ֵΪval�Ľ�㣬�ҵ� �������ĵ�ַ���Ҳ��� ����NULL
Node * FindvalBt(Node *BT, BtDatatyepf val)
{
	if (BT == NULL)
		return NULL;
	if (BT->data == val)
		return BT;

	//��ͨ���
	if (FindvalBt(BT->Left, val) != NULL)
		return BT->Left;
	return FindvalBt(BT->Right, val);
}

//��һ������˫��
Node* ParentfindBt(Node * BT, BtDatatyepf val)
{
	//�ڵ�Ϊ�ջ���ֻ��һ���ڵ�����
	if (BT == NULL||(BT->Left ==NULL&&BT->Right==NULL))
		return NULL;
	//���������Ͻڵ�����
	if ((BT->Left != NULL&& BT->Left->data == val) || (BT->Right != NULL&& BT->Right->data == val))
		return BT;
	ParentfindBt(BT->Left, val);
	ParentfindBt(BT->Right, val);
}
