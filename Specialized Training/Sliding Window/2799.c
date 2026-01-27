// 2799. 统计完全子数组的数目
#include <stdio.h>
int countCompleteSubarrays(int *nums, int numsSize)
{
    int left = 0, right = 0;
    int cnt[2001] = {0};
    int ans = 0;
    for (; right < numsSize; right++)
    {
        if (cnt[nums[right]]++ == 0)
            ans = 0;
        while (cnt[nums[left]] > 1)
            cnt[nums[left++]]--;
        ans += left + 1;
    }
    return ans;
}