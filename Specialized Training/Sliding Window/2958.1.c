//2958. 最多 K 个重复元素的最长子数组
#include<stdio.h>
#include<uthash.h>
typedef struct {
    int key;
    int count;
    UT_hash_handle hh;
} HashItem;
int maxSubarrayLength(int* nums, int numsSize, int k) {
    HashItem* Item = NULL;
    int left = 0, right = 0;
    int maxLen = 0, cur = 0;
    for (; right < numsSize; right++)
    {
        HashItem* hash = NULL;
        HASH_FIND_INT(Item, &nums[right], hash);
        if (hash == NULL)
        {
            hash = (HashItem*)malloc(sizeof(HashItem));
            hash->key = nums[right];
            hash->count = 1;
            HASH_ADD_INT(Item, key, hash);
        }
        else
        {
            hash->count++;
        }
        while (hash->count > k)
        {
            HashItem* leftHash = NULL;
            HASH_FIND_INT(Item, &nums[left], leftHash);
            if (leftHash != NULL)
            {
                leftHash->count--;
            }
            left++;
        }
        cur = right - left + 1;
        if (cur > maxLen)
            maxLen = cur;
    }
    return maxLen;
}
int main()
{
    int nums[] = {4, 2, 4, 5, 6, 2, 2, 2};
    int res = maxSubarrayLength(nums, 8, 2);
    printf("res=%d\n", res);
    return 0;
}