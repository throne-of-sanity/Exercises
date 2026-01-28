// 704. 二分查找
#include <stdio.h>
int lowerbound(int *nums, int numsSize, int target)
{
    int left = -1, right = numsSize;
    while (left + 1 < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
            left = mid;
        else
            right = mid;
    }
    return right;
}
int search(int *nums, int numsSize, int target)
{
    int res = lowerbound(nums, numsSize, target);
    return res != numsSize && nums[res] == target ? res : -1;
}