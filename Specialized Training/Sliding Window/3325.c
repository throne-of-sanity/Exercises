// 3325. 字符至少出现 K 次的子字符串 I
#include <stdio.h>
int numberOfSubstrings(char *s, int k)
{
    int left = 0, right = 0;
    int ans = 0;
    int cnt[26] = {0};
    for (; s[right]; right++)
    {
        cnt[s[right] - 'a']++;
        while (cnt[s[right] - 'a'] >= k)
        {
            cnt[s[left] - 'a']--;
            left++;
        }
        ans += left;
    }
    return ans;
}