/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题1：赋值运算符函数
// 题目：如下为类型CMyString的声明，请为该类型添加赋值运算符函数。

/*
    知识点：
    一、拷贝赋值运算符，需要注意4个事情：
        1. 传的形参一定是const 类型名& a，即常量引用，如果传入是实例，会效率低下
        2. 返回值一定是 类型名&即类型引用，用于连续赋值
        3. 是否释放实例已有的内存
        4. 判断传入的参数与当前实例是不是同一个实例
*/
#include<cstring>
#include<cstdio>

class CMyString
{
public:
    CMyString(char* pData = nullptr);  //构造函数
    CMyString(const CMyString& str); //拷贝构造函数
    ~CMyString(void); //析构函数

    CMyString& operator = (const CMyString& str); //拷贝赋值运算符

    void Print();

private:
    char* m_pData;
};

CMyString::CMyString(char* pData)
{
    if (pData == nullptr) {
        m_pData = new char[1]; //这里不能说临时开辟一个变量，而是需要new，因为临时变量出了if{}后就直接被回收了
        m_pData[0] = '\0';
    }
    else {
        //1：首先开辟一个段新的空间，该空间在堆空间内，下次需要用delete删除
        int length = strlen(pData);
        m_pData = new char[length + 1];
        strcpy_s(m_pData, length + 1, pData); //不允许使用strcpy，改用strcpy_s，并且，strcpy_s在copy有new的成员时，需要用3个参数的重载

        //2：这里的意思是m_pData与pData指向同一个数据，没有达到复制的要求
        //m_pData = pData;
    }
}

CMyString::CMyString(const CMyString& str)
{
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strcpy_s(m_pData, length + 1, str.m_pData);
}

CMyString::~CMyString()
{
    delete[] m_pData;
}

CMyString& CMyString::operator = (const CMyString& str)
{
    if (this == &str) return *this;
    else {
        delete[] m_pData;
        m_pData = nullptr;

        int length = strlen(str.m_pData);
        m_pData = new char[length + 1];
        strcpy_s(m_pData, length + 1, str.m_pData);

        return *this;
    }
}

void CMyString::Print()
{
    printf("%s", m_pData);
}

// ====================测试代码====================
void Test1()
{
    printf("Test1 begins:\n");

    char text[] = "Hello world";

    CMyString str1(text);
    CMyString str2;
    str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");
}

// 赋值给自己
void Test2()
{
    printf("Test2 begins:\n");

    char text[] = "Hello world";

    CMyString str1(text);
    str1 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str1.Print();
    printf(".\n");
}

// 连续赋值
void Test3()
{
    printf("Test3 begins:\n");

    char text[] = "Hello world";

    CMyString str1(text);
    CMyString str2, str3;
    str3 = str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str3.Print();
    printf(".\n");
}

//测试拷贝构造函数
void Test4()
{
    printf("Test4 begins:\n");

    char text[] = "Hello world";

    CMyString str1(text);
    CMyString str2(str1);

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    return 0;
}

