
- [c语言指针](#c语言指针)
  - [1分钟讲透指针的概念](#1分钟讲透指针的概念)
- [markdown语法](#markdown语法)
- [web3.0](#web30)

# c语言指针
## 1分钟讲透指针的概念
一切都是地址，c语言用变量用变量来存储数据，用函数来定义一段可以重复使用的代码，他们最终都要放到内存中才能供CPU使用。

数据和代码都以二进制的形式存储在内存中，计算机无法从格式上区分某块内存到底存储的是数据还是代码。操作系统会给不同的内存块不同的权限，具有读取和执行权限的是代码，具有读取写入权限的内存快就是数据。

CPU只能通过地址来获取内存中的代码和数据，程序在执行过程中会告诉cpu要执行的代码和以及要读写的数据的地址。


<span style="color:red;">
CPU访问内存需要的是地址，而不是函数名和变量名。函数名和变量名其实只是一种符号而已。当源代码被编译和链接成可执行程序时，它们都会被替换成地址。编译和链接就是找到这些符号所对应的地址。
</span>



# markdown语法

Create Table of Contents 创建目录

a|b|c
aa|bb|cc

markdown语法网址 [markdown](https://www.runoob.com/markdown/md-link.html)


[markdown](https://www.runoob.com/markdown/md-link.html)


插入图片
! [](https://static0.xesimg.com/quality-mall/pc-home/image/how_1.png)


表格

| a    |   b   |    c |
| :--- | :---: | ---: |
| a    |   b   |    C |



代码块

``` c++
#include<iostream>
int main(){
    printf();
}



```

- aaa
  - avccdsa
- acasd
- sddsaf


1.  asdfasdf
    1. asdfasdfasdfsad
    2. sadfasdfasdf
    3. asdfasdfasdf
    4. asdfasdf
    5. 
2.  cccccccc
3.  asdfasdf
4.  dasd发生的



# web3.0
 