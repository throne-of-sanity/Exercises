// 1170. 比较字符串最小字母出现频次
#include <stdlib.h>
#include <stdio.h>
int f(const char *s)
{
    int cnt = 0;
    char ch = 'z';
    for (int i = 0; s[i]; i++)
    {
        char c = s[i];
        if (c < ch)
        {
            ch = c;
            cnt = 1;
        }
        else if (c == ch)
            cnt++;
    }
    return cnt;
}
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
int *numSmallerByFrequency(char **queries, int queriesSize, char **words, int wordsSize, int *returnSize)
{
    int nums[wordsSize];
    int *result = malloc(sizeof(int) * queriesSize);
    *returnSize = queriesSize;
    for (int i = 0; i < wordsSize; i++)
        nums[i] = f(words[i]);
    qsort(nums, wordsSize, sizeof(int), cmp);
    for (int i = 0; i < queriesSize; i++)
        result[i] = wordsSize - lowerbound(nums, wordsSize, f(queries[i]));
    return result;
}