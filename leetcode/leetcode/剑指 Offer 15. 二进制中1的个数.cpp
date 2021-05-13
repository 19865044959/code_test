#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法1：

说明：
    缺点：当输入一个负数时，即输入的类型是int类型时，有可能会发生这种情况，那么有可能会产生死循环
    这是因为负数左移，最高位仍然是1，即最高位一直给的是1而不是0

时间复杂度与空间复杂度：

涉及到的知识点：

***********************************************************************************************************/
// class Solution {
// public:
//     int hammingWeight(uint32_t n) {
//         int count = 0;
//         while(n){
//             if(n & 1) count++;
//             n = n >> 1;
//         }
//         return count;
//     }
// };



/**********************************************************************************************************
方法2：

说明：
    转换思路，我不一定移给定数字，还可以移动flag，让它逐个与n的所有位做与，直到flag == 0为止

时间复杂度与空间复杂度：

涉及到的知识点：

***********************************************************************************************************/
// class Solution {
// public:
//     int hammingWeight(uint32_t n) {
//         uint32_t flag = 1; //int类型会出错
//         int count = 0;
//         while(flag){
//             if(flag & n) count++;
//             flag = flag << 1;
//         }
//         return count;
//     }
// };


/**********************************************************************************************************
方法3：

说明：
    要记住的结论：将一个数-1后，再与原数进行与运算，得到的数与原数相比，最右边的1会变成0,除此外没有其他变化
    即 n & (n - 1) == n >> 1，它与n >> 1相比还有的好处就是：不怕负数

时间复杂度与空间复杂度：

涉及到的知识点：

***********************************************************************************************************/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};

int main() {
    Solution a;
    int a1 = 0x80000000;
    int a2 = 0xFFFFFFFF;
    int a3 = 1;
    cout << a.hammingWeight(a1) << endl;
    cout << a.hammingWeight(a2) << endl;
    cout << a.hammingWeight(a3) << endl;
    return 0;
}