#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：第一种想法：直接用一个int型变量储存最大数

说明：

时间复杂度与空间复杂度：

涉及到的知识点：

***********************************************************************************************************/
class Solution {
public:
    vector<int> printNumbers(int n) {
        long long maxNum = 1;
        for (int i = 0; i < n; i++) {
            maxNum *= 10;
        }
        vector<int> res(maxNum - 1);
        for (int i = 0; i < maxNum - 1; i++) {
            res[i] = i + 1;
        }
        return res;
    }
};
/*
    变式：若n > 64，仍然要打印输出，怎么办？
*/
/**********************************************************************************************************
方法：利用字符串代替输出

说明：

时间复杂度与空间复杂度：O(10^n)  O(1)

涉及到的知识点：

***********************************************************************************************************/
class Solution {
public:
    void printNumbers(int n) {
        string res(n, '0');
        while (!numIncrement(res)) {
            printNum(res);
        }
        return;
    }

    bool numIncrement(string& res) {
        bool overFlow = false;
        bool takeOver = false; //进位
        int nSum = 0;
        for (int i = res.size() - 1; i >= 0; i--) {
            nSum = res[i] - '0' + takeOver;
            takeOver = false; //进位清零
            if (i == res.size() - 1) nSum++;
            if (nSum == 10) {
                if (i == 0) {
                    overFlow = true;
                    return overFlow;
                }
                takeOver = true;
                nSum -= 10;
                res[i] = '0' + nSum;
            }
            else {
                res[i] = '0' + nSum;
                break;
            }
        }
        return takeOver;
    }

    void printNum(string& res) {
        int count = 0;
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == '0') {
                count++;
                continue;
            }
            break;
        }
        cout << res.substr(count, res.size() - count) << endl;
        return;
    }
};

int main() {
    Solution a;
    a.printNumbers(5);
    return 0;
}