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

	if (ps->_top == ps->_capacity)//栈满或栈为空的情况//通过此操作保证要有空间
	{
		size_t newcapacity = ps->_capacity == 0 ? 2 : ps->_capacity*2;//确定新的容量大小
		ps->_a = (STDataType*)realloc(ps->_a ,newcapacity*sizeof(STDataType));//开辟新的空间
		assert(ps->_a);
		ps->_capacity = newcapacity;	
	}
		ps->_a[ps->_top ] = x;
		ps->_top++;
}
void StackPop(Stack* ps)
{
	assert(ps&&ps->_top >0);//保证栈至少有一个元素

	--ps->_top;//top-1,直接删掉栈顶数据
}
//取栈顶元素，但不删除
STDataType StackTop(Stack* ps)
{
	assert(ps);

	return ps->_a[ps->_top-1];
}
int StackEmpty(Stack* ps)//非空返回0，空返回1
{
	assert(ps);
	return ps->_top == 0;
}
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->_top;
}