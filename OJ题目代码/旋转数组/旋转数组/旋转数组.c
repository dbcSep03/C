// https://leetcode.cn/problems/rotate-array/
// 给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。

void rotate(int* nums, int numsSize, int k) {
	k = k % numsSize;
	int m = k / 2;
	int n = (numsSize - k) / 2;
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		temp = *(nums + i);
		*(nums + i) = *(nums + numsSize - k - 1 - i);
		*(nums+numsSize - k - 1 - i) = temp;
	}
	for (int i = 0; i < m; i++)
	{
		temp = *(nums + numsSize - 1 - i);
		*(nums + numsSize - 1 - i) = *(nums +numsSize - k + i);
		*(nums + numsSize - k + i) = temp;
	}
	for (int i = 0; i < numsSize / 2; i++)
	{
		temp = *(nums +numsSize - 1 - i);
		*(nums + numsSize - 1 - i) = *(nums +i);
		*(nums+ i) = temp;
	}
}
