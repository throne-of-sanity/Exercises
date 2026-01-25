// 2024. 考试的最大困扰度
#include <stdio.h>
#include <string.h>
#define MAX(a, b) ((b) > (a) ? (b) : (a))
int maxConsecutiveAnswers(char *answerKey, int k)
{
    int ans = 0, left = 0, cnt[2] = {};
    for (int right = 0; answerKey[right]; right++)
    {
        cnt[answerKey[right] >> 1 & 1]++;
        while (cnt[0] > k && cnt[1] > k)
        {
            cnt[answerKey[left] >> 1 & 1]--;
            left++;
        }
        ans = MAX(ans, right - left + 1);
    }
    return ans;
}
int main()
{
    char answerKey[] = "TTFTTFTT";
    int k = 1;
    int res = maxConsecutiveAnswers(answerKey, k);
    printf("res=%d\n", res);
    return 0;
}