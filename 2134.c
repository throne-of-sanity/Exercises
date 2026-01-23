#include <stdlib.h>
#include <stdio.h>
int minSwaps(int *nums, int numsSize)
{
    int sum = 0, ans = 0, cnt = 0;
    for (int i = 0; i < numsSize; i++)
    {
        cnt += nums[i];
    }
    for (int i = 0; i < numsSize + cnt - 1; i++)
    {
        sum += nums[i % numsSize];
        if (i < cnt - 1)
            continue;
        if (sum > ans)
            ans = sum;
        sum -= nums[i - cnt + 1];
    }
    return cnt - ans;
}
int main()
{
    int nums[] = {1, 0, 1, 0, 1};
    int numsSize = 5;
    int ans = minSwaps(nums, numsSize);
    printf("%d\n", ans);
    return 0;
}