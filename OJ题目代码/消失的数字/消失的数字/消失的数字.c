// ����nums������0��n������������������ȱ��һ�������д�����ҳ��Ǹ�ȱʧ������

int missingNumber(int* nums, int numsSize) {
	int n = 0;
	for (int i = 0; i < numsSize +1; i++)
	{
		n = n ^ i;
	}
	for (int i = 0; i < numsSize; i++)
	{
		n = n ^ *(nums + i);
	}
	return n;
}
