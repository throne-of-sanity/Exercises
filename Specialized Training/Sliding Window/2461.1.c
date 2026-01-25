// 2461. 长度为 K 子数组中的最大和
#include "uthash.h"
#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b));
typedef struct
{
    int key;
    int cnt;
    UT_hash_handle hh;
} HashNode;
long long maximumSubarraySum(int *nums, int numsSize, int k)
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
            entry = malloc(sizeof(HashNode));
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
        if (distinct == k)
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
    int nums[] = {1, 5, 4, 2, 9, 9, 9};
    int k = 3;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    long long res = maximumSubarraySum(nums, numsSize, k);
    printf("%lld\n", res);
    return 0;
}