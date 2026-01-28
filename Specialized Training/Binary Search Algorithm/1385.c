// 1385. 两个数组间的距离值
#include <stdlib.h>
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int lowerbound(int *nums, int numssize, int target)
{
    int left = -1, right = numssize;
    while (left + 1 < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target)
            right = mid;
        else
            left = mid;
    }
    return right;
}
int findTheDistanceValue(int *arr1, int arr1Size, int *arr2, int arr2Size, int d)
{
    qsort(arr2, arr2Size, sizeof(int), cmp);
    int ans = 0;
    for (int i = 0; i < arr1Size; i++)
    {
        int x = arr1[i];
        int threshold = lowerbound(arr2, arr2Size, x - d);
        if (threshold == arr2Size || arr2[threshold] > x + d)
            ans++;
    }
    return ans;
}