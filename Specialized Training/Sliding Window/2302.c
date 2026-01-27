// 2302. 统计得分小于 K 的子数组数目
#include <stdio.h>
long long countSubarrays(int *nums, int numsSize, long long k)
{
    long long ans = 0, sum = 0;
    int right = 0, left = 0;
    for (; right < numsSize; right++)
    {
        sum += nums[right];
        while (sum * (right - left + 1) >= k)
        {
            sum -= nums[left];
            left++;
        }
        ans += right - left + 1;
    }
    return ans;
}
int main()
{
    int nums[] = {2, 1, 4, 3, 5};
    int numsSize = 5;
    long long k = 10;
    printf("%d", countSubarrays(nums, numsSize, k));
    return 0;
}