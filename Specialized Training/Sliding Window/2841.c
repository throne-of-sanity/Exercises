// 2841. 几乎唯一子数组的最大和
#include "uthash.h"
#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b));
typedef struct
{
    int key;
    int cnt;
    UT_hash_handle hh;
} HashNode;
long long maxSum(int *nums, int numsSize, int m, int k)
{
    long long ans = 0, sum = 0;
    int distinct = 0;
    HashNode *count = NULL;
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
        HashNode *entry = NULL;
        HASH_FIND_INT(count, &nums[i], entry);
        if (entry == NULL)
        {
            distinct++;
            entry = (HashNode *)malloc(sizeof(HashNode));
            entry->key = nums[i];
            entry->cnt = 1;
            HASH_ADD_INT(count, key, entry);
        }
        else
        {
            entry->cnt++;
        }
        if (i < k - 1)
            continue;
        if (distinct >= m)
            ans = MAX(ans, sum);
        sum -= nums[i - k + 1];
        HashNode *exit = NULL;
        HASH_FIND_INT(count, &nums[i - k + 1], exit);
        if (exit != NULL)
        {
            exit->cnt--;
            if (exit->cnt == 0)
            {
                distinct--;
                HASH_DEL(count, exit);
                free(exit);
            }
        }
    }
    return ans;
}
int main()
{
    int nums[] = {5, 9, 9, 2, 4, 5, 4};
    int m = 1;
    int k = 3;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    long long res = maxSum(nums, numsSize, m, k);
    printf("%lld\n", res);
    return 0;
}