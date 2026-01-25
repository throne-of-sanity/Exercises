// 1297. 子串的最大出现次数
// 滑动窗口+哈希表
#include <stdio.h>
#include <string.h>
#include <uthash.h>
#include <stdbool.h>
#define MAX_SIZE 26
#define MAX(a, b) ((a) > (b) ? (a) : (b))
typedef struct
{
    char str[MAX_SIZE];
    int count;
    UT_hash_handle hh;
} HashNode;
int maxFreq(char *s, int maxLetters, int minSize, int maxSize)
{
    HashNode *Node = NULL;
    char str[minSize + 1];
    int len = strlen(s);
    int result = 0, distinct = 0;
    int cnt[MAX_SIZE] = {0};
    for (int i = 0; i < len; i++)
    {
        HashNode *entry = NULL;
        if (cnt[s[i] - 'a'] == 0)
            distinct++;
        cnt[s[i] - 'a']++;
        if (i < minSize - 1)
            continue;
        if (distinct <= maxLetters)
        {
            strncpy(str, s + i - minSize + 1, minSize);
            str[minSize] = '\0';
            HASH_FIND_STR(Node, str, entry);
            if (entry == NULL)
            {
                entry = malloc(sizeof(HashNode));
                strcpy(entry->str, str);
                entry->count = 1;
                HASH_ADD_STR(Node, str, entry);
            }
            else
            {
                entry->count++;
            }
            result = MAX(result, entry->count);
        }
        cnt[s[i - minSize + 1] - 'a']--;
        if (cnt[s[i - minSize + 1] - 'a'] == 0)
            distinct--;
    }
    return result;
}
int main()
{
    char s[] = "aababcaab";
    int maxLetters = 2;
    int minSize = 3;
    int maxSize = 4;
    int res = maxFreq(s, maxLetters, minSize, maxSize);
    printf("res=%d\n", res);
    return 0;
}