#include <stdio.h>
#include <limits.h>
int maxScore(int *cardPoints, int cardPointsSize, int k)
{
    int sum = 0, ans = INT_MAX, total = 0;
    int a = cardPointsSize - k;
    for (int i = 0; i < cardPointsSize; i++)
    {
        total += cardPoints[i];
        if (a)
        {
            sum += cardPoints[i];
            if (i < a - 1)
                continue;
            if (sum < ans)
                ans = sum;
            sum -= cardPoints[i - a + 1];
        }
    }
    if (a == 0)
        return total;
    return total - ans;
}
int main()
{
    int cardPoints[] = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    int cardPointsSize = sizeof(cardPoints) / sizeof(cardPoints[0]);
    int res = maxScore(cardPoints, cardPointsSize, k);
    printf("%d\n", res);
    return 0;
}