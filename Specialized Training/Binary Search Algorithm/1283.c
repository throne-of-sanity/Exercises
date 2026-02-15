// 1283. 使结果不超过阈值的最小除数
#include <stdio.h>
#define MAX(a, b) ((a) > ((b)) ? (a) : (b))
int check(int a, int *nums, int numsSize, int threshold)
{
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        sum += (nums[i] + a - 1) / a;
        if (sum > threshold)
            return 0;
    }
    return 1;
}
int smallestDivisor(int *nums, int numsSize, int threshold)
{
    int left = 0, right = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        right = MAX(right, nums[i]);
    }
    while (left + 1 < right)
    {
        int mid = left + (right - left) / 2;
        if (check(mid, nums, numsSize, threshold))
            right = mid;
        else
            left = mid;
    }
    return right;
}