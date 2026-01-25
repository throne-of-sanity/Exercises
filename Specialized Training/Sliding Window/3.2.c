// 3. 无重复字符的最长子串
// 记录下标法+滑动窗口
#include <string.h>
#include <stdio.h>
int lengthOfLongestSubstring(char *s)
{
    int result = 0, ans = 0;
    int len = strlen(s);
    int last[128];
    memset(last, -1, sizeof(last));
    int r = 0;
    for (int i = 0; i < len; i++)
    {
        if (last[s[i]] >= r)
        {
            r = last[s[i]] + 1;
        }
        last[s[i]] = i;
        ans = i - r + 1;
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