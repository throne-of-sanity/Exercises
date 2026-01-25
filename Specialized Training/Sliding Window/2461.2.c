// 2461. 长度为 K 子数组中的最大和
// 记录下标
#include <stdio.h>
#include <string.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
long long maximumSubarraySum(int *nums, int numsSize, int k)
{
    int hash[100001];
    memset(hash, -1, sizeof(int) * 100001);
    int left = 0;
    long long s = 0, result = 0;
    for (int i = 0; i < numsSize; i++)
    {
        while (hash[nums[i]] >= left)
        {
            s -= nums[left];
            left++;
        }
        hash[nums[i]] = i;
        s += nums[i];

        if ((i - left + 1) < k)
            continue;
        result = MAX(result, s);
        s -= nums[left++];
    }
    return result;
}
int main()
{
    int nums[] = {1, 1, 4, 2, 7, 9, 9};
    int k = 3;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    long long res = maximumSubarraySum(nums, numsSize, k);
    printf("%lld\n", res);
    return 0;
}
