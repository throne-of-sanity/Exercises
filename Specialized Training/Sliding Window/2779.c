// 2779. 数组的最大美丽值
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int maximumBeauty(int *nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    int left = 0, right = 0;
    int maxBeauty = 1;
    for (; right < numsSize; right++)
    {
        while (nums[right] - nums[left] > 2 * k)
        {
            left++;
        }
        int currentBeauty = right - left + 1;
        if (currentBeauty > maxBeauty)
        {
            maxBeauty = currentBeauty;
        }
    }
    return maxBeauty;
}
int main()
{
    int nums[] = {4, 6, 1, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 2;
    int res = maximumBeauty(nums, numsSize, k);
    printf("res=%d\n", res);
    return 0;
}