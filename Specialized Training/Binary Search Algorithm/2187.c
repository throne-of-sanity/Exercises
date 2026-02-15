// 2187. 完成旅途的最少时间
#include <stdlib.h>
#include <stdio.h>
#define MIN(a, b) ((b) < (a) ? (b) : (a))
int check(long long a, int *nums, int numsSize, int totalTrips)
{
    long long sum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        sum += a / nums[i];
        if (sum >= totalTrips)
            return 1;
    }
    return 0;
}
long long minimumTime(int *time, int timeSize, int totalTrips)
{
    long long min = time[0];
    for (int i = 1; i < timeSize; i++)
    {
        min = MIN(min, time[i]);
    }
    long long left = min - 1;
    long long right = (long long)min * totalTrips;
    while (left + 1 < right)
    {
        long long mid = left + (right - left) / 2;
        if (check(mid, time, timeSize, totalTrips))
            right = mid;
        else
            left = mid;
    }
    return right;
}