#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief移动零
 * 给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。
 * 由于在某些语言中不能改变数组的长度，所以必须将结果放在数组nums的第一部分。更规范地说，如果在删除重复项之后有 k 个元素，那么 nums 的前 k 个元素应该保存最终结果。
 * 将最终结果插入 nums 的前 k 个位置后返回 k 。
 * 不要使用额外的空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
 *
 *  输入：nums = [1,1,2]
 *  输出：2, nums = [1,2,_]
 *  解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。
 */
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        //[0,k) k代表为前k个值为互不相等的元素
        int k = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[k - 1])
            {
                if (k != i)
                {
                    nums[k] = nums[i];
                }
                k++;
            }
        }
        return k;
    }
};

int main()
{
    int arr[] = {1, 2, 2, 2, 3};

    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
    Solution().removeDuplicates(vec);

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}