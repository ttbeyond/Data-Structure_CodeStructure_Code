#include"BinaryTree.h"

void testbinarytree()
{
	BtDatatyepf arr[] = "ABD***CE**F";
	Node *Bt = NULL;
	int count = 0;
	Bt = BTcreat(arr, (sizeof(arr) / sizeof(arr[0])), &count);
	printf("ǰ�������\n");
	PreBtree(Bt);
	printf("\n");

	printf("���������\n");
	MidBtree(Bt);
	printf("\n");

	printf("���������\n");
	AfterBtree(Bt);
	printf("\n");
	printf("���ĸ߶�Ϊ��%d \n", HightBtree(Bt));
	printf("�����ܽ�����Ϊ��%d \n", SizeBtree(Bt));
	printf("�Ƿ���ƽ����(1Ϊ��  0Ϊ��)��%d\n", BalaceBt(Bt));
	printf("Ҷ�ӽڵ�ĸ����ǣ�%d\n", Leafsize(Bt));
	printf("��%d��Ľ������ǣ�%d\n", 3, KsizeBt(Bt, 3));
	printf("%d\n", FindvalBt(Bt, 'F'));
	printf("%d\n", ParentfindBt(Bt, 'B'));

}

int main()
{
	testbinarytree();
	system("pause");
	return 0;
}