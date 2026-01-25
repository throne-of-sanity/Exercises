// 1493. 删掉一个元素以后全为 1 的最长子数组
#include <stdio.h>
int longestSubarray(int *nums, int numsSize)
{
    int left = 0, right = 0;
    int max = 0, cur = 0;
    int zero = 0;
    for (; right < numsSize; right++)
    {
        cur++;
        if (nums[right] == 0)
            zero++;
        while (zero > 1)
        {
            if (nums[left] == 0)
                zero--;
            left++;
            cur--;
        }
        if (cur > max)
            max = cur;
    }
    return max - 1;
}
int main()
{
    int nums[] = {1, 1, 0, 1};
    int res = longestSubarray(nums, 4);
    printf("%d\n", res);
    return 0;
}