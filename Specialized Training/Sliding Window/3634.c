// 3634. 使数组平衡的最少移除数目
#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int minRemoval(int *nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    int left = 0, right = 0;
    int max = 0, cur = 0;
    for (; right < numsSize; right++)
    {
        while ((long long)nums[right] > (long long)k * nums[left])
        {
            left++;
        }
        cur = right - left + 1;
        if (cur > max)
            max = cur;
    }
    return numsSize - max;
}
int main()
{
    int nums[] = {3, 6, 1, 2, 5, 4};
    int k = 2;
    int res = minRemoval(nums, sizeof(nums) / sizeof(nums[0]), k);
    printf("%d\n", res);
    return 0;
}