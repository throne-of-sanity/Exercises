// 1358. 包含所有三种字符的子字符串数目
#include <stdio.h>
#include <string.h>
int numberOfSubstrings(char *s)
{
    int cnt[3] = {0};
    int left = 0, right = 0;
    int ans = 0;
    for (; s[right]; right++)
    {
        cnt[s[right] - 'a']++;
        while (cnt[0] && cnt[1] && cnt[2])
        {
            cnt[s[left] - 'a']--;
            left++;
        }
        ans += left;
    }
    return ans;
}