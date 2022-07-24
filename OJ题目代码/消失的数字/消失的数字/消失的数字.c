// 数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数

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
