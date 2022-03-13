

/**
 * @brief
 *c++多文件编程，student.h分别需要引入student.cpp文件和main.cpp文件。理由很简单，因为
 *这两个文件中需要使用student.h文件声明的Student类，如同我们在使用cin和cout时需要提前引入<iostream>
 *头文件一样。
 */
#ifndef INC_01_BINARY_SEARCH_UTIL_H
#define INC_01_BINARY_SEARCH_UTIL_H

#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;
namespace MyUtil
{
    int *generateRandomArray(int n, int l, int r)
    {
        assert(n > 0 && l <= r);
        // C++又新增了两个关键字，new 和 delete：new 用来动态分配内存，delete 用来释放内存。
        int *p = new int[n];
        // delete[] p;
        srand(time(NULL));
        for (int i = 0; i < n; i++)
        {
            p[i] = rand() % (r - l + 1) + l;
        }
        return p;
    }
    int *generateOrderArray(int n, int l, int r)
    {
        assert(n > 0 && l <= r);
        int *p = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; i++)
        {
            p[i] = i;
        }
        return p;
    }

}
#endif // INC_01_BINARY_SEARCH_UTIL_H
