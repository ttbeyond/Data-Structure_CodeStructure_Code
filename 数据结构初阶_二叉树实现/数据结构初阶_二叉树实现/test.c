#include"BinaryTree.h"

void testbinarytree()
{
	BtDatatyepf arr[] = "ABD***CE**F";
	Node *Bt = NULL;
	int count = 0;
	Bt = BTcreat(arr, (sizeof(arr) / sizeof(arr[0])), &count);
	printf("前序遍历：\n");
	PreBtree(Bt);
	printf("\n");

	printf("中序遍历：\n");
	MidBtree(Bt);
	printf("\n");

	printf("后序遍历：\n");
	AfterBtree(Bt);
	printf("\n");
	printf("树的高度为：%d \n", HightBtree(Bt));
	printf("树的总结点个数为：%d \n", SizeBtree(Bt));
	printf("是否是平衡树(1为是  0为否)：%d\n", BalaceBt(Bt));
	printf("叶子节点的个数是：%d\n", Leafsize(Bt));
	printf("第%d层的结点个数是：%d\n", 3, KsizeBt(Bt, 3));
	printf("%d\n", FindvalBt(Bt, 'F'));
	printf("%d\n", ParentfindBt(Bt, 'B'));

}

int main()
{
	testbinarytree();
	system("pause");
	return 0;
}