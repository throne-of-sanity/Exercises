// 2962. 统计最大元素出现至少 K 次的子数组
#include <stdio.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
long long countSubarrays(int *nums, int numsSize, int k)
{
    int max = nums[0];
    for (int i = 1; i < numsSize; i++)
        max = MAX(max, nums[i]);
    int left = 0, right = 0;
    int cnt = 0;
    long long ans = 0;
    for (; right < numsSize; right++)
    {
        if (nums[right] == max)
            cnt++;
        while (cnt >= k)
        {
            if (nums[left] == max)
                cnt--;
            left++;
        }
        ans += left;
    }
    return ans;
}