#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
static uint64_t fnv1a_hash(const char *p, int len)
{
    uint64_t h = 1469598103934665603ULL;
    for (int i = 0; i < len; ++i)
    {
        h ^= (unsigned char)p[i];
        h *= 1099511628211ULL;
    }
    return h;
}
int maxFreq(char *s, int maxLetters, int minSize, int maxSize)
{
    (void)maxSize; // unused as per algorithm using only minSize
    int L = minSize;
    int n = (int)strlen(s);
    if (L <= 0 || n <= 0 || L > n)
        return 0;

    int expected = n - L + 1;
    size_t cap = 16;
    while (cap < (size_t)(expected * 2))
        cap <<= 1;

    char **keys = (char **)calloc(cap, sizeof(char *));
    int *counts = (int *)calloc(cap, sizeof(int));
    if (!keys || !counts)
    {
        free(keys);
        free(counts);
        return 0;
    }
    int freq[26] = {0};
    int distinct = 0;
    int left = 0;
    int ans = 0;
    for (int right = 0; right < n; ++right)
    {
        int idx = s[right] - 'a';
        if (idx >= 0 && idx < 26)
        {
            if (freq[idx] == 0)
                distinct++;
            freq[idx]++;
        }
        while (right - left + 1 > L)
        {
            int j = s[left] - 'a';
            if (j >= 0 && j < 26)
            {
                freq[j]--;
                if (freq[j] == 0)
                    distinct--;
            }
            left++;
        }
        if (right - left + 1 == L && distinct <= maxLetters)
        {
            const char *p = s + left;
            uint64_t h = fnv1a_hash(p, L);
            size_t mask = cap - 1;
            size_t pos = (size_t)h & mask;
            while (keys[pos] != NULL)
            {
                if (memcmp(keys[pos], p, L) == 0)
                {
                    counts[pos]++;
                    if (counts[pos] > ans)
                        ans = counts[pos];
                    goto cont_loop;
                }
                pos = (pos + 1) & mask;
            }
            keys[pos] = (char *)p;
            counts[pos] = 1;
            if (ans < 1)
                ans = 1;
        }
    cont_loop:;
    }
    free(keys);
    free(counts);
    return ans;
}
int main()
{
    // Example usage
    char s[] = "aababcaab";
    int maxLetters = 2;
    int minSize = 3;
    int maxSize = 4;
    int result = maxFreq(s, maxLetters, minSize, maxSize);
    printf("Max frequency: %d\n", result);
    return 0;
}