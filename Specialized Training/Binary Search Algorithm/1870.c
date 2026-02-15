// 1870. 准时到达的列车最小时速
#define MAX(a, b) ((b) > (a) ? (b) : (a))

int check(int v, int *dist, int n, long long h100)
{
    long long t = 0;
    for (int i = 0; i < n - 1; i++)
    {
        t += (dist[i] - 1) / v + 1;
    }
    return (t * v + dist[n - 1]) * 100 <= h100 * v;
}
int minSpeedOnTime(int *dist, int n, double hour)
{
    long long h100 = round(hour * 100);
    long long delta = h100 - (n - 1) * 100;
    if (delta <= 0)
    {
        return -1;
    }
    int max_dist = 0;
    long long sum_dist = 0;
    for (int i = 0; i < n; i++)
    {
        max_dist = MAX(max_dist, dist[i]);
        sum_dist += dist[i];
    }
    if (h100 <= n * 100)
    {
        return MAX(max_dist, (int)((dist[n - 1] * 100 - 1) / delta + 1));
    }
    int left = (sum_dist * 100 - 1) / h100;
    int h = h100 / (n * 100);
    int right = (max_dist - 1) / h + 1;
    while (left + 1 < right)
    {
        int mid = (left + right) / 2;
        if (check(mid, dist, n, h100))
            right = mid;
        else
            left = mid;
    }
    return right;
}