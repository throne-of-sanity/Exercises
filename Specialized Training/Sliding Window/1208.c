// 1208. 尽可能使字符串相等
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int equalSubstring(char *s, char *t, int maxCost)
{
    int len = strlen(s);
    int left = 0, right = 0;
    int cur = 0, max = 0;
    int sum = 0;
    for (; right < len; right++)
    {
        sum += abs(s[right] - t[right]);
        while (sum > maxCost)
        {
            sum -= abs(s[left] - t[left]);
            left++;
        }
        cur = right - left + 1;
        if (cur > max)
            max = cur;
    }
    return max;
}
int main()
{
    char s[] = "abcd";
    char t[] = "bcdf";
    int maxCost = 3;
    int res = equalSubstring(s, t, maxCost);
    printf("%d\n", res);
    return 0;
}