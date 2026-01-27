// 2904. 最短且字典序最小的美丽子字符串
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *shortestBeautifulSubstring(char *s, int k)
{
    int n = strlen(s);
    int minLen = n + 1;
    int bestStart = -1;
    int cnt = 0;
    int left = 0;
    for (int right = 0; right < n; right++)
    {
        if (s[right] == '1')
        {
            cnt++;
        }
        while (cnt == k)
        {
            int len = right - left + 1;
            if (len < minLen)
            {
                minLen = len;
                bestStart = left;
            }
            else if (len == minLen)
            {
                int cmp = strncmp(s + left, s + bestStart, len);
                if (cmp < 0)
                {
                    bestStart = left;
                }
            }
            if (s[left] == '1')
            {
                cnt--;
            }
            left++;
        }
    }
    if (bestStart == -1)
    {
        char *result = malloc(1);
        if (result)
            result[0] = '\0';
        return result;
    }
    char *result = malloc(minLen + 1);
    if (!result)
        return NULL;
    strncpy(result, s + bestStart, minLen);
    result[minLen] = '\0';
    return result;
}
int main()
{
    char s[9] = "100011001";
    int k = 3;
    printf("%s", shortestBeautifulSubstring(s, k));
    return 0;
}