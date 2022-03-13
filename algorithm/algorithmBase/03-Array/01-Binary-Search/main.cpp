#include <iostream>
#include <cmath>
#include <cassert>
#include <ctime>
#include "util.h"

using namespace std;
/**
 * 得来纸上终觉浅,绝知此事要躬行。
 * 二分搜索法的思想于1946年提出，第一个没有bug的二分搜索法直到1962年才出现。由此可见真正写出一个完全没有bug的程序相对是很困难的。
 * 我们用自然语言来描述算法的思想是很容易的，但是去写往往也花很长时间。这也是为什么大厂面试都必须要手写算法。
 * （ps: 二分搜索的整形溢出问题，c++中int型是32位二进制数，首位0和1分别表示数字的正和负，所以最大的能表示的数为2^31 - 1。
 *   若要表示的数大于等于2^31，则会仍进位，也就是首位为1，但计算机会认为这个数是负数。
 * 所以 mid = (l + r) / 2 要写成 mid = l+ (r - l) / 2 ）
 *
 * 如何写出正确的程序，
 * 明确变量的定义
 * 循环不变量
 * 小数据量调试
 * 大数据量测试
 *
 * @tparam T
 */

template <typename T>
/**
 * @brief
 *
 * @param arr
 * @param n
 * @param target
 * @return int
 */
int binarySearch(T arr[], int n, T target)
{
    //清晰的定义好l,r，在区间[l,r]中搜索值
    //循环不变量
    int l = 0, r = n - 1;
    int mid = 0;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

template <typename T>
int binarySearch2(T arr[], int n, T target)
{
    //清晰的定义好l,r，在区间[l,r)中搜索值
    //循环不变量
    int l = 0, r = n;
    int mid = 0;
    while (l + 1 <= r)
    {
        mid = (l + r) / 2; //
        if (arr[mid] == target)
            return mid;
        if (arr[mid] > target)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}
int mySqrt(int x)
{
    assert(x >= 0);
    int l = 0, r = x;
    int mid = 0;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (mid * mid == x)
            return mid;
        if (mid * mid > x)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l - 1;
}
int main()
{
    int sqx = 0;
    sqx = mySqrt(90);

    int n = pow(10, 6);
    int *data = MyUtil::generateOrderArray(n, 10, 20);

    clock_t startTime = clock();
    for (int i = 0; i < n; i++)
        assert(i == binarySearch2(data, n, i));
    clock_t endTime = clock();

    cout << "Binary Search test complete." << endl;
    cout << "Time cost: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

    return 0;
}