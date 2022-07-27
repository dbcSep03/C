#include "SeqList.h"

void SeqListInit(SeqList* ps)
{
	assert(ps);   // ����һ�£���ֹ�����ָ��
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

void SeqListDestroy(SeqList* ps)
{
	assert(ps);
	if (ps->a != NULL)
	{
		ps->a = NULL;
		ps->capacity = ps->size = 0;
	}
}

void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

// β��
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps);
	
	SeqListCheck(&ps);
	ps->a[ps->size] = x;
	ps->size++;
}

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

//ͷ��            
void SeqListPushFront(SeqList* ps, SLDateType x)
{

}
void SeqListPopFront(SeqList* ps);
void SeqListPopBack(SeqList* ps);