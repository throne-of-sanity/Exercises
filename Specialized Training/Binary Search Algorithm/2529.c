// 2529. 正整数和负整数的最大计数
#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int lowerbound(int *nums, int numsSize, int target)
{
    int left = -1, right = numsSize;
    while (left + 1 < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > target)
            right = mid;
        else
            left = mid;
    }
    return right;
}
int maximumCount(int *nums, int numsSize)
{
    return MAX(numsSize - lowerbound(nums, numsSize, 0), lowerbound(nums, numsSize, -1));
}