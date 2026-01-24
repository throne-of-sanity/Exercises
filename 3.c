#include <string.h>
#include <stdio.h>
int lengthOfLongestSubstring(char *s)
{
    int result = 0, ans = 0;
    int len = strlen(s);
    int cnt[128];
    memset(cnt, -1, sizeof(cnt));
    int r = 0;
    for (int i = 0; i < len; i++)
    {
        if (cnt[s[i]] >= r)
        {
            r = cnt[s[i]] + 1;
            ans = i - r;
        }
        cnt[s[i]] = i;
        ans++;
        if (ans > result)
            result = ans;
    }
    return result;
}
int main()
{
    char s[] = " ";
    int res = lengthOfLongestSubstring(s);
    printf("res=%d\n", res);
    return 0;
}