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

时间复杂度与空间复杂度：O(n) O(n)

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<int, int> hash;
        int retSize = 0;
        for (int i = 0; i < chars.size(); i++) {
            hash[chars[i]]++;
        }
        int n = words.size();
        for (int i = 0; i < n; i++) {
            auto temp = hash;
            int flag = 1;
            for (int j = 0; j < words[i].size(); j++) {
                if (temp.find(words[i][j]) == temp.end() || --temp[words[i][j]] < 0) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) retSize += words[i].size();
        }
        return retSize;
    }
};