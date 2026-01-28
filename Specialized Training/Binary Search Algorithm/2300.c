// 2300. 咒语和药水的成功对数
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
int *successfulPairs(int *spells, int spellsSize, int *potions, int potionsSize, long long success, int *returnSize)
{
    qsort(potions, potionsSize, sizeof(int), cmp);
    *returnSize = spellsSize;
    for (int i = 0; i < spellsSize; i++)
    {
        long long target = (success - 1) / spells[i];
        if (target < potions[potionsSize - 1])
            spells[i] = potionsSize - lowerbound(potions, potionsSize, target);
        else
            spells[i] = 0;
    }
    return spells;
}