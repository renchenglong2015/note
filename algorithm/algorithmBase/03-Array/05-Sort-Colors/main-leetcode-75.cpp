#include <iostream>
#include <vector>

using namespace std;

/**
 *  @brief sort colors
 *  给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，
 *  使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 *  我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 *  必须在不使用库的sort函数的情况下解决这个问题。
 * 利用三路快排
 */
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        //[0,zero] ==1
        int zero = -1;
        //[two,n-1] ==2;
        int two = nums.size();
        for (int i = 0; i < two;)
        {
            if (nums[i] == 1)
                i++;
            else if (nums[i] == 2)
            {
                two--;
                swap(nums[i], nums[two]);
            }
            else
            {
                assert(nums[i] == 0);
                zero++;
                swap(nums[i], nums[zero]);
                i++;
            }
        }
    }
};

int main()
{
    int arr[] = {2, 2, 2, 1, 0, 1};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

    Solution().sortColors(vec);

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}