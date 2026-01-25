// 3679. 使库存平衡的最少丢弃次数
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int minArrivalsToDiscard(int *arrivals, int arrivalsSize, int w, int m)
{
    int *hash = malloc(sizeof(int) * 100001);
    memset(hash, 0, sizeof(int) * 100001);
    int sum = 0;
    for (int i = 0; i < arrivalsSize; i++)
    {
        hash[arrivals[i]]++;
        if (hash[arrivals[i]] > m)
        {
            sum++;
            hash[arrivals[i]]--;
            arrivals[i] = 0;
        }
        if (i < w - 1)
            continue;
        hash[arrivals[i - w + 1]]--;
    }
    return sum;
}
int main()
{
    int arrivals[] = {1, 2, 1, 3, 1};
    int w = 4;
    int m = 2;
    int arrivalsSize = sizeof(arrivals) / sizeof(arrivals[0]);
    int res = minArrivalsToDiscard(arrivals, arrivalsSize, w, m);
    printf("%d\n", res);
    return 0;
}