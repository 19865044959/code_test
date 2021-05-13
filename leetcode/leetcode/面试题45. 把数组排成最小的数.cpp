#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
涉及到的知识点：
1.sort函数其实有3个参数，前两个参数输入迭代器，后一个参数可以输入一个函数，要求：
    (1)该函数返回值bool类型，且仅有两个输入
    (2)若该函数return值为true，则说明第一个参数传递的元素<第二个参数传递元素
    (3)只需要传递函数名，而不需要变量

2.非静态成员函数均存在默认参数this指针，因此如果stringValueDefine不加static的话会有3个参数从而报错

3.static关键字在c++中的作用：
    (1)定义在类内，静态成员函数或者静态变量，被所有的成员所共享，它的生存周期是程序的生存周期，与成员无关
    (2)定义在类外，修饰全局变量，或者函数，那么变量或者函数只能在本文件中使用，无法利用extern在其他文件中调用，
    因此可以利用static在一个工程之中的不同源文件之中声明同名函数而不会发出重定义错误
    (完美解决我和权哥代码有processState函数名重复问题)

4.string之间相加是字符串的拼接操作

5.c++之中，字符串进行比较是比较第一个不相同字母的ascii码，而ascii码中数字<大写字母<小写字母要注意

6.利用to_string(在string头文件之中)可以实现int -> string
***********************************************************************************************************/
class Solution_45 {
public:
    string minNumber(vector<int>& nums) {
        vector<string> temp;
        for (auto i : nums) {
            temp.push_back(to_string(i));
        }
        sort(temp.begin(), temp.end(), stringValueDefine);
        string ans = "";
        for (auto i : temp) {
            ans += i;
        }
        return ans;
    }

private:
    static bool stringValueDefine(string& str1, string& str2) {
        return str1 + str2 < str2 + str1;
    }
};