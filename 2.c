#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *head = NULL, *result = NULL;
    int carry = 0;
    int n1, n2, sum;
    while (l1 || l2)
    {
        n1 = l1 ? l1->val : 0;
        n2 = l2 ? l2->val : 0;
        sum = n1 + n2 + carry;
        if (!head)
        {
            head = result = malloc(sizeof(struct ListNode));
            result->val = sum % 10;
        }
        else
        {
            result->next = malloc(sizeof(struct ListNode));
            result->next->val = sum % 10;
            result = result->next;
        }
        result->next = NULL;
        carry = sum / 10;
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    if (carry > 0)
    {
        result->next = malloc(sizeof(struct ListNode));
        result->next->val = carry;
        result->next->next = NULL;
    }
    return head;
}
int main()
{
    return 0;
}