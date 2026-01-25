// 904. 水果成篮
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int totalFruit(int *fruits, int fruitsSize)
{
    int *hash = malloc(sizeof(int) * fruitsSize);
    memset(hash, 0, sizeof(int) * fruitsSize);
    int left = 0, right = 0;
    int distinctCount = 0;
    int max = 0, cur = 0;
    for (; right < fruitsSize; right++)
    {
        if (hash[fruits[right]] == 0)
        {
            distinctCount++;
        }
        hash[fruits[right]]++;
        while (distinctCount > 2)
        {
            hash[fruits[left]]--;
            if (hash[fruits[left]] == 0)
            {
                distinctCount--;
            }
            left++;
        }
        cur = right - left + 1;
        if (cur > max)
            max = cur;
    }
    free(hash);
    return max;
}
int main()
{
    int fruits[] = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    int res = totalFruit(fruits, 11);
    printf("%d\n", res);
    return 0;
}