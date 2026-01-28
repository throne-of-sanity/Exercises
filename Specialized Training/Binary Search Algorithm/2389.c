// 2389. 和有限的最长子序列
#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int lowerbound(int *nums, int numssize, int target)
{
    int left = -1, right = numssize;
    while (left + 1 < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > target)
            right = mid;
        else
            left = mid;
    }
    return right;
}
int *answerQueries(int *nums, int numsSize, int *queries, int queriesSize, int *returnSize)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 1; i < numsSize; i++)
        nums[i] += nums[i - 1];
    int *arr = malloc(sizeof(int) * queriesSize);
    *returnSize = queriesSize;
    for (int i = 0; i < queriesSize; i++)
    {
        arr[i] = lowerbound(nums, numsSize, queries[i]);
    }
    return arr;
}