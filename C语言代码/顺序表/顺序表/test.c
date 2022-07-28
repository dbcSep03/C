#include "SeqList.h"

void test1()
{
	SeqList ps;
	SeqListInit(&ps);
	for (int i = 0; i < 5; i++)
	{
		SeqListPushBack(&ps, i);
	}
	SeqListPrint(&ps);
	SeqListPushFront(&ps, 3);
	SeqListPushFront(&ps, 5);
	SeqListPrint(&ps);
	SeqListPopFront(&ps);
	SeqListPrint(&ps);
	SeqListPopBack(&ps);
	SeqListPrint(&ps);
	int a = SeqListFind(&ps, 5);
	if (a!= -1)
	{
		printf("下标为%d", a);
	}
	else
	{
		printf("没找到\n");
	}
	SeqListInsert(&ps, 2, 1);
	SeqListPrint(&ps);
	SeqListErase(&ps, 2);
	SeqListPrint(&ps);
}
int main()
{
	test1();
}
