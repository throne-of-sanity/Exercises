// 3306. 元音辅音字符串计数 II
#include <stdio.h>
int numFriendRequests(int *ages, int agesSize)
{
    int cnt[121] = {};
    for (int i = 0; i < agesSize; i++)
    {
        cnt[ages[i]]++;
    }
    int ans = 0, cnt_window = 0, age_y = 0;
    for (int age_x = 0; age_x < 121; age_x++)
    {
        cnt_window += cnt[age_x];
        if (age_y * 2 <= age_x + 14) // 一般为while但此处特殊
        {                            // 不能发送好友请求
            cnt_window -= cnt[age_y];
            age_y++;
        }
        if (cnt_window > 0)
        { // 存在可以发送好友请求的用户
            ans += cnt[age_x] * cnt_window - cnt[age_x];
        }
    }
    return ans;
}