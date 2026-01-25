// 2090. 半径为 k 的子数组平均值
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int *getAverages(int *nums, int numsSize, int k, int *returnSize)
{
    int *avgs = malloc(sizeof(int) * numsSize);
    memset(avgs, -1, sizeof(int) * numsSize);
    long long sum = 0;
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
        if (i < 2 * k)
            continue;
        avgs[i - k] = sum / (2 * k + 1);
        sum -= nums[i - 2 * k];
    }
    return avgs;
}
int main()
{
    int nums[] = {7, 4, 3, 9, 1, 8, 5, 2, 6};
    int k = 3;
    int returnSize = 0;
    int *avgs = getAverages(nums, sizeof(nums) / sizeof(nums[0]), k, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", avgs[i]);
    }
    printf("\n");
    free(avgs);
    return 0;
}