// 1385. 两个数组间的距离值
#include <stdlib.h>
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int findTheDistanceValue(int *arr1, int arr1Size, int *arr2, int arr2Size, int d)
{
    qsort(arr1, arr1Size, sizeof(int), cmp);
    qsort(arr2, arr2Size, sizeof(int), cmp);
    int ans = 0, j = 0;
    for (int i = 0; i < arr1Size; i++)
    {
        int x = arr1[i];
        while (j < arr2Size && arr2[j] < x - d)
        {
            j++;
        }
        if (j == arr2Size || arr2[j] > x + d)
        {
            ans++;
        }
    }
    return ans;
}