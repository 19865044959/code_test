/*
    给了你一个判断字符串是否相等的规则：s1与s2长度相同，如果是长度是奇数，那么一个一个判断，要都相同才是相同的字符串
    如果是偶数个，那么取其中点，分割成两个相同长度的字符串，s1_1  == s2_1 || s1_2 == s2_1任意一个成立就是相等的，现在让你用这个判断条件
    去判断两个字符串
*/

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
using std::vector;
using std::swap;

using namespace std;

bool dfs(string& s1, string& s2, int s1_left, int s1_right, int s2_left, int s2_right) {
    if (s2_left > s2_right) return true;
    int n = s2_right - s2_left + 1;
    if (n & 0x01) {
        for (int i = s2_left; i <= s2_right; i++) {
            if (s1[i] != s2[i]) return false;
        }
        return true;
    }
    else {
        if (n == 2) { //没有写这个，使得通过率为0%
            for (int i = 0; i < 2; i++) {
                if (s1[s1_left + i] != s2[s2_left + i]) return false;
            }
            return true;
        }
        else {
            int s1_mid = s1_left + (s1_right - s1_left) / 2;
            int s2_mid = s2_left + (s2_right - s2_left) / 2;
            return(dfs(s1, s2, s1_left, s1_mid, s2_left, s2_mid) && dfs(s1, s2, s1_mid + 1, s1_right, s2_mid + 1, s2_right)) || (dfs(s1, s2, s1_left, s1_mid, s2_mid + 1, s2_right) && dfs(s1, s2, s1_mid + 1, s1_right, s2_left, s2_mid));
        }
    }
}

int main() {
    int t;
    while (cin >> t) {
        for (int k = 0; k < t; k++) {
            string s1, s2;
            cin >> s1;
            cin >> s2;
            string str;
            if (dfs(s1, s2, 0, s1.size() - 1, 0, s2.size() - 1) == true) str = "YES";
            else {
                str = "NO";
            }
            cout << str << endl;
        }
    }
    return 0;
}
/*
1
aabc
bcaa
*/