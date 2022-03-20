#include <iostream>
#include <vector>

using namespace std;

/**
 *  @brief
 * 215
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 * 利用快速排序
 */
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k){

    };
};
int main()
{
    int arr[] = {4, 5, 6, 0, 0, 0};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

    Solution().findKthLargest(vec, 2);

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}