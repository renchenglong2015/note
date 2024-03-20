#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief 在一个字符串中寻找没有重复字母的最长子串
 *如"bbbbbb" 结果为b
 *如"pwwkew" 则结果为wke
 */
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
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

    cout << Solution().lengthOfLongestSubstring("abcabcbb") << endl; // 3
    cout << Solution().lengthOfLongestSubstring("bbbbb") << endl;    // 1
    cout << Solution().lengthOfLongestSubstring("pwwkew") << endl;   // 3
    cout << Solution().lengthOfLongestSubstring("c") << endl;        // 1
    cout << Solution().lengthOfLongestSubstring("") << endl;         // 0
}