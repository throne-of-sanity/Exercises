// 3824. 减小数组使其满足条件的最小 K 值
#include <math.h>
#define MAX(a, b) ((a) > ((b)) ? (a) : (b))
int nonPositive(int *nums, int numsSize, int k)
{
    int sum = numsSize;
    for (int i = 0; i < numsSize; i++)
        sum += (nums[i] - 1) / k;
    return sum;
}
int minimumK(int *nums, int numsSize)
{
    int left = 0, right = numsSize;
    for (int i = 0; i < numsSize; i++)
    {
        right = MAX(right, nums[i]);
    }
    while (left + 1 < right)
    {
        int mid = left + (right - left) / 2;
        if (nonPositive(nums, numsSize, mid) <= (long long)mid * mid)
            right = mid;
        else
            left = mid;
    }
    return right;
}