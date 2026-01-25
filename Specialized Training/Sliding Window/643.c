// 643. 子数组最大平均数 I
#include <stdio.h>
#include <limits.h>
double findMaxAverage(int *nums, int numsSize, int k)
{
    int sum = 0, ans = INT_MIN;
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
        int left = i - k + 1;
        if (left < 0)
        {
            continue;
        }
        if (sum > ans)
        {
            ans = sum;
        }
        sum -= nums[left];
    }
    return (double)ans / k;
}
int main()
{
    int nums[] = {1, 12, -5, -6, 50, 3};
    int k = 4;
    double res = findMaxAverage(nums, sizeof(nums) / sizeof(nums[0]), k);
    printf("%.5f\n", res);
    return 0;
}