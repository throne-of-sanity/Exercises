// 930. 和相同的二元子数组
// 恰好型滑动窗口
#include <stdio.h>
int solve(int *nums, int numsSize, int goal)
{
    int left = 0, right = 0;
    int sum = 0, ans = 0;
    for (; right < numsSize; right++)
    {
        sum += nums[right];
        while (sum >= goal && left <= right)
        {
            sum -= nums[left];
            left++;
        }
        ans += left;
    }
    return ans;
}
int numSubarraysWithSum(int *nums, int numsSize, int goal)
{
    return solve(nums, numsSize, goal) - solve(nums, numsSize, goal + 1);
}