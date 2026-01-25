// 2730. 找到最长的半重复子字符串
#include <stdio.h>
int longestSemiRepetitiveSubstring(char *s)
{
    int left = 0, right = 0;
    int maxLength = 0;
    int repeat = 0;
    for (; s[right]; right++)
    {
        if (right > 0 && s[right] == s[right - 1])
        {
            repeat++;
        }
        while (repeat > 1)
        {
            if (s[left] == s[left + 1])
            {
                repeat--;
            }
            left++;
        }
        int currentLength = right - left + 1;
        if (currentLength > maxLength)
        {
            maxLength = currentLength;
        }
    }
    return maxLength;
}
int main()
{
    char s[] = "52233";
    int res = longestSemiRepetitiveSubstring(s);
    printf("res=%d\n", res);
    return 0;
}
