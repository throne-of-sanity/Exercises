#include <string.h>
#include <stdio.h>
int main()
{
    char s[] = "011101";
    int len = strlen(s);
    int sum = 0;
    int i = 1;
    int score = 0, ans = 0;
    for (; i < len; i++)
    {
        for (int j = 0; j < i; j++)
            if (s[j] == '0')
                ans++;
        for (int j = i; j < len; j++)
            if (s[j] == '1')
                ans++;
        if (ans > score)
            score = ans;
        ans = 0;
    }
    printf("%d\n", score);
    return 0;
}