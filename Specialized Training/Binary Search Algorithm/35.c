// 35. 搜索插入位置
#include <stdio.h>
int lowerbound(int *nums, int numsSize, int target)
{
    int left = -1, right = numsSize;
    while (left + 1 < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target)
            right = mid;
        else
            left = mid;
    }
    return right;
}
int searchInsert(int *nums, int numsSize, int target)
{
    return lowerbound(nums, numsSize, target);
}
int main()
{
    return 0;
}