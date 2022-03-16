#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief移动零
 *
 */
class Solution
{
public:
    void moveZeros(vector<int> &nums)
    {
        //[0,k) k代表为前n个非零元素
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i])
            {
                if (i != k)
                {
                    swap(nums[i], nums[k]);
                    k++;
                }
            }
        }
    }
};

int main()
{
    int arr[] = {0, 1, 0, 3, 12};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

    Solution().moveZeros(vec);

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}