#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：

说明：

时间复杂度与空间复杂度：

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans = s;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            ans[indices[i]] = s[i];
        }
        return ans;
    }
};