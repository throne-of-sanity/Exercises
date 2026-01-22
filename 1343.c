#include <stdio.h>
int numOfSubarrays(int *arr, int arrSize, int k, int threshold)
{
    int a = k * threshold;
    int sum = 0, cnt = 0;
    for (int i = 0; i < arrSize; i++)
    {
        sum += arr[i];
        if (i >= k - 1)
        {
            if (sum >= a)
                cnt++;
            sum -= arr[i - k + 1];
        }
    }
    return cnt;
}
int main()
{
    int arr[] = {2, 2, 2, 2, 5, 5, 5, 8};
    int k = 3;
    int threshold = 4;
    int res = numOfSubarrays(arr, sizeof(arr) / sizeof(arr[0]), k, threshold);
    printf("%d\n", res);
    return 0;
}