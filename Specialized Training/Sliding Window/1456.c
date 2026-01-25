// 1456. 定长子串中元音的最大数目
#include <stdio.h>
#define MAX(a, b) ((b) > (a) ? (b) : (a))
int maxVowels(char *s, int k)
{
    int ans = 0, vowel = 0;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            vowel++;
        }
        int left = i - k + 1;
        if (left < 0)
        {
            continue;
        }
        ans = MAX(ans, vowel);
        if (ans == k)
        {
            break;
        }
        char out = s[left];
        if (out == 'a' || out == 'e' || out == 'i' || out == 'o' || out == 'u')
        {
            vowel--;
        }
    }
    return ans;
}
int main()
{
    char s[] = "abciiidef";
    int k = 3;
    int res = maxVowels(s, k);
    printf("%d\n", res);
    return 0;
}