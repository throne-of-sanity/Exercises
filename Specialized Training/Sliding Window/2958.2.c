// 2958. 最多 K 个重复元素的最长子数组
#include <stdio.h>
#include <stdlib.h>
int maxSubarrayLength(int *nums, int numsSize, int k)
{
    int min = nums[0];
    int max = nums[0];
    int i = 0;
    for (i = 0; i < numsSize; i++) // 遍历确定元素范围
    {
        if (min > nums[i])
        {
            min = nums[i];
        }

        if (max < nums[i])
        {
            max = nums[i];
        }
    }
    int *p = (int *)calloc((max - min + 1), sizeof(int)); // 将哈希表大小根据映射调整到合理范围

    int j = 0;
    int len = 0;
    for (i = 0; i < numsSize; i++)
    {
        p[nums[i] - min]++;
        while (p[nums[i] - min] > k) // 找到极值了，更新长度
        {
            p[nums[j] - min]--;
            j++;
        }
        if (i - j + 1 > len) // 判断不存在极值的情况
            len = i - j + 1;
    }
    return len;
}
int main()
{
    int nums[] = {4, 2, 4, 5, 6, 2, 2, 2};
    int res = maxSubarrayLength(nums, 8, 2);
    printf("res=%d\n", res);
    return 0;
}