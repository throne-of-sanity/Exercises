// 1695. 删除子数组的最大得分
#include <stdio.h>
#include <string.h>
int maximumUniqueSubarray(int *nums, int numsSize)
{
    int hash[10001];
    memset(hash, -1, sizeof(hash));
    int left = 0, right = 0;
    int sum = 0, maxSum = 0;
    for (; right < numsSize; right++)
    {
        sum += nums[right];
        while (hash[nums[right]] >= left)
        {
            sum -= nums[left];
            left++;
        }
        hash[nums[right]] = right;
        if (sum > maxSum)
            maxSum = sum;
    }
    return maxSum;
}
int main()
{
    int nums[] = {4, 2, 4, 5, 6};
    int res = maximumUniqueSubarray(nums, 5);
    printf("res=%d\n", res);
    return 0;
}