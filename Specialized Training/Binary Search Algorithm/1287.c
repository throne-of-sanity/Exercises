// 1287. 有序数组中出现次数超过25%的元素
int lowerBound(int *nums, int numsSize, int target)
{
    int left = -1, right = numsSize;
    while (left + 1 < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    return right;
}
int findSpecialInteger(int *arr, int arrSize)
{
    int m = arrSize / 4;
    for (int i = m; i <= m * 2 + 1; i += m + 1)
    {
        int x = arr[i];
        int j = lowerBound(arr, arrSize, x);
        if (arr[j + m] == x)
        {
            return x;
        }
    }
    return arr[m * 3 + 2];
}