// 3258. 统计满足 K 约束的子字符串数量 I
#include <stdio.h>
#include <string.h>
int countKConstraintSubstrings(char *s, int k)
{
    int cnt[2] = {0};
    int left = 0, right = 0;
    int len = strlen(s);
    int ans = 0;
    for (; s[right]; right++)
    {
        cnt[s[right] - '0']++;
        while (cnt[0] > k && cnt[1] > k)
        {
            cnt[s[left] - '0']--;
            left++;
        }
        ans += right - left + 1;
    }
    return ans;
}
int main()
{
    char s[] = "10101";
    int k = 1;
    printf("%d", countKConstraintSubstrings(s, k));
    return 0;
}