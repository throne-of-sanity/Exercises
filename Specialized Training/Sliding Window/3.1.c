// 3. 无重复字符的最长子串
// 记录出现次数+滑动窗口
#include <string.h>
#include <stdio.h>
int lengthOfLongestSubstring(char *s)
{
    int result = 0, ans = 0;
    int len = strlen(s);
    int hash[128];
    memset(hash, 0, sizeof(hash));
    int left = 0, right = 0;
    for (; right < len; right++)
    {
        hash[s[right]]++;
        while (hash[s[right]] > 1)
        {
            hash[s[left]]--;
            left++;
        }
        ans = right - left + 1;
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