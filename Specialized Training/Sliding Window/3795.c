// 3795. 不同元素和至少为 K 的最短子数组长度
#include <stdio.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
int minLength(int *nums, int numsSize, int k)
{
    int left = 0, right = 0;
    int cnt[100001] = {0};
    int sum = 0, minlen = 100002;
    for (; right < numsSize; right++)
    {
        if (cnt[nums[right]] == 0)
            sum += nums[right];
        cnt[nums[right]]++;
        while (sum >= k)
        {
            cnt[nums[left]]--;
            if (cnt[nums[left]] == 0)
                sum -= nums[left];
            minlen = MIN(right - left + 1, minlen);
            left++;
        }
    }
    return minlen == 100002 ? -1 : minlen;
}
int main()
{
    int nums[] = {2, 2, 3, 1};
    int numsSzie = 4;
    int k = 4;
    int res = minLength(nums, numsSzie, k);
    printf("res==%d", res);
    return 0;
}