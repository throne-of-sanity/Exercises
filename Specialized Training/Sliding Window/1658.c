// 1658. 将 x 减到 0 的最小操作数
#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int minOperations(int *nums, int numsSize, int x)
{
    int total = 0;
    for (int i = 0; i < numsSize; i++)
    {
        total += nums[i];
    }
    int target = total - x;
    if (target < 0)
        return -1;
    if (target == 0)
        return numsSize;
    int left = 0, right = 0, result = -1, sum = 0;
    for (; right < numsSize; right++)
    {
        sum += nums[right];
        while (sum > target)
        {
            sum -= nums[left];
            left++;
        }
        if (sum == target)
        {
            result = MAX(result, right - left + 1);
        }
    }
    return result != -1 ? numsSize - result : -1;
}
int main()
{
    int nums[] = {1, 1, 4, 2, 3};
    int x = 5;
    int res = minOperations(nums, sizeof(nums) / sizeof(nums[0]), x);
    printf("res=%d\n", res);
    return 0;
}