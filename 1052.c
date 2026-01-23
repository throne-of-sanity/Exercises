#include <stdio.h>
#define MAX(a, b) ((b) > (a) ? (b) : (a))
int maxSatisfied(int *customers, int customersSize, int *grumpy, int grumpySize, int minutes)
{
    int s[2] = {}, max_s1 = 0;
    for (int i = 0; i < customersSize; i++)
    {
        s[grumpy[i]] += customers[i];
        int left = i - minutes + 1;
        if (left < 0)
        {
            continue;
        }
        max_s1 = MAX(max_s1, s[1]);
        s[1] -= grumpy[left] ? customers[left] : 0;
    }
    return s[0] + max_s1;
}
int main()
{
    int customers[] = {1, 0, 1, 2, 1, 1, 7, 5};
    int grumpy[] = {0, 1, 0, 1, 0, 1, 0, 1};
    int minutes = 3;
    int result = maxSatisfied(customers, 8, grumpy, 8, minutes);
    printf("%d\n", result);
    return 0;
}