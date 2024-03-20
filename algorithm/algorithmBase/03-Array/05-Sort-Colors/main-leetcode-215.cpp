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

private:
    int _partition(vector<int> &arr, int l, int r)
    {
        //首个值
        int v = arr[l];
        int j = l; // arr[l+1...j] < v ; arr[j+1...i) > v
        for (int i = l + 1; i <= r; i++)
            if (arr[i] < v)
            {
                j++;
                swap(arr[j], arr[i]);
            }

        swap(arr[l], arr[j]);
        return j;
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