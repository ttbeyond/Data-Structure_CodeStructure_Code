#include"Stack.h"

void StackInit(Stack* ps)
{
	assert(ps);

	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}
void StackDestory(Stack* ps)
{
	assert(ps&&ps->_a !=NULL);

		free(ps->_a);
		ps->_capacity = 0;
		ps->_top = 0;
		ps = NULL;
}
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);

	if (ps->_top == ps->_capacity)//ջ����ջΪ�յ����//ͨ���˲�����֤Ҫ�пռ�
	{
		size_t newcapacity = ps->_capacity == 0 ? 2 : ps->_capacity*2;//ȷ���µ�������С
		ps->_a = (STDataType*)realloc(ps->_a ,newcapacity*sizeof(STDataType));//�����µĿռ�
		assert(ps->_a);
		ps->_capacity = newcapacity;	
	}
		ps->_a[ps->_top ] = x;
		ps->_top++;
}
void StackPop(Stack* ps)
{
	assert(ps&&ps->_top >0);//��֤ջ������һ��Ԫ��

	--ps->_top;//top-1,ֱ��ɾ��ջ������
}
//ȡջ��Ԫ�أ�����ɾ��
STDataType StackTop(Stack* ps)
{
	assert(ps);

	return ps->_a[ps->_top-1];
}
int StackEmpty(Stack* ps)//�ǿշ���0���շ���1
{
	assert(ps);
	return ps->_top == 0;
}
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->_top;
}