// 209. 长度最小的子数组
#include <stdio.h>
int minSubArrayLen(int target, int *nums, int numsSize)
{
    int left = 0, right = 0;
    int sum = 0;
    int cur = 0, min = numsSize + 1;
    for (; right < numsSize; right++)
    {
        sum += nums[right];
        while (sum - nums[left] >= target)
        {
            sum -= nums[left];
            left++;
        }
        cur = right - left + 1;
        if (sum >= target)
            if (cur < min)
                min = cur;
    }
    return min <= numsSize ? min : 0;
}
int main()
{
    int nums[] = {2, 3, 1, 2, 4, 3};
    int target = 7;
    int res = minSubArrayLen(target, nums, sizeof(nums) / sizeof(nums[0]));
    printf("%d\n", res);
    return 0;
}