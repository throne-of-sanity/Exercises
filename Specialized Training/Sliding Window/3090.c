// 3090. 每个字符最多出现两次的最长子字符串
#include <stdio.h>
#include <string.h>
int maximumLengthSubstring(char *s)
{
    int cnt[26] = {0};
    int left = 0, right = 0;
    int len = strlen(s);
    int max = 0, cur = 0;
    for (; right < len; right++)
    {
        cnt[s[right] - 'a']++;
        cur++;
        while (cnt[s[right] - 'a'] > 2)
        {
            cnt[s[left++] - 'a']--;
            cur--;
        }
        if (cur > max)
            max = cur;
    }
    return max;
}
int main()
{
    char s[] = "bcbbbcba";
    int res = maximumLengthSubstring(s);
    printf("%d\n", res);
    return 0;
}