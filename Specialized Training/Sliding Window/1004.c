// 1004. 最大连续1的个数 III
#include <stdio.h>
int longestOnes(int *nums, int numsSize, int k)
{
    int left = 0, right = 0;
    int maxLength = 0;
    int zeroCount = 0;
    for (; right < numsSize; right++)
    {
        if (nums[right] == 0)
        {
            zeroCount++;
        }
        while (zeroCount > k)
        {
            if (nums[left] == 0)
            {
                zeroCount--;
            }
            left++;
        }
        int currentLength = right - left + 1;
        if (currentLength > maxLength)
        {
            maxLength = currentLength;
        }
    }
    return maxLength;
}
int main()
{
    int nums[] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    int res = longestOnes(nums, sizeof(nums) / sizeof(nums[0]), k);
    printf("res=%d\n", res);
    return 0;
}