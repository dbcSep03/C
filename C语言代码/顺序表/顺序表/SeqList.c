#include "SeqList.h"
#include<stdio.h>


//顺序表初始化
void SeqListInit(SeqList* ps)
{
	assert(ps);   // 断言一下，防止传入空指针
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

//顺序表销毁
void SeqListDestroy(SeqList* ps)
{
	assert(ps);
	if (ps->a != NULL)
	{
		ps->a = NULL;
		ps->capacity = 0;
		ps->size = 0;
	}
}

//顺序表打印
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//检查
void SeqListCheck(SeqList* ps)
{
	assert(ps);
	// 判断是否已经满了
	if (ps->capacity == ps->size)
	{
		int newsCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SeqList* temp = (SeqList*)realloc(ps->a, newsCapacity * sizeof(SeqList));
		if (temp == NULL)
		{
			perror("reallooc fail");
			return;
		}
		ps->a = temp;
		ps->capacity = newsCapacity;
	}
}

// 尾插
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps);
	SeqListCheck(ps);
	ps->a[ps->size] = x;
	ps->size++;
}


//头插            
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);
	SeqListCheck(ps);

	for (int i = ps->size; i > 0; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->size++;
	ps->a[0] = x;
}

// 头删
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	assert(ps->size>0);
	for (int i = 0; i < ps->size-1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

//尾删
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	assert(ps->size > 0);
	ps->size--;
}
//顺序表查找
int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);
	assert(ps->size > 0);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps);
	assert(pos < ps->size);

	SeqListCheck(ps);
	size_t end = ps->size;
	while (end > pos)
	{
		ps->a[end] = ps->a[end-1];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}

// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	assert(pos < ps->size);
	
	size_t begin = pos;
	while (begin < ps->size-1)
	{
		ps->a[begin] = ps->a[begin + 1];
		begin++;
	}
	ps->size--;
}