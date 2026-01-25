// 3694. 删除子字符串后不同的终点
#include <stdio.h>
#include <string.h>
#include "uthash.h"
typedef struct
{
    long long key;
    int count;
    UT_hash_handle hh;
} HashSet;
int distinctPoints(char *s, int k)
{
    int x = 0, y = 0;
    long long key = 0;
    int len = strlen(s);
    int cnt = 0;
    HashSet *set = NULL, *entry = NULL;
    for (int i = 0; s[i]; i++)
    {
        switch (s[i])
        {
        case 'L':
            x--;
            break;
        case 'R':
            x++;
            break;
        case 'D':
            y--;
            break;
        case 'U':
            y++;
            break;
        }
        int left = i + 1 - k;
        if (left < 0)
        {
            continue;
        }
        key = ((long long)(x + len) << 32 | (y + len));
        HASH_FIND(hh, set, &key, sizeof(long long), entry);
        if (entry == NULL)
        {
            entry = (HashSet *)malloc(sizeof(HashSet));
            entry->key = key;
            entry->count = 1;
            HASH_ADD(hh, set, key, sizeof(long long), entry);
            cnt++;
        }
        switch (s[left])
        {
        case 'L':
            x++;
            break;
        case 'R':
            x--;
            break;
        case 'D':
            y++;
            break;
        case 'U':
            y--;
            break;
        }
    }
    return cnt;
}
int main()
{
    char s[] = "LURD";
    int k = 2;
    int result = distinctPoints(s, k);
    printf("Distinct points: %d\n", result);
    return 0;
}