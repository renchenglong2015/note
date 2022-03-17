#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief移动零
 * 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
 * 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
 * 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
 */
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        //[0,k) k代表为前n个值为val 的元素
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                if (i != k)
                {
                    swap(nums[i], nums[k]);
                }
                k++;
            }
        }
        return k;
    }
};

int main()
{
    int val = 3;
    int arr[] = {3, 2, 2, 3};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

    Solution().removeElement(vec, val);

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}