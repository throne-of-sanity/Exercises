// 713. 乘积小于 K 的子数组
#include <stdio.h>
int numSubarrayProductLessThanK(int *nums, int numsSize, int k)
{
    if (k <= 1)
        return 0;
    int right = 0, left = 0;
    int prod = 1;
    int ans = 0;
    for (; right < numsSize; right++)
    {
        prod *= nums[right];
        while (prod >= k)
        {
            prod /= nums[left];
            left++;
        }
        ans += right - left + 1;
    }
    return ans;
}
int main()
{
    int nums[] = {10, 5, 2, 6};
    int numsSize = 4;
    int k = 100;
    int res = numSubarrayProductLessThanK(nums, numsSize, k);
    printf("res=%d", res);
    return 0;
}