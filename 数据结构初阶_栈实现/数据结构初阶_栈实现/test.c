#include"Stack.h"

void TestStack()
{
	Stack stack;

	StackInit(&stack);
	StackPush(&stack, 1);
	StackPush(&stack, 2);
	StackPush(&stack, 3);
	StackPush(&stack, 4);
	StackPush(&stack, 5);

	while (!StackEmpty(&stack))
	{
		printf("%d ", StackTop(&stack));
		StackPop(&stack);
	}

	printf("\n");

	StackDestory(&stack);
}

int main()
{
	TestStack();
	system("pause");
	return 0;
}