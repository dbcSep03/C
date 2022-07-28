// https://leetcode.cn/problems/merge-sorted-array/

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int end = m + n - 1;
    int step1 = m - 1;
    int step2 = n - 1;
    while (step1 >= 0 & step2 >= 0)
    {
        if (nums1[step1] > nums2[step2])
        {
            nums1[end] = nums1[step1];
            end--;
            step1--;
        }
        else
        {
            nums1[end] = nums2[step2];
            end--;
            step2--;
        }
    }
    while (step2 >= 0)
    {
        nums1[end] = nums2[step2];
        end--;
        step2--;
    }
}

int main()
{
    return 0;
}