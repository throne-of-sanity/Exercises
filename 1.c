#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"
struct hashTable
{
    int key;
    int val;
    UT_hash_handle hh;
};
struct hashTable *hashtable;
struct hashTable *find(int key)
{
    struct hashTable *tmp;
    HASH_FIND_INT(hashtable, &key, tmp);
    return tmp;
}
void insert(int ikey, int ival)
{
    struct hashTable *it = find(ikey);
    if (it == NULL)
    {
        struct hashTable *tmp = malloc(sizeof(struct hashTable));
        tmp->key = ikey;
        tmp->val = ival;   
        HASH_ADD_INT(hashtable, key, tmp);
    }
    else
    {
        it->val = ival;
    }
}
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    hashtable = NULL;
    for (int i = 0; i < numsSize; i++)
    {
        struct hashTable *it = find(target - nums[i]);
        if (it != NULL)
        {
            int *result = malloc(sizeof(int) * 2);
            result[0] = it->val;
            result[1] = i;
            *returnSize = 2;
            return result;
        }
        insert(nums[i], i);
    }
    *returnSize = 0;
    return NULL;
}
int main()
{
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int *result = twoSum(nums, 4, target, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }
    return 0;
}