#include "SeqList.h"
#include<stdio.h>


//˳����ʼ��
void SeqListInit(SeqList* ps)
{
	assert(ps);   // ����һ�£���ֹ�����ָ��
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

//˳�������
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

//˳����ӡ
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//���
void SeqListCheck(SeqList* ps)
{
	assert(ps);
	// �ж��Ƿ��Ѿ�����
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

// β��
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps);
	SeqListCheck(ps);
	ps->a[ps->size] = x;
	ps->size++;
}


//ͷ��            
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

// ͷɾ
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

//βɾ
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	assert(ps->size > 0);
	ps->size--;
}
//˳������
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

// ˳�����posλ�ò���x
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

// ˳���ɾ��posλ�õ�ֵ
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