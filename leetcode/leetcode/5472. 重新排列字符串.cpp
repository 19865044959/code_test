#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
������

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�

�漰����֪ʶ�㣺

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