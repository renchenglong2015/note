#include <iostream>
#include <vector>

using namespace std;

/**
 * 给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 最多出现两次 ，返回删除后数组的新长度。
 *
 * 输入：nums = [1,1,1,2,2,3]
 * 输出：5, nums = [1,1,2,2,3]
 * 解释：函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。 不需要考虑数组中超出新长度后面的元素。
 */
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        //    int arr[] = {0, 0, 1, 1, 1, 1, 2, 3, 3};

        //[0,k) k代表为前k个值为互不相等的元素
        int k = 1;
        //代表数字出现的次数
        int count = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[k - 1])
            {
                if (k != i)
                {
                    nums[k] = nums[i];
                }
                k++;
                count = 1;
            }
            else if (nums[i] == nums[k - 1] && count < 2)
            {
                if (k != i)
                {
                    nums[k] = nums[i];
                }
                k++;
                count++;
            }
        }

        return k;
    }
};

int main()
{
    int arr[] = {0, 0, 1, 1, 1, 1, 2, 3, 3};

    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
    Solution().removeDuplicates(vec);

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}