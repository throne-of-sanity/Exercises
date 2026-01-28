// 744. 寻找比目标字母大的最小字母
#include <stdio.h>
char nextGreatestLetter(char *letters, int lettersSize, char target)
{
    int left = -1, right = lettersSize;
    while (left + 1 < right)
    {
        int mid = left + (right - left) / 2;
        if (letters[mid] > target)
            right = mid;
        else
            left = mid;
    }
    return right == lettersSize ? letters[0] : letters[right];
}