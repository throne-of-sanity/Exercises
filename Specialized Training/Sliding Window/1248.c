// 1248. 统计「优美子数组」
#include <stdio.h>
int numberOfSubarrays(int *nums, int numsSize, int k)
{
    int sum = 0;
    int odd[numsSize + 2];
    int cnt = 0;
    for (int i = 0; i < numsSize; i++)
        if (nums[i] & 1)
            odd[++cnt] = i;
    odd[0] = -1;
    odd[++cnt] = numsSize;
    for (int i = 1; i + k - 1 < cnt; i++)
    {
        int leftnumber = odd[i] - odd[i - 1];
        int rightnumber = odd[i + k] - odd[i + k - 1];
        sum += leftnumber * rightnumber;
    }
    return sum;
}