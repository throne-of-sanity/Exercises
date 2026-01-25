// 904. 水果成篮
#include <stdio.h>
#include <uthash.h>
typedef struct
{
    int key;
    int cnt;
    UT_hash_handle hh;
} HsahNode;
int totalFruit(int *fruits, int fruitsSize)
{
    int left = 0, right = 0;
    int distinctCount = 0;
    int max = 0, cur = 0;
    HsahNode *Node = NULL;
    for (; right < fruitsSize; right++)
    {
        HsahNode *entry = NULL;
        HASH_FIND_INT(Node, &fruits[right], entry);
        if (entry == NULL)
        {
            distinctCount++;
            entry = (HsahNode *)malloc(sizeof(HsahNode));
            entry->key = fruits[right];
            entry->cnt = 1;
            HASH_ADD_INT(Node, key, entry);
        }
        else
        {
            entry->cnt++;
        }
        while (distinctCount > 2)
        {
            HsahNode *temp = NULL;
            HASH_FIND_INT(Node, &fruits[left], temp);
            temp->cnt--;
            if (temp->cnt == 0)
            {
                distinctCount--;
                HASH_DEL(Node, temp);
                free(temp);
            }
            left++;
        }
        cur = right - left + 1;
        if (cur > max)
            max = cur;
    }
    HsahNode *current, *tmp;
    HASH_ITER(hh, Node, current, tmp)
    {
        HASH_DEL(Node, current);
        free(current);
    }
    return max;
}
int main()
{
    int fruits[] = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    int res = totalFruit(fruits, 11);
    printf("%d\n", res);
    return 0;
}