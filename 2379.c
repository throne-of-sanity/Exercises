#include <string.h>
#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
int minimumRecolors(char *blocks, int k)
{
    int ans = 0, cnt = 0;
    for (int i = 0; blocks[i]; i++)
    {
        if (blocks[i] == 'B')
            ans++;
        if (i < k - 1)
            continue;
        cnt = max(cnt, ans);
        if (cnt == k)
            return 0;
        if (blocks[i - k + 1] == 'B')
            ans--;
    }
    return k - cnt;
}
int main()
{
    char blocks[] = "WBBWWBBWBW";
    int k = 7;
    int res = minimumRecolors(blocks, k);
    printf("%d\n", res);
    return 0;
}