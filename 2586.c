// 2586. 统计范围内的元音字符串数
#include <stdio.h>
#include <string.h>
int vowelStrings(char **words, int wordsSize, int left, int right)
{
    int cnt = 0;
    for (int i = left; i <= right; i++)
    {
        int a = 0, b = 0;
        int len = strlen(words[i]);
        int l = words[i][0];
        int r = words[i][len - 1];
        switch (l)
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            a = 1;
        switch (r)
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            b = 1;
        if (a && b)
            cnt++;
    }
    return cnt;
}
int main()
{
    char *words[] = {"aba", "bcb", "ece", "aa", "e"};
    int res = vowelStrings(words, 5, 0, 4);
    printf("%d\n", res);
    return 0;
}