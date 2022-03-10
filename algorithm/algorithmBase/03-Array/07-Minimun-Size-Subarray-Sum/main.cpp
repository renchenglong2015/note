/**
 * @file main.cpp
 * @author renchenglong (523465560@qq.com)
 * @brief  leetcode 209号问题
 * @version 0.1
 * @date 2022-03-01
 * @copyright Copyright (c) 2022
 * 给定一个整型数组和一个数字s,找到数组中最短的一个连续子数组，使得连续子数组的数字和sum >= s,
 * 返回这个最短的连续子数组的长度值。
 * 比如给定数组[2,3,1,2,4,3],s =7
 * 答案[4,3],返回2。
 */
#include <iostream>
#include <vector>
#include <cassert>
#include <typeinfo>

using namespace std;

class Solution
{
public:
    /**
     * 暴力解法
     *
     * @param s
     * @param nums
     * @return int
     */
    int minSubArrayLen(int s, vector<int> &nums)
    {
        assert(s > 0);
        int res = nums.size() + 1;
        for (int l = 0; l < nums.size(); l++)
        {
            int sum = 0;
            for (int r = l; r < nums.size(); r++)
            {
                sum += nums[r];
                if (sum >= s)
                {
                    res = min(res, r - l + 1);
                    break;
                }
            }
        }
        if (res >= nums.size() + 1)
            return 0;

        return res;
    }
    /**
     * 双指针解法
     *
     * @param s
     * @param nums
     * @return int
     */
    int minSubArrayLen1(int s, vector<int> &nums)
    {
        assert(s > 0);
        int l = 0, r = -1; // [l,r]为我们的滑动窗口
        int res = nums.size() + 1;
        int sum = 0;

        while (l < nums.size())
        {

            if (sum < s && r + 1 < (int)nums.size())
            {
                sum = sum + nums[r + 1];
                r++;
            }
            else // r已经到头，或者 sum >= s
            {
                sum = sum - nums[l];
                l++;
            }
            if (sum >= s)
            {
                res = min(res, r - l + 1);
            }
        }
        if (res >= nums.size() + 1)
            return 0;

        return res;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
    int s = 1;
    int a = 0;
    a = Solution().minSubArrayLen1(s, vec);
    cout << a;
    return 0;
}