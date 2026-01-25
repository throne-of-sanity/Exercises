// 1652. 拆炸弹
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
int *decrypt(int *code, int codeSize, int k, int *returnSize)
{
    int *ans = malloc(codeSize * sizeof(int));
    *returnSize = codeSize;
    memset(ans, 0, codeSize * sizeof(int));
    if (k == 0)
        return ans;
    int right = k > 0 ? k : codeSize - 1;
    k = abs(k);
    for (int i = right - k + 1; i <= right; i++)
    {
        ans[0] += code[i % codeSize];
    }
    for (int i = 1; i < codeSize; i++)
    {
        right++;
        ans[i] = ans[i - 1] - code[(right - k) % codeSize] + code[(right) % codeSize];
    }
    return ans;
}
int main()
{
    int codeSize = 4;
    int code[4] = {5, 7, 1, 4};
    int k = 3;
    int returnSize;
    int *ans = decrypt(code, codeSize, k, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}