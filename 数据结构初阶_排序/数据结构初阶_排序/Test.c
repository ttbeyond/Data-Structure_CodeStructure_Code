#include"Sort.h"

void Test()
{
	int arr[] = { 3, 6, 2, 4, 5, 7, 9, 8, 1, 4 };
	//HeapSort(arr, sizeof(arr) / sizeof(int));
	//Print(arr, sizeof(arr) / sizeof(int));

	//BubbleSort(arr, sizeof(arr) / sizeof(int));
	//Print(arr, sizeof(arr) / sizeof(int));

	QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	Print(arr, sizeof(arr) / sizeof(int));

	//MergeSort(arr, sizeof(arr) / sizeof(int));
	//Print(arr, sizeof(arr) / sizeof(int));

	//InsertSort(arr, sizeof(arr) / sizeof(int));
	//Print(arr, sizeof(arr) / sizeof(int));

	//ShellSort(arr, sizeof(arr) / sizeof(int));
	//Print(arr, sizeof(arr) / sizeof(int));

	//SelectSort(arr, sizeof(arr) / sizeof(int));
	//Print(arr, sizeof(arr) / sizeof(int));

	//CountSort(arr, sizeof(arr) / sizeof(int));
	//Print(arr, sizeof(arr) / sizeof(int));

}

int main()
{
	Test();
	system("pause");
	return 0;
}