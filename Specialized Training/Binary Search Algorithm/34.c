// 34. 在排序数组中查找元素的第一个和最后一个位置
#include <stdio.h>
#include <string.h>
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
int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
    int *ans = malloc(sizeof(int) * 2);
    *returnSize = 2;
    int start = lowerbound(nums, numsSize, target);
    if (start == numsSize || nums[start] != target)
    {
        ans[0] = -1;
        ans[1] = -1;
        return ans;
    }
    int end = lowerbound(nums, numsSize, target + 1) - 1;
    ans[0] = start;
    ans[1] = end;
    return ans;
}