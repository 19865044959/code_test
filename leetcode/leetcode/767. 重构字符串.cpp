#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
方法：分析法

说明：分析所给信息与条件，通过条件逐步编程

时间复杂度与空间复杂度：O(n)  O(n)

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    string reorganizeString(string S) {
        int n = S.size();
        if (n == 1) return S;

        vector<int> hash(26, 0);
        int maxLength = 0;
        int id;
        for (int i = 0; i < n; i++) {
            if (maxLength < ++hash[S[i] - 'a']) {
                maxLength = hash[S[i] - 'a'];
                id = S[i] - 'a';
            }
        }
        /*
        这里举例进行说明：
        长度为奇数时：aaabc√  aaaaabc× 即a的maxnum为int((length + 1) / 2)
        长度为偶数时：aabc√   aaaabc×  即a的maxnum为int((length + 1) / 2)
        综上，当maxLength > int((length + 1) / 2)时，一定无法重构
        */
        if (maxLength > int((n + 1) / 2)) return "";

        /*
        剩下的一定是可以进行重构的，仅有一种情况是maxLength对应元素必须要在偶数位置，即为aaabc，
        需要放成abaca（bc可互换）
        那么把这种情况单独拎出来说明（n为奇数并且maxLength =int((length + 1) / 2)），其他的情况插空排就好了
        */
        int even = 0;
        int odd = 1;
        string ans(n, ' ');  //这里是否可以优化？我写成：string ans(n)无法通过
        //特殊情况
        if (n % 2 && maxLength == int((n + 1) / 2)) {
            while (hash[id]) {
                hash[id]--;
                ans[even] = char(id + 'a');
                even += 2;
            }
            for (int i = 0; i < 26; i++) {
                //将剩余的全部放到奇数位上
                while (hash[i] && odd < n) {
                    hash[i]--;
                    ans[odd] = char(i + 'a');
                    odd += 2;
                }
            }
        }
        //除了这种特殊情况，其他的全部插空排就好
        else {
            for (int i = 0; i < 26; i++) {
                while (hash[i] && even < n) {
                    hash[i]--;
                    ans[even] = char(i + 'a');
                    even += 2;
                }
                while (hash[i] && odd < n) {
                    hash[i]--;
                    ans[odd] = char(i + 'a');
                    odd += 2;
                }
            }
        }
        return ans;
    }
};
