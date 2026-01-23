#include <stdio.h>
int maxFreeTime(int eventTime, int k, int *startTime, int startTimeSize, int *endTime, int endTimeSize)
{
    int n = startTimeSize;
    int time[n + 1];
    time[0] = startTime[0];
    time[n] = eventTime - endTime[endTimeSize - 1];
    for (int i = 1; i < n; i++)
    {
        time[i] = startTime[i] - endTime[i - 1];
    }
    int sum = 0, ans = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += time[i];
        if (i < k)
            continue;
        if (sum > ans)
            ans = sum;
        sum -= time[i - k];
    }
    return ans;
}
int main()
{
    int eventTime = 20;
    int k = 2;
    int startTime[] = {2, 8, 15};
    int endTime[] = {5, 12, 18};
    int result = maxFreeTime(eventTime, k, startTime, 3, endTime, 3);
    printf("%d\n", result);
    return 0;
}