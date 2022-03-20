#include <iostream>
#include <vector>

using namespace std;

/**
 *  @brief
 * 88. 合并两个有序数组
 * 给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，
 * 另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
 * 请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
 * 利用归并排序
 */
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int sorted[m + n];

        int i = 0, j = 0;
        for (int k = 0; k < m + n; k++)
        {
            /**
             * 考虑好边界值
             */
            if (i >= m)
            {
                sorted[k] = nums2[j];
                j++;
            }
            else if (j >= n)
            {
                sorted[k] = nums1[i];
                i++;
            }
            else if (nums1[i] < nums2[j])
            {
                sorted[k] = nums1[i];
                i++;
            }
            else
            {
                sorted[k] = nums2[j];
                j++;
            }
        }
        for (int i = 0; i < m + n; ++i)
        {
            nums1[i] = sorted[i];
        }
    };
};
int main()
{
    int arr[] = {4, 5, 6, 0, 0, 0};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
    int arr1[] = {1, 2, 3, 0, 0};

    vector<int> vec1(arr1, arr + sizeof(arr1) / sizeof(int));

    Solution().merge(vec, 3, vec1, 3);

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}