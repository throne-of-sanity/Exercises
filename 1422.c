// 1422. 分割字符串的最大得分
#include <string.h>
#include <stdio.h>
int maxScore(char *s)
{
    int len = strlen(s);
    int sum = 0;
    int score = 0, ans = 0;
    if(s[0]=='0') score++;
    for(int i=1;i<len;i++){
        score+=s[i]-'0';
    }
    ans=score;
    for (int i = 2; i < len; i++)
    {
        if(s[i-1]=='0') ans++;
        else ans--;
        if (ans > score)
            score = ans;
    }
    return score;
}
int main()
{
    char s[] = "011101";
    int res = maxScore(s);
    printf("%d\n", res);
    return 0;
}