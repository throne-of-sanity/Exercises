#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/**
 * @brief 二维指针cmp函数写法
 *        字符串的cmp函数写法
 */
int Cmp(const void *a, const void *b)
{
    char *tmpA = *(char **)a;
    char *tmpB = *(char **)b;

    return strcmp(tmpA, tmpB);
}
/**
 * @brief 一维指针cmp函数写法
 *        字符串的cmp函数写法
 */
int CmpQsort(const void *a, const void *b)
{
    char tmpA = *(char *)a;
    char tmpB = *(char *)b;

    if (tmpA > tmpB)
    {
        return 1;
    }

    if (tmpA < tmpB)
    {
        return -1;
    }
    return 0;
}
bool IsDiffLetterNumSatisifyInWin(char *s, int left, int right, int maxLetters)
{
    // 将窗内字符转化为Bitmap
    int bitmap = 0;
    for (int i = left; i <= right; i++)
    {
        // 将字符转化为ASCII码
        int tmp = s[i] - 'a'; // 每个字母相对于字符a的偏移量
        bitmap |= 1U << tmp;
    }

    // 统计bitmap中1的个数
    int cnt = 0;
    while (bitmap)
    {
        cnt++;
        bitmap &= (bitmap - 1);
    }

    return cnt <= maxLetters;
}
int maxFreq(char *s, int maxLetters, int minSize, int maxSize)
{
    if (s == NULL || maxLetters == 0 || minSize == 0 || maxSize == 0)
    {
        return 0;
    }
    // 用来保存所有满足条件的子串信息
    int len = strlen(s);
    char **letterInfo = (char **)malloc(sizeof(char *) * (len - minSize + 1));
    if (letterInfo == NULL)
    {
        return 0;
    }
    // 子串长度是minSize的情况肯定包含子串长度是maxSize，所以只需计算minSize长度的子串
    // 窗的大小是 minSize
    int left = 0;
    int right = minSize - 1;
    int letterLen = 0;
    while (right < len)
    {
        // 窗内的字母数目是否小于等于maxLetters
        if (IsDiffLetterNumSatisifyInWin(s, left, right, maxLetters))
        {
            // 不直接保存满足条件子串每个字符，而是将地址挂靠上
            letterInfo[letterLen++] = &s[left];
        }

        right++;
        left++;
    }
    if (letterLen <= 1)
    { // 下面的比较方法不包括letternLen是1的情况，所以0和1要特殊处理
        free(letterInfo);
        letterInfo = NULL;
        return letterLen;
    }
    // 将所有满足条件的每个子串进行字符按ASCII码排序
    // for (int i = 0; i < letterLen; i++) {
    //    qsort(letterInfo[i], minSize, sizeof(char), CmpQsort); // 注意每个子串的大小，子串里的每个字符的大小
    //}
    qsort(letterInfo, letterLen, sizeof(char *), Cmp); // 整体排序，不是数组里的单个字符串排序,注意二维字符串指针cmp函数的写法，排序完，字符相近的字符串会挨在一块，这样才能用下面一维的比较方法进行比较,可以打印出来看看效果
    // 所有满足条件子串信息已经找到并保存好, 开始找其中出现次数最多的子串出现的次数
    int k = 1;
    int res = 0;
    // for (int i = 0; i < letterLen; i++) {
    // if (!strncmp(letterInfo[i], letterInfo[i + 1], minSize)) {}  // 这种写法容易造成数组访问越界
    //}
    for (int i = 1; i < letterLen; i++)
    { // 比较方法比较特别，注意学习, i从1开始，是有假设,只有letterLen大于1才能进，所以letterLen等于1要特殊处理
        if (strncmp(letterInfo[i], letterInfo[i - 1], minSize) == 0)
        {
            k++; /* 这里是对重复出现的子串进行计数 */
        }
        else
        {
            k = 1; /* 一旦不相等，由于已经进行过qsort排序，因此k要重新置位为1 */
        }

        res = res > k ? res : k;
    }
    return res;
}
int main()
{
    char s[] = "aababcaab";
    int maxLetters = 2;
    int minSize = 3;
    int maxSize = 4;
    int res = maxFreq(s, maxLetters, minSize, maxSize);
    printf("res=%d\n", res);
    return 0;
}