#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief 找到字符串中所有字母异位词
 * 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 * 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
 * 输入: s = "cbaebabacd", p = "abc"
 * 输出: [0,6]
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 */
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int freq[256] = {0};
        //使用滑动窗口技术
        //初始为[l= 0,r =-1]空窗口，直到[l = s.size()-1,r = s.size()]结束窗口
        int l = 0, r = -1;
        int res = 0;
        while (l < s.size())
        {
            if (r + 1 < s.size() && freq[s[r + 1]] == 0)
            {
                r++;
                freq[s[r]]++;
            }
            else //当出现重复的字母时，或者当前滑动窗口右指针走到头的时候。
            {

                freq[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
        }
        return res;
    }
};

int main()
{

    cout << Solution().findAnagrams("cbaebabacd", "abc") << endl; // 3
}